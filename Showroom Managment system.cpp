#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

void menu();
bool menu1(int choice);
void Admin();
bool AdminLogin();
void Signup();
void User();
bool Customer1();
void saveCarData();
void removeCar(string name, string company, string model, string type, string color, int price);
void DeleteCar(string model, string company);
void UserMenu();
void display_cars();

string filename = "car_data.txt";



const int MAXNUMBER = 100;
static int TotalCustomers = 0, TotalCars = 0;
int Hello = 1;


class Car {
protected:
	string name;
	string company;
	string model;
	string type;
	string color;
public:
	Car(string n, string com, string m, string t, string c) {
		name = n;
		company = com;
		model = m;
		type = t;
		color = c;
	}
	virtual void show() {
		cout << "Name: " << name << endl;
		cout << "Company: " << company << endl;
		cout << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Color: " << color << endl;
	}
};

class Sell_a_car : public Car {
private:
	int price;
public:
	Sell_a_car(string n, string com, string m, string t, string c, int p) : Car(n, com, m, t, c) {
		price = p;
	}
	void show() {
		Car::show();
		cout << "Price: " << price << endl;
	}

};

class Buy_a_car : public Car {
private:
	int offer;
public:
	Buy_a_car(string n, string com, string m, string t, string c, int o) : Car(n, com, m, t, c) {
		offer = o;
	}
	void show() {
		Car::show();
		cout << "Offer: " << offer << endl;
	}
};

class Add_a_car : public Car {
	int price;
public:
	Add_a_car(string n, string com, string m, string t, string c, int p) : Car(n, com, m, t, c) {
		price = p;
	}
	void show() {
		Car::show();
		cout << "Price: " << price << endl;
	}
	string getmodel() {
		return model;
	}
	string getname() {
		return name;
	}
	string gettype() {
		return type;
	}
	string getcolor() {
		return color;
	}
	string getcompany() {
		return company;
	}
	int getprice() {
		return price;
	}
	void setmodel(string m) {
		model = m;
	}
	void setname(string n) {
		name = n;
	}
	void settype(string t) {
		type = t;
	}
	void setcolor(string c) {
		color = c;
	}
	void setprice(int p) {
		price = p;
	}
	/*void saveToFile() {
		ofstream outfile;
		outfile.open("car_data.txt", ios::app);
		outfile << name << "," << company << "," << model << "," << type << "," << color << "," << price << endl;
		outfile.close();
	}*/

};
Add_a_car* AddCar[MAXNUMBER];

class Delete_a_car : public Car {
	int price;
public:
	Delete_a_car(string n, string com, string m, string t, string c, int p) : Car(n, com, m, t, c) {
		price = p;
	}
	void show() {
		Car::show();
		cout << "Price: " << price << endl;
	}
	/*void removeCar()
		{
			ifstream infile;
			ofsteam outfile;
			infile.open("car_data.txt")
				outfile("temp.txt",ios::app )
				string inline;
			while (getline(infile, line))
			{
				stringstream ss(line);
				string n, com, m, t, c, p;
				getline(ss, n, ',');
				getline(ss, com, ',');
				getline(ss, m, ',');
				getline(ss, t, ',');
				getline(ss, c, ',');
				getline(ss, p, ',');
				if (n == name && com == company && m = model && t = type && c = color && p = to_string(price))
				{
					cout << "car founf and removed" << endl;
					show();
					continue;
				}
				outfile << line << endl;
			}
			infile.close();
			outfile.close();
			remove("car_data.txt");
			rename("temp.txr", "car_data.txt");
		}*/

};



void C_Login();


void menu() {
	while (Hello == 1) {
		int choice;
		cout << "| Select any one option:  |\n";
		cout << "| Press 1 | For Admin     |\n";
		cout << "| Press 2 | For Customer  |\n";
		cout << "| Press 3 | To Exit       |\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice < 1 || choice>3) {
			cout << "Error ! Please enter correct choice. " << endl;
			cin >> choice;
		}
		if (choice == 1) {
			system("cls");
			Admin();
		}
		else if (choice == 2) {
			system("cls");
			UserMenu();
			//C_Login();
		}
		else {
			Hello = 0;
			system("cls");
		}
	}

	cout << "Thankyou for Visiting our Showroom !! \n";
	"See you soon.\n";
	return;
}



void Admin() {
	int h = 0, j = 0;
	while (j == 0) {
		if (AdminLogin()) {
			while (h == 0) {
				int choice1;
				cout << "Please select any one of the following option..!!!" << endl;
				cout << "| Press 1 | To Add a car            |" << endl;
				cout << "| Press 2 | To Delete a car         |" << endl;
				cout << "| Press 3 | To Return to Main Menu  |" << endl << endl;
				cout << "Enter your choice: ";
				cin >> choice1;
				while (choice1 < 1 || choice1>3) {
					cout << "Error ! Invalid Choice.\n Enter choice again." << endl;
					cin >> choice1;
				}

				if (choice1 == 1) {
					system("cls");
					int n;
					cout << "How many cars do you want to add?\n";
					cin >> n;
					cout << endl << endl;
					for (int i = 0, z = 1; i < n; i++) {
						string name, company, model, type, color;
						int price;
						cout << "Enter the details of car " << z << " you want to add : " << endl;
						cout << "Name: ";
						cin >> name;
						cout << "Company: ";
						cin >> company;
						cout << "Model: ";
						cin >> model;
						cout << "Type: ";
						cin >> type;
						cout << "Color: ";
						cin >> color;
						cout << "Price: ";
						cin >> price;

						AddCar[TotalCars++] = new Add_a_car(name, company, model, type, color, price);

						z++;
						system("cls");
					}
					saveCarData();


				}
				else if (choice1 == 2) {
					system("cls");
					display_cars();
					cout << endl << endl;

					string name, company, model, type, color;
					int price;
					cout << "Enter the details of car you want to delete : " << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Company: ";
					cin >> company;
					cout << "Model: ";
					cin >> model;
					cout << "Type: ";
					cin >> type;
					cout << "Color: ";
					cin >> color;
					cout << "Price: ";
					cin >> price;

					removeCar(name, company, model, type, color, price);



					system("cls");
				}
				else if (choice1 == 3) {
					h = 1, j = 1;
					return;
				}
			}

		}
		else {
			int c;
			cout << "| Press 1 | To enter username and password again   |" << endl;
			cout << "| Press 2 | To return to main menu                 |" << endl;
			cin >> c;
			while (c < 1 || c>2) {
				cout << "Error ! Invalid Choice.\n Enter choice again." << endl;
				cin >> c;
			}
			if (c == 1) {
				system("cls");
				j = 0;
			}
			else {
				system("cls");
				j = 1;
			}
		}
	}
	return;
}

bool AdminLogin() {

	string user, pass;
	cout << endl;
	cout << "\n\n<<<<<   PLease Log-in As Admin  >>>>>\n\n";
	cout << "Enter Username: ";
	cin >> user;
	cout << "Enter Password: ";
	cin >> pass;
	if (user == "admin" && pass == "admin")
	{
		system("cls");
		cout << "\nAdmin Successfully Log-in\n\n";
		return true;
	}
	else
	{
		cout << "\nIncorrect username or password !";
		system("cls");
		return false;
	}
}

void UserMenu() {
	//int choice;
	cout << "\t\t\t--------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t                     HELLO SIR / MA'AM  !!                     \n\n";
	cout << "\t\t\t----------------------------------------------------------------\n\n";

	C_Login();

}

void User() {
	int h = 0;
	display_cars();
	while (h == 0) {
		int choice;
		cout << "Please select any one of the following option..!!!" << endl;
		cout << "Press 1 | To Sell a car            |" << endl;
		cout << "Press 2 | To Buy a car             |" << endl;
		cout << "Press 3 | To return to main menu   |" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		while (choice < 1 || choice>3) {
			cout << "Error !! Invalid choice. Enter choice again: ";
			cin >> choice;
		}
		system("cls");
		if (choice == 1) {
			string name, company, model, type, color;
			int price;
			cout << "Enter the details of the car you want to sell:" << endl;
			cout << "Name: ";
			cin >> name;
			cout << "Company: ";
			cin >> company;
			cout << "Model: ";
			cin >> model;
			cout << "Type: ";
			cin >> type;
			cout << "Color: ";
			cin >> color;
			cout << "Price: ";
			cin >> price;
			saveCarData();
			AddCar[TotalCars++] = new Add_a_car(name, company, model, type, color, price);



			Sell_a_car* car = new Sell_a_car(name, company, model, type, color, price);
			cout << "Details of the car you want to sell:" << endl;
			car->show();
		}

		else if (choice == 2) {
			string name, company, model, type, color;
			int offer;
			cout << "Enter the details of the car you want to buy:" << endl;
			cout << "Name: ";
			cin >> name;
			cout << "Company: ";
			cin >> company;
			cout << "Model: ";
			cin >> model;
			cout << "Type: ";
			cin >> type;
			cout << "Color: ";
			cin >> color;
			cout << "Offer: ";
			cin >> offer;

			Buy_a_car* car = new Buy_a_car(name, company, model, type, color, offer);
			//cout << "Details of the car you want to buy:" << endl;
			removeCar(name, company, model, type, color, offer);
			//car->show();

		}

		else if (choice == 3) {
			system("cls");
			h = 1;
			menu();
		}
	}
}

bool usernameExists(string username) {
	ifstream usersFile("userss.txt");
	string line;
	while (getline(usersFile, line)) {
		if (line.substr(0, username.size()) == username) {
			return true;
		}
	}
	return false;
}

// function to create a new user account
void signnUp() {
	string username, password;
	cout << "Enter a username: ";
	cin >> username;
	if (usernameExists(username)) {
		cout << "Username already exists." << endl << endl;
		return;
	}
	cout << "Enter a password: ";
	cin >> password;
	ofstream usersFile("userss.txt", ios::app);
	usersFile << username << " " << password << endl;
	usersFile.close();
	system("cls");
	cout << "Account created successfully." << endl;
}

// function to validate a user's login credentials
bool validateLogin(string username, string password) {
	ifstream usersFile("userss.txt");
	string line;
	while (getline(usersFile, line)) {
		if (line.substr(0, username.size()) == username) {
			string storedPassword = line.substr(username.size() + 1);
			if (storedPassword == password) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

// function to prompt the user to login and validate their credentials
void loginn() {
	string username, password;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;
	if (validateLogin(username, password)) {
		system("cls");
		cout << "Login successful." << endl << endl;
		User();
	}
	else {
		cout << "Invalid username or password." << endl;
	}

}



void C_Login() {
	int choice;
	int h = 1;
	while (h == 1) {
		cout << "1. Sign up" << endl;
		cout << "2. Login" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		cout << endl << endl;

		switch (choice) {
		case 1:
			signnUp();
			break;
		case 2:
			h = 0;
			loginn();
			break;
		case 3:
			cout << "Goodbye." << endl;
			h = 0;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}
	}

}



void saveCarData() {
	ofstream file(filename, ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < TotalCars; i++) {
			file << AddCar[i]->getname() << ","
				<< AddCar[i]->getcompany() << ","
				<< AddCar[i]->getmodel() << ","
				<< AddCar[i]->gettype() << ","
				<< AddCar[i]->getcolor() << ","
				<< AddCar[i]->getprice() << endl;
		}
		file.close();
	}
	else {
		cerr << "Error: Unable to open file " << filename << endl;
	}
}



void removeCar(string name, string company, string model, string type, string color, int price)
{
	ifstream infile;
	ofstream outfile;
	infile.open("car_data.txt");
	outfile.open("temp.txt");
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string n, com, m, t, c, p;
		getline(ss, n, ',');
		getline(ss, com, ',');
		getline(ss, m, ',');
		getline(ss, t, ',');
		getline(ss, c, ',');
		getline(ss, p, ',');
		if (n == name && com == company && m == model && t == type && c == color && stoi(p) == price)
		{
			cout << "car found and removed" << endl;
			continue;
		}
		outfile << line << endl;
	}
	infile.close();
	outfile.close();
	remove("car_data.txt");
	rename("temp.txt", "car_data.txt");
}

void display_cars() {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: Unable to open file." << endl;
		return;
	}

	cout << "-------------------------------------------------" << endl;
	cout << "Cars available for purchase:" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Name\tCompany\tModel\tType\tColor\tPrice" << endl;
	cout << "-------------------------------------------------" << endl;

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string name, company, model, type, color;
		int price;
		getline(ss, name, ',');
		getline(ss, company, ',');
		getline(ss, model, ',');
		getline(ss, type, ',');
		getline(ss, color, ',');
		ss >> price;
		cout << name << "\t" << company << "\t" << model << "\t" << type << "\t" << color << "\t" << price << endl;
	}
	file.close();
}




int main() {
	cout << "\t\t\t-----------------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t                       WELCOME TO OUR SHOWROOM                          \n\n";
	cout << "\t\t\t-------------------------------------------------------------------------\n\n";
	menu();

	return 0;

}