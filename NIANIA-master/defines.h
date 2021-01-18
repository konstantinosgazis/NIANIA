#ifndef DEFINES_H
#define DEFINES_H

#define PROGRAM_BEGIN int main(int argc, char **argv){

#define PROGRAM_END ; return 0; }

#define TRUE BOOLEAN(1)

#define FALSE BOOLEAN(0)

#define JSON ;Variable

#define NUMBER Number

#define STRING String

#define BOOLEAN Boolean

#define ARRAY (*(new Array()))

#define PRINT ;print(

#define  END );

#define RETURN return;

#define SET ;

#define ASSIGN =

#define OBJECT Object<string, Variable >

#define KEY(name) Key(name) , 0?-1 

#define APPEND .array+=

#define ERASE(x) ;x.array.clear()

#define SIZE_OF(x) Sizeof(x)

#define IS_EMPTY(x) IsEmpty(x)

#define TYPE_OF(x) TypeOf(x)

#define HAS_KEY(...) HasKey(__VA_ARGS__)

#endif //DEFINES_H