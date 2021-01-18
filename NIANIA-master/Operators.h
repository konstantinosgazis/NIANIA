#include "JSONlang.h"
#include <cstring>

template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    return (v1.size() == v2.size() &&
            std::equal(v1.begin(), v1.end(), v2.begin()));
}

Variable operator== (Variable left , Variable right)    
{
    if(left.getType() != right.getType())
    {
        cout << "Task failed succesfully! Cannot set equal two differrent variables!" << endl;
        exit(0);
    }
    switch(left.getType())
    {
        case 0://NUMBER
            return *(new Number(left.getNumber() == right.getNumber()));
        case 1://STRING
            return *(new String(left.getWord()));
        case 2://BOOLEAN
            return *(new Boolean(left.getBool() == right.getBool()));
        case 3://OBJECT
            return *(new Number(left.getNumber() == right.getNumber()));
        case 4://ARRAY
            return *(new Number(left.getNumber() == right.getNumber()));
        case 5://UNDEFINED
            return *(new Number(left.getNumber() == right.getNumber()));
        default:{//DEFAULT
            cout << "SHOULD NEVER REACH THIS POINT!" <<endl;
            return *(new Number(left.getNumber() == right.getNumber()));
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
    return *(new Number(left.getNumber() < right.getNumber()));
}
Variable operator>  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (>) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber() > right.getNumber()));
}
Variable operator<= (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (<=) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber() <= right.getNumber()));
}
Variable operator>= (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must compare (>=) only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber() >= right.getNumber()));
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
        vector <Variable> newarray;
        newarray.reserve(left.getArray().size() + right.getArray().size());
        newarray.insert( newarray.end(), left.getArray().begin(), left.getArray().end() );
        newarray.insert( newarray.end(), right.getArray().begin(), right.getArray().end() );
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
    return *(new Number(left.getNumber() - right.getNumber()));
}

Variable operator*  (Variable left , Variable right)    
{
   if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must multiply only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber() * right.getNumber()));
}

Variable operator/  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must div only numbers!" << endl;
        exit(0);
    }
    return *(new Number(left.getNumber() / right.getNumber()));
}

Variable operator%  (Variable left , Variable right)    
{
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must module only numbers!" << endl;
        exit(0);
    }
    return *(new Number(static_cast<int>(left.getNumber()) % static_cast<int>(right.getNumber())));
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

vector<Variable> operator,(Variable a, Variable b){
    vector<Variable> v;
    v.push_back(a);
    v.push_back(b);
    return v;
}
vector<Variable> operator,(vector<Variable> a, Variable b){
    a.push_back(b);
    return a;
}

Variable Sizeof(Variable var)
{
    if(var.getType() == ARRAY) 
    {
        cout<< "Sizeof: " << var.getArray().size() << endl;
        return *(new Number(var.getArray().size()));
    }
        
    else if(var.getType() == OBJECT)
    {
        return *(new Number(0));
    } 
    cout << "Sizeof: " << 1 << endl;
    return *(new Number(1));
}

Variable IsEmpty(Variable var)
{
    if(var.getType() == ARRAY && var.getArray().empty())
    {
        cout << "Empty Array" << endl;
        return *(new Boolean(true));
    } 
    if(var.getType() == ARRAY && !var.getArray().empty())
    {
        cout << "Array not empty" << endl;
        return *(new Boolean(false));
    } 
    else if(var.getType() == OBJECT){
        return *(new Boolean(true));
    }
    return *(new Boolean(false));
}

Variable HasKey(Variable var, string key)
{
    if(var.getType() == OBJECT)
    {
        if(var.getObj().find(key) == var.getObj().end())
        {
            return (*(new Boolean(false)));
        }
    }
    return *(new Boolean(true));
}

Variable TypeOf(Variable var)
{
    switch(var.getType())
    {
        case 0:
            cout << "Number" << endl;
            return *(new String("Number"));
        case 1:
            cout << "String" << endl;
            return *(new String("String"));
        case 2:
            cout << "Boolean" << endl;
            return *(new String("Boolean"));
        case 3:
            cout << "Object" << endl;
            return *(new String("Object"));
        case 4:
            cout << "Array" << endl;
            return *(new String("Array"));
        case 5:
            cout << "Undefined" << endl;  
            return *(new String("Undefined"));
        default:
            return *(new String("Should never reach this point!"));
    }
}