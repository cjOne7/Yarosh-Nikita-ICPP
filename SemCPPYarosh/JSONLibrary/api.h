#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "platform.h"


using namespace std;

// - �ablona s parametrem datov�ho typu ulo�en�ch hodnot
// - nen� povoleno u�it� STL kontejner� ani jin�ch knihoven pro ukl�d�n� dat
// - realizace mus� vyu��vat dynamicky alokovan� pole, spojov� seznam nebo jinou vhodnou V�mi implementovanou ADS

template<typename T>
class DLL_SPEC DynamicArray {
public:
	DynamicArray();

	~DynamicArray();

	// - p�id� element na konec pole
	void append(const T& element);

	// - v�jimky p�i neplatn�m nebo nekorektn�m indexu
	const T& getElementAt(int index) const;

	// - vrac� velikost (po�et prvk�) v poli
	int getSize() const;

	bool isFull() const;

	T remove(int index);

private:
	const int START_SIZE = 5;
	int growingCoefficient = 2;
	int capacity = START_SIZE;
	int size = 0;
	T* array;

	void boostArray();

	void checkSize(int index) const;

};

template<typename T>
bool DynamicArray<T>::isFull() const {
	return size == capacity;
}

template<typename T>
void DynamicArray<T>::checkSize(int index) const {
	if (index < 0 || index >= size) {
		throw out_of_range("ArrayIndexOutOfBoundsException");
	}
}

template<typename T>
inline DynamicArray<T>::DynamicArray() {
	array = new T[START_SIZE];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] array;
}

template<typename T>
void DynamicArray<T>::boostArray() {
	capacity = growingCoefficient * capacity;
	T* newArray = new T[capacity];
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}

template<typename T>
int DynamicArray<T>::getSize() const {
	return size;
}

template<typename T>
void DynamicArray<T>::append(const T& element) {
	if (isFull()) {
		boostArray();
	}
	array[size++] = element;
}

template<typename T>
const T& DynamicArray<T>::getElementAt(int index) const {
	checkSize(index);
	return array[index];
}

template<typename T>
T DynamicArray<T>::remove(int index) {
	T value = array[index];
	int i = 0;
	while (i != size - index - 1) {
		array[index + i] = array[index + i + 1];
		i++;
	}
	size--;
	return value;
}

///////////////////////////////////////////////////////////////////////////////

// JSON hodnota - reprezentuje abstraktn�ho p�edka pro z�kladn� datov� typy v JSON (string, number, object, array, bool, null)
class DLL_SPEC Value {
public:
	virtual ~Value() = default;

	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////


// - definuje p�r kl�� (�et�zec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair  {
private:
	std::string key;
	Value* value;
public:

	KeyValuePair() = default;

	KeyValuePair(std::string key, Value* value);

	// - vr�t� kl��
	std::string getKey() const;

	// - vr�t� hodnotu
	Value* getValue() const;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON null
class DLL_SPEC NullValue : public Value {
public:
	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON bool
class DLL_SPEC BoolValue : public Value {
private:
	bool boolValue;
public:
	BoolValue(bool value);

	// - vrac� bool hodnotu
	bool get() const;

	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON ��slo
class DLL_SPEC NumberValue : public Value {
private:
	double value;
public:
	NumberValue(double value);

	// - vrac� ��selnou hodnotu 
	double get() const;

	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON �et�zec (string)
class DLL_SPEC StringValue : public Value {
private:
	std::string value;
public:
	StringValue(std::string value);

	// - vrac� �et�zcovou hodnotu
	std::string get() const;

	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON pole
class DLL_SPEC ArrayValue : public Value {
public:
	ArrayValue() {
		dynamicArray = new DynamicArray<Value*>();
	}

	~ArrayValue() {
		for (int i = 0; i < dynamicArray->getSize(); ++i) {
			delete dynamicArray->getElementAt(i);
		}
		delete dynamicArray;
	}

	// - p�id� element na konec pole
	void append(Value* element);

	DynamicArray<Value*>* getDynamicArray() const;

	std::string serialize() const override;

private:
	// - atribut DynamicArray<Value*> pro uchov�n� jednotliv�ch element� v poli
	DynamicArray<Value*>* dynamicArray;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class DLL_SPEC ObjectValue : public Value {
public:

	ObjectValue() {
		dynamicObjectArray = new DynamicArray<KeyValuePair>();
	}

	~ObjectValue() {
		for (int i = 0; i < dynamicObjectArray->getSize(); ++i) {
			delete dynamicObjectArray->getElementAt(i).getValue();
		}
		delete dynamicObjectArray;
	}

	// - p�id� kl��-element do objektu
	void append(const KeyValuePair& pair);

	DynamicArray<KeyValuePair>* getDynamicObjectArray() const;

	std::string serialize() const override;

private:
	// - atribut DynamicArray<KeyValuePair> pro uchov�n� jednotliv�ch hodnot a kl��� v objektu
	DynamicArray<KeyValuePair>* dynamicObjectArray;
};

///////////////////////////////////////////////////////////////////////////////

// - t��da pro pr�ci s JSON
class DLL_SPEC JSON {
public:
	// - provede deserializaci �et�zce na vytvo�en� objekty
	// - p�e�tu znak a rozhodnu se
	// -- '{' - za��n�m ��st objekt
	// -------- �tu znaky, pak mus� b�t dvojte�ka, potom vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo '}', podle situace se �ten� opakuje
	// -- '[' - za��n�m ��st pole
	// -------- vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo ']', podle situace se �ten� opakuje
	// -- '"' - za��n�m ��st �et�zec - pozor na escapovan� uvozovky
	// -- [-0123456789] - za��n�m ��st ��slo - na�tu v�echny ��slice (pozor na mo�nou desetinnou te�ku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jin�ho - vyvol�v�m v�jimku
	// - nen� p��pustn� vracet nullptr
	// - deserializace mus� b�t rozumn� implementov�na - nen� p��pustn� zde napsat jednu extr�mn� dlouhou metodu
	static Value* deserialize(const std::string& string);

	// - provede serializaci do JSON �et�zce
	static std::string serialize(const Value* value);

};

///////////////////////////////////////////////////////////////////////////////

