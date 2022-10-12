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
		cout << "Name: " << Name << endl;
		cout << "Employee ID: " << Emp_ID << endl;
		cout << "Gross Salary: $" << Gross_Salary << endl;
		cout << "Savings: $" << Savings << endl;
		cout << "Monthly Salary: $" << Gross_Salary / 12 << endl;
		cout << "Net Salary: $" << Gross_Salary - Savings << endl;
	}

	void operator = (const Employee &E)
	{
		Name = E.Name;
		Emp_ID = E.Emp_ID;
		Gross_Salary = E.Gross_Salary;
		Savings = E.Savings;
	}

	Employee operator + (const Employee &E)
	{
		Employee employee;
		employee.Gross_Salary = this->Gross_Salary + E.Gross_Salary;
		employee.Savings = this->Savings + E.Savings;
		employee.Name = "Aggregate";
		employee.Emp_ID = 1111;
		return employee;
	}

	friend ostream &operator << (ostream &os, const Employee &E)
	{
		os << "Employee Name: " << E.Name << "\nEmployee ID " << E.Emp_ID << "\nEmployee Salary $" << E.Gross_Salary << "\nEmployee Savings $" << E.Savings << endl;
		return os;
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


	Employee Emp[3];
	for (int x = 0; x < 3; x++)
	{
		cout << "Please enter the name of Employee #" << x + 1 << ":" << endl;
		cin >> name;

		cout << "Please enter the Employee #" << x + 1 << "'s ID:" << endl;
		cin >> Employee_id;

		cout << "Please enter the gross salary of Employee #" << x + 1 << ":" << endl;
		cin >> grossSalary;

		Employee temp(name, Employee_id, grossSalary);
		Emp[x] = temp;
	}

	for (int x = 0; x < 3; x++)
	{
		cout << "Employee#" << x + 1 << " Info:" << endl;
		cout << Emp[x] << endl;

		Employee EmpCopy[3];
		EmpCopy[x] = Emp[x];
		cout << "Employee copy # " << x + 1 << " Info:" << endl;
		cout << EmpCopy[x] << endl;
	
	}
	cout << "Employee #1 + Employee #2 Combined Info: " << endl;
	cout << Emp[0] + Emp[1] << endl;


	system("pause");
	return 0;
}
