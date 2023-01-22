# Printf

## 42 Cursus Project Introduction

The versatility of the printf function in the C language gives us a huge workout for programming. This project is of medium difficulty. It will enable you to discover variable functions in C language.
Well-structured and easily extensible code is the secret to a successful ft_printf function.

## Subject

Write a lib with ft_printf function that will mimic the real printf

### Allow Function

```c
malloc(), free(), write(), va_start(), va_arg(), va_copy(), va_end()
```

### Mandatory part

> <i> Rules:
>
> - prototype of ft_printf function int ft_printf(const char *, ...); should be in the form.
> - You have to rewrite the printf function in the libc library.
> - The function you will write should not do buffer management like real printf.
> - Your function should convert: cspdiuxX%
>
> <i> Brief descriptions of the required conversions:
>
> - `%c` print a single character.
> - `%s` print a string of characters.
> - `%p` The void * pointer argument is printed in hexadecimal.
> - `%d` print a decimal (base 10) number.
> - `%i` print an integer in base 10.
> - `%u` print an unsigned decimal (base 10) number.
> - `%x` print a number in hexadecimal (base 16).
> - `%%` print a percent sign.

## Usage

You can try our project with the following commands:

First, clone the repository

```sh
git clone https://github.com/zeynepssasmaz/printf.git
cd printf
make
(u need write main and )gcc printf.c libftprintf.a
(and you get the result)./a.out
```
