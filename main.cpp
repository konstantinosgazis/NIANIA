#include "Operators.h"
#include "defines.h"
PROGRAM_BEGIN

JSON(emp) = STRING("Hello, world!")
JSON(num1) = NUMBER(23.5)
JSON(num2) = NUMBER(16.5)
JSON(bol) = BOOLEAN(TRUE)
JSON(ar) = ARRAY [emp, num1 , STRING("mesaa")]

JSON(t) = ARRAY [ ar , ARRAY [ num1 ] , ARRAY [ ar , ar]]

JSON(week_temperatures) = ARRAY [
NUMBER(20),NUMBER(19.5),NUMBER(19),NUMBER(20),
NUMBER(19),NUMBER(18.5),NUMBER(19)
]

JSON(sum) = num1 && bol

SET week_temperatures[2] ASSIGN NUMBER(22)

PRINT(emp)
PRINT(num1)
PRINT(ar)
PRINT(bol)
PRINT(sum)

PRINT(t)
PRINT(week_temperatures)

PROGRAM_END