#include "Operators.h"
#include "defines.h"
PROGRAM_BEGIN

JSON(emp) = STRING("Hello, world!\n")
JSON(num) = NUMBER(23.5)
JSON(bol) = BOOLEAN(TRUE)
JSON(ar) = ARRAY [emp, num]

PRINT(emp)
PRINT(num)
PRINT(ar)
PRINT(bol)

PROGRAM_END