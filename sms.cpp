#include<iostream>
#include<algorithm>
#include"sms.h"

void sem_load(Students stud){
    int sum = 0;
    for(int i = 0; i < stud.no_of_course; i++)
        sum+= stud.courses[i].credit + sum;

    if(sum >= 17 && sum <= 19)
        cout<<"Semester Load: NORMAL LOAD\n";
    else if(sum < 17)
        cout<<"Semester Load: UNDER LOAD\n";
    else
        cout<<"Semester Load: OVER LOAD\n";
    //adds all credit hours and calculate semester load
}
void status(double studentgpa[],int size){
    int exe = 0,vgood = 0,good = 0,ni = 0,fail = 0;
    for(int i = 0; i < size; i++){
        if(studentgpa[i] == 4)
            exe++;
        else if(studentgpa[i] < 4 && studentgpa[i] >= 3.5)
            vgood++;
        else if(studentgpa[i] < 3.5 && studentgpa[i] >= 3)
            good++;
        else if(studentgpa[i] < 3 && studentgpa[i] >= 2)
            ni++;
        else if(studentgpa[i] < 2 && studentgpa[i] >= 0)
            fail++;
    }
    //calculates how well students performed
}
void course_input(Students stud){
    for(int i = 0; i < stud.no_of_course; i++){
        cout << "Instructer full name: ";
        cin >> stud.courses[i].instructor[0]>>stud.courses[i].instructor[1];
        cout << "Course name: ";
        cin >> stud.courses[i].name;
        cout << "Course CHr: ";
        cin >> stud.courses[i].credit;
        cout << "Course code: ";
        cin >> stud.courses[i].code;
        }
        //admin access to register courses
}
/*void cgpa(Course course[]){
    int mark;
    for (int i = 0; i < 5; i++)
    {
        if (mark >= 90 && mark < 100)
            course[i].grade = "A+";
        else if (mark < 90 && mark >= 85)
            course[i].grade = "A";
        else if (mark < 85 && mark >= 80)
            course[i].grade = "A-";
        else if (mark < 80 && mark >= 75)
            course[i].grade = "B+";
        else if (mark < 75 && mark >= 70)
            course[i].grade = "B";
        else if (mark < 70 && mark >= 65)
            course[i].grade = "B-";
        else if (mark < 65 && mark >= 60)
            course[i].grade = "C+";
        else if (mark < 60 && mark >= 50)
            course[i].grade = "C";
        else if (mark < 50 && mark >= 45)
            course[i].grade = "C-";
        else if (mark < 45 && mark >= 40)
            course[i].grade = "D";
        else if (mark < 40 && mark >= 0)
            course[i].grade = "F";
        else
            cout << "Mark is out of range!!!";

        float Grade_num[6];

        if (course[i].grade == "A+" || course[i].grade == "A")
            Grade_num[i] = 4;
        else if (course[i].grade == "A-")
            Grade_num[i] = 3.75;
        else if (course[i].grade == "B+")
            Grade_num[i] = 3.5;
        else if (course[i].grade == "B")
            Grade_num[i] = 3;
        else if (course[i].grade == "B-")
            Grade_num[i] = 2.75;
        else if (course[i].grade == "C+")
            Grade_num[i] = 2.5;
        else if (course[i].grade == "C")
            Grade_num[i] = 2;
        else if (course[i].grade == "C-")
            Grade_num[i] = 1.75;
        else if (course[i].grade == "D")
            Grade_num[i] = 1;
        else if (course[i].grade == "F")
            Grade_num[i] = 0;

        double GPA = 0;
        for (int i = 0; i < 6; i++)
        {
            GPA += Grade_num[i];
        }
    }
}*/
Students registration(Students stud){
    cin.ignore();
    cout<<"Enter full name: ";
    getline(cin,stud.fullName,'\n');
    cout<<"Enter id: ";
    cin>>stud.id;
    cout<<"Enter dorm block: ";
    cin>>stud.dorm.block;
    cout<<"Enter dorm room: ";
    cin>>stud.dorm.room;
    cout<<"Enter major: ";
    cin>>stud.major;
    cout<<"Enter department: ";
    cin>>stud.dep.name;
    return stud;
    //admin access to register new students
    //also used to edit students
}
int search(Students stud[],int size){
    string id;
    cout<<"Enter id: ";
    cin>>id;
    for(int i = 0; i < size; i++){
        if(id == stud[i].id){
            cout<<stud[i].fullName<<endl;
            return i;
        }
    }
    cout<<"Not found\n";
    return 0;
    //searches student in database by id
}
void sort(Students stud[],int size){
    string names[size],lnames[size],id[size];
    for(int i = 0; i < size; i++){
        names[i] = stud[i].fullName;
         }
         sort(names,names+size);

         for(int i = 0; i < size; i++)
            cout<<names[i]<<endl;
    //sorts students by id using built in
}
void del(Students stud[],int x,int size){
    for(int i = x; i < size; i++){
        stud[i] = stud[i+1];
    }
    //deletes a single student from database
}
