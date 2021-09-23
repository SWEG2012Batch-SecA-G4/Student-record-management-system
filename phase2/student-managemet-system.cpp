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
void registration(){
    cin.ignore();
    cout<<"Enter full name: ";
    getline(cin,stud.fullName,'\n');
    int x;
    for( x = 0; x < stud.fullName.length(); x++){
        if(stud.fullName[x] == ' ')
            break;
    }
    char username[stud.fullName.length()];
    for(int i = 0; i <= stud.fullName.length();i++ ){
        if(i < x){
            username[i] = stud.fullName[i];
        }
        else{
            if(i != stud.fullName.length()-1)
                username[i] = stud.fullName[i+1];
            else
                username[i] = '\0';
        }
    }
    cout<<"Enter id: ";
    cin>>stud.id;
    cout<<"Enter dorm block: ";
    cin>>stud.dorm.block;
    cout<<"Enter dorm room: ";
    cin>>stud.dorm.room;
    cout<<"Enter department(sweg,arc,elec,civ): ";
    cin>>stud.dep.name;
    ofstream sout("student.txt" , ios::app);
    sout<<stud.id<<" "<<stud.fullName<<" "<<username<<" "<<stud.dep.name<<" "<<stud.dorm.block<<" "<<stud.dorm.room<<endl;
    //admin access to register new students
    //also used to edit students
}
Students search(){
    string search,name[2],line,id,dep,block,room;
    Students student;
    cout<<" Enter name or id:";
    cin.ignore();
    getline(cin,search);
    ifstream sread("student.txt");
    while(sread>>stud.id>>name[0]>>name[1]>>line>>dep){
        getline(sread,line);
        if((name[0]+" "+name[1]) == search){
            stud.fullName = search;
            stud.dep.name = dep;
            stud.line = line;
            return stud;
        }
        else if(search == stud.id){
            stud.fullName = name[0]+" "+name[1];
            stud.dep.name = dep;
            stud.line = line;
            return stud;
        }
    }
    student.fullName = "no";
    return student;
}
void edit(Students stud){
    string usernames,name[2],dep,block,room,id;
    int line_count = 0;
    ifstream stu("student.txt");
    while(getline(stu,name[0])){
        line_count++;
    }
    string line[line_count];
    int j = 0;
    stu.close();
    ifstream sread("student.txt");
    while(sread>>id){
        getline(sread,name[0]);
        if(id == stud.id){
            cin.ignore();
            cout<<"Enter full name: ";
            getline(cin,stud.fullName,'\n');
            int x;
            for( x = 0; x < stud.fullName.length(); x++){
                if(stud.fullName[x] == ' ')
                    break;
            }
            char username[stud.fullName.length()];
            for(int i = 0; i <= stud.fullName.length();i++ ){
                if(i < x){
                    username[i] = stud.fullName[i];
                }
                else{
                    if(i != stud.fullName.length()-1)
                        username[i] = stud.fullName[i+1];
                    else
                        username[i] = '\0';
                }
            }
            cout<<"Enter id: ";
            cin>>stud.id;
            cout<<"Enter dorm block: ";
            cin>>stud.dorm.block;
            cout<<"Enter dorm room: ";
            cin>>stud.dorm.room;
            cout<<"Enter department(sweg,arc,elec,civ): ";
            cin>>stud.dep.name;
            usernames = username;
            line[j++] = stud.id+" "+stud.fullName+" "+usernames+" "+stud.dep.name+" "+stud.dorm.block+" "+stud.dorm.room;
            cout<<line[j-1];
        }
        else
            line[j++] = id+" "+name[0];
}
    sread.close();
    ofstream trunc("student.txt");
    trunc.close();
    ofstream swrite("student.txt",ios::app);
    for(int i = 0; i < line_count; i++){
        swrite<<line[i]<<endl;
        cout<<line[i]<<endl;
    }
}
void del(Students stud){
    string line;
    vector<string> lines;
    string usernames,name[2],dep,block,room,id;
    int line_count = 0;
    ifstream stu("student.txt");
    while(getline(stu, line)){
        lines.push_back(line);
    }
    stu.close();
    ifstream sread("student.txt");
    while(sread>>id){
        getline(sread, name[0]);
        if(id == stud.id){
            break;
        }
        line_count++;
    }
    sread.close();
    ofstream trunc("student.txt");
    trunc.close();
    ofstream swrite("student.txt",ios::app);
    for(int i = line_count+1; i < lines.size(); i++) {
        lines[i-1] = lines[i];
    }
    lines.pop_back();
    for(int i = 0; i < lines.size(); i++){
        swrite<<lines[i]<<endl;
    }
    swrite.close();
}
void reg_course(Course courses){
    cout<<"Course name: ";
    cin>>courses.name;
    cout<<"Instructors name: ";
    cin>>courses.instructor[0]>>courses.instructor[1];
    cin.ignore();
    cout<<"Course year: ";
    cin>>courses.year;
    cin.ignore();
    cout<<"Course credit: ";
    cin>>courses.credit;
    cout<<"Prerequesite (if not available type no): ";
    cin>>courses.pre_req;
    ofstream cwrite("course.txt",ios::app);
    cwrite <<courses.code<<" "<< courses.name<<" "<<courses.instructor[0]<<" "<<courses.instructor[1]<<" "<<courses.year<<" "<<courses.credit<<" "<<courses.pre_req<<endl;
    cwrite.close();

}
void edit_course(Course courses){
    string code,name,iname[2],year,credit,pre;
    int line_count = 0;
    ifstream stu("course.txt");
    while(stu>>code>>name>>iname[0]>>iname[1]>>year>>credit>>pre){
        line_count++;
    }
    string line[line_count];
    int j = 0;
    stu.close();
    ifstream sread("course.txt");
    while(sread>>code>>name>>iname[0]>>iname[1]>>year>>credit>>pre){
        if(name == courses.name){
            cout<<"Course name: ";
            cin>>courses.name;
            cout<<"Instructors name: ";
            cin>>courses.instructor[0]>>courses.instructor[1];
            cin.ignore();
            cout<<"Course year: ";
            cin>>courses.year;
            cin.ignore();
            cout<<"Course credit: ";
            cin>>credit;
            cout<<"Prerequesite (if not available type no): ";
            cin>>courses.pre_req;
            line[j++] = courses.code+" "+courses.name+" "+courses.instructor[0]+" "+courses.instructor[1]+" "+courses.year+" "+credit+" "+courses.pre_req;
            cout<<line[j-1];
        }
        else
            line[j++] = code+" "+name+" "+iname[0]+" "+iname[1]+" "+year+" "+credit+" "+pre;
}
    sread.close();
    ofstream trunc("course.txt");
    trunc.close();
    ofstream cwrite("course.txt",ios::app);
    for(int i = 0; i < line_count; i++){
        cwrite<<line[i]<<endl;
        cout<<line[i]<<endl;
    }
}
Course search_course(Course courses){
    string search,code,name,iname[2],year,credit,pre;
    cout<<" Enter course name: ";
    cin.ignore();
    cin>>search;
    ifstream cread("course.txt");
    while(cread>>courses.code>>courses.name>>courses.instructor[0]>>courses.instructor[1]>>courses.year>>courses.credit>>courses.pre_req){
        if(courses.name == search){
            return courses;
        }
    }
    courses.name = "no";
    return courses;
}
void del_courses(Course course){
    string line;
    vector<string> lines;
    string code,name,iname[2],year,credit,pre;
    int line_count = 0;
    ifstream cread("course.txt");
    while(getline(cread, line)){
        lines.push_back(line);
    }
    cread.close();
    bool flag = false;
    ifstream sread("course.txt");
    while(sread>>code>>name>>iname[0]>>iname[1]>>year>>credit>>pre){
        if(code == course.code){
            if(name == course.name){
                flag = true;
                break;
            }
        }
        else
            flag = false;
        line_count++;
    }
    sread.close();
    if(flag){
        ofstream trunc("course.txt");
        trunc.close();
        ofstream swrite("course.txt",ios::app);
        for(int i = line_count+1; i < lines.size(); i++) {
            lines[i-1] = lines[i];
        }
        lines.pop_back();
        for(int i = 0; i < lines.size(); i++){
            swrite<<lines[i]<<endl;
        }
        swrite.close();
    }
    else
        cout<<"course not available\n";
}
bool teacher_login(Course &course){
    string username,password,name[7];
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    ifstream cread("course.txt");
    while(cread>>name[0]>>name[1]>>name[2]){
        getline(cread,name[3]);
        if(name[2] == username && password == "teacher2013"){
            course.code = name[0];
            course.name = name[1];
            course.instructor[0] = name[2];
            return true;
        }
    }
    return false;
}
bool student_login(Students &stud){
    string username,password,name[4];
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    ifstream sread("student.txt");
    while(sread>>stud.id>>name[0]>>name[1]>>name[2]>>name[3]){
        if(name[2] == username && password == "student2013"){
            stud.fullName = name[0]+" "+name[1];
            stud.dep.name = name[3];
            return true;
        }
        getline(sread,name[3]);
    }
    return false;
}
void _teacher(Course course){
    x:
    system("cls");
    ifstream sr("student.txt");
    string line;
    vector <string> lines;
    while(getline(sr,line)){
        lines.push_back(line);
    }
    sr.close();
    switch(menu_21()){
        case 1:{
            int studs[lines.size()];
            int index = show_stud(course.name,studs);
            line = lines[index];
            add_grade(line,course.name);
            lines[index] = line;
            ofstream trunc("student.txt");
            trunc.close();
            ofstream swrite("student.txt",ios::app);
            for(int i = 0; i < lines.size();i++){
                swrite << lines[i]<<endl;
            }
            system("pause");
            goto x;
            break;
        }
        case 2:
            main();
        case 3:
            break;
    }
}
void _student(Students stud){
    system("cls");
    beg:
    switch(menu_31()){
        case 1:{
            system("cls");
            vector<string> lines;
            string dep,line,li;
            ifstream cread("course.txt");
            while(cread>>dep){
                if(dep == stud.dep.name){
                    getline(cread,line);
                    lines.push_back(line);
                }
            }
            cread.close();
            for(int i = 0; i < lines.size(); i++)
                cout<<1+i<<". "<<lines[i]<<endl;
            int add;
            string course_name;
            cout<<"Choose course to add: ";
            cin>>add;
            add--;
            for(int i = 1; i < lines[add].size(); i++){
                if(lines[add][i] == ' ')
                    break;
                course_name+=lines[add][i];
            }
            ifstream sread("student.txt");
            vector<string> students;
            string student;
            while(getline(sread,student)){
                students.push_back(student);
            }
            sread.close();
            ifstream srea("student.txt");
            string s_line,name[2],department,block,room,id;
            int j = 0;
            while(srea>>id){
                getline(srea,s_line);
                if(id == stud.id)
                    break;
                j++;
            }
            students[j] =students[j]+" "+course_name;
            ofstream trunc("student.txt");
            trunc.close();
            ofstream swrite("student.txt",ios::app);
            for(int i = 0; i < students.size();i++){
                swrite<<students[i]<<endl;
            }
            system("pause");
            main();
            break;
        }
        case 2:{
            string id,line,p_line;
            vector<string> grade;
            ifstream sread("student.txt");
            while(sread>>id){
                getline(sread,line);
                if(id == stud.id)
                    break;
            }
            istringstream iss(line);
            while(iss>>p_line){
                grade.push_back(p_line);
            }
            cout<<"ID\tName\n";
            cout<<id<<"\t"<<grade[0]<<" "<<grade[1]<<"  ";
            for(int i = 6; i < line.size(); i++){
                cout<<grade[i]<<"  ";
            }
            system("pause");
            main();
            break;
        }
        case 3:
            main();
        case 4:{
            break;
        }
    }
}
int show_stud(string c_name,int studs[]){
    cout<<c_name<<endl;
    ifstream sread("student.txt");
    string line,present,print,grade;
    vector<string> lines;
    while(getline(sread,line))
        lines.push_back(line);
    int j,t_choose,counter = 0, i,choose;
    bool flag;
    system("cls");
    cout<<"no ID\tName\n";
    for(i = 0; i < lines.size(); i++){
        j = 0;
        flag = false;
        istringstream iss(lines[i]);
        while(iss >> present){
            if(present == c_name)
                flag = true;
        }
        if(flag){
        counter++;
        studs[counter] = i;
        istringstream isss(lines[i]);
        cout<<counter<<". ";
        while(isss >> print && j < 3){
            if(j == 0)
                cout<<print<<"\t";
            else
                cout<<print<<" ";
            j++;
        }
        cout<<endl;
        }
    }
    do{
        cout<<"Choose student: ";
        cin>>choose;
        choose;
    }while(choose > counter);
    return studs[choose];
}
void add_grade(string & g_stud,string c_name){
    system("cls");
    string line,present,print,gpa,marks[] = {"5% :","5% :","10% :","30% :","50% :","100%"};
    int i = 0;
    float sum = 0,mark;
    cout<<"ID\tName\n";
    istringstream isss(g_stud);
    int j = 0;
    while(isss >> print && j < 3){
            if(j == 0)
                cout<<print<<"\t";
            else
                cout<<print<<" ";
            j++;
        }
        cout<<endl;
    for(int i = 0; i < 6; i++){
        if(i == 5){
            cout<<marks[i]<<" :"<<sum<<endl;
            break;
        }
        cout<<"Enter mark "<<i+1<<"-"<<marks[i];
        cin>>mark;
        sum+=mark;
    }
    gpa = grade(sum);
    cout<<" "<<gpa<<endl;
    istringstream iss(g_stud);
    while(iss >> line){
        if(line == c_name){
            line+=" "+gpa;
        }
        present += line+" ";
    }
    g_stud = present;


}
string grade(float sum){
    string g;
    if(sum >= 90 && sum <=100)
        g = "A+";
    else if (sum < 90 && sum >= 85)
        g = "A";
    else if (sum < 85 && sum >= 80)
        g = "A-";
    else if (sum < 80 && sum >= 75)
        g = "B+";
    else if (sum < 75 && sum >= 70)
        g = "B";
    else if (sum < 70 && sum >= 65)
        g = "B-";
    else if (sum < 65 && sum >= 60)
        g = "C+";
    else if (sum < 60 && sum >= 50)
        g = "C";
    else if (sum < 50 && sum >= 45)
        g = "C-";
    else if (sum < 45 && sum >= 40)
        g = "D";
    else if (sum < 40 && sum >= 0)
        g = "F";
    return g;
}
float cgpa(string grade){
    if(grade == "A+" || grade == "A")
        return 4;
    else if (grade == "A-")
        return 3.75;
    else if(grade == "B+")
        return 3.5;
    else if(grade == "B")
        return 3;
    else if(grade == "B-")
        return 2.75;
    else if(grade == "C+")
        return 2.5;
    else if(grade == "C")
        return 2;
    else if(grade == "C-")
        return 1.75;
    else if(grade == "D")
        return 1;
    else
        return 0;
}
void stat(){
    ifstream sread("student.txt");
    vector<string> lines;
    string line;
    int sweg_c,arc_c,civ_c,elec_c;
    while(getline(sread, line))
        lines.push_back(line);
    for(int i = 0; i < lines.size();i++){
        istringstream iss(lines[i]);
        while(iss>>line>>line>>line>>line>>line){
            if(line == "sweg")
                sweg_c++;
            else if(line == "arc")
                arc_c++;
            else if(line == "civ_c")
                civ_c++;
            else
                elec_c++;
        }
    }
}
