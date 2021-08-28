#include<iostream>
using namespace std;
 void display_student(student stud[],int studNum,int name_length,int dep_length ) // function to display student record
    {

       cout<<"______________________________________________________________________________________________________________"<<endl;
        cout<<"| full name        |ID     |gender| academic year| department | GPA  | dorm building number| dorm room number|"<<endl;// table made by using cout only
        cout<<"|__________________|_______|______|______________|____________|______|_____________________|_________________|"<<endl;
        for(int i=0;i<studNum;i++)
{
        cout<<"|"<<stud[i].fullname;
        if(name_length==18) // this is to make the table solid and not change when string length of input changes
        {
        cout<<"|"<<stud[i].ID<<"|  "<<stud[i].gender<<"   |   "<<stud[i].academic_year<<"        | "<<stud[i].department<<"   | "<<stud[i].GPA<<" |          "<<stud[i].dorm_building_number<<"         |"<<stud[i].dorm_room_number<<endl;
        }
        else if(name_length<18)
        {
            for(int j=0;j<18-name_length;j++)// if the string length is below 18 it is filled by spaces
        {
            cout<<" ";
        }
        cout<<"|"<<"ETS0015"<<"|  "<<stud[i].gender<<"   |   "<<stud[i].academic_year<<"          | "<<stud[i].department;
        }
        if(dep_length==11)
        {
           cout<<"| "<<stud[i].GPA<<"  |          "<<stud[i].dorm_building_number<<"         |"<<stud[i].dorm_room_number<<endl;
        }
        else if(dep_length<11) // same applies here if it is below 11
        {
            for(int j=0;j<11-dep_length;j++)
        {
            cout<<" ";
        }
          cout<<"| "<<stud[i].GPA<<"  |          "<<stud[i].dorm_building_number<<"         |"<<stud[i].dorm_room_number<<"|"<<endl;
        }
        cout<<"|__________________|_______|______|______________|____________|______|_____________________|_________________|"<<endl;
        cout<<"|abdulsemed muhaba |ETS0015|  M   |   2nd        | software   | 3.82 |          11         |       1         |"<<endl;
        cout<<"|__________________|_______|______|______________|____________|______|_____________________|_________________|"<<endl;
}
        cout<<endl;
    }
     void display_course(course_info course[],int course_name_length)
     {
        cout<<"________________________________________________________________________________"<<endl;
        cout<<"| course name   |course credit hour|course tutor hour| marks                   |"<<endl;
        cout<<"|_______________|__________________|_________________|_________________________|"<<endl;
        for(int i=0;i<3;i++)
        {
       if(course_name_length==16) // if string length is below 16 it is filled with spaces
        {
         cout<<"|"course[i].course_name<<"|"<<course[i].course_credit_hour<<"|"<<course[i].course_tutor_hour<<"|";
        }
         else if(course_name_length<16){
                for(int i=0;i<16-course_name_length;i++)
                {
                    cout<<" ";
                }
            cout<<"|"course[i].course_name<<"|"<<course[i].course_credit_hour<<"|"<<course[i].course_tutor_hour<<"|";
            }
            for(int j=0;j<marksNum;j++)
            {
                cout<<course[i].mark[j]<<" ";
            }
            cout<<endl;

        cout<<"|               |                  |                 |                         |"<<endl;
        cout<<"|_______________|__________________|_________________|_________________________|"<<endl;
        }
        cout<<"|"<<endl;
     }
int main()
{
   int studNum, name_length, dep_length; // studNum is number of students name_length is holder of string length of name for student dep_length is for department string length holder
   int course_name_length; // course_name_length is for course name string length
   display_student(student stud[], studNum, name_length, dep_length);
   display_course(course_info course[], course_name_length);
}
