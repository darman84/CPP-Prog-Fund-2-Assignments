// Employee class, made by zachary williams
#include <iostream>
#include <string>
using namespace std;
 
class Employee
{

private:
	string Name;
	int Emp_ID;
	int Gross_Salary;
	double Savings;

public:
	//Constructor
	Employee() {}

	// Overloading constructors
	Employee(string Name, int Emp_ID, int Gross_Salary)
	{
		this->Name = Name;
		this->Emp_ID = Emp_ID;
		this->Gross_Salary = Gross_Salary;
		this->Savings = Gross_Salary * .1;
	}

	
	void DisplayEmp()
	{
		cout << "Name: " << Name <<endl;
		cout << "Employee ID: " << Emp_ID << endl;
		cout << "Gross Salary: $" << Gross_Salary << endl;
		cout << "Savings: $" << Savings << endl;
		cout << "Monthly Salary: $" << Gross_Salary / 12 << endl;
		cout << "Net Salary: $" << Gross_Salary - Savings << endl;
	}

	int GetSalary()
	{
		return Gross_Salary;
	}

	double ShowSavings()
	{
		return Savings;
	}

};



int main()
{
	string name;
	int Employee_id;
	int grossSalary;


	Employee Emp[5];
	for (int x = 0; x < 5; x++)
	{
		cout << "Please enter the name of Employee #" << x+1 << ":" << endl;
		cin >> name;

		cout << "Please enter the Employee #" << x+1 << "'s ID:" << endl;
		cin >> Employee_id;

		cout << "Please enter the gross salary of Employee #" << x+1 << ":" << endl;
		cin >> grossSalary;

		Employee temp(name, Employee_id, grossSalary);
		Emp[x] = temp;
	}

	for (int x = 0; x < 5; x++)
	{
		cout << "Employee#" << x + 1 << " Info:" << endl;
		Emp[x].DisplayEmp();
		cout << "Employee salary displayed from GetSalary: " << Emp[x].GetSalary() << endl;
		cout << "Employee savings displayed from ShowSavings: " << Emp[x].ShowSavings() << endl << endl;
	}


	system("pause");
	return 0;
}