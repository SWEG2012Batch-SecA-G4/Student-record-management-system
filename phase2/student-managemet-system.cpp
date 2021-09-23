#include<iostream>
#include<windows.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<iomanip>
#include<fstream>
#include <sstream>

using namespace std;

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
void signup(){
    system("cls");
    string username,password;
    ofstream aout("admin.txt" , ios::app);
    cout<<"Enter username: ";
    cin>>admin.username;
    cout<<"Enter password: ";
    cin>>admin.password;
    ifstream ain("admin.txt");
    while(ain>>username>>password){
        if(username==admin.username){
            cout<<"Username already exists! choose a new one\n";
            system("pause");
            signup();
        }
    }
    aout<<admin.username<<" "<<admin.password<<endl;
    aout.close();
}
bool login(string user){
    system("cls");
    ifstream file(user);
    string username,password;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    while(file >> admin.username >> admin.password){
        if(username == admin.username && password == admin.password){
            cout<<"Welcome "<<username<<"!!\n";
            return true;
        }
    }
    return false;
}
void adminstration(){
    int reg_count = 0;
    system("cls");
    cout<<"admin page!";
    switch(menu_1()){
        case 1:{
            switch(menu_11()){
                case 1:{
                    registration();
                    reg_count++;
                    adminstration();
                    break;
                }
                case 2:{
                    switch(menu_112()){
                        case 1:{
                            edit(search());
                            adminstration();
                            break;
                        }
                        case 2:{
                            del(search());
                            adminstration();
                            break;
                        }
                        case 3:{
                            ofstream trunc("student.txt");
                            trunc.close();
                            adminstration();
                            break;
                        }
                        case 4:
                            adminstration();
                        case 5:
                            main();
                    }
                    break;
                }
                case 3:{
                    stud = search();
                    if(stud.fullName != "no")
                        cout<<stud.fullName<<endl<<stud.id<<endl;
                    else{
                        cout<<"Not found!"<<endl;
                        system("pause");
                        adminstration();
                    }
                    break;
                }
                case 4:{
                    adminstration();
                }
                default: {
                    main();
                }
            }
            break;
        }
        case 2:{
            switch(menu_12()){
                case 1:
                    course.code = "sweg";
                    switch(menu_121()){
                        case 1:
                            reg_course(course);
                            adminstration();
                            break;
                        case 2:
                            edit_course(search_course(course));
                            adminstration();
                            break;
                        case 3:
                            del_courses(search_course(course));
                            adminstration();
                            break;
                        case 4:
                            adminstration();
                        case 5:
                            main();
                    }
                    break;
                case 2:
                    course.code = "arc";
                    switch(menu_121()){
                        case 1:
                            reg_course(course);
                            adminstration();
                            break;
                         case 2:
                            edit_course(search_course(course));
                            adminstration();
                            break;
                        case 3:
                            del_courses(search_course(course));
                            adminstration();
                            break;
                        case 4:
                            adminstration();
                        case 5:
                            main();
                    }
                    break;
                case 3:
                    course.code = "elec";
                    switch(menu_121()){
                        case 1:
                            reg_course(course);
                            adminstration();
                            break;
                         case 2:
                            edit_course(search_course(course));
                            adminstration();
                            break;
                        case 3:
                            del_courses(search_course(course));
                            adminstration();
                            break;
                        case 4:
                            adminstration();
                        case 5:
                            main();
                    }
                    break;
                case 4:
                    course.code = "civ";
                    switch(menu_121()){
                        case 1:
                            reg_course(course);
                            adminstration();
                            break;
                         case 2:
                            edit_course(search_course(course));
                            adminstration();
                            break;
                        case 3:
                            del_courses(search_course(course));
                            adminstration();
                            break;
                        case 4:
                            adminstration();
                        case 5:
                            main();
                            break;
                    }
                    break;
                case 5:
                    adminstration();
                    break;
                default:{
                    main();
                }
            }
        }
        case 3:{
            main();
        }
        default:{
            break;
        }
    }
}
