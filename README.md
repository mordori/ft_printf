# ft_printf

> Simplified recreation of the variadic `printf` function with the following data types as supported conversions:
> 
> `%c (char)`
> `%s (char *)`
> `%p (void *)`
> `%d %i (int) `
> `%u (unsigned int)`
> `%x %X (unsigned int to Hex)`
> `%% ('%')`

> [!NOTE]
> This project was developed and tested using clang on Ubuntu. It will likely work on other Linux distributions and with compatible C/C++ compilers.

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
