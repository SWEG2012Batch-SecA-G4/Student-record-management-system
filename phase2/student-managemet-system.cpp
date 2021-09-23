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

int menu_11(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Add new students"<<endl;
    cout<<" 2. Update students records "<<endl;
    cout<<" 3. Search student records"<<endl;
    cout<<" 4. back"<<endl;
    cout<<" 5. Main menu\n->";
    cin>>menu;
    return menu;
}
int menu_112(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Edit students record"<<endl;
    cout<<" 2. Delete a student from record"<<endl;
    cout<<" 3. Delete all student records "<<endl;
    cout<<" 4. Back\n";
    cout<<" 5. Main menu\n->";
    cin>>menu;
    return menu;
}
int menu_113(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Sort students record"<<endl;
    cout<<" 2. Search student records "<<endl;
    cout<<" 3. List all students"<<endl;
    cout<<" 4. Back\n";
    cout<<" 5. Main menu\n";
    cin>>menu;
    return menu;
}
int menu_12(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Department of software engineering\n";
    cout<<" 2. Department of architectural engineering\n";
    cout<<" 3. Department of electrical engineering\n";
    cout<<" 4. Department of civil engineering\n";
    cout<<" 5. Back\n";
    cout<<" 6. Main menu\n";
    cout<<"->";
    cin>>menu;
    return menu;
}
int menu_121(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Add course\n";
    cout<<" 2. Edit course\n";
    cout<<" 3. Delete course\n";
    cout<<" 4. Back\n";
    cout<<" 5. Main menu\n->";
    cin>>menu;
    return menu;
}
//teacher
int menu_21(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Grading\n";
    cout<<" 2. Back\n";
    cout<<" 3. Exit\n->";
    cin>>menu;
    return menu;
}
//student
int menu_31(){
    system("cls");
    int menu;
    cout<<"Please select your option"<<endl;
    cout<<" 1. Add course\n";
    cout<<" 2. View grade\n";
    cout<<" 3. Back\n";
    cout<<" 4. Exit\n";
    cin>>menu;
    return menu;
}
void signup();
bool login(string);
Students search();
void registration();
void adminstration();
void _teacher(Course);
void _student(Students);
void edit(Students);
void del(Students);
void reg_course(Course);
void edit_course(Course);
Course search_course(Course);
void del_courses(Course);
bool teacher_login(Course &);
bool student_login(Students &);
int show_stud(string,int []);
void add_grade(string &,string);
string grade(float);
float cgpa(string);
void comulative();
float total();
float credit(string);
void stat();
int main(){
        int account;
        switch(menu()){
        //admin
        case 1:{
            cout<<"Admin page\n";
            cout<<" 1. signup\n 2. login\n->";
            cin>>account;
            if(account==1){
                signup();
                cout<<"Signed up!\n" ;
                system("pause");
                main();
            }
            else if(account == 2)
                if(login("admin.txt")){
                    adminstration();
                }
            else
                main();
            break;
        }
        //teacher
        case 2:{
            if(teacher_login(course))
                _teacher(course);
            break;
        }//student
        case 3:{
            if(student_login(stud))
                _student(stud);
            break;
        }//back
        case 4:{return 0;}
        default:{main();}
    }
}
