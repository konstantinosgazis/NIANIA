#include "Operators.h"
#include "defines.h"
PROGRAM_BEGIN

//simple variables declaration
JSON(string1) = STRING("Hello,")
JSON(string2) = STRING(" world!")

PRINT string1 END
PRINT string2 END

JSON(num1) = NUMBER(23.5)
JSON(num2) = NUMBER(23.5)

PRINT num1 END
PRINT num2 END

JSON(bool1) = TRUE
PRINT bool1 END

JSON(bool2) = FALSE
PRINT bool2 END

//empty array declaration
JSON(empty) = ARRAY

//array declarations
JSON(ar) = ARRAY [
    string1, num1 , STRING("mesaa")
]
PRINT ar END

JSON(array1) = ARRAY[
    NUMBER(22), NUMBER(23)
]
PRINT array1 END

JSON(array2) = ARRAY[
    NUMBER(85), NUMBER(62.5)
]
PRINT array2 END

//more complex array declaration
JSON(complexar) = ARRAY [ 
    ar , ARRAY [ num1 ] ,
     ARRAY [ ar , ar]
]
PRINT complexar END

//example with week temperatures
JSON(week_temperatures) = ARRAY [
    NUMBER(20),NUMBER(19.5),NUMBER(19),NUMBER(20),
    NUMBER(19),NUMBER(18.5),NUMBER(19)
]

PRINT week_temperatures END

//set third position of array as value 22
SET week_temperatures[2] ASSIGN NUMBER(22)


SET week_temperatures APPEND string1, string2

ERASE(array1)
PRINT array1 END

//ERASE array1
PRINT array1 END
//print again to see that value has changed
PRINT week_temperatures END

JSON(obj) = OBJECT 
    ("Dijkstra",string1) 
    ("LALALLA", string2)
PRINT obj END

JSON(obj2) = OBJECT 
    ("lala",string1) 
    ("iw", string2)
PRINT obj2 END

// SET obj[1]ASSIGN STRING("csd404@csd.uoc.gr")

//sum of objects, arrays ,strings and numbers
// JSON(sumarr) = array1 + array2
// PRINT(sumarr)

JSON(sumstrings) = string1 + string2
PRINT sumstrings END

JSON(sumnums) = NUMBER(85) + NUMBER(84)
PRINT sumnums END

//check other operators for numbers only
JSON(subnums) = num1 - num2
PRINT subnums END

JSON(mulnums) = num1 * num2
PRINT mulnums END

JSON(divnums) = num1 / num2
PRINT divnums END

JSON(pernums) = num1 % num2
PRINT pernums END

JSON(biggernum) = num1 > num2
JSON(smallernum) = num1 < num2
JSON(smeqnum) = num1 <= num2
JSON(bigeqnum) = num1 >= num2

//check boolean values
JSON(andb) = bool1 && bool2
JSON(orb) = bool1 || bool2

JSON(equalnum) = num1 == num2
PRINT equalnum END
JSON(equalstr) = string1 == string2

PRINT SIZE_OF(string1) END
PRINT IS_EMPTY(array1) END
PRINT TYPE_OF(string1) END
PRINT HAS_KEY(obj,"lala") END


//PRINT(TYPE_OF(emp))

PROGRAM_END