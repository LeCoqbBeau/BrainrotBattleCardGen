#!/bin/bash

# Directory to search for files
user_dir="./user"

# Check if the directory exists
if [ ! -d "$user_dir" ]; then
    echo "Directory $user_dir does not exist."
    exit 1
fi

# Go to the user directory
cd "$user_dir" || exit

list=()
last_valid=""

# Find all unique names of files that have both .png and .stat files
for file in *.png; do
    character_name="${file%.png}"  # Get the character name by removing the .png extension

    # Check if there is a corresponding .stat file for this character
    if [ -f "$character_name.stat" ]; then
        # Add the character name to the list array
        list+=("$character_name")
        last_valid="$character_name"
    fi
done

cd .. || exit

make

# Print the list (for debugging purposes)
# echo "${list[@]}"

# Run the CardGen program with the list of character names, ensuring all elements are passed correctly
./CardGen "${list[@]}" > /dev/null

# Open the output for the last processed character
open "output/${last_valid}.png"
