#include <iostream>
using namespace std;

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
}

int main(){
    Students stud;
    course_input(stud);
}
