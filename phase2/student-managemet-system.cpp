#include<iostream>
#include<windows.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<iomanip>
#include<fstream>
#include <sstream>

using namespace std;
//dormitary
struct Dorm{
    string block,room;
};
struct Users{
    string username,password,type;
}admin,teacher,student;
struct Course{
    string name,instructor[2],code,pre_req,grade,year;
    int credit;
    double mark[6];
}course;
struct Department{
    string name,code;
    Course courses[60];
    int count;
};
class Students{
    public:
        string fullName,id,line;
        int no_of_course;
        Dorm dorm;
        Course courses[10];
        Department dep;
}stud;

void color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
int menu(){
    int menu;
    system("cls");
    cout<<"Student Record Management System\n";
    cout<<"Welcome!\n";
    //all users are accessable to the login page, but as per the type of account the functionalities differ
    //but only admin can sign up
    cout<<" 1. Admin page\n 2. Teacher page\n 3. Student page\n 4. Back\n-> ";
    cin>>menu;
    return menu;
}
//admin
int menu_1(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Student Database"<<endl;
    cout<<" 2. Department database"<<endl;
    cout<<" 3. back"<<endl;
    cout<<" 4. Exit\n->";
    cin>>menu;
    return menu;
}
