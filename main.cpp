#include "Operators.h"
#include "defines.h"
PROGRAM_BEGIN

JSON(emp) = STRING("Hello, world!")
JSON(emp1) = STRING(" NIANIA")
JSON(num1) = NUMBER(23.5)
JSON(num2) = NUMBER(16.5)
JSON(bol) = BOOLEAN(TRUE)
JSON(ar) = ARRAY [emp, num1 , STRING("mesaa")]
JSON(array1) = ARRAY[NUMBER(22), NUMBER(23)]
JSON(array2) = ARRAY[NUMBER(22), NUMBER(23)]

JSON(t) = ARRAY [ ar , ARRAY [ num1 ] , ARRAY [ ar , ar]]

JSON(empty) = ARRAY

JSON(week_temperatures) = ARRAY [
NUMBER(20),NUMBER(19.5),NUMBER(19),NUMBER(20),
NUMBER(19),NUMBER(18.5),NUMBER(19)
]

JSON(sum) = array1 + array2
JSON(sum1) = emp + emp1

SET week_temperatures[2] ASSIGN NUMBER(22)

SIZE_OF(emp)
//IS_EMPTY(empty)
TYPE_OF(emp)

PRINT(emp)
PRINT(num1)
PRINT(ar)
PRINT(bol)
PRINT(sum)
PRINT(sum1)

PROGRAM_END