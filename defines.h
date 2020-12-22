#ifndef DEFINES_H
#define DEFINES_H

#define PROGRAM_BEGIN int main(int argc, char **argv){

#define PROGRAM_END ; return 0; }

#define TRUE true

#define FALSE false

#define JSON(x) Variable(x)

#define NUMBER(x) Number(x);

#define STRING(x) String(x);

#define BOOLEAN(x) Boolean(x);

#define ARRAY (*(new Array()))

#define PRINT(x) ;print(x)

#define AND &&

#define OR ||

#define NOT ~

#define IF if(

#define ELSE_IF ;}else if(

#define DO ){

#define ELSE ;}else{

#define END ;}

#define RETURN return;

#define cout std::cout;

#define endl std::endl;

#endif //DEFINES_H