#include "JSONlang.h"
#include <cstring>

bool operator== (Variable left , Variable right)    
{
    if(left.getType() != right.getType())
    {
        cout << "Task failed succesfully! Cannot set equal two differrent variables!" << endl;
        exit(0);
    }
    switch(left.getType())
    {
        case 0://NUMBER
            return left.getNumber() == right.getNumber();
        case 1://STRING
            return left.getWord() == right.getWord();
        case 2://BOOLEAN
            return left.getBool() == right.getBool();
        case 3://OBJECT
            return false;
        case 4://ARRAY
            return cmp(left.getArray(), right.getArray());
        case 5://UNDEFINED
            return false;
        default:{//DEFAULT
            cout << "SHOULD NEVER REACH THIS POINT!" <<endl;
            return false;
        }
    }
}
bool operator!= (Variable left , Variable right)    
{
    if(left.getType() != right.getType())
    {
        cout << "Task failed succesfully! Cannot set not equal two differrent variables!" << endl;
        exit(0);
    }
    switch(left.getType())
    {
        case 0://NUMBER
            return !(left.getNumber() == right.getNumber());
        case 1://STRING
            return !(left.getWord() == right.getWord());
        case 2://BOOLEAN
            return !(left.getBool() == right.getBool());
        case 3://OBJECT
            return false;
        case 4://ARRAY
            return false;
        case 5://UNDEFINED
            return false;
        default:{//DEFAULT
            cout << "SHOULD NEVER REACH THIS POINT!" <<endl;
            return false;
        }
    }
}

Variable operator&& (Variable left, Variable right)
{
    if(left.getType() != BOOLEAN || right.getType() != BOOLEAN)
    {
        cout << "Task failed succesfully! Must AND only booleans!" << endl;
        exit(0);
    }
    return *(new Boolean(left.getBool() && right.getBool()));
}

Variable operator|| (Variable left, Variable right)
{
    if(left.getType() != BOOLEAN || right.getType() != BOOLEAN)
    {
        cout << "Task failed succesfully! Must OR only booleans!" << endl;
        exit(0);
    }
    return *(new Boolean(left.getBool() || right.getBool()));
}


Variable operator<  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (<) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() < left.getNumber()));
}
Variable operator>  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (>) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() > left.getNumber()));
}
Variable operator<= (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (<=) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() <= left.getNumber()));
}
Variable operator>= (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (>=) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() >= left.getNumber()));
}

Variable operator+  (Variable left , Variable right)    
{
    if(left.getType() == WORD && right.getType() == WORD)
    {
        const char* p = new char [strlen(left.getWord())+strlen(right.getWord())+1];
        const char* s = new char [strlen(left.getWord())+strlen(right.getWord())+1];
        strcat(const_cast<char*>(p),left.getWord());
        strcat(const_cast<char*>(p),right.getWord());
        strcpy(const_cast<char*>(s),p);
        return *(new String(p));
    }
    else if(left.getType() == NUMBER && right.getType() == NUMBER)
    {
        return *(new Number(left.getNumber() + right.getNumber()));
    }
    else if(left.getType() == ARRAY && right.getType() == ARRAY)
    {
        vector <Variable>* newarray = new vector<Variable>();
        newarray->reserve(left.getArray()->size() + right.getArray()->size());
        newarray->insert( newarray->end(), left.getArray()->begin(), left.getArray()->end() );
        newarray->insert( newarray->end(), right.getArray()->begin(), right.getArray()->end() );
        return newarray;
    }
    cout << "Task failed succesfully! Must add only numbers, strings, arrays or objects!" << endl;
    exit(0);
}

Variable operator-  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must subtract only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() - left.getNumber()));
}

Variable operator*  (Variable left , Variable right)    
{
   if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must multiply only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() * left.getNumber()));
}

Variable operator/  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must div only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() / left.getNumber()));
}

Variable operator%  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must module only numbers!" << endl;
        exit(0);
    }
    return *(new Number(static_cast<int>(right.getNumber()) % static_cast<int>(left.getNumber())));
}


Variable operator+  (Variable left , int  right)    
{
    if(left.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must add only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber())) + right;
}
Variable operator-  (Variable left , int  right)    
{
    if(left.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must subtract only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber())) - right;
}
Variable operator*  (Variable left , int  right)    
{
    if(left.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must multiply only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber())) * right;
}
Variable operator/  (Variable left , int  right)    
{
    if(left.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must div only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber())) / right;
}
Variable operator%  (Variable left , int  right)    
{
    if(left.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must subtract only numbers!" << endl;
        exit(0);
    }
    return *(new Number(static_cast<int>(left.getNumber()))) % right;
}

vector<Variable>* operator,(Variable a, Variable b){
    vector<Variable>* v = new vector<Variable>();
    v->push_back(a);
    v->push_back(b);
    return v;
}
vector<Variable>* operator,(vector<Variable>* a, Variable b){
    a->push_back(b);
    return a;
}