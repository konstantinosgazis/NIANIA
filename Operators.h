#include "JSONlang.h"
bool operator== (Variable left , Variable right)    {return -1;}
bool operator!= (Variable left , Variable right)    {return -1;}
bool operator<  (Variable left , Variable right)    {return -1;}
bool operator>  (Variable left , Variable right)    {return -1;}
bool operator<= (Variable left , Variable right)    {return -1;}
bool operator>= (Variable left , Variable right)    {return -1;}
// Variable operator+  (Variable left , Variable right)    {return;}
// Variable operator-  (Variable left , Variable right)    {return;}
// Variable operator*  (Variable left , Variable right)    {return;}
// Variable operator/  (Variable left , Variable right)    {return;}
// Variable operator%  (Variable left , Variable right)    {return;}
bool operator== (Variable left , int  right)    {return -1;}
bool operator!= (Variable left , int  right)    {return -1;}
bool operator<  (Variable left , int  right)    {return -1;}
bool operator>  (Variable left , int  right)    {return -1;}
bool operator<= (Variable left , int  right)    {return -1;}
bool operator>= (Variable left , int  right)    {return -1;}
// Variable operator+  (Variable left , int  right)    {return;}
// Variable operator-  (Variable left , int  right)    {return;}
// Variable operator*  (Variable left , int  right)    {return;}
// Variable operator/  (Variable left , int  right)    {return;}
// Variable operator%  (Variable left , int  right)    {return;}
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