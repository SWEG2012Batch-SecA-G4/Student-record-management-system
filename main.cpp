#include<iostream>
#include"sms.h"
using namespace std;

int main(){
    int count = 1;
    Students stud[100],new_reg;
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
            cout<<" 3. main menu"<<endl;
            cout<<" 4. EXIT"<<endl;
            cin>>x;
            switch(x){
                case 1:
                    if(count < 1)
                        stud[search(stud,count)] = registration(stud[search(stud,count)]);
                    else
                        cout<<"Empty record\n";
                    break;
                case 2:
                    if(count >= 1)
                        //del(stud[search(stud,count)],stud);
                        ;
                    else
                        cout<<"Empty record\n";
                    break;
                case 3:
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

}