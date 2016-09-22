#include <algorithm>
#include <cctype>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include <dirent.h>

class Directory {
public:
  explicit Directory(const std::string& path)
  : dir_(opendir(path.c_str()))
  {
    if (!dir_) throw std::runtime_error(strerror(errno));
  }

  ~Directory() {
    if (dir_)
      closedir(dir_);
  }

  std::vector<std::string> Contents(bool skip_dotfiles = true) const {
    std::vector<std::string> contents;

    errno = 0;
    while (dirent* entry = readdir(dir_)) {
      std::string name(entry->d_name);
      if (name.empty()) continue;

      if (skip_dotfiles && name[0] == '.') continue;

      contents.push_back(entry->d_name);
    }
    rewinddir(dir_);
    if (errno) {
      throw std::runtime_error(strerror(errno));
    }

    return contents;
  }

private:
  DIR* dir_;
};

std::string Extension(const std::string& file) {
  const std::regex suffix_regex("[^.]*$");
  std::sregex_iterator it(file.begin(), file.end(), suffix_regex);
  if (it == std::sregex_iterator()) return "";

  return it->str();
}

std::string Author(const std::string& file) {
  const std::regex author_regex(".* - (.*) - CppCon 2016\\.[^.]*$");
  std::smatch result;
  regex_search(file, result, author_regex);

  if (result.size() < 2) return "";

  return result[1];
}

void GenerateEntry(const std::string& session_name,
                   const std::string& path) {
  const Directory dir(path);

  std::string readme_md_file;
  std::string presentation_file;
  std::vector<std::string> all_presentation_files, all_other_files;
  std::string author;

  const std::regex presentation_regex("- CppCon 2016\\.[^.]*$");
  const std::regex pdf_regex("\\.pdf$", std::regex_constants::icase);
  const std::regex readme_md_regex("README\\.md$");

  for (const auto& name : dir.Contents()) {
    if (std::regex_search(name, presentation_regex)) {
      // Pick the first file we found, but prefer PDF files if there is one.
      if (presentation_file.empty() || std::regex_search(name, pdf_regex)) {
        presentation_file = name;
        author = Author(name);
      }

      all_presentation_files.push_back(name);
    } else if (std::regex_search(name, readme_md_regex)) {
      readme_md_file = name;
    } else {
      all_other_files.push_back(name);
    }
  }

  std::cout << " - [" << session_name << "]("
            << path + "/" + presentation_file << ") by "
            << author;
  if (all_presentation_files.size() >= 2) {
    for (const auto& file : all_presentation_files) {
      std::string extension = Extension(file);

      std::for_each(extension.begin(), extension.end(),
        [](char& c) { c = std::tolower(c); });
      std::cout << " \\[[." << extension << "](" << path + "/" + file << ")\\]";
    }
  }

  if (!readme_md_file.empty()) {
    std::cout << " \\[[README](" << path << "/" << readme_md_file << ")\\]";
  }

  if (!all_other_files.empty()) {
    std::cout << " \\[[more materials](" << path << ")\\]";
  }

  std::cout << std::endl;
}

void GenerateIndex(const std::string& path) {
  const Directory dir(path);

  std::vector<std::string> contents = dir.Contents();

  // Note this only works reliably for ASCII, but that's enough for our needs.
  auto case_insensitive_lt = [](const std::string& a, const std::string& b){
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
      [](char c, char d){ return std::tolower(c) < std::tolower(d); });
  };
  std::sort(contents.begin(), contents.end(), case_insensitive_lt);
  for (const auto& name : contents) {
    GenerateEntry(name, path + "/" + name);
  }
}

int main(int argc, char** argv) {
  if (argc != 2 || std::string(argv[1]).empty()) {
    std::cerr << "Usage: " << argv[0] << " /path/to/materials\n";
    return 1;
  }

  try {
    std::string path = argv[1];
    path.erase(path.find_last_not_of("/") + 1);  // strip trailing /, if any.
    GenerateIndex(path);
  } catch (const std::exception& e) {
    std::cerr << argv[0] << ": error: " << e.what() << '\n';
    return 1;
  }
}
