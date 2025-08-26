# ft_printf
## ✨ Features
Simplified recreation of the variadic `printf` function. 

Following data types are supported as conversions:

| Conversion			    	| Data type													|
|-------------------|-----------------------|
| `%c`             	| char |
| `%s`           	  | char * |
| `%p`             	| void * |
| `%d`             	| int |
| `%i`             	| int |
| `%u`             	| unsigned int |
| `%x`             	| unsigned int to lower-case Hex |
| `%X`             	| unsigned int to upper-case Hex |
| `%%`             	| '%' character|

> [!TIP]
> ## 🚀 How to use
Run the following commands to clone the repository and create `libftprintf.a` library
``` git
git clone https://github.com/mordori/ft_printf.git ft_printf
cd ft_printf
make
```

To compile and run the tests, use the following command:
``` Makefile
make test
```

To delete all of the compiled files, use
``` Makefile
make fclean
```
