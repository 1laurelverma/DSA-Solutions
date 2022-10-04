#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    int rollNo1,year1;
    string name1,grade1[4],branch1;
    

    void searchStudent(int rollNo);
    void searchStudent(string name);
    void addStudent(string name,int rollNo,string grade[],int year,string branch);
    void highestGrade(int rollNo);

    void printAllStudentDetails(int rollNo,int n);

    void printAllStudentDetails(string branch,int n);
};

class Details
{

  public:
        string name;
        int model;
        int year_brought;
        string made_in;
        int cost;

        Details(string a, int m, int yb, string mi, int c)
        {
            name = a;
            model = m;
            year_brought = yb;
            made_in = mi;
            cost = c;
        }

        Details( Details &t)
        {
            cout << "Printing Details"
                << "\n";
            cout << "Name is:" + t.name << "\n";
            cout << "Model is:" + t.model << "\n";
            cout << "Year brought is" + t.year_brought << "\n";
            cout << "The car is made in " + t.made_in << "\n";
            cout << "Cost of the car is " + t.cost << "\n";
        }
};

Student students[100];
int noOfStuds=0;

void Student::addStudent(string name,int rollNo,string grade[],int year,string branch){
    students[noOfStuds-1].name1=name;
    students[noOfStuds-1].rollNo1=rollNo;
    for(int i=0;i<4;i++)
    students[noOfStuds-1].grade1[i]=grade[i];
    students[noOfStuds-1].year1=year;
    students[noOfStuds-1].branch1=branch;

}

void Student::printAllStudentDetails(string branch,int n){

        cout<<"Students with branch: "<<branch<<"\n\n";
        for(int i=0;i<n;i++){
            if(students[i].branch1==branch){
                cout<<"Name: "<<students[i].name1<<"\n";
                cout<<"Roll Number: "<<students[i].rollNo1<<"\n";
                cout<<"Physics"<<students[i].grade1[0]<<"\n";
                cout<<"Chemistry"<<students[i].grade1[1]<<"\n";
                cout<<"Maths"<<students[i].grade1[2]<<"\n";
                cout<<"History"<<students[i].grade1[3]<<"\n";
                cout<<"Year Of Study: "<<students[i].year1<<"\n";
                cout<<"Branch: "<<students[i].branch1<<"\n";
            }
        }
    }

void Student::printAllStudentDetails(int rollNo,int n){

        for(int i=0;i<n;i++){
            if(students[i].rollNo1==rollNo){
                cout<<"Name: "<<students[i].name1<<"\n";
                cout<<"Roll Number: "<<students[i].rollNo1<<"\n";
                cout<<"Physics"<<students[i].grade1[0]<<"\n";
                cout<<"Chemistry"<<students[i].grade1[1]<<"\n";
                cout<<"Maths"<<students[i].grade1[2]<<"\n";
                cout<<"History"<<students[i].grade1[3]<<"\n";
                cout<<"Year Of Study: "<<students[i].year1<<"\n";
                cout<<"Branch: "<<students[i].branch1<<"\n";
            }
        }
    }


void Student::searchStudent(int rollNo){
    int i;
    for(i=0;i<noOfStuds;i++){
        if(students[i].rollNo1==rollNo){
            Student::printAllStudentDetails(rollNo,noOfStuds);
            break;
        }
    }
    if(i==noOfStuds){
            cout<<"Student Not Found\n";
        }
}
void Student::searchStudent(string name){
    for(int i=0;i<noOfStuds;i++){
        if(students[i].name1==name){
            Student::printAllStudentDetails(students[i].rollNo1,noOfStuds);
            break;
        }
        if(i==noOfStuds){
            cout<<"Student Not Found\n";
        }
    }
}
int grade(string grade){
    if(grade=="A"||grade=="a"){
        return 5;
    }
    else if(grade=="b"||grade=="B"){
        return 4;
    }
    else if(grade=="c"||grade=="C"){
        return 3;
    }
    else if(grade=="d"||grade=="D"){
        return 2;
    }
    else if(grade=="F"||grade=="f"){
        return 1;
    }
}

void Student::highestGrade(int rollNo){
    int max=6;
    int maxI;
    for(int i=0;i<4;i++){
        if(grade(students[i].grade1[i])<=max){
            maxI=i;
        }
    }
    cout<<"\n"<<"The max grade is: "<<grade1[maxI];
}

int Q1(){
    int ch;
    int close=1;
    int rollNo,year;
    string name,grade[4],branch;

    cout<<"Please Enter the task you want to perform\n";
    cout<<"1.Add Student\n";
    cout<<"2.Search Student using roll number\n";
    cout<<"3.Search Student using name\n";
    cout<<"4.Find highest grade of a student\n";
    cout<<"5.print All Students of a branch\n";
    cin>>ch;
    if(ch==1){
        cout<<"Enter Name:\n";
        cin>>name;
        cout<<"Enter roll number:\n";
        cin>>rollNo;
        for(int i=0;i<noOfStuds;i++){
            if(students[i].rollNo1==rollNo){
                cout<<"Roll Number Already exists...\n";
                Q1();
            }
        }
        cout<<"Enter grades(A,B,C,D,F)in Physics Chemistry Maths History respectively\n";
        for(int i=0;i<4;i++){
            cin>>grade[i];
        }
        cout<<"Enter year of study:\n";
        cin>>year;
        cout<<"Enter branch:\n";
        cin>>branch;
        noOfStuds++;
        students[noOfStuds].addStudent(name,rollNo,grade,year,branch);
    }
    else if(ch==2){
        cout<<"Enter the roll number you want to search:\n";
        cin>>rollNo;
        students[noOfStuds].searchStudent(rollNo);
    }
    else if(ch==3){
        cout<<"Enter the name you want to search:\n";
        cin>>name;
        students[noOfStuds].searchStudent(name);
    }
    else if(ch==4){
        cout<<"Enter the roll number:\n";
        cin>>rollNo;
        students[noOfStuds].highestGrade(rollNo);
    }
    else if(ch==5){
        cout<<"Enter Branch:\n";
        cin>>branch;
        students[noOfStuds].printAllStudentDetails(branch,noOfStuds);
    }
    else{
        close=0;
    }
    if(close){
        Q1();
    }
}

int Q2(){
    string Name;
    int Model;
    int Year_brought;
    string Made_in;
    int Cost;

    cout << "Enter the Details of the car in order\n 1.Name\n2.Model\n3.Year it was bought\n4.Made in\n5.Cost\n\n";
    cin >> Name;
    cin >> Model;
    cin >> Year_brought;
    cin >> Made_in;
    cin >> Cost;

    Details d1(Name, Model, Year_brought, Made_in, Cost);
    Details d2(d1);
}

int main(){
    Q1();
    Q2();
}
