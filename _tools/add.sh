#!/bin/bash -e

if [ -z "$1" ] ; then
    echo "Usage: $0 /path/to/presentation"
    exit 1
fi

if [ ! -e _tools ] ; then
    echo Run this from the CppCon2016 root.
    exit 1
fi

FILE="$1"

SESSION=""
while [[ ! "$SESSION" =~ ^[pkltdo]$ ]]; do
    read -p "[P]resentation, [K]eynote, [T]utorial, [L]ighting/Lunch, [D]emo, P[o]ster? " SESSION
    SESSION=`echo $SESSION | tr '[:upper:]' '[:lower:]'`
done

if [ $SESSION = p ] ; then
    FOLDER="Presentations"
    TYPE="Presentation"
elif [ $SESSION = k ] ; then
    FOLDER="Keynotes"
    TYPE="Keynote"
elif [ $SESSION = l ] ; then
    FOLDER="Lightning Talks and Lunch Sessions"
    TYPE="Lighting Talk and Lunch Session"
elif [ $SESSION = t ] ; then
    FOLDER="Tutorials"
    TYPE="Tutorial"
elif [ $SESSION = d ] ; then
    FOLDER="Demos"
    TYPE="Demo"
elif [ $SESSION = o ] ; then
    FOLDER="Posters"
    TYPE="Poster"
fi

FILENAME=`basename "$FILE"`

TITLE=`echo $FILENAME | sed 's,\(.*\) - \(.*\) - CppCon 2016\.[^.]*$,\1,'`
AUTHOR=`echo $FILENAME | sed 's,\(.*\) - \(.*\) - CppCon 2016\.[^.]*$,\2,'`
EXTENSION=`echo $FILENAME | sed 's,.*\.\([^.]*\)$,\1,'`

echo
echo "Extension is .$EXTENSION"
echo

if [ -z "$TITLE" -o -z "$AUTHOR" ] ; then
    read -p "Title: " TITLE
    read -p "Author: " AUTHOR
fi

OKAY=""
while [[ ! "$OKAY" =~ ^[Yy]$ ]] ; do
    echo "Title: $TITLE"
    echo "Author: $AUTHOR"
    read -p "OK? [y/n]: " OKAY
    if [[ "$OKAY" =~ ^[Nn]$ ]] ; then
        read -p "Title: " TITLE
        read -p "Author: " AUTHOR
    fi

    # TODO: would be nice if this just immediately prompted for the new title/author.
    NEW_FILENAME="$TITLE - $AUTHOR - CppCon 2016.$EXTENSION"
    if [[ "$NEW_FILENAME" =~ [\"*:\<\>?\\/|] ]]; then
        echo "Filename contains invalid characters."
        OKAY=n
    fi
done

mkdir -p "$FOLDER/$TITLE"
mv "$FILE" "$FOLDER/$TITLE/$NEW_FILENAME"
git add "$FOLDER/$TITLE"
_tools/make_README.sh
git add README.md
git commit -v -m "Add $TITLE by $AUTHOR." -e
