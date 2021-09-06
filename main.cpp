#include<iostream>
#include<string.h>
#include"sms.h"
using namespace std;

Students stud[100];
Users account[100];
Department sweg,civ,elec,arc;
int userCount = 0,count = 1,courseCount = 0;


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
    cout<<" Enter username: ";
    cin>>username;
    cout<<" Enter password: ";
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
    cout<<" 1. Student database\n 2. Department database\n 3. Back\n 4.Exit\n -- ";
    Students new_reg;
    cin>>choice;
    system("cls");
    switch(choice){
        //if admin chhose student database the functionalitis below will be avialable
        case 1:
            a:
            cout<<"Please selection your option"<<endl;
            cout<<" 1. Add new students"<<endl;
            cout<<" 2. Update students records "<<endl;
            cout<<" 3. Search student records"<<endl;
            cout<<" 4. back"<<endl;
            cout<<" 5. Main menu\n --";
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
                    cout<<" 5. Back"<<endl;
                    cout<<" 6. Exit"<<endl<<" --";
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
                        case 5:
                            goto a;
                            break;
                        default:
                            return 0;
                    }
                    break;
                case 3:
                    cout<<" 1. Sort by name"<<endl;
                    cout<<" 2. Search by id"<<endl;
                    cout<<" 3. main menu"<<endl;
                    cout<<" 4. Back"<<endl;
                    cout<<" 5. EXIT"<<endl<<" --";
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
                        case 4:
                            goto a;
                        default:
                            return 0;
                    }
                    break;
                case 4:
                    goto x;
                    break;
                default:
                    return 0;
            }
            break;
            case 2:
                b:
                cout<<" 1. Department of software engineering\n";
                cout<<" 2. Department of architectural engineering\n";
                cout<<" 3. Department of electrical engineering\n";
                cout<<" 4. Department of civil engineering\n";
                cout<<" 5. Back\n";
                cout<<" 6. Main menu\n";
                cout<<" --";
                cin>>choice;
                system("cls");
                switch(choice){
                    case 1:
                        cout<<" Welcome to Department of Software Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Main menu\n";
                        cout<<" 3. Back\n";
                        cout<<" 4. Main menu\n --";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1://add course to software department
                                cout<<"Course name: ";
                                cin>>sweg.courses[sweg.count].name;
                                cout<<"Instructors name: ";
                                cin>>sweg.courses[sweg.count].instructor[0]>>sweg.courses[sweg.count].instructor[1];
                                teacher_signup(sweg.courses[sweg.count].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>sweg.courses[sweg.count].year;
                                cout<<"Course credit: ";
                                cin>>sweg.courses[sweg.count].credit;
                                cout<<"Course code: sweg\n";
                                sweg.code = "sweg";
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>sweg.courses[sweg.count].pre_req;
                                sweg.count++;
                                break;
                            case 2:
                                goto x;
                                break;
                            case 3:
                                goto b;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    case 2://add course to arc department
                        cout<<" 1. Add course\n";
                        cout<<" 2. Main menu\n";
                        cout<<" 3. Back\n";
                        cout<<" 4. Main menu\n --";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>arc.courses[arc.count].name;
                                cout<<"Instructors name: ";
                                cin>>arc.courses[arc.count].instructor[0]>>sweg.courses[arc.count].instructor[1];
                                teacher_signup(arc.courses[arc.count].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>arc.courses[arc.count].year;
                                cout<<"Course credit: ";
                                cin>>arc.courses[arc.count].credit;
                                cout<<"Course code: arc\n";
                                sweg.code = "arc";
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>arc.courses[arc.count].pre_req;
                                arc.count++;
                                break;
                           case 2:
                                goto x;
                                break;
                            case 3:
                                goto b;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    case 3://add course to electrical
                        cout<<" Welcome to Department of Electrical Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Main menu\n";
                        cout<<" 3. Back\n";
                        cout<<" 4. Main menu\n --";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>elec.courses[elec.count].name;
                                cout<<"Instructors name: ";
                                cin>>elec.courses[elec.count].instructor[0]>>sweg.courses[elec.count].instructor[1];
                                teacher_signup(elec.courses[elec.count].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>elec.courses[elec.count].year;
                                cout<<"Course credit: ";
                                cin>>elec.courses[elec.count].credit;
                                cout<<"Course code: elec\n";
                                sweg.code = "elec";
                                cout<<" Prerequesit (if not available type no): ";
                                cin>>elec.courses[elec.count].pre_req;
                                elec.count++;
                                break;
                            case 2:
                                goto x;
                                break;
                            case 3:
                                goto b;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    case 4://add course to civil
                        cout<<" Welcome to Department of Civil Engineering\n";
                        cout<<" 1. Add course\n";
                        cout<<" 2. Main menu\n";
                        cout<<" 3. Back\n";
                        cout<<" 4. Main menu\n --";
                        cin>>choice;
                        system("cls");
                        switch(choice){
                            case 1:
                                cout<<"Course name: ";
                                cin>>civ.courses[civ.count].name;
                                cout<<"Instructors name: ";
                                cin>>civ.courses[civ.count].instructor[0]>>sweg.courses[civ.count].instructor[1];
                                teacher_signup(civ.courses[civ.count].instructor[0]);
                                userCount++;
                                cout<<"Course year: ";
                                cin>>civ.courses[civ.count].year;
                                cout<<"Course credit: ";
                                cin>>civ.courses[civ.count].credit;
                                cout<<"Course code: civ\n";
                                sweg.code = "civ";
                                cout<<" Prerequesite (if not available type no): ";
                                cin>>civ.courses[civ.count].pre_req;
                                civ.count++;
                                break;
                            case 2:
                                goto x;
                                break;
                            case 3:
                                goto b;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    case 5:
                        goto x;
                    default:
                        return 0;

                }
                break;
            case 3:
            default:
                return 0;
        }
    goto x;
    return 0;
}
void teacher(int index){
    a:
    system("cls");
    cout<<" 1. My students\n";
    cout<<" 2. Back\n";
    cout<<" 3. Main menu\n --";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<" 1. Grading\n";
            cout<<" 2. Back\n";
            cout<<" 3. Main menu\n --";
            cin>>choice;
            switch(choice){
            case 1:
                int x = search(stud,count),i;
                double sum = 0;
                bool flag = false;
                for(i = 0; i < 10; i++)
                    if(stud[x].courses[i].instructor[0] == account[index].username){
                        flag = true;
                        break;
                    }
                if(flag){
                    again:
                    for(int j = 0; j < 5; j++){
                        system("cls");
                        cout<<"Name\tID\t5%\t5%\t10%\t30%\t50%\t100%\tGrade\n";
                        cout<<stud[x].fullName<<"\t"<<stud[x].id<<"\t";
                        for(int k = 0; k <= j; k++)
                            cout<<stud[x].courses[i].mark[k]<<"\t";
                        cout<<" Mark "<<j+1<<" :";
                        cin>>stud[x].courses[i].mark[j];
                        sum+=stud[x].courses[i].mark[j];
                    }
                        system("cls");
                        cout<<"Name\tID\t5%\t5%\t10%\t30%\t50%\t100%\tGrade\n";
                        cout<<stud[x].fullName<<"\t"<<stud[x].id<<"\t";
                        for(int k = 0; k < 5; k++)
                            cout<<stud[x].courses[i].mark[k]<<"\t";
                        cout<<sum<<"\t";
                        if(sum >= 90 && sum <=100)
                            stud[x].courses[i].grade = "A+";
                        else if (sum < 90 && sum >= 85)
                            stud[x].courses[i].grade = "A";
                        else if (sum < 85 && sum >= 80)
                            stud[x].courses[i].grade = "A-";
                        else if (sum < 80 && sum >= 75)
                            stud[x].courses[i].grade = "B+";
                        else if (sum < 75 && sum >= 70)
                            stud[x].courses[i].grade = "B";
                        else if (sum < 70 && sum >= 65)
                            stud[x].courses[i].grade = "B-";
                        else if (sum < 65 && sum >= 60)
                            stud[x].courses[i].grade = "C+";
                        else if (sum < 60 && sum >= 50)
                            stud[x].courses[i].grade = "C";
                        else if (sum < 50 && sum >= 45)
                            stud[x].courses[i].grade = "C-";
                        else if (sum < 45 && sum >= 40)
                            stud[x].courses[i].grade = "D";
                        else if (sum < 40 && sum >= 0)
                            stud[x].courses[i].grade = "F";
                        else{
                            cout << "Mark is out of range!!!";
                            goto again;
                        }
                        cout<<stud[x].courses[i].grade;
                    _getwch();

                }
                else
                    cout<<"Student not found\n";
                    _getwch();
                break;
            }
            break;
        case 2:
            goto a;
            break;
        default:
            break;
    }
}
void student(int index){
    system("cls");
    cout<<" 1. Add course\n";
    cout<<" 2. View grade\n";
    cout<<" 3. view other details\n";
    cout<<" 4. Back\n";
    cout<<" 5. Main menu\n";
    int choose;
    cin>>choose;//choose functionality
    switch(choose){
    case 1:
        cout<<"Choose course\n";//check which department the student joined
        if(stud[index].dep.name == "sweg"){
            for(int i = 0; i < sweg.count;i++){//print all available courses
               cout<<" "<<i+1<<". "<<sweg.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < sweg.count;i++){
               if(choose == i+1)
                    stud[index].courses[x] = sweg.courses[i];//student chooses courses
                    x++;
            }
            stud[index].dep.code = "sweg";
            cout<<"courses added!";
            _getwch();
        }
        else if(stud[index].dep.name == "arc"){
            for(int i = 0; i < arc.count;i++){
               cout<<" "<<i+1<<". "<<arc.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < arc.count;i++){
               if(choose == i+1)
                    stud[index].courses[x] = arc.courses[i];
                    x++;
            }
            stud[index].dep.code = "arc";
            cout<<"courses added!";
            _getwch();
        }
        else if(stud[index].dep.name == "elec"){
            for(int i = 0; i < elec.count;i++){
               cout<<" "<<i+1<<". "<<elec.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < elec.count;i++){
               if(choose == i+1)
                    stud[index].courses[x] = elec.courses[i];
                    x++;
            }
            stud[index].dep.code = "elec";
            cout<<"courses added!";
            _getwch();
        }
        else if(stud[index].dep.name == "civ"){
                for(int i = 0; i < civ.count;i++){
               cout<<" "<<i+1<<". "<<civ.courses[i].name<<endl;
            }
            cin>>choose;
            int x = 0;
            for(int i = 0; i < civ.count;i++){
               if(choose == i+1)
                    stud[index].courses[x] = civ.courses[i];
                    x++;
            }
            stud[index].dep.code = "civ";
            cout<<"courses added!";
            _getwch();
        }
        break;
        case 2:
            system("cls");
            cout<<"Name\tID\t5%\t5%\t10%\t30%\t50%\t100%\tGrade\n";
            cout<<stud[index].fullName<<"\t"<<stud[index].id<<"\t";
                if(stud[index].dep.code == "sweg")
                    for(int i = 0; i < sweg.count; i++){
                        for(int k = 0; k < 5; k++)
                            cout<<stud[index].courses[i].mark[k]<<"\t";
                        cout<<endl;
                    }
                else if(stud[index].dep.code == "arc")
                   for(int i = 0; i < arc.count; i++){
                        for(int k = 0; k < 5; k++)
                            cout<<stud[index].courses[i].mark[k]<<"\t";
                        cout<<endl;
                    }
                else if(stud[index].dep.code == " elec")
                    for(int i = 0; i < elec.count; i++){
                        for(int k = 0; k < 5; k++)
                            cout<<stud[index].courses[i].mark[k]<<"\t";
                        cout<<endl;
                    }
                else if(stud[index].dep.code == "civ")
                    for(int i = 0; i < civ.count; i++){
                        for(int k = 0; k < 5; k++)
                            cout<<stud[index].courses[i].mark[k]<<"\t";
                        cout<<endl;
                    }
                    
        _getwch();
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
    cout<<" 1. Admin page\n 2. Other users page\n 3. Back\n -- ";
    int user,log;
    cin>>user;
    if(user != 1 && user != 2)
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
            _getwch();
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
