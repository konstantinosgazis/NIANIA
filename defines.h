#ifndef DEFINES_H
#define DEFINES_H

#define PROGRAM_BEGIN int main(int argc, char **argv){

#define PROGRAM_END ; return 0; }

#define NUMBER(x) JSON(x);

#define STRING(x) JSON(x);

#define BOOLEAN(x) JSON(x);

#define PRINT(x) print(x);

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