# Printf Project Manual

## Overview

This manual provides detailed information about the custom implementation of the `printf` function within this repository. The `_printf` function is a critical element in C programming, and this manual aims to guide users through its features, usage, and compilation.

## Project Description

### _printf Function

`_printf` is a versatile function designed to handle various format specifiers, providing a wide range of formatting capabilities from basic to advanced. Its primary objective is to emulate the standard `printf` function with additional functionalities.

#### Features

- **Basic Format Specifiers**: Handles characters (`c`), strings (`s`), and the percent sign (`%`).
- **Integer Handling**: Includes support for integer specifiers (`d`, `i`).
- **Advanced Specifiers**: The implementation extends to more complex specifiers, detailed in the project tasks.
- **Compliance**: Adheres to the Betty coding and documentation styles for C programming.

## Requirements

Before using the `_printf` function, ensure that your code meets the following requirements:

- Compiled on Ubuntu 20.04 LTS using `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow the Betty style guide.
- Restrictions include no global variables and a maximum of 5 functions per file.
- Function prototypes must be declared in the header file `main.h`.

## Compilation

To compile your code, use the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```


## Usage

To use the `_printf` function in your C program:

1. Include the `main.h` header file:

   ```c
   #include "main.h"
   ```
2. Call the `_printf` function similarly to the standard `printf`. For example:

   ```c
   _printf("Hello, %s!\n", "World");
   ```

## Acknowledgements

This project is part of the curriculum at [ALX SE]. The `_printf` function draws inspiration from the C standard library's `printf` function.

For additional details, refer to the source code and documentation within this repository.

```

Feel free to adjust and customize the manual according to your specific needs and project details.
```


## Developeres

- [@Ahmed Ramzy](https://www.github.com/RamzyAR7)
- [@Ashraf Atef](https://www.github.com/Ashraf-Atef1)
