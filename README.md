# `_printf`

A custom implementation of the `printf` function written in C, developed by Ludwig Vandenberghe and Ibrahim Houmaidi as part of a Holberton School project.

---

## Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Usage](#usage)
4. [Examples](#examples)
5. [Files](#files)
6. [Installation](#installation)
7. [Limitations](#limitations)
8. [Authors](#authors)

---

## Overview
`_printf` is a re-implementation of the standard library `printf` function. It provides basic formatted output capabilities by supporting a subset of the standard format specifiers. This project focuses on understanding variadic functions, format string parsing, and output management in C.

---

## Features
- Supports the following format specifiers:
  - `%c` - Print a single character.
  - `%s` - Print a string.
  - `%d` or `%i` - Print an integer.
  - `%%` - Print a literal `%`.

- Mimics the behavior of `printf` by returning the number of characters printed.
- Handles errors gracefully, returning `-1` in cases such as `NULL` format strings.

---

## Usage

### Function Prototype
```c
int _printf(const char *format, ...);
Compilation
Ensure you have all required source files in your working directory, and compile them using gcc:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf

Example Code
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Number: %d\n", 42);
    _printf("Character: %c\n", 'A');
    return (0);
}

Examples :

-Print a string:

_printf("Welcome to %s!\n", "Holberton");
// Output: Welcome to Holberton!

-Print an integer:

_printf("Answer: %d\n", 42);
// Output: Answer: 42

-Print special characters:

_printf("Show %% with _printf\n");
// Output: Show % with _printf

-Print multiple types:

_printf("%c %s %d\n", 'H', "School", 2024);
// Output: H School 2024

Files :

main.h: Header file containing function prototypes and structure definitions.
_printf.c: Main implementation of the _printf function.
character_flags.c: Functions to handle character and string printing.
printing_functions.c: Utility functions for printing numbers and handling characters.
_putchar.c: Function to write a single character to standard output.

Installation :

Clone this repository to your local machine:

git clone git@github.com:LVandenberghe16/holbertonschool-printf.git (ssh-key)

Navigate into the project directory and compile:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf

Limitations :

Unsupported Specifiers:

Floating-point values (%f).
Hexadecimal (%x, %X) and octal (%o) integers.
Width and precision modifiers (e.g., %5d, %.2s).

Performance :

Not as optimized as the standard library implementation.

Memory Management:

Dynamic allocation in _printf introduces potential memory issues.

Authors :

-Ludwig Vandenberghe
-Ibrahim Houmaidi