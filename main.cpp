#include "Operators.h"
#include "defines.h"
PROGRAM_BEGIN

JSON(emp) = STRING("Hello, world!")
JSON(num) = NUMBER(23.5)
JSON(bol) = BOOLEAN(TRUE)
JSON(ar) = ARRAY [emp, num , STRING("mesaa")]

JSON(t) = ARRAY [ ar , ARRAY [ num ] , ARRAY [ ar , ar]]

JSON(week_temperatures) = ARRAY [
NUMBER(20),NUMBER(19.5),NUMBER(19),NUMBER(20),
NUMBER(19),NUMBER(18.5),NUMBER(19)
]

SET week_temperatures[2] ASSIGN NUMBER(22)

PRINT(emp)
PRINT(num)
PRINT(ar)
PRINT(bol)

PRINT(t)
PRINT(week_temperatures)

PROGRAM_END