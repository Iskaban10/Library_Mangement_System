#include <iostream>
#include <ctime>
#include<fstream>
using namespace std;

class Member
{
    public:
    string name;
    string dob;
    string dept;
    string degree;
    string session;
    string emailid;
    string contact_no;
    time_t tt;
    struct tm* ti;
    Member()
    {
        cout<<"-----ENTER DETAILS IN BLOCK CAPITALS-----"<<endl;
        cout<<"Enter Name: "<<endl;
        getline(cin,name);
        cout<<"Enter Dob: "<<endl;
        getline(cin,dob);
        cout<<"Enter Department: "<<endl;
        getline(cin,dept);
        cout<<"Enter Email-Id: "<<endl;
        getline(cin,emailid);
        cout<<"Enter Contact Number: "<<endl;
        getline(cin,contact_no);
        cout<<"Enter Degree Enrolled In (Ex: BTech,BSc...): "<<endl;
        getline(cin,degree);
        cout<<"Enter Session: "<<endl;
        getline(cin,session);
    }
    void save()
    {
        string copy=name;
        int c=0;
        while(c<copy.length())
        {
            if(copy[c]==' ')
            {
                copy[c]='_';
            }
            c++;
        }
        string file_name=copy+'_'+dept.substr(0,3);
        ofstream file("Member_Database/"+file_name+".txt"); 
        file<<"-----MEMBER DETAILS-----"<<endl;       
        file<<"Name: "<<name<<endl;
        file<<"Date of birth: "<<dob<<endl;
        file<<"Enrolled in "<<degree<<" "<<dept<<endl;
        file<<"Enrolled for the academic session "<<session<<endl;
        time(&tt);
        ti=localtime(&tt);
        file<<"Registerd on "<<asctime(ti);
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Date of birth: "<<dob<<endl;
        cout<<"Enrolled in "<<degree<<" "<<dept<<endl;
        cout<<"Enrolled for academic session "<<session<<endl;
        time(&tt);
        ti=localtime(&tt);
        cout<<"Registerd on "<<asctime(ti);
    }
};

int main()
{
    Member m1;
    m1.save();
    m1.display();
    return 0;
}