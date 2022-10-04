#include <bits/stdc++.h>
using namespace std;



//----------------------QUESTION 1----------------------

class Employee
{

public:
    string firstName;
    string lastName;
    string employeeID;
    float basicSal;
    int allowancePercent;

public:
    int findEmployeeSalary(string employee_id);
    void printEmployeeDetail(int i);
    void createEmployee();
    void findEmployeeById();
    void findEmployeeByName();

} employee[11];
int total_employees = 0;

int findEmployeeSalary(string employee_id)
{
    int flag = -1;
    string employeeID;
    employeeID = employee_id;
    for (int i = 0; i < total_employees; i++)
    {
        if (employee[i].employeeID == employeeID)
        {
            flag = i;
            break;
        }
    }
    int calculate = employee[flag].basicSal + (employee[flag].basicSal * employee[flag].allowancePercent) / 100;
    if (flag != -1)
    {
        return calculate;
    }
    else
    {
        cout << "Your ID doesnt exist\n";
        return 0;
    }
}

void printEmployeeDetail(int i)
{
    cout << "NAME: " + employee[i].firstName + employee[i].lastName<<"\n";
    cout << "ID: " << employee[i].employeeID << "\n";
    cout << "Salary: " << findEmployeeSalary(employee[i].employeeID) << "\n";
    cout << "Allowance Percentage: " << employee[i].allowancePercent << "\n";
    cout << "\n";
}
void createEmployee()
{
    string firstName;
    string lastName;
    string employeeID;
    int nc = 0, flag = 1;
    float basicSal;

    cout << "Enter Employee ID: ";
    cin >> employeeID;
    for (int i = 0; i < total_employees; i++)
    {

        if (employee[i].employeeID == employeeID)
        {
            cout << "ID already exists" << endl;
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        employee[total_employees].employeeID = employeeID;

        cout << "First Name: ";
        cin >> firstName;
        employee[total_employees].firstName = firstName;

        cout << "Last Name: ";
        cin >> lastName;
        employee[total_employees].lastName = lastName;

        cout << "Salary: ";
        cin >> basicSal;
        employee[total_employees].basicSal = basicSal;

        cout << "Allowance Percentage: ";
        cin >> nc;
        employee[total_employees].allowancePercent = nc;

        total_employees++;
        cout << "\n\nRecord Resgistered\n\n\n";
    }
}

void findEmployeeById()
{
    int flag = -1;
    string employeeID;
    cout << "Enter Employee ID:";
    cin >> employeeID;

    for (int i = 0; i < total_employees; i++)
    {
        if (employee[i].employeeID == employeeID)
        {
            flag = i;
            break;
        }
    }
    if (flag != -1)
    {
        printEmployeeDetail(flag);
    }
    else
        cout << "Your ID doesnt exist\n";
}
void findEmployeeByName()
{
    string name;
    int flag = 1;
    cout << "Enter the employee name: ";
    fflush(stdin);
    getline(cin, name);
    for (int i = 0; i < total_employees; i++)
    {
        if (employee[i].firstName + " " + employee[i].lastName == name)
        {
            flag = 0;
            printEmployeeDetail(i);
        }
    }
    if (flag)
        cout << "This name is not found" << endl;
}



//----------------------QUESTION 2----------------------

class hospitaldetails
{
        private:
        string patientname;
        string doctorname;
        public:
                void input();
                void display();


}patient[10];

int total=0;
void hospitaldetails::input()
{
        cout<<"Enter Patient name:";
        cin>>patient[total].patientname;
        cout<<"Enter Doctor name:";
        cin>>patient[total].doctorname;
        total++;
}
void hospitaldetails::display()
{
     for(int i=0;i<total;i++){

        cout<<"\nName:"<<patient[i].patientname;
        cout<<"\nDoctor's Name:"<<patient[i].doctorname;
     }
}


int Q1()
{
    cout<<"----------------------QUESTION 1----------------------"<<"\n\n";
    int func, close = 0;

    while (1)
    {   
        cout << "Please enter function\n"
            "1. Create an Employee\n"
            "2. Find Employee By ID\n"
            "3. Find Employee By Name\n"
            "4. Find Employee Salary\n"
            "5. End Task\n";

        cin >> func;

        if (func == 1)
        {
            createEmployee();
        }
        else if (func == 2)
        {
            findEmployeeById();
        }
        else if (func == 3)
        {
            findEmployeeByName();
        }
        else if (func == 4)
        {
            cout << "Enter employee id: ";
            string id;
            cin >> id;
            cout << "\n\nSalary: " << findEmployeeSalary(id) << endl
                 << "\n\n";
        }
        else if (func == 5)
        {
            break;
        }

    
    }

    return 0;
}

int Q2()
{
    cout<<"----------------------QUESTION 2----------------------"<<"\n\n";
    cout<<"1-Enter Patient Details \n2-Display Records\n3-Exit Task\n";
    int ch;
    hospitaldetails s;
    while(1){
        cin>>ch;
        if(ch==3){
            break;
        }
        switch(ch){
            case 1:
                s.input();
                break;
            case 2:
                s.display();
                break;
            default:
                break;
        }
    }
}

int main()
{
    Q1();
    Q2();
}
