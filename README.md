# strjoin_va

A simple C function that joins a variable number of strings into a single dynamically allocated string.

## Features
- Accepts multiple strings as arguments.
- Uses `stdarg.h` to handle a variable number of arguments.
- Dynamically allocates memory for the concatenated result.
- Returns a pointer to the joined string (must be freed by the caller).

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
#include <string.h>

char *strjoin_va(int count, ...) {
    if (count < 1)
        return NULL;

    va_list args;
    va_start(args, count);

    int total_length = 0;
    for (int i = 0; i < count; i++) {
        char *str = va_arg(args, char *);
        total_length += strlen(str);
    }
    va_end(args);

    char *result = malloc(total_length + 1);
    if (!result)
        return NULL;
    result[0] = '\0';

    va_start(args, count);
    for (int i = 0; i < count; i++) {
        strcat(result, va_arg(args, char *));
    }
    va_end(args);

    return result;
}
```

## Compilation
Compile your program using:
```sh
gcc -o program main.c strjoin_va.c
```

## Notes
- The function dynamically allocates memory, so the caller must `free()` the returned string.
- Ensure all passed strings are valid (non-null).
- The function does not handle a separator. If needed, you can extend it to support a delimiter.

## License
This project is open-source under the MIT License.

