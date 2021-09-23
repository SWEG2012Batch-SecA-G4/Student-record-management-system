
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
