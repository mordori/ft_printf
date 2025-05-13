# ft_printf

> Simplified recreation of the variadic <stdio.h> `printf` function with the following data types as supported conversions: `c s p d i u x X %`.

> [!NOTE]
> This project was developed and compiled using clang on Ubuntu. It will likely work on other Linux distributions and with compatible C/C++ compilers, but clang on Ubuntu is the environment it was originally built and tested in.

> [!TIP]
> ## How to use
 - Create the `libftprintf.a` library in your terminal with the command:
 ``` Makefile
 make
 ```
 - To compile and run the tests, use the following command:
 ``` Makefile
 make test
 ```
 - To delete all of the compiled files, use:
 ``` Makefile
 make fclean
 ```
