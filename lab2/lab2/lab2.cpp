// zachary williams
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

	virtual void DisplayEmp()
	{
		cout << "Name: " << Name << endl;
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
class FullTimeEMP : public Employee
{
private:
	double BonusPercentage;

public:
	FullTimeEMP() {}
	FullTimeEMP(string Name, int Emp_ID, int Gross_Salary, double NewBonusPercentage) : Employee(Name, Emp_ID, Gross_Salary)
	{
		this->BonusPercentage = NewBonusPercentage;
	}
	void DisplayEmp() override
	{
		Employee::DisplayEmp();

		DisplayBonus();
	}
	void DisplayBonus()
	{
		cout << "The bonus percentage is " << BonusPercentage << "%" << endl <<endl;
	}
};
class PartTimeEMP : protected Employee
{
private:
	int BonusAmount;
public:
	PartTimeEMP() {}
	PartTimeEMP(string Name, int Emp_ID, int Gross_Salary, int NewBonusAmount) : Employee(Name, Emp_ID, Gross_Salary)
	{
		this->BonusAmount = NewBonusAmount;
	}
	void DisplayEmp() override
	{
		Employee::DisplayEmp();
		cout << "The bonus amount is $" << BonusAmount << endl <<endl;
	}
};

int main()
{
	string name;
	int Employee_id;
	int grossSalary;
	int BonusPercentage;
	FullTimeEMP FullTime[2];
	PartTimeEMP PartTime[2];

	for (int x = 0; x < 2; x++)
	{
		cout << "Please enter the name of  Employee #" << x + 1 << ":" << endl;
		cin >> name;
		cout << "Please enter the Employee #" << x + 1 << "'s ID:" << endl;
		cin >> Employee_id;
		cout << "Please enter the gross salary of Employee #" << x + 1 << ":" << endl;
		cin >> grossSalary;
		cout << "Please enter the bonus percentage of Employee #" << x + 1 << ":" << endl;
		cin >> BonusPercentage;
		FullTimeEMP temp(name, Employee_id, grossSalary, BonusPercentage);
		FullTime[x] = temp;
	}

	for (int x = 0; x < 2; x++)
	{
		cout << "Employee#" << x + 1 << " Info:" << endl;
		FullTime[x].DisplayEmp();
	}

	for (int x = 0; x < 2; x++)
	{
		cout << "Please enter the name of  Employee #" << x + 1 << ":" << endl;
		cin >> name;
		cout << "Please enter the Employee #" << x + 1 << "'s ID:" << endl;
		cin >> Employee_id;
		cout << "Please enter the gross salary of Employee #" << x + 1 << ":" << endl;
		cin >> grossSalary;
		cout << "Please enter the bonus amount of Employee #" << x + 1 << ":" << endl;
		cin >> BonusPercentage;
		PartTimeEMP temp(name, Employee_id, grossSalary, BonusPercentage);
		PartTime[x] = temp;
	}

	for (int x = 0; x < 2; x++)
	{
		cout << "Employee#" << x + 1 << " Info:" << endl;
		PartTime[x].DisplayEmp();
		//PartTime[x].DisplayBonus();
	}
	system("pause");
	return 0;
}