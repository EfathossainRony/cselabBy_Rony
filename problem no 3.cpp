#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name,birthday;

    Person() {};
    Person(string name,string birthday)
    {
        this->name=name;
        this->birthday=birthday;
    }
    void viewPerson()
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
    }
};

class Department
{
    string department_name;
public:
    Department() {};
    Department(string department_name)
    {
        this->department_name=department_name;
    }
    void viewDepartment()
    {
        cout<<"Name of Department : "<<this->department_name<<endl;
    }

};

class Student : public Person
{
    int roll;
    Department department;
public:
    Student() {};
    Student(string name,string birthday,int roll,Department department) : Person(name,birthday)
    {
        this->roll=roll;
        this->department=department;
    }
    void viewStudent()
    {
        viewPerson();
        department.viewDepartment();
        cout<<"Roll : "<<this->roll<<endl;
    }
};

class Teacher: public Person
{
    int teacher_id;
    Department department;
public:
    Teacher() {};
    Teacher(string name,string birthday,int teacher_id,Department department) : Person(name,birthday)
    {
        this->teacher_id=teacher_id;
        this->department=department;
    }

};

class Society_member : public Student
{
    string designation;
public:
    Society_member() {};
    Society_member(string name,string birthday,int roll,Department department,string deisgnation): Student(name,birthday,roll,department)
    {
        this->designation=designation;
    }
    void view_memberInfo()
    {
        cout<<"Society Member Info: "<<endl;
        viewStudent();
        cout<<"Designation : "<<this->designation<<endl;
    }


};

int main()
{
    Department department("CSE");
    Student *students[4]=
    {
        new Student("Nahidul Alam","18-11-1998",10708041,department),
        new Student("Kalam Ahmed","04-12-1999",10708013,department),
        new Student("Mahbub Islam","10-02-1999",10508010,department),
        new Student("Saiful Ahmed","18-10-1996",10708041,department)
    };
    Teacher *teachers[5]=
    {
        new Teacher("Kamal Hossain Chowdhury","11-04-1980",1,department),
        new Teacher("Mahmudul Hasan Raju","03-05-1982",2,department),
        new Teacher("Hasan Hafizur Rahman","23-05-1983",4,department),
        new Teacher("Faisal Bin Abdul Aziz","09-02-1985",3,department),
        new Teacher("Partha chakrobarthy","05-08-1984",5,department)
    };
    Society_member *members[4]=
    {
        new Society_member("Dipto Brata Das","10-10-1995",11408041,department,"VP"),
        new Society_member("Jawad Shafi","12-12-1996",11608015,department,"GS"),
        new Society_member("Kaysar Ahmed","11-12-1997",11708015,department,"AGS"),
        new Society_member("Umme Honey Fomey","04-09-1996",11508015,department,"Member")
    };
    int marksByStudents[5][5]= {{3,5,3,8,5},{3,3,4,3,4},{3,4,5,4,5},{3,3,4,4,3}};
    int marksByTeachers[6][5]= {{4,3,4,5,4},{3,3,4,5,4},{4,4,3,3,4},{3,3,4,4,3},{4,4,3,4,3},{3,5,3,4,4}};
    cout<<"Students Who Voted In The Survey"<<endl<<endl;
    for(int i=0; i<4; i++)
    {
        cout<<i+1<<". "<<students[i]->name<<endl<<endl;
    }
    cout<<endl<<endl;

    cout<<"Teachers Who Voted In The Survey"<<endl<<endl;


    for(int i=0; i<5; i++)
    {
        cout<<i+1<<". "<<teachers[i]->name<<endl<<endl;
    }

    cout<<"Final Result Of the Survey"<<endl<<endl;
    for(int i=0; i<4; i++)
    {
        int sum=0;
        for(int j=0; j<4; j++)
        {
            for(int k=i; k<=i; k++)
            {
                sum+=marksByStudents[j][k];
            }
        }
        for(int j=0; j<5; j++)
        {
            for(int k=i; k<=i; k++)
            {
                sum+=marksByTeachers[j][k];
            }
        }
        cout<<"Member Name: "<<members[i]->name<<endl;
        cout<<"Total Marks : "<<sum<<endl<<endl;
    }
    return 0;
}
