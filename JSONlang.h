#ifndef JSONLANG_H
#define JSONLANG_H
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <cstdarg> //For variaditic functions (Mutiltiple arguments)
#include "boost/variant.hpp"


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

class JSON {
private:
	int number;
	const char* word;
	bool boolean;
	vector<JSON> list;
	vector <JSON> array;
public:


	JSON() {
		std::cout << "Called json empty constructor" << std::endl;
	}

	JSON(int num) {
		std::cout << "Constructor int  called" << std::endl;
		number = num;
		word = NULL;
		boolean = NULL;
	}

	JSON(const char*  w) {
		std::cout << "Called char * constrctor" << std::endl;
		word = w;
		number = NULL;
		boolean = NULL;
	}

	JSON(string a) {
		std::cout << "Called char * constrctor" << std::endl;
		word = a.c_str();
		number = NULL;
		boolean = NULL;
	}

	JSON(bool b) {
		std::cout << "Called boolean constructor" << std::endl;
		boolean = b;
		word = NULL;
		number = NULL;
	}


	void setArray(std::initializer_list<JSON> list) {
		array = list;
	}

	inline int getNumber() const {
		return number;
	}

	inline bool getBool() const {
		return boolean;
	}

	inline const char * getWord() const {
		return word;
	}


	bool operator ==(const JSON& json);

	bool operator !=(const JSON& json);

	bool operator <=(const JSON& json);

	bool operator <(const JSON& json);

	bool operator >(const JSON& json);

	bool operator >=(const JSON& json);

	void pushToList(JSON a) {
		list.push_back(a);
	}

	void clearList() {
		list.clear();
	}

	vector<JSON> getList() const {
		return list;
	}

	vector<JSON>& getArray()  {
		return array;

	}

	void setValueArray(int index,JSON value){
		this->array.at(index)= value;
	}
	
	vector<JSON>::iterator begin() {
		return list.begin();
	}
	vector<JSON>::iterator end() {
		return list.end();
	}

	void insert_front_bookList(JSON make) {
		list.insert(list.begin(), make);
	}


};

JSON operator, (JSON b1, JSON b2);
std::ostream & operator << (std::ostream& stream, const JSON& m);

class OBJECT :public JSON{
	private:
		
	public:


};

class LIST :public JSON {
private:
	//vector<MAKE> list;
public:
	LIST &operator[](JSON make);
};

class SENTENCE :public JSON {
private:
	//vector<MAKE> list;
public:
	template <class T>
	SENTENCE(T t) {
		JSON temp = (JSON)t;
		if (temp.getWord() == NULL) {
			cerr << "No string object to insert" << endl;
			return;
		}
		pushToList(temp);
	}
	template <class T, class... T2>
	SENTENCE(T t, T2... rest):SENTENCE(rest...)
	{
		JSON temp = (JSON)t;
		if (temp.getWord() == NULL) {
			cerr << "No string object to insert" << endl;
			return;
		}
		insert_front_bookList(temp);
	}
};


class ARRAY :public JSON {
private:
	
public:
	ARRAY(std::initializer_list<JSON> list) {
		setArray(list);
	}
};

void print(JSON json)
{
    const char* word = json.getWord();
	if (word != NULL) {
		cout << word << endl;
	}
	else {
		std::cerr << "You can only draw const char *" << endl;
		return ;
	}

	return;
}

#endif //JSONLANG_H