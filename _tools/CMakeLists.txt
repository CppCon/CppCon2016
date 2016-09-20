project(cppcon2016_speaker_files)
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

add_executable(mkindex mkindex.cpp)
target_compile_features(mkindex PRIVATE cxx_range_for)
