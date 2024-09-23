#!/bin/bash

# Directory to search for files
user_dir="./user"

# Check if the directory exists
if [ ! -d "$user_dir" ]; then
    echo "Directory $user_dir does not exist."
    exit 1
fi

# Go to the user directory
cd "$user_dir"

list=""

# Find all unique names of files that have both .png and .stat files
for file in *.png; do
    character_name="${file%.png}"  # Get the character name by removing the .png extension

    # Check if there is a corresponding .stat file for this character
    if [ -f "$character_name.stat" ]; then
        list+=" \"$character_name\""
    fi
done

cd ..

make

echo $list

./CardGen $list > /dev/null

open "output/$character_name.png"
