# gwc - Word Count (wc) Clone

## Overview

This program is a simple clone of the Unix `wc` command, designed to provide basic word, line, and character counting functionality in text files or standard input.

## Features

- Count characters, words, and lines in a text file.
  - `-f` to specify a filename
- Optionally, read input from standard input (stdin) instead of a file.
- Command-line switches to select specific counts:
  - `-c` to count characters.
  - `-w` to count words.
  - `-l` to count lines.

## Requirements

- GCC compiler (or any standard C compiler)
- Make (for using the provided Makefile)

## Installation

1. Clone the repository or download the source code.
2. Navigate to the directory containing the source code.

## Compilation

Run the following command in the terminal:

```bash
# This will create an executable named gwc.
$ make
```

## Usage

To use the program, you can either specify a file name or use standard input. Here are some examples:

Count words, lines, and characters in a file:

```bash
$ ./gwc -f filename.txt

# optionally with combined flags
$ ./gwc -cwl -f filename.txt
```

Count lines from piped input:

```bash
$ cat filename.txt | ./gwc
```

## Cleaning Up

To remove the compiled files, run:

```bash
$ make clean
```
