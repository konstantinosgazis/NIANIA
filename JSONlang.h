#ifndef JSONLANG_H
#define JSONLANG_H
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using namespace std;

enum Type{
	NUMBER,
	WORD,
	BOOLEAN,
	OBJECT,
	ARRAY,
	UNDEFINED
};

class Variable {
protected:
	Type type;
	double number;
	const char* word;
	bool boolean;
	vector <Variable>* array;
public:


	Variable() {
		type = UNDEFINED;
		number = 0;
		word = NULL;
		boolean = NULL;
	}
    Variable(vector<Variable>* v){
        this->array = new vector<Variable>();
        this->type = ARRAY;
        for(auto i : *v){
            (this->array)->push_back(i);
        }
    }

	void setType(Type t){
		this->type = t;
	}

	inline Type getType(){
		return type;
	}
	
	inline double getNumber() const {
		return number;
	}

	inline bool getBool() const {
		return boolean;
	}

	inline const char * getWord() const {
		return word;
	}

	vector<Variable> *getArray() const {
		return this->array;
	}

	void setArray(vector <Variable>* array)  {
		this->array = array;

	}

	auto begin() {
		return array->begin();
	}
	auto end() {
		return array->end();
	}
	Variable& operator[] (size_t index){
		return this->array->at(index);
	}

	Variable operator[] (size_t index) const{
		return   (*const_cast<Variable*>(this))[index] ;
	}

	

};

class Number : public Variable {
	private:
	public:
	Number(double n){
		std::cout << "Called int constructor " << std::endl;
		setType(NUMBER);
		number = n;
	}
};


class String : public Variable {
	private:
	public:
	String(const char* s){
		std::cout << "Called string constructor " << std::endl;
		setType(WORD);
		word = s;
	}
};

class Boolean : public Variable {
	private:
	public:
	Boolean(bool b){
		std::cout << "Called boolean constructor " << std::endl;
		setType(BOOLEAN);
		boolean = b;
	}
};

class Array: public Variable{
	public:
    Array()
	{
		std::cout << "Called Array constructor " << std::endl;
		setType(ARRAY);
	}
    Array(vector<Variable>* v){
        setType(ARRAY);
        setArray(v);
    }
    Array operator[](vector<Variable>* v){
        setType(ARRAY);
        setArray(v);
        return *this;
    }
    Array operator[](Variable h){
        vector<Variable>* v = new vector<Variable>();
        v->push_back(h);
        setType(ARRAY);
        setArray(v);
        return *this;
    }
};

string toString(Variable json)
{
	switch(json.getType()){
		case 0:{
			return to_string(json.getNumber());
		}
		case 1:{
			return json.getWord();
		}
		case 2:{
			return ( json.getBool() ? "true" : "false" );
		}
		case 3:{
			return "OBJECT";
		}
		case 4:{
			string sb = "[ ";
			for(int i=0; i<json.getArray()->size();i++){
				sb += toString( json.getArray()->at(i) ) +" ";
			}
			sb+="]";
			return sb;
		}
		case 5:{
			return "Undefined";
		}
		default:
			return "SHOULD NEVER REACH THIS POINT!!!";
	}
}
void print(Variable json){
	cout << toString(json) << endl;
}

#endif //JSONLANG_H