#include<fstream>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Person
{
public:

	char user_name[15], password[15];

	virtual bool login() = 0;
	virtual void delet() {};
};

class Admin : public Person
{
public:
	bool login();
	void add();
	void delet();
};


class Doctors : public Person
{
public:
	char name[15], phone[15], department[15];
	int id;
	bool login();
	void edit();
	void delet();
	void showDepart();
};


class Patient
{
private:
	char name[15], adress[15], phone[15], illness[15], nameDoc[15];
	int ID, age , idDoc;
public:
	void setID(int n)
	{
		ID = n;
	}
	void setAge(int n)
	{
		age = n;
	}
	void setIDDOC(int n)
	{
		idDoc = n;
	}

	void setName(char n[])
	{
		strcpy_s(name, n);
	}
	void setadress(char n[])
	{
		strcpy_s(adress, n);
	}
	void setphone(char n[])
	{
		strcpy_s(phone, n);
	}
	void setillness(char n[])
	{
		strcpy_s(illness, n);
	}
	void setnameDoc(char n[])
	{
		strcpy_s(nameDoc, n);
	}

	char* getName()
	{
		return name;
	}
	char* getadress()
	{
		return adress;
	}
	char* getphone()
	{
		return phone;
	}
	int getid()
	{
		return ID;
	}
	int getAge()
	{
		return age;
	}
	char* getillness()
	{
		return illness;
	}
	char* getnameDoc()
	{
		return nameDoc;
	}
	int getIDDOC()
	{
		return idDoc;
	}

	void filldata();
	void savedata(int i);

};