#include<iostream>
using namespace std;
    void edit() {} // function that edit students record
    void Delete() {}   // function that delete student record  
    void Sort() {}    // function that sort students record
    void  Search_by_id() {}  // function that search students record by id 
    void Search_by_name() {}  // function that search students record by name 
void students() {}  //function to add new students 

void update()
{
    int choice;
    cout<<"Selection your option"<<endl;
    cout<<" 1. To edit students record"<<endl;
    cout<<" 2. To delete students record "<<endl;
    cin>>choice;
    switch (choice)
    {
case 1:
    edit();
    break;
case 2:
    Delete();
    break;
    }
}
void Search()  //menu under student search record
{
    int Search;
    cout<<"Selection your option"<<endl;
    cout<<" 1. To sort students record"<<endl;
    cout<<" 2. To search students record by ID "<<endl;
    cout<<" 3. To search students record by NAME "<<endl;
    cin>>Search;
    switch (Search) 
    {
case 1:
    Sort();
    break;
case 2:
    Search_by_id();
    break;
case 3:
    Search_by_name();
    break;
    }
}
int main()
{
    go:
    bool flag=true;
    int teacher;
    cout<<"Please selection your option"<<endl; //the main body menu 
    cout<<" 1. To add new students"<<endl;
    cout<<" 2. To update students records "<<endl;
    cout<<" 3. To search student records"<<endl;
    cout<<" 4. To exit"<<endl;
    cin>>teacher;
    switch (teacher)
    {
case 1:
    students();
    break;
case 2:
    update();
    break;
case 3:
   Search();
    break;
case 4:
    flag=false;
    break;
    }
    if(flag)
        goto go;
}
