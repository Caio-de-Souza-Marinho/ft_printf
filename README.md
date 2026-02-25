# ft_printf

*This project has been created as part of the 42 curriculum by caide-so.*

## Description

This project consists of reimplementing the `printf()` function from the C standard library.

This README focuses exclusively on the **bonus part**, which extends the mandatory implementation by handling:

- Field minimum width
- Flags: `-`, `0`, `.`, `#`, ` ` (space), `+`
- Any valid combination of these flags
- All mandatory conversions (`cspdiuxX%`) with full flag interaction

The bonus part is evaluated **only if the mandatory part is perfect**.

---

## Features Implemented

### Supported Flags

| Flag | Behavior |
|------|----------|
| `-`  | Left-align within the given field width |
| `0`  | Zero-padding (ignored if `-` is present or precision is set) |
| `.`  | Precision handling (numbers and strings) |
| `#`  | Alternate form (`0x`, `0X`, `0`) |
| ` `  | Space prefix for positive numbers |
| `+`  | Explicit sign for positive numbers |

---

## Field Minimum Width

- Pads output to match a specified minimum width.
- Padding can be spaces or zeroes depending on flags.
- Correct interaction with precision and alignment.

---

## Parsing Strategy

The bonus implementation relies on a format state structure storing:

- Flags
- Width
- Precision
- Conversion type

Conceptual structure:

    typedef struct s_format
    {
        int minus;
        int zero;
        int dot;
        int hash;
        int space;
        int plus;
        int width;
        int precision;
        char type;
    }   t_format;

---

## Algorithm Explanation

### Format Parsing

When encountering `%`, the parser:

1. Initializes a format structure.
2. Parses flags.
3. Parses width.
4. Parses precision.
5. Stores conversion type.
6. Dispatches to the correct handler.

### Formatting Order (Numbers)

1. Determine sign or prefix.
2. Apply precision.
3. Compute final length.
4. Apply width padding.
5. Apply alignment if needed.

### Flag Interaction Rules

- `-` overrides `0`
- Precision disables `0` for numeric conversions
- `+` overrides space
- `#` applies only for non-zero hexadecimal values
- Precision `0` with value `0` prints nothing (except width padding)

---

## Data Structure Justification

The structured parsing approach:

- Separates parsing from printing
- Prevents duplicated logic
- Keeps the implementation extensible
- Avoids complex nested conditionals

---

## Compilation

    make bonus

Rules:

    make
    make bonus
    make clean
    make fclean
    make re

Compiled with:

    -Wall -Wextra -Werror

Library generated:

    libftprintf.a

---

## Testing Philosophy

Tested against the original `printf()` with:

- Complex flag combinations
- Width and precision edge cases
- Zero and NULL behavior
- Alignment interactions

Goal: strict behavior equivalence.

---

## Resources

- https://man7.org/linux/man-pages/man3/printf.3.html
- https://en.cppreference.com/w/c/io/fprintf
- ISO C99 Standard — Formatted Output
- Variadic Functions — `stdarg.h` documentation

### AI Usage Disclosure

AI was used only for documentation clarification and validation of edge-case behavior.

---

## Author

**caide-so** — caide-so@student.42sp.org.br
