#include"Hospital.h"
void show(Patient p , int n);	// polymorphism   overloading
void show(Doctors d);	// polymorphism   overloading  
int main()
{
	Patient patient;
	Admin admin;
	Doctors doctors;
	Person* ptr;
	int ch, il;

	cout << "1- Administrator" << endl;
	cout << "2- Doctoe" << endl;
	cout << "3- Patient" << endl;
	cout << "4- Exit" << endl;
	cout << "Enter your chose [1 : 4]= ";
	cin >> ch;

	switch (ch)
	{
	case 1:
		system("cls");
		ptr = &admin;
		cout << "\t\t\t\t user = admin \n\t\t\t\t pass = admin\n" << endl;
		if (ptr->login())
		{
			system("cls");
			cout << "1- Add Doctor" << endl;
			cout << "2- Delet Doctor" << endl;
			cout << "3- Show All Doctors" << endl;
			cout << "4- Exit" << endl;
			cout << "Enter your chose [1 : 4]= ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				system("cls");
				admin.add();
				break;
			case 2:
				system("cls");
				show(doctors);
				ptr->delet();
				break;
			case 3:
				system("cls");
				show(doctors);
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Enter valid Number" << endl;
				break;
			}
		}
		else
		{
			cout << "Enter valid user or password" << endl;
		}
		break;
	case 2:
		system("cls");
		ptr = &doctors;
		if (ptr->login())
		{
			system("cls");
			cout << "1- Show All Patient" << endl;
			cout << "2- update Patient information" << endl;
			cout << "3- Delet Patient" << endl;
			cout << "4- Exit" << endl;
			cout << "Enter your chose [1 : 4]= ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				system("cls");
				patient.setID(0);
				show(patient , doctors.id);
				break;
			case 2:
				system("cls");
				patient.setID(0);
				show(patient, doctors.id);
				doctors.edit();
				break;
			case 3:
				system("cls");
				patient.setID(0);
				show(patient, doctors.id);
				ptr->delet();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Enter valid Number" << endl;
				break;
			}
		}
		else
		{
			cout << "Enter valid user or password" << endl;
		}
		break;
	case 3:
		doctors.showDepart();
		cout << "Enter id of Doctor = ";
		cin >> il;
		patient.filldata();
		patient.savedata(il);
		break;
	case 4:
		exit(0);
		break;
	default:
		cout << "Enter valid Number" << endl;
		break;
	}
	return 0;
}

void show(Patient p , int n )
{
	fstream file;
	file.open("Patient.dat", ios::in);
	printf("| %-5s | %-5s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "ID", "Age", "Name", "Phone", "Adress", "illness" , "Doc Name");
	cout << "---------------------------------------------------------------------------------------------------------\n";

	while (file.read((char*)&p, sizeof(Patient)))
	{
		if (n == p.getIDDOC())
		{
			printf("| %-5d | %-5d | %-15s | %-15s | %-15s | %-15s | %-15s |\n", p.getid(), p.getAge(), p.getName(), p.getphone(), p.getadress(), p.getillness(), p.getnameDoc());
			printf("---------------------------------------------------------------------------------------------------------\n");
		}
	}
	file.close();
}

void show(Doctors d)
{
	fstream file;
	file.open("Doc.dat", ios::in);
	printf("| %-5s | %-15s | %-15s| %-15s | %-15s | %-15s |\n", "ID", "Name", "Phone", "department", "user_name", "password");
	cout << "---------------------------------------------------------------------------------------------------------\n";

	while (file.read((char*)&d, sizeof(Doctors)))
	{
		printf("| %-5d | %-15s | %-15s| %-15s | %-15s | %-15s |\n", d.id, d.name, d.phone, d.department, d.user_name, d.password);
		printf("---------------------------------------------------------------------------------------------------------\n");

	}
	file.close();
}
