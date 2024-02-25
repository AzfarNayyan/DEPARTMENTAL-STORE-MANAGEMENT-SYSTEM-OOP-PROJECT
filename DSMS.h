#include<iostream>
#include <SFML/Graphics.hpp>
#include<string>
#include<fstream>

using namespace std;
using namespace sf;

//CLASSSSEEESSS: ------------------------------------------

class inventory
{
	int product_count = 0;
public:
	int getCount()
	{
		return product_count;
	}
	void incrementTheCount()
	{
		product_count += 1;
	}
	void setProductCount(int count)
	{
		product_count = count;
	}
};

class product :public inventory
{
	int product_code;
	int quantity;
public:
	virtual void addProduct() = 0;
	virtual void deleteProduct(int choice) = 0;
	virtual void setName(string name) = 0;
	virtual void setPrice(double price) = 0;
	virtual void setSerialNo(int serial) = 0;
	virtual string getName() = 0;
	virtual double getPrice() = 0;
	virtual int getSerialNo() = 0;
	void setProductCode(int code)
	{
		product_code = code;
	}
	void setProductQuantity(int quan)
	{
		quantity = quan;
	}
	int getProductCode() const
	{
		return product_code;
	}
	int getProductQuantity() const
	{
		return quantity;
	}
	virtual ~product() {};
};

class clothing :public product
{
	string product_name_clothing;
	double product_price_clothing;
	int product_serial_no_clothing;
public:
	clothing()
	{
		product_price_clothing = 0;
		product_serial_no_clothing = 0;
	}
	void setName(string name)
	{
		product_name_clothing = name;
	}
	void setPrice(double price)
	{
		product_price_clothing = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_clothing = serial;
	}
	string getName()
	{
		return  product_name_clothing;
	}
	double getPrice()
	{
		return product_price_clothing;
	}
	int getSerialNo()
	{
		return product_serial_no_clothing;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("clothing.txt", ios::app);
		fr << product_serial_no_clothing << " ";
		fr << getProductCode() << " ";
		fr << product_name_clothing << " ";
		fr << product_price_clothing << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "clothing.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	clothing* loadProducts() 
	{
		ifstream fg;
		fg.open("clothing.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		clothing* ptr;
		ptr = new clothing[numRows+1];
		ptr[0].setProductCount(numRows);
	
		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("clothing.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;
	}
	~clothing() {};
};

class electronics :public product
{
	string product_name_electronics;
	double product_price_electronics;
	int product_serial_no_electronics;
public:
	electronics()
	{
		product_price_electronics = 0;
		product_serial_no_electronics = 0;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("electronics.txt", ios::app);
		fr << product_serial_no_electronics << " ";
		fr << getProductCode() << " ";
		fr << product_name_electronics << " ";
		fr << product_price_electronics << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "electronics.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	electronics* loadProducts() 
	{
		ifstream fg;
		fg.open("electronics.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		electronics* ptr;
		ptr = new electronics[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("electronics.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;
	}
	void setName(string name)
	{
		product_name_electronics = name;
	}
	void setPrice(double price)
	{
		product_price_electronics = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_electronics = serial;
	}
	string getName()
	{
		return  product_name_electronics;
	}
	double getPrice()
	{
		return product_price_electronics;
	}
	int getSerialNo()
	{
		return product_serial_no_electronics;
	}
	~electronics() {};
};

class grocery :public product
{
	string product_name_grocery;
	double product_price_grocery;
	int product_serial_no_grocery;
public:
	grocery()
	{
		product_price_grocery = 0;
		product_serial_no_grocery = 0;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("grocery.txt", ios::app);
		fr << product_serial_no_grocery << " ";
		fr << getProductCode() << " ";
		fr << product_name_grocery << " ";
		fr << product_price_grocery << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "grocery.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	grocery* loadProducts() 
	{
		ifstream fg;
		fg.open("grocery.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		grocery* ptr;
		ptr = new grocery[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("grocery.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;
	}
	void setName(string name)
	{
		product_name_grocery = name;
	}
	void setPrice(double price)
	{
		product_price_grocery = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_grocery = serial;
	}
	string getName()
	{
		return  product_name_grocery;
	}
	double getPrice()
	{
		return product_price_grocery;
	}
	int getSerialNo()
	{
		return product_serial_no_grocery;
	}
	~grocery() {};
};

class toys :public product
{
	string product_name_toys;
	double product_price_toys;
	int product_serial_no_toys;
public:
	toys()
	{
		product_price_toys = 0;
		product_serial_no_toys = 0;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("toys.txt", ios::app);
		fr << product_serial_no_toys << " ";
		fr << getProductCode() << " ";
		fr << product_name_toys << " ";
		fr << product_price_toys << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "toys.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	toys* loadProducts() 
	{
		ifstream fg;
		fg.open("toys.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		toys* ptr;
		ptr = new toys[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("toys.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;
	}
	void setName(string name)
	{
		product_name_toys = name;
	}
	void setPrice(double price)
	{
		product_price_toys = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_toys = serial;
	}
	string getName()
	{
		return  product_name_toys;
	}
	double getPrice()
	{
		return product_price_toys;
	}
	int getSerialNo()
	{
		return product_serial_no_toys;
	}
	~toys() {};
};

class cosmetics :public product
{
	string product_name_cosmetics;
	double product_price_cosmetics;
	int product_serial_no_cosmetics;
public:
	cosmetics()
	{
		product_price_cosmetics = 0;
		product_serial_no_cosmetics = 0;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("cosmetics.txt", ios::app);
		fr << product_serial_no_cosmetics << " ";
		fr << getProductCode() << " ";
		fr << product_name_cosmetics << " ";
		fr << product_price_cosmetics << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "cosmetics.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	cosmetics* loadProducts() 
	{
		ifstream fg;
		fg.open("cosmetics.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		cosmetics* ptr;
		ptr = new cosmetics[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("cosmetics.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;;
	}
	void setName(string name)
	{
		product_name_cosmetics = name;
	}
	void setPrice(double price)
	{
		product_price_cosmetics = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_cosmetics = serial;
	}
	string getName()
	{
		return  product_name_cosmetics;
	}
	double getPrice()
	{
		return product_price_cosmetics;
	}
	int getSerialNo()
	{
		return product_serial_no_cosmetics;
	}
	~cosmetics() {};
};

class furniture : public product
{
	string product_name_furniture;
	double product_price_furniture;
	int product_serial_no_furniture;
public:
	furniture()
	{
		product_price_furniture = 0;
		product_serial_no_furniture = 0;
	}
	void addProduct() override
	{
		ofstream fr;
		fr.open("furniture.txt", ios::app);
		fr << product_serial_no_furniture << " ";
		fr << getProductCode() << " ";
		fr << product_name_furniture << " ";
		fr << product_price_furniture << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override
	{
		string filename = "furniture.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	furniture* loadProducts() 
	{
		ifstream fg;
		fg.open("furniture.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();


		furniture* ptr;
		ptr = new furniture[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("furniture.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;

	}
	void setName(string name)
	{
		product_name_furniture = name;
	}
	void setPrice(double price)
	{
		product_price_furniture = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_furniture = serial;
	}
	string getName()
	{
		return  product_name_furniture;
	}
	double getPrice()
	{
		return product_price_furniture;
	}
	int getSerialNo()
	{
		return product_serial_no_furniture;
	}
	~furniture() {};
};

class games : public product
{
	string product_name_games;
	double product_price_games;
	int product_serial_no_games;
public:
	games()
	{
		product_price_games = 0;
		product_serial_no_games = 0;
	}
	void addProduct() override final
	{
		ofstream fr;
		fr.open("games.txt", ios::app);
		fr << product_serial_no_games << " ";
		fr << getProductCode() << " ";
		fr << product_name_games << " ";
		fr << product_price_games << " ";
		fr << getProductQuantity() << " " << endl;
		fr.close();
		this->incrementTheCount();
	}
	void deleteProduct(int choice) override final
	{
		string filename = "games.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	games* loadProducts() 
	{
		ifstream fg;
		fg.open("games.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		games* ptr;
		ptr = new games[numRows + 1];
		ptr[0].setProductCount(numRows);

		int serial, code, quantity;
		string name;
		double price;

		ifstream fr;
		fr.open("games.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> serial;
			ptr[i].setSerialNo(serial);
			fr >> code;
			ptr[i].setProductCode(code);
			fr >> name;
			ptr[i].setName(name);
			fr >> price;
			ptr[i].setPrice(price);
			fr >> quantity;
			ptr[i].setProductQuantity(quantity);
		}
		fr.close();

		return ptr;
	}
	void setName(string name)
	{
		product_name_games = name;
	}
	void setPrice(double price)
	{
		product_price_games = price;
	}
	void setSerialNo(int serial)
	{
		product_serial_no_games = serial;
	}
	string getName()
	{
		return  product_name_games;
	}
	double getPrice()
	{
		return product_price_games;
	}
	int getSerialNo()
	{
		return product_serial_no_games;
	}
	~games() {};
};

class Customer
{
	string name;
	int id;
	string** cart;
	double** price;
	double amount;
	static int size;
public:
	Customer()
	{
		cart = new string * [size];
		cart[size - 1] = new string;
		price = new double* [size];
		price[size - 1] = new double;
	}
	string getName()
	{
		return name;
	}
	int getId()
	{
		return id;
	}
	double getAmount()
	{
		return amount;
	}
	void setId(int i)
	{
		id = i;
	}
	void setName(string n)
	{
		name = n;
	}
	void setAmount(double a)
	{
		amount = a;
	}
	int getSize()
	{
		return size;
	}
	string**& getCart()
	{
		return cart;
	}
	double**& getPrices()
	{
		return price;
	}
	void addtocart(string name, double pr, int quantity)
	{
		double p = pr * quantity;
		int presize = size;
		size++;
		string** temp;
		temp = new string * [size];
		for (int i = 0; i < size; i++)
			temp[i] = new string;
		int i;
		for (i = 0; i < presize; i++)
		{
			temp[i][0] = cart[i][0];
		}
		for (int j = i; j < size; j++)
		{
			temp[j][0] = name;
		}
		delete cart;
		cart = new string * [size];
		for (int i = 0; i < size; i++)
			cart[i] = new string;
		for (i = 0; i < presize; i++)
		{
			cart[i][0] = temp[i][0];
		}
		for (int j = i; j < size; j++)
		{
			cart[i][0] = name;
		}

		double** temp1;
		temp1 = new double * [size];
		for (int i = 0; i < size; i++)
			temp1[i] = new double;
		for (i = 0; i < presize; i++)
		{
			temp1[i][0] = price[i][0];
		}
		for (int j = i; j < size; j++)
		{
			temp1[j][0] = p;
		}
		delete price;
		price = new double * [size];
		for (int i = 0; i < size; i++)
			price[i] = new double;
		for (i = 0; i < presize; i++)
		{
			price[i][0] = temp1[i][0];
		}
		for (int j = i; j < size; j++)
		{
			price[i][0] = p;
		}
	}
	void printDetails()
	{
		cout << "======7ELEVEN SUPERMARKETT=========" << endl << endl;
		double amount = 0;
		cout << "name: " << name << endl;
		cout << "id: " << id << endl << endl;
		for (int i = 1; i < size; i++)
		{
			cout << cart[i][0] << " " << price[i][0] << endl;
			amount += price[i][0];
		}
		cout << endl;
		cout << "amount: " << amount << endl << endl;
	}
	~Customer() 
	{
		for (int i = 0; i < size; i++)
		{
			delete cart[i];
			delete price[i];
		}
		delete cart;
		delete price;
	}
};

int Customer::size = 1;

class Employee
{
	string emp_name;
	string emp_category_name;
	int id;
	double salary;
public:
	Employee()
	{
		emp_name = "";
		emp_category_name = "";
		id = 0;
		salary = 0;
	}
	void addEmp()
	{
		ofstream fr;
		fr.open("employees.txt", ios::app);
		fr << emp_name << " ";
		fr << id << " ";
		fr << salary << " ";
		fr << emp_category_name << " ";
		fr << endl;
		fr.close();
	}
	void setName(string name)
	{
		emp_name = name;
	}
	void setCate(string cate)
	{
		emp_category_name = cate;
	}
	void setId(int i)
	{
		id = i;
	}
	void setSal(double sal)
	{
		salary = sal;
	}
	string getName()
	{
		return emp_name;
	}
	string getCate()
	{
		return emp_category_name;
	}
	int getId()
	{
		return id;
	}
	double getSal()
	{
		return salary;
	}
	Employee* loadEmployees()
	{
		Employee* ptr = NULL;

		ifstream fg;
		fg.open("clothing.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		ptr = new Employee[numRows + 1];

		string name, cate;
		int id;
		double sal;

		ifstream fr;
		fr.open("employees.txt");
		for (int i = 0; i < numRows; i++)
		{
			fr >> name;
			ptr[i].setName(name);
			fr >> id;
			ptr[i].setId(id);
			fr >> sal;
			ptr[i].setSal(sal);
			fr >> cate;
			ptr[i].setCate(cate);
		}
		fr.close();
		return ptr;
	}
	int empCount()
	{
		ifstream fg;
		fg.open("employees.txt");
		string line;
		int numRows = 0;
		while (getline(fg, line)) {
			++numRows;
		}
		fg.close();

		return numRows;
	}
	void deleteEmployee(int choice)
	{
		string filename = "employees.txt";
		ifstream inputFile(filename);
		ofstream tempFile("temp.txt");

		string line;
		int lineNumber = 1;
		while (getline(inputFile, line)) {
			if (lineNumber != choice) {
				tempFile << line << endl;
			}
			lineNumber++;
		}

		inputFile.close();
		tempFile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	~Employee() {};
};

// FUNCTIONS (GRAPHICAL & OTHERS):-------------------------------------
void DisplayLoadingScreen(RenderWindow& Window);
int DisplayMainMenu(RenderWindow& Window);
int InventoryMenu(RenderWindow& Window, int& category);
int AddItem(RenderWindow& Window, int category);
int DisplayItems(RenderWindow& Window, int category);
int DeleteItem(RenderWindow& Window, int category);
int EmployeeMenu(RenderWindow& Window);
int AddEmployee(RenderWindow& Window);
int DisplayEmployee(RenderWindow& Window);
int DeleteEmployee(RenderWindow& Window);
int CustomerMenu(RenderWindow& Window, int& category, Customer& customer);
int CustomerDisplay(RenderWindow& Window, int category, Customer& customer);
int confirmCart(RenderWindow& Window, Customer& customer);
int customerBill(RenderWindow& Window, Customer& customer);
void ADD_PRODUCT(int category, int code, string name, double price, int serialno, int quantity);
void ADD_EMPLOYEE(string empname, string empcate, int empid, double empsal);
void DELETE_PRODUCT(int category, int choice);
//-----------------------------------------------------------------------


//FUNCTIONS:------------------------------------------------------------

void ADD_PRODUCT(int category, int code, string name, double price, int serialno, int quantity)
{
	product* p = NULL;

	if (category == 1) p = new clothing;

	if (category == 2) p = new electronics;

	if (category == 3) p = new grocery;

	if (category == 4) p = new toys;

	if (category == 5) p = new cosmetics;

	if (category == 6) p = new furniture;

	if (category == 7) p = new games;
	
	p->setName(name);
	p->setPrice(price);
	p->setProductCode(code);
	p->setProductQuantity(quantity);
	p->setSerialNo(serialno);
	p->addProduct();
}

void DELETE_PRODUCT(int category, int choice)
{
	product* p = NULL;

	if (category == 1) p = new clothing;
	
	if (category == 2) p = new electronics;
	
	if (category == 3) p = new grocery;

	if (category == 4) p = new toys;
	
	if (category == 5) p = new cosmetics;
	
	if (category == 6) p = new furniture;
	
	if (category == 7) p = new games;
	
	p->deleteProduct(choice);
}

void ADD_EMPLOYEE(string empname, string empcate, int empid, double empsal)
{
	Employee emp;
	emp.setName(empname);
	emp.setCate(empcate);
	emp.setId(empid);
	emp.setSal(empsal);
	emp.addEmp();
}

void DisplayLoadingScreen(RenderWindow& Window)
{
	Texture loading;
	loading.loadFromFile("loading.jpg");
	Sprite loadingSprite;
	loadingSprite.setTexture(loading);

	RectangleShape loadingBar(Vector2f(0, 50));
	loadingBar.setFillColor(Color::Black);
	loadingBar.setPosition(200, 450);

	RectangleShape rectangle(Vector2f(800, 80));
	rectangle.setPosition(100, 100);
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(Color::White);
	Text text;
	Font font;
	Text text1;
	font.loadFromFile("Pacifico.ttf");
	text.setFont(font);
	text1.setFont(font);
	text.setString("Departmental Store Management System.");
	text1.setString("Loading...");
	text.setCharacterSize(45);
	text1.setCharacterSize(20);
	text1.setFillColor(Color::Black);
	text.setFillColor(Color::White);
	text1.setPosition(460, 470);
	text.setPosition(114, 110);

	while (loadingBar.getSize().x < 600)
	{
		loadingBar.setSize(Vector2f(loadingBar.getSize().x + 1, 10));
		Window.clear(Color::Black);
		Window.draw(loadingSprite);
		Window.draw(loadingBar);
		Window.draw(rectangle);
		Window.draw(text);
		Window.draw(text1);
		Window.display();
	}
}

int DisplayMainMenu(RenderWindow& Window)
{
	RectangleShape topbar(Vector2f(1200, 95));
	topbar.setFillColor(Color::Black);
	topbar.setPosition(sf::Vector2f(0, 0));
	topbar.setOutlineColor(Color(34, 34, 34));
	topbar.setOutlineThickness(2);

	Font font;
	font.loadFromFile("Pacifico.ttf");

	Text t1("Departmental Store Management System.", font, 50);
	t1.setFillColor(Color::White);
	t1.setPosition(70, 15);

	Texture background;
	background.loadFromFile("background.jpg");
	Sprite backgroundSprite;
	backgroundSprite.setTexture(background);
	backgroundSprite.setPosition(0, 100);

	RectangleShape b1(Vector2f(300, 60));
	b1.setFillColor(Color::Black);
	b1.setPosition(340, 180);
	b1.setOutlineColor(Color::White);
	b1.setOutlineThickness(8);

	RectangleShape b2(Vector2f(300, 60));
	b2.setFillColor(Color::Black);
	b2.setPosition(340, 300);
	b2.setOutlineColor(Color::White);
	b2.setOutlineThickness(8);

	RectangleShape b3(Vector2f(300, 60));
	b3.setFillColor(Color::Black);
	b3.setPosition(340, 420);
	b3.setOutlineColor(Color::White);
	b3.setOutlineThickness(8);

	Text tb1("Inventory Menu", font, 30);
	Text tb2("Customer Menu", font, 30);
	Text tb3("Employee Menu", font, 30);
	tb1.setFillColor(Color::White);
	tb2.setFillColor(Color::White);
	tb3.setFillColor(Color::White);
	tb1.setPosition(390, 190);
	tb2.setPosition(390, 310);
	tb3.setPosition(390, 430);




	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (b1.getGlobalBounds().contains(mousePos))
					{
						return 1;
					}
					if (b2.getGlobalBounds().contains(mousePos))
					{
						return 2;
					}
					if (b3.getGlobalBounds().contains(mousePos))
					{
						return 3;
					}
				}
			}
		}

		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (b1.getGlobalBounds().contains(mousePos))
		{
			b1.setOutlineColor(Color(61, 89, 171));
		}
		else
		{
			b1.setOutlineColor(Color::Black);
		}
		if (b2.getGlobalBounds().contains(mousePos))
		{
			b2.setOutlineColor(Color(61, 89, 171));
		}
		else
		{
			b2.setOutlineColor(Color::Black);
		}
		if (b3.getGlobalBounds().contains(mousePos))
		{
			b3.setOutlineColor(Color(61, 89, 171));
		}
		else
		{
			b3.setOutlineColor(Color::Black);
		}

		Window.clear(Color::Black);
		Window.draw(backgroundSprite);
		Window.draw(b1);
		Window.draw(b2);
		Window.draw(b3);
		Window.draw(tb1);
		Window.draw(tb2);
		Window.draw(tb3);
		Window.draw(topbar);
		Window.draw(t1);
		Window.display();
	}

}

int InventoryMenu(RenderWindow& Window, int& category)
{
	RectangleShape dashboard(Vector2f(200, 600));
	dashboard.setFillColor(Color::Black);     //61, 89, 171, 128
	dashboard.setPosition(0, 60);

	RectangleShape d(Vector2f(150, 45));
	d.setFillColor(Color::Green);
	d.setPosition(26, 7);

	RectangleShape D2(Vector2f(1200, 600));
	D2.setFillColor(Color(255, 253, 208, 128));                        //255, 253, 208,128
	D2.setPosition(0, 60);                                           //255, 218, 185,128

	RectangleShape bar1(Vector2f(1200, 5));
	bar1.setFillColor(Color::Black);
	bar1.setPosition(200, 60);

	RectangleShape bar2(Vector2f(200, 5));
	bar2.setFillColor(Color(255, 253, 208, 128));
	bar2.setPosition(0, 60);

	Font font2;
	font2.loadFromFile("Aovel.ttf");
	Font font;
	font.loadFromFile("emmasophia.ttf");

	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 25);
	tx1.setFillColor(Color::Black);

	Text tx2("INVENTORY MENU", font, 20);
	tx2.setPosition(415, 25);
	tx2.setFillColor(Color::White);

	RectangleShape b1(Vector2f(170, 50));
	b1.setFillColor(Color::White);
	b1.setPosition(18, 90);
	b1.setOutlineThickness(6);
	b1.setOutlineColor(Color::Black);

	RectangleShape b2(Vector2f(170, 50));
	b2.setFillColor(Color::White);
	b2.setPosition(18, 160);
	b2.setOutlineThickness(6);
	b2.setOutlineColor(Color::Black);

	RectangleShape b3(Vector2f(170, 50));
	b3.setFillColor(Color::White);
	b3.setPosition(18, 230);
	b3.setOutlineThickness(6);
	b3.setOutlineColor(Color::Black);

	RectangleShape b4(Vector2f(170, 50));
	b4.setFillColor(Color::White);
	b4.setPosition(18, 300);
	b4.setOutlineThickness(6);
	b4.setOutlineColor(Color::Black);

	RectangleShape b5(Vector2f(170, 50));
	b5.setFillColor(Color::White);
	b5.setPosition(18, 370);
	b5.setOutlineThickness(6);
	b5.setOutlineColor(Color::Black);

	RectangleShape b6(Vector2f(170, 50));
	b6.setFillColor(Color::White);
	b6.setPosition(18, 440);
	b6.setOutlineThickness(6);
	b6.setOutlineColor(Color::Black);

	RectangleShape b7(Vector2f(170, 50));
	b7.setFillColor(Color::White);
	b7.setPosition(18, 510);
	b7.setOutlineThickness(6);
	b7.setOutlineColor(Color::Black);

	RectangleShape cbox(Vector2f(200, 40));
	cbox.setPosition(550, 95);
	cbox.setFillColor(Color::White);
	cbox.setOutlineColor(Color::Black);
	cbox.setOutlineThickness(6);

	RectangleShape additem(Vector2f(200, 70));
	additem.setPosition(320, 270);
	additem.setFillColor(Color::White);
	additem.setOutlineColor(Color::Black);
	additem.setOutlineThickness(6);

	
	RectangleShape displayitem(Vector2f(200, 70));
	displayitem.setPosition(470, 370);
	displayitem.setFillColor(Color::White);
	displayitem.setOutlineColor(Color::Black);
	displayitem.setOutlineThickness(6);

	RectangleShape deleteitem(Vector2f(200, 70));
	deleteitem.setPosition(620, 270);
	deleteitem.setFillColor(Color::White);
	deleteitem.setOutlineColor(Color::Black);
	deleteitem.setOutlineThickness(6);

	Text t1("Clothing", font2, 28);
	t1.setPosition(55, 95);
	t1.setFillColor(Color::Black);
	Text t2("Electronics", font2, 28);
	t2.setPosition(40, 165);
	t2.setFillColor(Color::Black);
	Text t3("Grocery", font2, 28);
	t3.setPosition(55, 235);
	t3.setFillColor(Color::Black);
	Text t4("Toys", font2, 28);
	t4.setPosition(75, 305);
	t4.setFillColor(Color::Black);
	Text t5("Cosmetics", font2, 28);
	t5.setPosition(40, 375);
	t5.setFillColor(Color::Black);
	Text t6("Furniture", font2, 28);
	t6.setPosition(55, 445);
	t6.setFillColor(Color::Black);
	Text t7("Games", font2, 28);
	t7.setPosition(60, 515);
	t7.setFillColor(Color::Black);
	Text t8("CATEGORY: ", font, 16);
	t8.setPosition(340, 110);
	t8.setFillColor(Color::Black);
	Text t9("--Select--", font2, 28);
	t9.setPosition(595, 95);
	t9.setFillColor(Color::Black);
	Text t10("ADD ITEM", font, 16);
	t10.setPosition(345, 300);
	t10.setFillColor(Color::Black);
	Text t12("DISPLAY ITEMS", font, 14);
	t12.setPosition(475, 400);
	t12.setFillColor(Color::Black);
	Text t13("DELETE ITEM", font, 14);
	t13.setPosition(630, 300);
	t13.setFillColor(Color::Black);

	category = 0;

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (b1.getGlobalBounds().contains(mousePos)) {
						t9.setString("Clothing.");
						category = 1;
					}
					if (b2.getGlobalBounds().contains(mousePos)) {
						t9.setString("Electronics.");
						category = 2;
					}
					if (b3.getGlobalBounds().contains(mousePos)) {
						t9.setString("Grocery.");
						category = 3;
					}
					if (b4.getGlobalBounds().contains(mousePos)) {
						t9.setString("Toys.");
						category = 4;
					}
					if (b5.getGlobalBounds().contains(mousePos)) {
						t9.setString("Cosmetics.");
						category = 5;
					}
					if (b6.getGlobalBounds().contains(mousePos)) {
						t9.setString("Furniture.");
						category = 6;
					}
					if (b7.getGlobalBounds().contains(mousePos)) {
						t9.setString("Games.");
						category = 7;
					}
					if (d.getGlobalBounds().contains(mousePos)) {
						return -1;
					}
					if (additem.getGlobalBounds().contains(mousePos)) {
						if (category == 0){
							cout << "SELECT CATEGORY!" << endl;
						}
						else{
							return 1;
						}
					}
					if (deleteitem.getGlobalBounds().contains(mousePos)) {
						if (category == 0) {
							cout << "SELECT CATEGORY!" << endl;
						}
						else {
							return 3;
						}
					}
					if (displayitem.getGlobalBounds().contains(mousePos)) {
						if (category == 0) {
							cout << "SELECT CATEGORY!" << endl;
						}
						else {
							return 4;
						}
					}
				}
			}
		}

		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (b1.getGlobalBounds().contains(mousePos)) {
			b1.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b1.setOutlineColor(Color::Black);
		}
		if (b2.getGlobalBounds().contains(mousePos)) {
			b2.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b2.setOutlineColor(Color::Black);
		}
		if (b3.getGlobalBounds().contains(mousePos)) {
			b3.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b3.setOutlineColor(Color::Black);
		}
		if (b4.getGlobalBounds().contains(mousePos)) {
			b4.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b4.setOutlineColor(Color::Black);
		}
		if (b5.getGlobalBounds().contains(mousePos)) {
			b5.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b5.setOutlineColor(Color::Black);
		}
		if (b6.getGlobalBounds().contains(mousePos)) {
			b6.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b6.setOutlineColor(Color::Black);
		}
		if (b7.getGlobalBounds().contains(mousePos)) {
			b7.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b7.setOutlineColor(Color::Black);
		}
		if (d.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (additem.getGlobalBounds().contains(mousePos)) {
			additem.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			additem.setOutlineColor(Color::Black);
		}
		if (displayitem.getGlobalBounds().contains(mousePos)) {
			displayitem.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			displayitem.setOutlineColor(Color::Black);
		}
		if (deleteitem.getGlobalBounds().contains(mousePos)) {
			deleteitem.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			deleteitem.setOutlineColor(Color::Black);
		}


		Window.clear();
		Window.draw(dashboard);
		Window.draw(D2);
		Window.draw(d);
		Window.draw(bar1);
		Window.draw(bar2);
		Window.draw(tx1);
		Window.draw(tx2);
		Window.draw(b1);
		Window.draw(b2);
		Window.draw(b3);
		Window.draw(b4);
		Window.draw(b5);
		Window.draw(b6);
		Window.draw(b7);
		Window.draw(cbox);
		Window.draw(additem);
		Window.draw(displayitem);
		Window.draw(deleteitem);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(t3);
		Window.draw(t4);
		Window.draw(t5);
		Window.draw(t6);
		Window.draw(t7);
		Window.draw(t8);
		Window.draw(t9);
		Window.draw(t10);
		Window.draw(t12);
		Window.draw(t13);
		Window.display();
	}
}

int AddItem(RenderWindow& Window, int category)
{
	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));
	RectangleShape box(Vector2f(200, 50));
	box.setPosition(730, 20);
	box.setFillColor(Color::White);
	Font font;
	font.loadFromFile("emmasophia.ttf");
	Font font2;
	font2.loadFromFile("Dosis.ttf");
	Text t1("ADD ITEM", font, 20);
	t1.setPosition(230, 40);
	t1.setFillColor(Color::White);
	Text t2("CATEGORY: ", font, 20);
	t2.setPosition(480, 40);
	t2.setFillColor(Color::White);
	Text t3;
	t3.setPosition(765, 35);
	t3.setFont(font);
	t3.setFillColor(Color::Black);
	t3.setCharacterSize(18);
	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);
	if (category == 1) {
		t3.setString("Clothing");
	}
	if (category == 2) {
		t3.setString("Electronics");
	}
	if (category == 3) {
		t3.setString("Grocery");
	}
	if (category == 4) {
		t3.setString("Toys");
	}
	if (category == 5) {
		t3.setString("Cosmetics");
	}
	if (category == 6) {
		t3.setString("Furniture");
	}
	if (category == 7) {
		t3.setString("Games");
	}
	Text code("Product Code: ", font2, 24);
	code.setFillColor(Color::Black);
	code.setPosition(30, 190);
	RectangleShape productcode(Vector2f(180, 40));
	productcode.setFillColor(Color::White);
	productcode.setPosition(250, 185);
	productcode.setOutlineThickness(4);
	productcode.setOutlineColor(Color::Black);
	Text name("Product Name: ", font2, 24);
	name.setFillColor(Color::Black);
	name.setPosition(30, 290);
	RectangleShape productname(Vector2f(180, 40));
	productname.setFillColor(Color::White);
	productname.setPosition(250, 285);
	productname.setOutlineColor(Color::Black);
	productname.setOutlineThickness(4);
	Text price("Product Price: ", font2, 24);
	price.setFillColor(Color::Black);
	price.setPosition(30, 390);
	RectangleShape productprice(Vector2f(180, 40));
	productprice.setFillColor(Color::White);
	productprice.setPosition(250, 385);
	productprice.setOutlineColor(Color::Black);
	productprice.setOutlineThickness(4);
	Text serial("Serial No: ", font2, 24);
	serial.setFillColor(Color::Black);
	serial.setPosition(530, 190);
	RectangleShape serialno(Vector2f(180, 40));
	serialno.setFillColor(Color::White);
	serialno.setOutlineColor(Color::Black);
	serialno.setOutlineThickness(4);
	serialno.setPosition(730, 190);
	Text tax("Quantity : ", font2, 24);
	tax.setFillColor(Color::Black);
	tax.setPosition(530, 290);
	RectangleShape quantity(Vector2f(180, 40));
	quantity.setFillColor(Color::White);
	quantity.setOutlineColor(Color::Black);
	quantity.setOutlineThickness(4);
	quantity.setPosition(730, 285);
	Text add("ENTER ITEM", font, 12);
	add.setFillColor(Color::Black);
	add.setPosition(425, 525);
	RectangleShape enter(Vector2f(210, 55));
	enter.setFillColor(Color::White);
	enter.setOutlineColor(Color::Black);
	enter.setOutlineThickness(6);
	enter.setPosition(390, 500);

	bool productcodeStatus = false;
	string productcodeTextString = "";
	Text productcodeText("", font2, 20);
	productcodeText.setFillColor(Color::Black);
	productcodeText.setPosition(productcode.getPosition().x + 5.f, productcode.getPosition().y + 5.f);
	bool productnameStatus = false;
	string productnameTextString = "";
	Text productnameText("", font2, 20);
	productnameText.setFillColor(Color::Black);
	productnameText.setPosition(productname.getPosition().x + 5.f, productname.getPosition().y + 5.f);
	bool productpriceStatus = false;
	string productpriceTextString = "";
	Text productpriceText("", font2, 20);
	productpriceText.setFillColor(Color::Black);
	productpriceText.setPosition(productprice.getPosition().x + 5.f, productprice.getPosition().y + 5.f);
	bool serialnoStatus = false;
	string serialnoTextString = "";
	Text serialnoText("", font2, 20);
	serialnoText.setFillColor(Color::Black);
	serialnoText.setPosition(serialno.getPosition().x + 5.f, serialno.getPosition().y + 5.f);
	bool quantityStatus = false;
	string quantityTextString = "";
	Text quantityText("", font2, 20);
	quantityText.setFillColor(Color::Black);
	quantityText.setPosition(quantity.getPosition().x + 5.f, quantity.getPosition().y + 5.f);


	//SCREEN LOOP:------------------------------------------


	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (productcode.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						productcodeStatus = true;
						productnameStatus = false;
						productpriceStatus = false;
						serialnoStatus = false;
						quantityStatus = false;
					}
					if (productname.getGlobalBounds().contains(mousePos))
					{
						productcodeStatus = false;
						productnameStatus = true;
						productpriceStatus = false;
						serialnoStatus = false;
						quantityStatus = false;
					}
					if (productprice.getGlobalBounds().contains(mousePos))
					{
						productcodeStatus = false;
						productnameStatus = false;
						productpriceStatus = true;
						serialnoStatus = false;
						quantityStatus = false;
					}
					if (serialno.getGlobalBounds().contains(mousePos))
					{
						productcodeStatus = false;
						productnameStatus = false;
						productpriceStatus = false;
						serialnoStatus = true;
						quantityStatus = false;
					}
					if (quantity.getGlobalBounds().contains(mousePos))
					{
						productcodeStatus = false;
						productnameStatus = false;
						productpriceStatus = false;
						serialnoStatus = false;
						quantityStatus = true;
					}
					if (back.getGlobalBounds().contains(mousePos))
					{
						return -1;
					}
					if (enter.getGlobalBounds().contains(mousePos))
					{
						int code = stoi(productcodeTextString);
						int serialno = stoi(serialnoTextString);
						double price = stod(productpriceTextString);
						int quantity = stoi(quantityTextString);
						ADD_PRODUCT(category, code, productnameTextString, price, serialno, quantity);
						return -1;
					}
				}
			}
			if (productcodeStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (productcodeTextString.size() > 0)
					{
						productcodeTextString.erase(productcodeTextString.size() - 1, 1);
						productcodeText.setString(productcodeTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					productcodeStatus = false;
					productcodeText.setString(productcodeTextString);
				}
				else if (event.text.unicode < 128)
				{
					productcodeTextString += static_cast<char>(event.text.unicode);
					productcodeText.setString(productcodeTextString);
				}
			}
			if (productnameStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (productnameTextString.size() > 0)
					{
						productnameTextString.erase(productnameTextString.size() - 1, 1);
						productnameText.setString(productnameTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					productnameStatus = false;
					productnameText.setString(productnameTextString);
				}
				else if (event.text.unicode < 128)
				{
					productnameTextString += static_cast<char>(event.text.unicode);
					productnameText.setString(productnameTextString);
				}
			}
			if (productpriceStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (productpriceTextString.size() > 0)
					{
						productpriceTextString.erase(productpriceTextString.size() - 1, 1);
						productpriceText.setString(productpriceTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					productpriceStatus = false;
					productpriceText.setString(productpriceTextString);
				}
				else if (event.text.unicode < 128)
				{
					productpriceTextString += static_cast<char>(event.text.unicode);
					productpriceText.setString(productpriceTextString);
				}
			}
			if (serialnoStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (serialnoTextString.size() > 0)
					{
						serialnoTextString.erase(serialnoTextString.size() - 1, 1);
						serialnoText.setString(serialnoTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					serialnoStatus = false;
					serialnoText.setString(serialnoTextString);
				}
				else if (event.text.unicode < 128)
				{
					serialnoTextString += static_cast<char>(event.text.unicode);
					serialnoText.setString(serialnoTextString);
				}
			}
			if (quantityStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (quantityTextString.size() > 0)
					{
						quantityTextString.erase(quantityTextString.size() - 1, 1);
						quantityText.setString(quantityTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					quantityStatus = false;
					quantityText.setString(quantityTextString);
				}
				else if (event.text.unicode < 128)
				{
					quantityTextString += static_cast<char>(event.text.unicode);
					quantityText.setString(quantityTextString);
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (enter.getGlobalBounds().contains(mousePos)) {
			add.setFillColor(Color::Red);
		}
		else {
			add.setFillColor(Color::Black);
		}

		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(box);
		Window.draw(productcode);
		Window.draw(productname);
		Window.draw(productprice);
		Window.draw(serialno);
		Window.draw(quantity);
		Window.draw(back);
		Window.draw(enter);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(t3);
		Window.draw(code);
		Window.draw(name);
		Window.draw(price);
		Window.draw(serial);
		Window.draw(tax);
		Window.draw(add);
		Window.draw(productcodeText);
		Window.draw(productnameText);
		Window.draw(productpriceText);
		Window.draw(serialnoText);
		Window.draw(quantityText);

		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (productcodeStatus==true)
		{
			cursor.setPosition(productcodeText.getGlobalBounds().left + productcodeText.getGlobalBounds().width + 5.f, productcodeText.getPosition().y);
			Window.draw(cursor);
		}
		if (productnameStatus==true)
		{
			cursor.setPosition(productnameText.getGlobalBounds().left + productnameText.getGlobalBounds().width + 5.f, productnameText.getPosition().y);
			Window.draw(cursor);
		}
		if (productpriceStatus==true)
		{
			cursor.setPosition(productpriceText.getGlobalBounds().left + productpriceText.getGlobalBounds().width + 5.f, productpriceText.getPosition().y);
			Window.draw(cursor);
		}
		if (serialnoStatus==true)
		{
			cursor.setPosition(serialnoText.getGlobalBounds().left + serialnoText.getGlobalBounds().width + 5.f,serialnoText.getPosition().y);
			Window.draw(cursor);
		}
		if (quantityStatus==true)
		{
			cursor.setPosition(quantityText.getGlobalBounds().left + quantityText.getGlobalBounds().width + 5.f, quantityText.getPosition().y);
			Window.draw(cursor);
		}

		Window.display();
	}
}	

int DisplayItems(RenderWindow& Window, int category)
{
	int size = 0;
	Text* SERIAL = NULL;
	Text* CODE = NULL;
	Text* NAME = NULL;
	Text* PRICE = NULL;
	Text* QUANTITY = NULL;

	Font font2;
	font2.loadFromFile("Metro.ttf");

	if (category == 1)
	{
		clothing Display;
		clothing* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
;
	}
	if (category == 2)
	{
		electronics Display;
		electronics* ptr = Display.loadProducts();
		 size = ptr[0].getCount();

		 SERIAL = new Text[size];
		 CODE = new Text[size];
		 NAME = new Text[size];
		 PRICE = new Text[size];
		 QUANTITY = new Text[size];
		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	
	}
	if (category == 3)
	{
		grocery Display;
		grocery* ptr = Display.loadProducts();
		 size = ptr[0].getCount();

		 SERIAL = new Text[size];
		 CODE = new Text[size];
		 NAME = new Text[size];
		 PRICE = new Text[size];
		 QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
		
	}
	if (category == 4)
	{
		toys Display;
		toys* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
			
		}
		
	}
	if (category == 5)
	{
		cosmetics Display;
		cosmetics* ptr = Display.loadProducts();
		 size = ptr[0].getCount();

		 SERIAL = new Text[size];
		 CODE = new Text[size];
		 NAME = new Text[size];
		 PRICE = new Text[size];
		 QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
		
	}
	if (category == 6)
	{
		furniture Display;
		furniture* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
		
	}
	if (category == 7)
	{
		games Display;
		games* ptr = Display.loadProducts();
		 size = ptr[0].getCount();

		 SERIAL = new Text[size];
		 CODE = new Text[size];
		 NAME = new Text[size];
		 PRICE = new Text[size];
		 QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			cout << quantity << endl;
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
		
	}
	
	int Yincrement = 0;
	for (int i = 0; i < size; i++)
	{
		SERIAL[i].setPosition(20, 150 + Yincrement);
		CODE[i].setPosition(180, 150 + Yincrement);
		NAME[i].setPosition(380, 150 + Yincrement);
		PRICE[i].setPosition(620, 150 + Yincrement);
		QUANTITY[i].setPosition(780, 150 + Yincrement);
		SERIAL[i].setFont(font2);
		CODE[i].setFont(font2);
		NAME[i].setFont(font2);
		PRICE[i].setFont(font2);
		QUANTITY[i].setFont(font2);
		QUANTITY[i].setFillColor(Color::Black);
		SERIAL[i].setFillColor(Color::Black);
		CODE[i].setFillColor(Color::Black);
		NAME[i].setFillColor(Color::Black);
		PRICE[i].setFillColor(Color::Black);
		QUANTITY[i].setFillColor(Color::Black);
		SERIAL[i].setCharacterSize(18);
		CODE[i].setCharacterSize(18);
		NAME[i].setCharacterSize(18);
		PRICE[i].setCharacterSize(18);
		QUANTITY[i].setCharacterSize(18);

		Yincrement += 20;
	}

	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));
	RectangleShape box(Vector2f(200, 50));
	box.setPosition(730, 20);
	box.setFillColor(Color::White);

	Font font;
	font.loadFromFile("emmasophia.ttf");

	Text t1("DISPLAY ITEMS", font, 20);
	t1.setPosition(200, 40);
	t1.setFillColor(Color::White);

	Text t2("CATEGORY: ", font, 20);
	t2.setPosition(480, 40);
	t2.setFillColor(Color::White);
	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);

	Text t3;
	t3.setPosition(765, 35);
	t3.setFont(font);
	t3.setFillColor(Color::Black);
	t3.setCharacterSize(18);

	if (category == 1) {
		t3.setString("Clothing");
	}
	if (category == 2) {
		t3.setString("Electronics");
	}
	if (category == 3) {
		t3.setString("Grocery");
	}
	if (category == 4) {
		t3.setString("Toys");
	}
	if (category == 5) {
		t3.setString("Cosmetics");
	}
	if (category == 6) {
		t3.setString("Furniture");
	}
	if (category == 7) {
		t3.setString("Games");
	}

	Text serial("SERIAL NO", font2, 18);
	serial.setFillColor(Color::Black);
	serial.setPosition(20, 100);

	Text code("CODE", font2, 18);
	code.setFillColor(Color::Black);
	code.setPosition(180, 100);

	Text name("PRODUCT NAME", font2, 18);
	name.setFillColor(Color::Black);
	name.setPosition(380, 100);

	Text price("PRICE", font2, 18);
	price.setFillColor(Color::Black);
	price.setPosition(640, 100);

	Text quantity("QUANTITY", font2, 18);
	quantity.setFillColor(Color::Black);
	quantity.setPosition(780, 100);

	RectangleShape bar(Vector2f(1200, 5));
	bar.setFillColor(Color::Black);
	bar.setPosition(0, 130);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(box);
		Window.draw(back);
		Window.draw(bar);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(t3);
		Window.draw(serial);
		Window.draw(code);
		Window.draw(name);
		Window.draw(price);
		Window.draw(quantity);
		for (int i = 0; i < size; i++)
		{
			Window.draw(SERIAL[i]);
			Window.draw(NAME[i]);
			Window.draw(CODE[i]);
			Window.draw(PRICE[i]);
			Window.draw(QUANTITY[i]);
		}
		Window.display();
	}


}

int DeleteItem(RenderWindow& Window, int category)
{
	int size = 0;
	Text* SERIAL = NULL;
	Text* CODE = NULL;
	Text* NAME = NULL;
	Text* PRICE = NULL;
	Text* QUANTITY = NULL;

	Font font2;
	font2.loadFromFile("Metro.ttf");

	if (category == 1)
	{
		clothing Display;
		clothing* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);

			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	}
	if (category == 2)
	{
		electronics Display;
		electronics* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];
		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	}
	if (category == 3)
	{
		grocery Display;
		grocery* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}

	}
	if (category == 4)
	{
		toys Display;
		toys* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);

		}
	}
	if (category == 5)
	{
		cosmetics Display;
		cosmetics* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	}
	if (category == 6)
	{
		furniture Display;
		furniture* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	}
	if (category == 7)
	{
		games Display;
		games* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		SERIAL = new Text[size];
		CODE = new Text[size];
		NAME = new Text[size];
		PRICE = new Text[size];
		QUANTITY = new Text[size];

		for (int i = 0; i < size; i++)
		{
			int serial = ptr[i].getSerialNo();
			string serialStr = to_string(serial);
			int code = ptr[i].getProductCode();
			string codeStr = to_string(code);
			int quantity = ptr[i].getProductQuantity();
			cout << quantity << endl;
			string quantityStr = to_string(quantity);
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);

			SERIAL[i].setString(serialStr);
			CODE[i].setString(codeStr);
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			QUANTITY[i].setString(quantityStr);
		}
	}

	int Yincrement = 0;
	for (int i = 0; i < size; i++)
	{
		SERIAL[i].setPosition(20, 150 + Yincrement);
		CODE[i].setPosition(180, 150 + Yincrement);
		NAME[i].setPosition(380, 150 + Yincrement);
		PRICE[i].setPosition(620, 150 + Yincrement);
		QUANTITY[i].setPosition(780, 150 + Yincrement);
		SERIAL[i].setFont(font2);
		CODE[i].setFont(font2);
		NAME[i].setFont(font2);
		PRICE[i].setFont(font2);
		QUANTITY[i].setFont(font2);
		QUANTITY[i].setFillColor(Color::Black);
		SERIAL[i].setFillColor(Color::Black);
		CODE[i].setFillColor(Color::Black);
		NAME[i].setFillColor(Color::Black);
		PRICE[i].setFillColor(Color::Black);
		QUANTITY[i].setFillColor(Color::Black);
		SERIAL[i].setCharacterSize(18);
		CODE[i].setCharacterSize(18);
		NAME[i].setCharacterSize(18);
		PRICE[i].setCharacterSize(18);
		QUANTITY[i].setCharacterSize(18);

		Yincrement += 20;
	}

	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));

	Font font;
	font.loadFromFile("emmasophia.ttf");

	Text t1("DELETE ITEM", font, 20);
	t1.setPosition(200, 40);
	t1.setFillColor(Color::White);

	Text t2("ENTER NUM: ", font, 14);
	t2.setPosition(480, 40);
	t2.setFillColor(Color::White);
	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);

	Text serial("SERIAL NO", font2, 18);
	serial.setFillColor(Color::Black);
	serial.setPosition(20, 100);

	Text code("CODE", font2, 18);
	code.setFillColor(Color::Black);
	code.setPosition(180, 100);

	Text name("PRODUCT NAME", font2, 18);
	name.setFillColor(Color::Black);
	name.setPosition(380, 100);

	Text price("PRICE", font2, 18);
	price.setFillColor(Color::Black);
	price.setPosition(640, 100);

	Text quantity("QUANTITY", font2, 18);
	quantity.setFillColor(Color::Black);
	quantity.setPosition(780, 100);

	RectangleShape bar(Vector2f(1200, 5));
	bar.setFillColor(Color::Black);
	bar.setPosition(0, 130);

	RectangleShape number(Vector2f(180, 40));
	number.setFillColor(Color::White);
	number.setOutlineColor(Color::Black);
	number.setOutlineThickness(4);
	number.setPosition(800, 30);
	bool Status = false;
	string TextString = "";
	Text Text("", font2, 20);
	Text.setFillColor(Color::Black);
	Text.setPosition(number.getPosition().x + 5.f, number.getPosition().y + 5.f);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (number.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					Status = true;
				}
			}
			if (Status == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (TextString.size() > 0)
					{
						TextString.erase(TextString.size() - 1, 1);
						Text.setString(TextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					Status = false;
					int choice = stoi(TextString);
					if (choice > 0 && choice <= size)
					{
						DELETE_PRODUCT(category, choice);
						return -1;
					}
					Text.setString(TextString);
				}
				else if (event.text.unicode < 128)
				{
					TextString += static_cast<char>(event.text.unicode);
					Text.setString(TextString);
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(back);
		Window.draw(bar);
		Window.draw(number);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(serial);
		Window.draw(code);
		Window.draw(name);
		Window.draw(price);
		Window.draw(Text);
		Window.draw(quantity);
		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (Status == true)
		{
			cursor.setPosition(Text.getGlobalBounds().left + Text.getGlobalBounds().width + 5.f, Text.getPosition().y);
			Window.draw(cursor);
		}
		for (int i = 0; i < size; i++)
		{
			Window.draw(SERIAL[i]);
			Window.draw(NAME[i]);
			Window.draw(CODE[i]);
			Window.draw(PRICE[i]);
			Window.draw(QUANTITY[i]);
		}
		Window.display();
	}
}

int EmployeeMenu(RenderWindow& Window)
{
	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));

	Font font;
	font.loadFromFile("emmasophia.ttf");

	Text t1("EMPLOYEE MENU", font, 20);
	t1.setPosition(350, 40);
	t1.setFillColor(Color::White);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);

	RectangleShape addemployee(Vector2f(250, 80));
	addemployee.setFillColor(Color::White);
	addemployee.setPosition(60, 250);
	addemployee.setOutlineColor(Color::Black);
	addemployee.setOutlineThickness(8);
	RectangleShape displayemps(Vector2f(250, 80));
	displayemps.setFillColor(Color::White);
	displayemps.setPosition(360, 250);
	displayemps.setOutlineColor(Color::Black);
	displayemps.setOutlineThickness(8);
	RectangleShape deleteemp(Vector2f(250, 80));
	deleteemp.setFillColor(Color::White);
	deleteemp.setPosition(660, 250);
	deleteemp.setOutlineColor(Color::Black);
	deleteemp.setOutlineThickness(8);

	Text add("ADD EMPLOYEE", font, 12);
	add.setFillColor(Color::Black);
	add.setPosition(95, 285);
	Text display("DISPLAY EMPLOYEES", font, 12);
	display.setFillColor(Color::Black);
	display.setPosition(370, 285);
	Text del("DELETE EMPLOYEE", font, 12);
	del.setFillColor(Color::Black);
	del.setPosition(678, 285);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (addemployee.getGlobalBounds().contains(mousePos))
				{
					return 1;
				}
				if (deleteemp.getGlobalBounds().contains(mousePos))
				{
					return 3;
				}
				if (displayemps.getGlobalBounds().contains(mousePos))
				{
					return 2;
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (addemployee.getGlobalBounds().contains(mousePos)) {
			addemployee.setOutlineColor(Color::Red);
		}
		else {
			addemployee.setOutlineColor(Color::Black);
		}
		if (deleteemp.getGlobalBounds().contains(mousePos)) {
			deleteemp.setOutlineColor(Color::Red);
		}
		else {
			deleteemp.setOutlineColor(Color::Black);
		}
		if (displayemps.getGlobalBounds().contains(mousePos)) {
			displayemps.setOutlineColor(Color::Red);
		}
		else {
			displayemps.setOutlineColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(addemployee);
		Window.draw(deleteemp);
		Window.draw(displayemps);
		Window.draw(back);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(add);
		Window.draw(display);
		Window.draw(del);
		Window.display();
	}


}

int AddEmployee(RenderWindow& Window)
{
	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));
	Font font;
	font.loadFromFile("emmasophia.ttf");
	Font font2;
	font2.loadFromFile("Dosis.ttf");
	Text t1("ADD EMPLOYEE", font, 20);
	t1.setPosition(350, 40);
	t1.setFillColor(Color::White);

	Text add("ADD EMPLOYEE", font, 12);
	add.setFillColor(Color::Black);
	add.setPosition(405, 525);
	RectangleShape enter(Vector2f(210, 55));
	enter.setFillColor(Color::White);
	enter.setOutlineColor(Color::Black);
	enter.setOutlineThickness(6);
	enter.setPosition(390, 500);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(180, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(188, 40);
	tx1.setFillColor(Color::Black);

	Text name("Employee Name: ", font2, 24);
	name.setFillColor(Color::Black);
	name.setPosition(30, 190);
	RectangleShape employeename(Vector2f(180, 40));
	employeename.setFillColor(Color::White);
	employeename.setPosition(250, 185);
	employeename.setOutlineThickness(4);
	employeename.setOutlineColor(Color::Black);

	Text ID("Employee ID: ", font2, 24);
	ID.setFillColor(Color::Black);
	ID.setPosition(30, 290);
	RectangleShape empID(Vector2f(180, 40));
	empID.setFillColor(Color::White);
	empID.setPosition(250, 285);
	empID.setOutlineColor(Color::Black);
	empID.setOutlineThickness(4);

	Text cate("Category Name: ", font2, 24);
	cate.setFillColor(Color::Black);
	cate.setPosition(495, 290);
	RectangleShape cate_n(Vector2f(180, 40));
	cate_n.setFillColor(Color::White);
	cate_n.setPosition(730, 290);
	cate_n.setOutlineColor(Color::Black);
	cate_n.setOutlineThickness(4);

	Text salary("Employee Salary: ", font2, 24);
	salary.setFillColor(Color::Black);
	salary.setPosition(490, 190);
	RectangleShape empsal(Vector2f(180, 40));
	empsal.setFillColor(Color::White);
	empsal.setOutlineColor(Color::Black);
	empsal.setOutlineThickness(4);
	empsal.setPosition(730, 190);

	bool empnameStatus = false;
	string empnameTextString = "";
	Text empnameText("", font2, 20);
	empnameText.setFillColor(Color::Black);
	empnameText.setPosition(employeename.getPosition().x + 5.f, employeename.getPosition().y + 5.f);

	bool empidStatus = false;
	string empidTextString = "";
	Text empidText("", font2, 20);
	empidText.setFillColor(Color::Black);
	empidText.setPosition(empID.getPosition().x + 5.f, empID.getPosition().y + 5.f);

	bool empcateStatus = false;
	string empcateTextString = "";
	Text empcateText("", font2, 20);
	empcateText.setFillColor(Color::Black);
	empcateText.setPosition(cate_n.getPosition().x + 5.f, cate_n.getPosition().y + 5.f);

	bool empsalStatus = false;
	string empsalTextString = "";
	Text empsalText("", font2, 20);
	empsalText.setFillColor(Color::Black);
	empsalText.setPosition(empsal.getPosition().x + 5.f, empsal.getPosition().y + 5.f);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (back.getGlobalBounds().contains(mousePos))
					{
						return -1;
					}
					if (employeename.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						empnameStatus = true;
						empidStatus = false;
						empsalStatus = false;
						empcateStatus = false;
					}
					if (empID.getGlobalBounds().contains(mousePos))
					{
						empnameStatus = false;
						empidStatus = true;
						empsalStatus = false;
						empcateStatus = false;
					}
					if (cate_n.getGlobalBounds().contains(mousePos))
					{
						empnameStatus = false;
						empidStatus = false;
						empsalStatus = false;
						empcateStatus = true;
					}
					if (empsal.getGlobalBounds().contains(mousePos))
					{
						empnameStatus = false;
						empidStatus = false;
						empsalStatus = true;
						empcateStatus = false;
					}
					if (enter.getGlobalBounds().contains(mousePos))
					{
						int emp_id = stoi(empidTextString);
						double emp_sal = stod(empsalTextString);
						ADD_EMPLOYEE(empnameTextString, empcateTextString, emp_id, emp_sal);
						return -1;
					}
				}
			}
			if (empnameStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (empnameTextString.size() > 0)
					{
						empnameTextString.erase(empnameTextString.size() - 1, 1);
						empnameText.setString(empnameTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					empnameStatus = false;
					empnameText.setString(empnameTextString);
				}
				else if (event.text.unicode < 128)
				{
					empnameTextString += static_cast<char>(event.text.unicode);
					empnameText.setString(empnameTextString);
				}
			}
			if (empidStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (empidTextString.size() > 0)
					{
						empidTextString.erase(empidTextString.size() - 1, 1);
						empidText.setString(empidTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					empidStatus = false;
					empidText.setString(empidTextString);
				}
				else if (event.text.unicode < 128)
				{
					empidTextString += static_cast<char>(event.text.unicode);
					empidText.setString(empidTextString);
				}
			}
			if (empcateStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (empcateTextString.size() > 0)
					{
						empcateTextString.erase(empcateTextString.size() - 1, 1);
						empcateText.setString(empcateTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					empcateStatus = false;
					empcateText.setString(empcateTextString);
				}
				else if (event.text.unicode < 128)
				{
					empcateTextString += static_cast<char>(event.text.unicode);
					empcateText.setString(empcateTextString);
				}
			}
			if (empsalStatus == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (empsalTextString.size() > 0)
					{
						empsalTextString.erase(empsalTextString.size() - 1, 1);
						empsalText.setString(empsalTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					empsalStatus = false;
					empsalText.setString(empsalTextString);
				}
				else if (event.text.unicode < 128)
				{
					empsalTextString += static_cast<char>(event.text.unicode);
					empsalText.setString(empsalTextString);
				}
			}
		}

		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(back);
		Window.draw(employeename);
		Window.draw(empID);
		Window.draw(empsal);
		Window.draw(cate_n);
		Window.draw(enter);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(add);
		Window.draw(name);
		Window.draw(ID);
		Window.draw(cate);
		Window.draw(salary);
		Window.draw(empnameText);
		Window.draw(empidText);
		Window.draw(empsalText);
		Window.draw(empcateText);
		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (empnameStatus == true)
		{
			cursor.setPosition(empnameText.getGlobalBounds().left + empnameText.getGlobalBounds().width + 5.f, empnameText.getPosition().y);
			Window.draw(cursor);
		}
		if (empsalStatus == true)
		{
			cursor.setPosition(empsalText.getGlobalBounds().left + empsalText.getGlobalBounds().width + 5.f, empsalText.getPosition().y);
			Window.draw(cursor);
		}
		if (empidStatus == true)
		{
			cursor.setPosition(empidText.getGlobalBounds().left + empidText.getGlobalBounds().width + 5.f, empidText.getPosition().y);
			Window.draw(cursor);
		}
		if (empcateStatus == true)
		{
			cursor.setPosition(empcateText.getGlobalBounds().left + empcateText.getGlobalBounds().width + 5.f, empcateText.getPosition().y);
			Window.draw(cursor);
		}

		Window.display();
	}
}

int DisplayEmployee(RenderWindow& Window)
{
	Text* NAME = NULL;
	Text* CATE = NULL;
	Text* SAL = NULL;
	Text* ID = NULL;

	Font font2;
	font2.loadFromFile("Dosis.ttf");

	Employee display;
	Employee* DISPLAY = display.loadEmployees();

	int size = display.empCount();

	NAME = new Text[size];
	CATE = new Text[size];
	SAL = new Text[size];
	ID = new Text[size];

	for (int i = 0; i < size; i++)
	{
		int id = DISPLAY[i].getId();
		double salary = DISPLAY[i].getSal();
		string name = DISPLAY[i].getName();
		string cate = DISPLAY[i].getCate();

		string ID_1 = to_string(id);
		string SALARY = to_string(salary);

		NAME[i].setString(name);
		CATE[i].setString(cate);
		SAL[i].setString(SALARY);
		ID[i].setString(ID_1);
	}

	int Yincrement = 0;
	for (int i = 0; i < size; i++)
	{
		NAME[i].setPosition(20, 150 + Yincrement);
		ID[i].setPosition(180, 150 + Yincrement);
		SAL[i].setPosition(380, 150 + Yincrement);
		CATE[i].setPosition(620, 150 + Yincrement);
	
		NAME[i].setFont(font2);
		CATE[i].setFont(font2);
		ID[i].setFont(font2);
		SAL[i].setFont(font2);
		
		NAME[i].setFillColor(Color::Black);
		CATE[i].setFillColor(Color::Black);
		ID[i].setFillColor(Color::Black);
		SAL[i].setFillColor(Color::Black);

		NAME[i].setCharacterSize(18);
		CATE[i].setCharacterSize(18);
		ID[i].setCharacterSize(18);
		SAL[i].setCharacterSize(18);

		Yincrement += 20;
	}


	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));
	Font font;
	font.loadFromFile("emmasophia.ttf");
	Text t1("DISPLAY EMPLOYEE", font, 20);
	t1.setPosition(350, 40);
	t1.setFillColor(Color::White);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(180, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(188, 40);
	tx1.setFillColor(Color::Black);

	Text empnames("EMP NAMES", font2, 18);
	empnames.setFillColor(Color::Black);
	empnames.setPosition(20, 100);

	Text empids("EMP ID", font2, 18);
	empids.setFillColor(Color::Black);
	empids.setPosition(180, 100);

	Text empcate("EMP SALARY", font2, 18);
	empcate.setFillColor(Color::Black);
	empcate.setPosition(380, 100);

	Text empsals("EMP CATEGORY", font2, 18);
	empsals.setFillColor(Color::Black);
	empsals.setPosition(640, 100);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(back);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(empnames);
		Window.draw(empids);
		Window.draw(empcate);
		Window.draw(empsals);
		for (int i = 0; i < size; i++)
		{
			Window.draw(NAME[i]);
			Window.draw(ID[i]);
			Window.draw(CATE[i]);
			Window.draw(SAL[i]);
		}
		Window.display();
	}

	delete DISPLAY;
	DISPLAY = NULL;
}

int DeleteEmployee(RenderWindow& Window)
{
	Text* NAME = NULL;
	Text* CATE = NULL;
	Text* SAL = NULL;
	Text* ID = NULL;

	Font font2;
	font2.loadFromFile("Dosis.ttf");

	Employee display;
	Employee* DISPLAY = display.loadEmployees();

	int size = display.empCount();

	NAME = new Text[size];
	CATE = new Text[size];
	SAL = new Text[size];
	ID = new Text[size];

	for (int i = 0; i < size; i++)
	{
		int id = DISPLAY[i].getId();
		double salary = DISPLAY[i].getSal();
		string name = DISPLAY[i].getName();
		string cate = DISPLAY[i].getCate();

		string ID_1 = to_string(id);
		string SALARY = to_string(salary);

		NAME[i].setString(name);
		CATE[i].setString(cate);
		SAL[i].setString(SALARY);
		ID[i].setString(ID_1);
	}

	int Yincrement = 0;
	for (int i = 0; i < size; i++)
	{
		NAME[i].setPosition(20, 150 + Yincrement);
		ID[i].setPosition(180, 150 + Yincrement);
		SAL[i].setPosition(380, 150 + Yincrement);
		CATE[i].setPosition(620, 150 + Yincrement);

		NAME[i].setFont(font2);
		CATE[i].setFont(font2);
		ID[i].setFont(font2);
		SAL[i].setFont(font2);

		NAME[i].setFillColor(Color::Black);
		CATE[i].setFillColor(Color::Black);
		ID[i].setFillColor(Color::Black);
		SAL[i].setFillColor(Color::Black);

		NAME[i].setCharacterSize(18);
		CATE[i].setCharacterSize(18);
		ID[i].setCharacterSize(18);
		SAL[i].setCharacterSize(18);

		Yincrement += 20;
	}


	RectangleShape topbar(Vector2f(1200, 90));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));
	Font font;
	font.loadFromFile("emmasophia.ttf");
	Text t1("DELETE EMPLOYEE", font, 20);
	t1.setPosition(220, 40);
	t1.setFillColor(Color::White);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);

	Text empnames("EMP NAMES", font2, 18);
	empnames.setFillColor(Color::Black);
	empnames.setPosition(20, 100);

	Text empids("EMP ID", font2, 18);
	empids.setFillColor(Color::Black);
	empids.setPosition(180, 100);

	Text empcate("EMP SALARY", font2, 18);
	empcate.setFillColor(Color::Black);
	empcate.setPosition(380, 100);

	Text empsals("EMP CATEGORY", font2, 18);
	empsals.setFillColor(Color::Black);
	empsals.setPosition(640, 100);

	Text enternumber("ENTER NUMBER OF", font2, 18);
	enternumber.setFillColor(Color::White);
	enternumber.setPosition(580, 30);
	Text enternumber2("EMP TO DELETE:", font2, 18);
	enternumber2.setFillColor(Color::White);
	enternumber2.setPosition(580, 50);

	RectangleShape number(Vector2f(180, 40));
	number.setFillColor(Color::White);
	number.setOutlineColor(Color::Black);
	number.setOutlineThickness(4);
	number.setPosition(800, 30);
	bool Status = false;
	string TextString = "";
	Text Text("", font2, 20);
	Text.setFillColor(Color::Black);
	Text.setPosition(number.getPosition().x + 5.f, number.getPosition().y + 5.f);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (number.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					Status = true;
				}
			}
			if (Status == true && event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (TextString.size() > 0)
					{
						TextString.erase(TextString.size() - 1, 1);
						Text.setString(TextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					Status = false;
					int choice = stoi(TextString);
					if (choice > 0 && choice <= size)
					{
						display.deleteEmployee(choice);
						return -1;
					}
					Text.setString(TextString);
				}
				else if (event.text.unicode < 128)
				{
					TextString += static_cast<char>(event.text.unicode);
					Text.setString(TextString);
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(back);
		Window.draw(number);
		Window.draw(tx1);
		Window.draw(t1);
		Window.draw(enternumber);
		Window.draw(enternumber2);
		Window.draw(empnames);
		Window.draw(empids);
		Window.draw(empcate);
		Window.draw(empsals);
		Window.draw(Text);
		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (Status == true)
		{
			cursor.setPosition(Text.getGlobalBounds().left + Text.getGlobalBounds().width + 5.f, Text.getPosition().y);
			Window.draw(cursor);
		}
		for (int i = 0; i < size; i++)
		{
			Window.draw(NAME[i]);
			Window.draw(ID[i]);
			Window.draw(CATE[i]);
			Window.draw(SAL[i]);
		}
		Window.display();
	}
}

int CustomerMenu(RenderWindow& Window, int& category,Customer& customer)
{
	RectangleShape topbar(Vector2f(1200, 80));
	topbar.setPosition(0, 0);
	topbar.setFillColor(Color::Black);
	RectangleShape bottombox(Vector2f(1200, 510));
	bottombox.setPosition(0, 90);
	bottombox.setFillColor(Color(255, 253, 208, 128));

	Font font, font2;
	font2.loadFromFile("Dosis.ttf");
	font.loadFromFile("emmasophia.ttf");

	Text t("CUSTOMER MENU", font, 20);
	t.setPosition(350, 40);
	t.setFillColor(Color::White);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(26, 25);
	Text tx1("<-GoBack", font, 15);
	tx1.setPosition(34, 40);
	tx1.setFillColor(Color::Black);

	RectangleShape b1(Vector2f(170, 50));
	b1.setFillColor(Color::White);
	b1.setPosition(100, 150);
	b1.setOutlineThickness(6);
	b1.setOutlineColor(Color::Black);
	RectangleShape b2(Vector2f(170, 50));
	b2.setFillColor(Color::White);
	b2.setPosition(400, 150);
	b2.setOutlineThickness(6);
	b2.setOutlineColor(Color::Black);
	RectangleShape b3(Vector2f(170, 50));
	b3.setFillColor(Color::White);
	b3.setPosition(700, 150);
	b3.setOutlineThickness(6);
	b3.setOutlineColor(Color::Black);
	RectangleShape b4(Vector2f(170, 50));
	b4.setFillColor(Color::White);
	b4.setPosition(100, 250);
	b4.setOutlineThickness(6);
	b4.setOutlineColor(Color::Black);
	RectangleShape b5(Vector2f(170, 50));
	b5.setFillColor(Color::White);
	b5.setPosition(400, 250);
	b5.setOutlineThickness(6);
	b5.setOutlineColor(Color::Black);
	RectangleShape b6(Vector2f(170, 50));
	b6.setFillColor(Color::White);
	b6.setPosition(700, 250);
	b6.setOutlineThickness(6);
	b6.setOutlineColor(Color::Black);
	RectangleShape b7(Vector2f(170, 50));
	b7.setFillColor(Color::White);
	b7.setPosition(400, 350);
	b7.setOutlineThickness(6);
	b7.setOutlineColor(Color::Black);

	Text t1("Clothing", font2, 20);
	t1.setPosition(130, 160);
	t1.setFillColor(Color::Black);
	Text t2("Electronics", font2, 20);
	t2.setPosition(430, 160);
	t2.setFillColor(Color::Black);
	Text t3("Grocery", font2, 20);
	t3.setPosition(730, 160);
	t3.setFillColor(Color::Black);
	Text t4("Toys", font2, 20);
	t4.setPosition(130, 260);
	t4.setFillColor(Color::Black);
	Text t5("Cosmetics", font2, 20);
	t5.setPosition(430, 260);
	t5.setFillColor(Color::Black);
	Text t6("Furniture", font2, 20);
	t6.setPosition(730, 260);
	t6.setFillColor(Color::Black);
	Text t7("Games", font2, 20);
	t7.setPosition(430, 360);
	t7.setFillColor(Color::Black);

	RectangleShape cart(Vector2f(150, 50));
	cart.setFillColor(Color::White);
	cart.setPosition(800, 500);
	cart.setOutlineThickness(4);
	cart.setOutlineColor(Color::Black);

	Text confirmcart("CONFIRM CART", font, 10);
	confirmcart.setFillColor(Color::Black);
	confirmcart.setPosition(803, 520);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (cart.getGlobalBounds().contains(mousePos))
				{
					return -2;
				}
				if (b1.getGlobalBounds().contains(mousePos))
				{
					category = 1;
					return 1;
				}
				if (b2.getGlobalBounds().contains(mousePos))
				{
					category = 2;
					return 2;
				}
				if (b3.getGlobalBounds().contains(mousePos))
				{
					category = 3;
					return 3;
				}
				if (b4.getGlobalBounds().contains(mousePos))
				{
					category = 4;
					return 4;
				}
				if (b5.getGlobalBounds().contains(mousePos))
				{
					category = 5;
					return 5;
				}
				if (b6.getGlobalBounds().contains(mousePos))
				{
					category = 6;
					return 6;
				}
				if (b7.getGlobalBounds().contains(mousePos))
				{
					category = 7;
					return 7;
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (b1.getGlobalBounds().contains(mousePos)) {
			b1.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b1.setOutlineColor(Color::Black);
		}
		if (b2.getGlobalBounds().contains(mousePos)) {
			b2.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b2.setOutlineColor(Color::Black);
		}
		if (b3.getGlobalBounds().contains(mousePos)) {
			b3.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b3.setOutlineColor(Color::Black);
		}
		if (b4.getGlobalBounds().contains(mousePos)) {
			b4.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b4.setOutlineColor(Color::Black);
		}
		if (b5.getGlobalBounds().contains(mousePos)) {
			b5.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b5.setOutlineColor(Color::Black);
		}
		if (b6.getGlobalBounds().contains(mousePos)) {
			b6.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b6.setOutlineColor(Color::Black);
		}
		if (b7.getGlobalBounds().contains(mousePos)) {
			b7.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			b7.setOutlineColor(Color::Black);
		}
		if (cart.getGlobalBounds().contains(mousePos)) {
			cart.setOutlineColor(Color(255, 253, 208, 128));
		}
		else {
			cart.setOutlineColor(Color::Black);
		}

		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombox);
		Window.draw(back);
		Window.draw(cart);
		Window.draw(b1);
		Window.draw(b2);
		Window.draw(b3);
		Window.draw(b4);
		Window.draw(b5);
		Window.draw(b6);
		Window.draw(b7);
		Window.draw(tx1);
		Window.draw(t);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(t3);
		Window.draw(t4);
		Window.draw(t5);
		Window.draw(t6);
		Window.draw(t7);
		Window.draw(confirmcart);
		Window.display();
	}
}

int CustomerDisplay(RenderWindow& Window, int category,Customer& customer)
{
	int size = 0;
	Text* NAME = NULL;
	Text* PRICE = NULL;
	Text* SERIAL = NULL;

	string* name = NULL;
	double* prices = NULL;
	int* quantities = NULL;

	Font font2;
	font2.loadFromFile("Metro.ttf");

	if (category == 1)
	{
		clothing Display;
		clothing* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);

			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();

			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);

		}
	}
	if (category == 2)
	{
		electronics Display;
		electronics* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
		}
	}
	if (category == 3)
	{
		grocery Display;
		grocery* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
		}
	}
	if (category == 4)
	{
		toys Display;
		toys* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
		}
	}
	if (category == 5)
	{
		cosmetics Display;
		cosmetics* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
		}
	}
	if (category == 6)
	{
		furniture Display;
		furniture* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
		}
	}
	if (category == 7)
	{
		games Display;
		games* ptr = Display.loadProducts();
		size = ptr[0].getCount();

		NAME = new Text[size];
		PRICE = new Text[size];
		SERIAL = new Text[size];

		name = new string[size];
		prices = new double[size];
		quantities = new int[size];

		for (int i = 0; i < size; i++)
		{
			double price = ptr[i].getPrice();
			string priceStr = to_string(price);
			name[i] = ptr[i].getName();
			prices[i] = ptr[i].getPrice();
			quantities[i] = ptr[i].getProductQuantity();
			NAME[i].setString(ptr[i].getName());
			PRICE[i].setString(priceStr);
			string serial = to_string(i + 1);
			serial += " :";
			SERIAL[i].setString(serial);
		}
	}

	int Yincrement = 0;
	for (int i = 0; i < size; i++)
	{
		SERIAL[i].setPosition(40, 130 + Yincrement);
		NAME[i].setPosition(100, 130 + Yincrement);
		PRICE[i].setPosition(350, 130 + Yincrement);

		NAME[i].setFont(font2);
		PRICE[i].setFont(font2);
		SERIAL[i].setFont(font2);
	
		NAME[i].setFillColor(Color::Black);
		PRICE[i].setFillColor(Color::Black);
		SERIAL[i].setFillColor(Color::Black);
	
		NAME[i].setCharacterSize(18);
		PRICE[i].setCharacterSize(18);
		SERIAL[i].setCharacterSize(20);

		Yincrement += 20;
	}

	RectangleShape topbar(Vector2f(1200, 92));
	topbar.setFillColor(Color(200, 255, 0));
	topbar.setPosition(0, 0);
	RectangleShape bottombar(Vector2f(1200, 500));
	bottombar.setFillColor(Color(64, 64, 64));
	bottombar.setPosition(0, 100);

	Font font, font3;
	font.loadFromFile("Dosis.ttf");
	font3.loadFromFile("emmasophia.ttf");

	Text shop("Shopping Menu", font, 40);
	shop.setFillColor(Color::Black);
	shop.setPosition(330, 20);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(180, 25);
	Text tx1("<-GoBack", font3, 15);
	tx1.setPosition(188, 40);
	tx1.setFillColor(Color::Black);

	RectangleShape menu(Vector2f(600, 450));
	menu.setFillColor(Color::White);
	menu.setOutlineColor(Color::Black);
	menu.setOutlineThickness(8);
	menu.setPosition(20, 120);

	Text num("ENTER NUMBER: ", font3, 12);
	num.setFillColor(Color::Black);
	num.setPosition(694, 170);
	RectangleShape num_b(Vector2f(180, 40));
	num_b.setFillColor(Color::White);
	num_b.setPosition(700, 200);
	num_b.setOutlineColor(Color::Black);
	num_b.setOutlineThickness(4);

	Text quan("ENTER QUANTITY: ", font3, 12);
	quan.setFillColor(Color::Black);
	quan.setPosition(694, 300);
	RectangleShape quan_b(Vector2f(180, 40));
	quan_b.setFillColor(Color::White);
	quan_b.setOutlineColor(Color::Black);
	quan_b.setOutlineThickness(4);
	quan_b.setPosition(700, 330);

	bool numStatus = false;
	string numTextString = "";
	Text numText("", font2, 20);
	numText.setFillColor(Color::Black);
	numText.setPosition(num_b.getPosition().x + 5.f, num_b.getPosition().y + 5.f);

	bool quanStatus = false;
	string quanTextString = "";
	Text quanText("", font2, 20);
	quanText.setFillColor(Color::Black);
	quanText.setPosition(quan_b.getPosition().x + 5.f, quan_b.getPosition().y + 5.f);

	RectangleShape confirm(Vector2f(200, 50));
	confirm.setFillColor(Color::White);
	confirm.setPosition(700, 400);
	confirm.setOutlineColor(Color::Black);
	confirm.setOutlineThickness(6);
	Text confirm_t("ADD TO CART", font3, 12);
	confirm_t.setFillColor(Color::Black);
	confirm_t.setPosition(710, 420);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (confirm.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					int choice = stoi(numTextString);
					int quantity = stoi(quanTextString);

					if ((choice > 0 && choice <= size) && (quantity > 0 && quantity <= quantities[choice-1]))
					{
						double p = quantity * prices[choice - 1];
						customer.setAmount(customer.getAmount() + p);
						customer.addtocart(name[choice - 1], prices[choice - 1], quantity);
						return -1;
					}
				}
				if (num_b.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					numStatus = true;
					quanStatus = false;
				}
				if (quan_b.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					numStatus = false;
					quanStatus = true;
				}
			}
			if (numStatus == true && event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (numTextString.size() > 0)
					{
						numTextString.erase(numTextString.size() - 1, 1);
						numText.setString(numTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					numStatus = false;
					numText.setString(numTextString);
				}
				else if (event.text.unicode < 128)
				{
					numTextString += static_cast<char>(event.text.unicode);
					numText.setString(numTextString);
				}
			}
			if (quanStatus == true && event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (quanTextString.size() > 0)
					{
						quanTextString.erase(quanTextString.size() - 1, 1);
						quanText.setString(quanTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					quanStatus = false;
					quanText.setString(quanTextString);
				}
				else if (event.text.unicode < 128)
				{
					quanTextString += static_cast<char>(event.text.unicode);
					quanText.setString(quanTextString);
				}
			}
		}

		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (confirm.getGlobalBounds().contains(mousePos)) {
			confirm.setOutlineColor(Color::Red);
		}
		else {
			confirm.setOutlineColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombar);
		Window.draw(back);
		Window.draw(menu);
		Window.draw(num_b);
		Window.draw(quan_b);
		Window.draw(confirm);
		Window.draw(shop);
		Window.draw(tx1);
		Window.draw(num);
		Window.draw(quan);
		Window.draw(numText);
		Window.draw(quanText);
		Window.draw(confirm_t);
		for (int i = 0; i < size; i++)
		{
			Window.draw(SERIAL[i]);
			Window.draw(NAME[i]);
			Window.draw(PRICE[i]);
		}
		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (numStatus == true)
		{
			cursor.setPosition(numText.getGlobalBounds().left + numText.getGlobalBounds().width + 5.f, numText.getPosition().y);
			Window.draw(cursor);
		}
		if (quanStatus == true)
		{
			cursor.setPosition(quanText.getGlobalBounds().left + quanText.getGlobalBounds().width + 5.f, quanText.getPosition().y);
			Window.draw(cursor);
		}
		Window.display();
	}
}

int confirmCart(RenderWindow& Window, Customer& customer)
{
	RectangleShape topbar(Vector2f(1200, 92));
	topbar.setFillColor(Color(200, 255, 0));
	topbar.setPosition(0, 0);
	RectangleShape bottombar(Vector2f(1200, 500));
	bottombar.setFillColor(Color(64, 64, 64));
	bottombar.setPosition(0, 100);
	Font font, font3;
	font.loadFromFile("Dosis.ttf");
	font3.loadFromFile("emmasophia.ttf");

	Text shop("ENTER DATA", font, 40);
	shop.setFillColor(Color::Black);
	shop.setPosition(330, 20);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(800, 25);
	Text tx1("<-GoBack", font3, 15);
	tx1.setPosition(808, 40);
	tx1.setFillColor(Color::Black);


	Text name("ENTER CUSTOMER NAME: ", font3, 12);
	name.setFillColor(Color::Black);
	name.setPosition(200, 220);
	RectangleShape name_b(Vector2f(180, 40));
	name_b.setFillColor(Color::White);
	name_b.setPosition(550, 200);
	name_b.setOutlineColor(Color::Black);
	name_b.setOutlineThickness(4);

	Text id("ENTER CUSTOMER ID: ", font3, 12);
	id.setFillColor(Color::Black);
	id.setPosition(200, 320);
	RectangleShape id_b(Vector2f(180, 40));
	id_b.setFillColor(Color::White);
	id_b.setOutlineColor(Color::Black);
	id_b.setOutlineThickness(4);
	id_b.setPosition(550, 300);

	bool nameStatus = false;
	string nameTextString = "";
	Text nameText("", font, 20);
	nameText.setFillColor(Color::Black);
	nameText.setPosition(name_b.getPosition().x + 5.f, name_b.getPosition().y + 5.f);

	bool idStatus = false;
	string idTextString = "";
	Text idText("", font, 20);
	idText.setFillColor(Color::Black);
	idText.setPosition(id_b.getPosition().x + 5.f, id_b.getPosition().y + 5.f);


	RectangleShape confirm(Vector2f(200, 50));
	confirm.setFillColor(Color::White);
	confirm.setPosition(410, 500);
	confirm.setOutlineColor(Color::Black);
	confirm.setOutlineThickness(6);
	Text confirm_t("COMPILE BILL", font3, 12);
	confirm_t.setFillColor(Color::Black);
	confirm_t.setPosition(430, 520);

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
				if (confirm.getGlobalBounds().contains(mousePos))
				{
					int i = stoi(idTextString);
					customer.setId(i);
					customer.setName(nameTextString);
					return 69;
				}
				if (name_b.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					nameStatus = true;
					idStatus = false;
				}
				if (id_b.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					nameStatus = false;
					idStatus = true;
				}
			}
			if (nameStatus == true && event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (nameTextString.size() > 0)
					{
						nameTextString.erase(nameTextString.size() - 1, 1);
						nameText.setString(nameTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					nameStatus = false;
					nameText.setString(nameTextString);
				}
				else if (event.text.unicode < 128)
				{
					nameTextString += static_cast<char>(event.text.unicode);
					nameText.setString(nameTextString);
				}
			}
			if (idStatus == true && event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8)
				{
					if (idTextString.size() > 0)
					{
						idTextString.erase(idTextString.size() - 1, 1);
						idText.setString(idTextString);
					}
				}
				else if (event.text.unicode == 13)
				{
					idStatus = false;
					idText.setString(idTextString);
				}
				else if (event.text.unicode < 128)
				{
					idTextString += static_cast<char>(event.text.unicode);
					idText.setString(idTextString);
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		if (confirm.getGlobalBounds().contains(mousePos)) {
			confirm.setOutlineColor(Color::Red);
		}
		else {
			confirm.setOutlineColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombar);
		Window.draw(name_b);
		Window.draw(id_b);
		Window.draw(back);
		Window.draw(shop);
		Window.draw(confirm);
		Window.draw(tx1);
		Window.draw(name);
		Window.draw(id);
		Window.draw(nameText);
		Window.draw(idText);
		Window.draw(confirm_t);
		RectangleShape cursor(Vector2f(2.f, 30.f));
		cursor.setFillColor(Color::Black);
		if (nameStatus == true)
		{
			cursor.setPosition(nameText.getGlobalBounds().left + nameText.getGlobalBounds().width + 5.f, nameText.getPosition().y);
			Window.draw(cursor);
		}
		if (idStatus == true)
		{
			cursor.setPosition(idText.getGlobalBounds().left + idText.getGlobalBounds().width + 5.f, idText.getPosition().y);
			Window.draw(cursor);
		}
		Window.display();
	}

}

int customerBill(RenderWindow& Window, Customer& customer)
{
	customer.printDetails();

	RectangleShape topbar(Vector2f(1200, 92));
	topbar.setFillColor(Color(200, 255, 0));
	topbar.setPosition(0, 0);
	RectangleShape bottombar(Vector2f(1200, 500));
	bottombar.setFillColor(Color(64, 64, 64));
	bottombar.setPosition(0, 100);

	RectangleShape bar(Vector2f(800, 4));
	bar.setFillColor(Color::Black);
	bar.setPosition(100, 175);

	Font font, font3;
	font.loadFromFile("Dosis.ttf");
	font3.loadFromFile("emmasophia.ttf");

	Text shop("CUSTOMER BILL", font, 40);
	shop.setFillColor(Color::Black);
	shop.setPosition(100, 20);

	RectangleShape back(Vector2f(150, 40));
	back.setFillColor(Color::Green);
	back.setPosition(580, 25);
	Text tx1("<-EXIT", font3, 15);
	tx1.setPosition(588, 40);
	tx1.setFillColor(Color::Black);

	RectangleShape bill(Vector2f(800, 470));
	bill.setFillColor(Color::White);
	bill.setOutlineColor(Color::Black);
	bill.setOutlineThickness(6);
	bill.setPosition(100, 116);

	Text storename("7 ELEVEN SUPERMARKET", font, 20);
	storename.setFillColor(Color::Black);
	storename.setPosition(330, 120);

	Text cusname("CUSTOMER NAME: ", font, 18);
	cusname.setFillColor(Color::Black);
	cusname.setPosition(100, 150);

	Text cusid("CUSTOMER ID: ", font, 18);
	cusid.setFillColor(Color::Black);
	cusid.setPosition(620, 150);

	Text cusamount("TOTAL AMOUNT: ", font, 18);
	cusamount.setFillColor(Color::Black);
	cusamount.setPosition(550, 550);

	Text amount("", font, 20);
	amount.setFillColor(Color::Black);
	amount.setPosition(750, 550);
	Text name("", font, 20);
	name.setFillColor(Color::Black);
	name.setPosition(320, 150);
	Text id("", font, 20);
	id.setFillColor(Color::Black);
	id.setPosition(800, 150);

	int i = customer.getId();
	string ID = to_string(i);
	id.setString(ID);
	string n = customer.getName();
	name.setString(n);
	double a = customer.getAmount();
	string AMOUNT = to_string(a);
	amount.setString(AMOUNT);

	int size = customer.getSize();

	Text* products = NULL;
	Text* price = NULL;

	products = new Text[size+1];
	price = new Text[size+1];

	string** cart = customer.getCart();
	double** pricess = customer.getPrices();

	for (int i = 1; i < customer.getSize(); i++)
	{
		double price1 = pricess[i][0];
		string priceStr = to_string(price1);

		products[i].setString(cart[i][0]);
		price[i].setString(priceStr);
	}

	int Yincrement = 0;
	for (int i = 1; i < size; i++)
	{
		products[i].setPosition(120, 185 + Yincrement);
		price[i].setPosition(520, 185 + Yincrement);

		products[i].setFont(font);
		price[i].setFont(font);

		products[i].setFillColor(Color::Black);
		price[i].setFillColor(Color::Black);

		products[i].setCharacterSize(18);
		price[i].setCharacterSize(18);

		Yincrement += 20;
	}

	while (Window.isOpen())
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f mousePos = Window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (back.getGlobalBounds().contains(mousePos))
				{
					return -1;
				}
			}
		}
		Vector2f mousePos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		if (back.getGlobalBounds().contains(mousePos)) {
			tx1.setFillColor(Color::Red);
		}
		else {
			tx1.setFillColor(Color::Black);
		}
		Window.clear();
		Window.draw(topbar);
		Window.draw(bottombar);
		Window.draw(bill);
		Window.draw(back);
		Window.draw(shop);
		Window.draw(bar);
		Window.draw(tx1);
		Window.draw(name);
		Window.draw(id);
		Window.draw(storename);
		Window.draw(cusname);
		Window.draw(cusid);
		Window.draw(cusamount);
		Window.draw(amount);
		for (int i = 0; i < size; i++)
		{
			Window.draw(products[i]);
			Window.draw(price[i]);
		}
		Window.display();
	}
}

//===============================================================================================================