#pragma once

#include <string>

using namespace std;
// - �ablona s parametrem datov�ho typu ulo�en�ch hodnot
// - nen� povoleno u�it� STL kontejner� ani jin�ch knihoven pro ukl�d�n� dat
// - realizace mus� vyu��vat dynamicky alokovan� pole, spojov� seznam nebo jinou vhodnou V�mi implementovanou ADS 
template<typename T>
class DynamicArray {
public:
	DynamicArray();

	~DynamicArray();

	// - p�id� element na konec pole
	void append(const T &element);

	// - v�jimky p�i neplatn�m nebo nekorektn�m indexu
	const T &getElementAt(int index) const;

	// - vrac� velikost (po�et prvk�) v poli
	int getSize() const;
};


///////////////////////////////////////////////////////////////////////////////

// JSON hodnota - reprezentuje abstraktn�ho p�edka pro z�kladn� datov� typy v JSON (string, number, object, array, bool, null)
class Value {
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////


// - definuje p�r kl�� (�et�zec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class KeyValuePair {
public:
	KeyValuePair(string key, Value *value);

	// - vr�t� kl��
	std::string getKey() const;

	// - vr�t� hodnotu
	Value *getValue() const;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON null
class NullValue : public Value {
public:
	string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON bool
class BoolValue : public Value {
private:
	bool boolValue;
public:
	BoolValue(bool value);

	// - vrac� bool hodnotu
	bool get() const;

	string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON ��slo
class NumberValue : public Value {
private:
	double value;
public:
	NumberValue(double value);

	// - vrac� ��selnou hodnotu 
	double get() const;

	string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON �et�zec (string)
class StringValue : public Value {
private:
	string value;
public:
	StringValue(string value);

	// - vrac� �et�zcovou hodnotu
	string get() const;

	string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON pole
class ArrayValue : public Value {
public:
	ArrayValue();

	~ArrayValue();

	// - p�id� element na konec pole
	void append(Value *element);

	string serialize() const override;

private:
	// - atribut DynamicArray<Value*> pro uchov�n� jednotliv�ch element� v poli
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class ObjectValue : public Value {
private:

public:

	ObjectValue();

	~ObjectValue();

	// - p�id� kl��-element do objektu
	void append(const KeyValuePair &pair);

	string serialize() const override;

private:
	// - atribut DynamicArray<KeyValuePair> pro uchov�n� jednotliv�ch hodnot a kl��� v objektu
};

///////////////////////////////////////////////////////////////////////////////

// - t��da pro pr�ci s JSON
class JSON {
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
	static Value *deserialize(const string &string);

	// - provede serializaci do JSON �et�zce
	static string serialize(const Value *value);
};

///////////////////////////////////////////////////////////////////////////////