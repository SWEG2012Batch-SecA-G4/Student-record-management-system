#include<iostream>
#include<string.h>
#include"sms.h"
using namespace std;

Students stud[100];
Users account[100];
int userCount = 0,count = 1,courseCount = 0;
Department sweg,civ,elec,arc;

void stud_signup(Students stud){
    char name[stud.fullName.length()];
    for(int i = 0; i < stud.fullName.length();i++ ){
        if(stud.fullName[i] == 32)
            break;
        else
            name[i] = stud.fullName[i];
    }
    account[userCount].username = name;
    account[userCount].password = "student2013";
    //account created automatically when a new student registeres
    //password is default
}
void teacher_signup(string name){
    account[userCount].username = name;
    account[userCount].password = "teacher2013";
    account[userCount].type = "teacher";
    //account created automatically when a new student registeres
    //password is default
}
Users signup(Users acc){
    cout<<"signup page\n";
    cout<<" Enter username: ";
    cin>>acc.username;
    cout<<" Enter password: ";
    cin>>acc.password;
    return acc;
    //signs up admin
}

int login(Users acc[],int size){
    string username,password;
    cout<<"login page\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    for(int i=0;i<size;i++){
        if(username == acc[i].username && password == acc[i].password)
            return i;
    }
    return -1;
    //checks if credentials entered are correct then returns the index if true
    //if no match was found, -1 would be returned
}

int admin(int index){
    int choice;
    x:
    system("cls"); // admin can access and modify students and department details so thus will be among his choices
    cout<<" 1. Student database\n 2. Department database\n 3. Back\n -- ";
    Students new_reg;
    cin>>choice;
    system("cls");
    switch(choice){
        //if admin chhose student database the functionalitis below will be avialable
        case 1:
            cout<<"Please selection your option"<<endl;
            cout<<" 1. Add new students"<<endl;
            cout<<" 2. Update students records "<<endl;
            cout<<" 3. Search student records"<<endl;
            cout<<" 4. exit"<<endl;
            int x;
            cin>>x;
            system("cls");
            switch(x){
                case 1:
                    //takes a single student to registration function then registers it to stud array
                    stud[count] = registration(new_reg);
                    account[userCount].type = "student";
                    stud_signup(stud[count]);
                    //every time a new student is added a new account is created, thus both usercount and student count will increase by 1
                    userCount++;
                    count++;
                    break;
                case 2:
                    cout<<" 1. Edit students record"<<endl;
                    cout<<" 2. Delete students record "<<endl;
                    cout<<" 3. Delete all records"<<endl;
                    cout<<" 4. main menu"<<endl;
                    cout<<" 5. EXIT"<<endl;
                    cin>>x;
                    system("cls");
                    switch(x){
                        case 1:
                            //to edit is like re registration
                            if(count > 1){
                                int ret = search(stud,count);
                                stud[ret] = registration(stud[ret]);
                            }
                            else
                                cout<<"Empty record\n";
                                _getwch();
                            break;
                        case 2:
                            //takes a single student to delete function
                            if(count >= 1){
                                del(stud,search(stud,count),count);
                                count--; //count is decremented because one student was deleted
                            }
                            else
                                cout<<"Empty record\n";
                                _getwch();
                            break;
                        case 3:
                            count = 1;//count is reset to one so that all students are unaccessable
                            //thus all new registers will over ride the old data
                            break;
                        case 4:
                            goto x;
                            break;
                        default:
                            return 0;
                    }
                    break;
                case 3:
                    cout<<" 1. Sort by name"<<endl;
                    cout<<" 2. Search by id"<<endl;
                    cout<<" 3. main menu"<<endl;
                    cout<<" 4. EXIT"<<endl;
                    cin>>x;
                    system("cls");
                    switch(x){
                        case 1:
                            if(count <= 1)
                                cout<<"Empty record!\n";
                            sort(stud,count);//all students will be sorted by alphabetical order
                            _getwch();
                            break;
                        case 2:
                            search(stud,count);//search function searches students by id
                            _getwch();
                            break;
                        case 3:
                            goto x;
                            break;
                        default:
                            return 0;
                    }
                    break;
                default:
                    return 0;
            }
            break;
            case 2:
                cout<<" 1. Department of software engineering\n";
                cout<<" 2. Department of architectural engineering\n";
                cout<<" 3. Department of electrical engineering\n";
                cout<<" 4. Department of civil engineering\n";
                cout<<" --";
                cin>>choice;
                system("cls");
                switch(choice){
                    case 1:
                        cout<<" Welcome to Department of Software Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Exit\n";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1://add course to software department
                                cout<<"Course name: ";
                                cin>>sweg.courses[courseCount].name;
                                cout<<"Instructors name: ";
                                cin>>sweg.courses[courseCount].instructor[0]>>sweg.courses[courseCount].instructor[1];
                                teacher_signup(sweg.courses[courseCount].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>sweg.courses[courseCount].year;
                                cout<<"Course credit: ";
                                cin>>sweg.courses[courseCount].credit;
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>sweg.courses[courseCount].pre_req;
                                cout<<"Course code: sweg";
                                courseCount++;
                                break;
                            default:
                                goto x;
                                break;
                        }
                        break;
                    case 2://add course to arc department
                        cout<<" Welcome to Department of Architecture\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Exit\n";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>arc.courses[courseCount].name;
                                cout<<"Instructors name: ";
                                cin>>arc.courses[courseCount].instructor[0]>>sweg.courses[courseCount].instructor[1];
                                teacher_signup(arc.courses[courseCount].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>arc.courses[courseCount].year;
                                cout<<"Course credit: ";
                                cin>>arc.courses[courseCount].credit;
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>arc.courses[courseCount].pre_req;
                                cout<<"Course code: arc";
                                break;
                            default:
                                goto x;
                                break;
                        }
                        break;
                    case 3://add course to electrical
                        cout<<" Welcome to Department of Electrical Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Exit\n";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>elec.courses[courseCount].name;
                                cout<<"Instructors name: ";
                                cin>>elec.courses[courseCount].instructor[0]>>sweg.courses[courseCount].instructor[1];
                                teacher_signup(elec.courses[courseCount].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>elec.courses[courseCount].year;
                                cout<<"Course credit: ";
                                cin>>elec.courses[courseCount].credit;
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>elec.courses[courseCount].pre_req;
                                cout<<"Course code: elec";
                                break;
                            default:
                                goto x;
                                break;
                        }
                        break;
                    case 4://add course to civil
                        cout<<" Welcome to Department of Civil Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Exit\n";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>civ.courses[courseCount].name;
                                cout<<"Instructors name: ";
                                cin>>civ.courses[courseCount].instructor[0]>>sweg.courses[courseCount].instructor[1];
                                teacher_signup(civ.courses[courseCount].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>civ.courses[courseCount].year;
                                cout<<"Course credit: ";
                                cin>>civ.courses[courseCount].credit;
                                cout<<" Prerequesite (if not available type no): ";
                                cin>>civ.courses[courseCount].pre_req;
                                cout<<"Course code: civ";
                                break;
                            default:
                                goto x;
                                break;
                        }
                        break;
                }
                break;
            default:
                return 0;
        }
    goto x;
    return 0;
}
void teacher(int index){
    system("cls");
}
void student(int index){
    system("cls");
    cout<<" 1. Add course\n";
    cout<<" 2. View grade\n";
    cout<<" 3. view other details\n";
    int choose;
    cin>>choose;
    switch(choose){
    case 1:
        cout<<"Choose course\n";
        if(stud[index].dep.name == "sweg"){
            for(int i = 0; i < courseCount;i++){
               cout<<" "<<i+1<<". "<<sweg.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < courseCount;i++){
               if(choose == i+1)
                    stud[index].courses[x] = sweg.courses[i];
                    x++;
            }
        }
        else if(stud[index].dep.name == "arc"){
            for(int i = 0; i < courseCount;i++){
               cout<<" "<<i+1<<". "<<arc.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < courseCount;i++){
               if(choose == i+1)
                    stud[index].courses[x] = arc.courses[i];
                    x++;
            }
        }
        else if(stud[index].dep.name == "elec"){
            for(int i = 0; i < courseCount;i++){
               cout<<" "<<i+1<<". "<<elec.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < courseCount;i++){
               if(choose == i+1)
                    stud[index].courses[x] = elec.courses[i];
                    x++;
            }
        }
        else if(stud[index].dep.name == "civ"){
                for(int i = 0; i < courseCount;i++){
               cout<<" "<<i+1<<". "<<civ.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < courseCount;i++){
               if(choose == i+1)
                    stud[index].courses[x] = civ.courses[i];
                    x++;
            }
        }
        break;
    }
}
int main(){
     first:
    system("cls");
    cout<<"Student Record Management System\n";
    cout<<"Welcome!\n";
   //all users are accessable to the login page, but as per the type of account the functionalities differ
          //but only admin can sign up
    cout<<" 1. Admin page\n 2. Teacher page\n 3. Student page\n 4. Back\n -- ";
    int user,log;
    cin>>user;
    if(user != 1 && user != 2 && user != 3)
        return 0;
    system("cls");
    cout<<" 1. signup\n 2. login\n --";
    cin>>log;
    if((userCount == 0 && log == 2) || log == 1){//if no account was created before or the user choose to sign up
            system("cls");
        if((userCount == 0 && log == 2))//if no account was avialable and user chose to login
            cout<<"No account available\n";
            if(user==1){
            account[userCount].type = "admin";
            account[userCount] = signup(account[userCount]);
            userCount++;
        }
        else{
            cout<<"account can only be created by admin! \n";
            goto first;
        }
       }
        if(userCount != 0){//uses the login function to check credentials and confirm accessability
                //as per accessability all users will be directed to there own functions
            system("cls");
            int flag = login(account,userCount);
            if(flag != -1){
                system("cls");
                if(account[flag].type == "admin"){
                    admin(flag);
                }
                if(account[flag].type == "teacher"){
                    teacher(flag);
                }
                else if(account[flag].type == "student"){
                    student(flag);
                }
            }
            else if(flag == -1){
                cout<<"No account found\n";
                _getwch();
            }
                goto first;
        }
}
