#include "JSONlang.h"

bool operator== (Variable left , Variable right)    
{
    return -1;
}
bool operator!= (Variable left , Variable right)    
{
    return -1;
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
    if(left.getType() != NUMBER || right.getType() != NUMBER)
    {
        cout << "Task failed succesfully! Must add only numbers!" << endl;
        exit(0);
    }
    return *(new Number(right.getNumber() + left.getNumber()));
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