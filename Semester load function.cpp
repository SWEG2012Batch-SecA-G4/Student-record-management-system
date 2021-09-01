#include<iostream>
using namespace std;
void sem_load(Students stud)    //function work the semester load of students
{
    int sum = 0;
    for(int i = 0; i < stud.no_of_course; i++)
        sum+= stud.courses[i].credit + sum;

    if(sum >= 17 && sum <= 19)
        cout<<"Semester Load: NORMAL LOAD\n";
    else if(sum < 17)
        cout<<"Semester Load: UNDER LOAD\n";
    else
        cout<<"Semester Load: OVER LOAD\n";

}
