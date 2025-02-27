# strjoin_va

A simple C function that joins a variable number of strings into a single dynamically allocated string.

## Features
- Accepts multiple strings as arguments.
- Uses `stdarg.h` to handle a variable number of arguments.
- Dynamically allocates memory for the concatenated result.
- Returns a pointer to the joined string (must be freed by the caller).
- Uses safer implementations of `strlen` (`ft_strlen`) and `strcat` (`ft_strcat`).

## Usage
### Function Prototype
```c
char *strjoin_va(int count, ...);
```

### Example
```c
#include <stdio.h>
#include <stdlib.h>

char *strjoin_va(int count, ...);

int main() {
    char *result = strjoin_va(3, "Hello", " ", "World!");
    if (result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
```

### Implementation
```c
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s) {
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *ft_strcat(char *str, char *add) {
    int start;
    int i;

    if (!str)
        return NULL;
    if (!add)
        return str;
    start = 0;
    while (str[start])
        start++;
    i = 0;
    while (add[i])
        str[start++] = add[i++];
    str[start] = 0;
    return str;
}

char *strjoin_va(int count, ...) {
    char *joined;
    char *str;
    va_list args;
    int i;
    int len;

    if (count < 1)
        return NULL;
    i = count--;
    len = 0;
    va_start(args, count);
    while (i--) {
        str = va_arg(args, char *);
        len += ft_strlen(str);
    }
    va_end(args);
    joined = malloc(len + 1);
    if (!joined)
        return NULL;
    *joined = 0;
    va_start(args, count);
    while (i++ < count)
        ft_strcat(joined, va_arg(args, char *));
    return (va_end(args), joined);
}
```

## Compilation
Compile your program using:
```sh
gcc -o program main.c strjoin_va.c
```

## Notes
- The function dynamically allocates memory, so the caller must `free()` the returned string.
- Ensures safer string operations by using `ft_strlen` and `ft_strcat`.
- Ensure all passed strings are valid (non-null).
- The function does not handle a separator. If needed, you can extend it to support a delimiter.

## License
This project is open-source under the MIT License.

