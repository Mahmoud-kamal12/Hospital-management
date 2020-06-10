#include "Hospital.h"

fstream file, file2;

bool Admin::login()
{
	cout << "Enter user name" << endl;
	cin >> user_name;
	cout << "Enter password" << endl;
	cin >> password;
	if (strcmp (user_name , "admin")==0 && strcmp( password , "admin") == 0)
	{
		return true;
	}
	else
	{
		return false;

	}
}

void Admin::add()
{
	Doctors d;
	cout << "Enter Doctor ID" << endl;
	cin >> d.id;
	cout << "Enter Doctor user name to login by it" << endl;
	cin.ignore();	cin.getline(d.user_name, 15);
	cout << "Enter Doctor password to login by it" << endl;
	cin.getline(d.password, 15);
	cout << "Enter Doctor name" << endl;
	cin.getline(d.name, 15);
	cout << "Enter Doctor phone" << endl;
	cin.getline(d.phone, 15);
	cout << "Enter Dovtor department" << endl;
	cin.getline(d.department, 15);
	file.open("Doc.dat", ios::app);
	file.write((char*)&d, sizeof(Doctors));
	file.close();
}

void Admin::delet()
{
	int i;
	cout << "Enter Doctor id to remove it = ";
	cin >> i;
	Doctors d;
	file.open("Doc.dat", ios::in);
	file2.open("temp.dat", ios::app);
	while (file.read((char*)&d, sizeof(Doctors)))
	{
		if (i != d.id)
		{
			file2.write((char*)&d, sizeof(Doctors));
		}
	}
	file.close();
	file2.close();
	remove("Doc.dat");
	rename("temp.dat", "Doc.dat");
}

bool Doctors::login()
{
	char u[15], p[15];
	Doctors d;
	int x = 0;
	cout << "Enter user name" << endl;
	cin.ignore();	cin.getline(u, 15);
	cout << "Enter password" << endl;
	cin.getline(p, 15);
	file.open("Doc.dat", ios::in);
	while (file.read((char*)&d, sizeof(Doctors)))
	{
		if (strcmp (d.user_name ,u)==0 && strcmp(d.password , p)==0)
		{
			x++;
			this->id = d.id;
		}
		else
		{
			continue;

		}
	}
	file.close();
	if (x > 0)
	{
		return true;
	}
	else
	{
		return false;

	}

}

void Doctors::edit()
{
	int i;
	char s[15];
	cout << "Enter Patient id to updata it" << endl;
	cin >> i;
	Patient p;
	file.open("Patient.dat", ios::in);
	file2.open("temp.dat", ios::app);
	while (file.read((char*)&p, sizeof(Patient)))
	{

		if (i == p.getid())
		{
			p.filldata();
			cout << "Enter Patient illness" << endl;
			cin.getline(s, 15);	p.setillness(s);

		}
		file2.write((char*)&p, sizeof(Patient));
	}
	file.close();
	file2.close();
	remove("Patient.dat");
	rename("temp.dat", "Patient.dat");

}

void Doctors::delet()
{
	int i;
	cout << "Enter Doctor id to remove it" << endl;
	cin >> i;
	Patient d;
	file.open("Patient.dat", ios::in);
	file2.open("temp.dat", ios::app);
	while (file.read((char*)&d, sizeof(Patient)))
	{
		if (i != d.getid())
		{
			file2.write((char*)&d, sizeof(Patient));
		}
	}
	file.close();
	file2.close();
	remove("Patient.dat");
	rename("temp.dat", "Patient.dat");
}

void Doctors::showDepart()
{
	fstream f;
	f.open("Doc.dat", ios::in);
	printf("| %-5s | %-15s | %-15s| %-15s |\n", "ID", "Name", "Phone", "department");
	printf("---------------------------------------------------------------------------------------------------------\n");

	while (f.read((char*)this, sizeof(Doctors)))
	{
		printf("| %-5d | %-15s | %-15s| %-15s |\n", id, name, phone, department);
		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	cout << endl;
	f.close();
}

void Patient::filldata()
{
	int i;		char s[20];
	cout << "Enter your id" << endl;
	cin >> i;	setID(i);
	cout << "Enter your age" << endl;
	cin >> i;	setAge(i);
	cout << "Enter your Name" << endl;
	cin.ignore();	cin.getline(s, 15);	setName(s);
	cout << "Enter your Phone" << endl;
	cin.getline(s, 15);	setphone(s);
	cout << "Enter your Adress" << endl;
	cin.getline(s, 15);	setadress(s);
}

void Patient::savedata(int i)
{
	Doctors d;
	file.open("Doc.dat", ios::in);
	while (file.read((char*)&d, sizeof(Doctors)))
	{
		if (d.id == i)
		{
			this->setillness(d.department);
			this->setnameDoc(d.name);
			this->setIDDOC(d.id);
		}
	}
	file.close();

	file.open("Patient.dat", ios::app);
	file.write((char*)this, sizeof(Patient));
	file.close();
}

