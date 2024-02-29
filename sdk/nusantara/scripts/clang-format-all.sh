#!/bin/bash

# clang-format-all: a tool to run clang-format on an entire project
# Copyright (C) 2016 Evan Klitzke <evan@eklitzke.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Modify by Fern Aerell with CHAT-GPT

function usage {
    echo "Usage: $0 [-v|--verbose] DIR..."
    exit 1
}

VERBOSE=false

while [[ $# -gt 0 ]]; do
    case "$1" in
        -v|--verbose)
            VERBOSE=true
            shift
            ;;
        *)
            break
            ;;
    esac
done

if [ $# -eq 0 ]; then
    usage
fi

# Function to log verbose messages
log_verbose() {
    if [ "$VERBOSE" = true ]; then
        echo "$1"
    fi
}

# Variable that will hold the name of the clang-format command
FMT=""

# Some distros just call it clang-format. Others (e.g. Ubuntu) are insistent
# that the version number be part of the command. We prefer clang-format if
# that's present, otherwise we work backwards from highest version to lowest
# version.
for clangfmt in clang-format{,-{4,3}.{9,8,7,6,5,4,3,2,1,0}}; do
    if which "$clangfmt" &>/dev/null; then
        FMT="$clangfmt"
        break
    fi
done

# Check if we found a working clang-format
if [ -z "$FMT" ]; then
    echo "failed to find clang-format"
    exit 1
fi

# Check all of the arguments first to make sure they're all directories
for dir in "$@"; do
    if [ ! -d "${dir}" ]; then
        echo "${dir} is not a directory"
        usage
    fi
done

# Find a dominating file, starting from a given directory and going up.
find-dominating-file() {
    if [ -r "$1"/"$2" ]; then
        return 0
    fi
    if [ "$1" = "/" ]; then
        return 1
    fi
    find-dominating-file "$(realpath "$1"/..)" "$2"
    return $?
}

# Run clang-format -i on all of the things
for dir in "$@"; do
    pushd "${dir}" &>/dev/null
    if ! find-dominating-file . .clang-format; then
        echo "Failed to find dominating .clang-format starting at $PWD"
        popd &>/dev/null
        continue
    fi
    log_verbose "Running clang-format -i on files in directory: $PWD"
    find . \
         \( -name '*.c' \
         -o -name '*.cc' \
         -o -name '*.cpp' \
         -o -name '*.h' \
         -o -name '*.hh' \
         -o -name '*.hpp' \) \
         -exec sh -c 'echo "Formatting: $1"; "$0" -i "$1"' "$FMT" {} \;
    popd &>/dev/null
done