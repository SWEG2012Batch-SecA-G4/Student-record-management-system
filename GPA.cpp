#include <iostream>
using namespace std;
//a function for calculating GPA by taking parameters for the structure Course
void cgpa(Course course[]){
    int mark;
    for (int i = 0; i < 6; i++)
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
        int total_credit=0;
        for (int i = 0; i < 6; i++)
        {
            GPA += Grade_num[i];
            total_credit+=credit[i];
            GPA=GPA/total_credit;
        }
    }
}

int main(){
    int n; //size of array will be determined by other functions
    Course course[n];
    cgpa(course);

}