# ft_printf

> Recreation of the C standard library printf function

## About

**ft_printf** is a 42 school project that recreates the `printf()` function from the C standard library. This project teaches variadic functions, string parsing, and type conversions.

**Prototype:** `int ft_printf(const char *format, ...);`

**Return value:** Total number of characters printed

---

## Installation

```bash
git clone https://github.com/your-username/ft_printf.git
cd ft_printf
make
```

**Make commands:**
- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove all generated files
- `make re` - Recompile from scratch

---

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

**Compile your program:**
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```

---

## Supported Conversions

| Format | Description | Example |
|--------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5c` |
| `%d` | Signed decimal integer | `ft_printf("%d", 42)` → `42` |
| `%i` | Signed decimal integer | `ft_printf("%i", -42)` → `-42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42)` → `42` |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%%` | Percent sign | `ft_printf("%%")` → `%` |

**Special cases handled:**
- `%s` with NULL → prints `(null)`
- `%p` with NULL → prints `(nil)` or `0x0`
- `%d` with INT_MIN → `-2147483648`

---

## Project Structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c          # Main function
├── ft_conversion.c      # Conversion handling
├── ft_putchar.c         # Print character
├── ft_putstr.c          # Print string
├── ft_putnbr.c          # Print signed integer
├── ft_putnbr_unsigned.c # Print unsigned integer
├── ft_puthex_lower.c    # Print hex (lowercase)
├── ft_puthex_upper.c    # Print hex (uppercase)
├── ft_putptr.c          # Print pointer
└── libft/               # Your libft library
```

---

## Testing

**Manual test:**
```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;
    
    ret1 = ft_printf("ft: %s %d\n", "test", 42);
    ret2 = printf("or: %s %d\n", "test", 42);
    printf("Returns: %d vs %d\n", ret1, ret2);
    
    return (0);
}
```
---

## Key Concepts

- **Variadic functions:** `va_start`, `va_arg`, `va_end` from `<stdarg.h>`
- **Type conversions:** Converting integers to strings, hexadecimal, etc.
- **String parsing:** Analyzing format specifiers in the input string
- **Character counting:** Tracking total output length

---

## Resources

- [man printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic)
- [Variadic functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)

---

**Made at 42 Luxembourg** | *January 2025*