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

char	*strjoin_va(int count, ...)
{
	char	*joined;
	char	*str;
	va_list	args;
	int		i;
	int		len;

	if (count < 1)
		return (NULL);
	i = count--;
	len = 0;
	va_start(args, count);
	while (i--)
	{
		str = va_arg(args, char *);
		len += strlen(str);
	}
	va_end(args);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	*joined = 0;
	va_start(args, count);
	while (i++ < count)
		strcat(joined, va_arg(args, char*));
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
- Ensure all passed strings are valid (non-null).
- The function does not handle a separator. If needed, you can extend it to support a delimiter.

## License
This project is open-source under the MIT License.

