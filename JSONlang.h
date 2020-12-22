#ifndef JSONLANG_H
#define JSONLANG_H
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

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
	vector<Variable> list;
public:
	vector <Variable>* array;


	Variable() {
		std::cout << "Called json empty constructor" << std::endl;
		type = UNDEFINED;
		number = NULL;
		word = NULL;
		boolean = NULL;
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

	void pushToList(Variable a) {
		list.push_back(a);
	}

	void clearList() {
		list.clear();
	}

	vector<Variable> *getArray() const {
		return this->array;
	}

	void setArray(vector <Variable>* array)  {
		this->array = array;

	}

	// void setValueArray(int index,JSON value){
	// 	this->array.at(index)= value;
	// }
	
	vector<Variable>::iterator begin() {
		return array->begin();
	}
	vector<Variable>::iterator end() {
		return array->end();
	}

	// void insert_front_bookList(JSON make) {
	// 	list.insert(list.begin(), make);
	// }
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
	String(char* s){
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
    vector<Variable> arr;
    Array()
	{
		std::cout << "Called Array constructor " << std::endl;
		setType(ARRAY);
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


void print(Variable json)
{
	switch(json.getType())
	{
		case 0:{					// NUMBER
			cout << json.getNumber() << endl;
			break;
		}
		case 1:{					//WORD
			cout << json.getWord() << endl;
			break;
		}
		case 2:{					//BOOLEAN
			cout<< ( json.getBool() ? "true" : "false" ) <<endl;
			break;
		}
		case 3:{					//OBJECT

			break;
		}
		case 4:{					//ARRAY
			if(json.array->empty()) 
			{
				cout << "Empty array!" <<endl;
				return;
			}
			string sb = "{";
			for(int i=0; i<json.array->size();i++){
				(*json.array)[i];
			}
			sb+="}";
			break;
		}
		case 5:{					//UNDEFINED
			cout<<"undefined"<<endl;
			break;
		}
		default: {					//DEFAULT 
			cout<<"SHOULD NEVER REACH THIS POINT!!!"<<endl;
			break;
		}
	}

	return;
}

#endif //JSONLANG_H