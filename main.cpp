#include<iostream>
#include"sms.h"
using namespace std;

Students stud[100];

Users signup(Users acc){
    cout<<"signup page\n";
    cout<<" Enter username: ";
    cin>>acc.username;
    cout<<" Enter password: ";
    cin>>acc.password;
    return acc;
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
}

int admin(){
    Students new_reg;
    int count = 1;
     x: 
    cout<<"Please selection your option"<<endl;
    cout<<" 1. Add new students"<<endl;
    cout<<" 2. Update students records "<<endl;
    cout<<" 3. Search student records"<<endl;
    cout<<" 4. exit"<<endl;
    int x;
    cin>>x;
    switch(x){
        case 1:
            stud[count] = registration(new_reg);
            count++;
            break;
        case 2:
            cout<<" 1. Edit students record"<<endl;
            cout<<" 2. Delete students record "<<endl;
            cout<<" 3. Delete all records"<<endl;
            cout<<" 4. main menu"<<endl;
            cout<<" 5. EXIT"<<endl;
            cin>>x;
            switch(x){
                case 1:
                    if(count > 1){
                        int ret = search(stud,count);
                        stud[ret] = registration(stud[ret]);
                    }
                    else
                        cout<<"Empty record\n";
                    break;
                case 2:
                    if(count >= 1){
                        del(stud,search(stud,count),count);
                        count--;
                    }
                    else
                        cout<<"Empty record\n";
                        count = 1;
                    break;
                case 3:
                    delall(stud,count);
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
            switch(x){
                case 1:
                    
                    sort(stud,count);
                    break;
                case 2:
                    search(stud,count);
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
    goto x;
    return 0;
}
void teacher(){

}
void student(){
    
}
int main(){
    cout<<"Student Record Management System\n";
    cout<<"Welcome!\n";
    first:
    cout<<" 1. Admin page\n 2. Teacher page\n 3. Student page\n 4. Exit\n -- ";
    int user,userCount = 0,log;
    cin>>user;
    if(user != 1 && user != 2 && user != 3)
        return 0;
    Users account[10];    
    cout<<" 1. signup\n 2. login\n --";
    cin>>log;
    if((userCount == 0 && log == 2) || log == 1){
        if((userCount == 0 && log == 2))
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
        if(userCount != 0){
            int flag = login(account,userCount);
            if(flag != -1){
                if(account[flag].type == "admin"){
                    admin();
                }
            }
            else if(flag == -1)
                cout<<"No account found\n";
                goto first;
        }
}