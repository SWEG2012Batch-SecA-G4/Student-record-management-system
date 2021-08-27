#include<iostream>
using namespace std;
 void display_student(student stud[],int studNum,int name_length,int dep_length )
    {

       cout<<"______________________________________________________________________________________________________________"<<endl;
        cout<<"| full name        |ID     |gender| academic year| department | GPA  | dorm building number| dorm room number|"<<endl;
        cout<<"|__________________|_______|______|______________|____________|______|_____________________|_________________|"<<endl;
        for(int i=0;i<studNum;i++)
{
        cout<<"|"<<stud[i].fullname;
        if(name_length==18)
        {
        cout<<"|"<<stud[i].ID<<"|  "<<stud[i].gender<<"   |   "<<stud[i].academic_year<<"        | "<<stud[i].department<<"   | "<<stud[i].GPA<<" |          "<<stud[i].dorm_building_number<<"         |"<<stud[i].dorm_room_number<<endl;
        }
        else if(name_length<18)
        {
            for(int j=0;j<18-name_length;j++)
        {
            cout<<" ";
        }
        cout<<"|"<<"ETS0015"<<"|  "<<stud[i].gender<<"   |   "<<stud[i].academic_year<<"          | "<<stud[i].department;
        }
        if(dep_length==11)
        {
           cout<<"| "<<stud[i].GPA<<"  |          "<<stud[i].dorm_building_number<<"         |"<<stud[i].dorm_room_number<<endl;
        }
        else if(dep_length<11)
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
       if(course_name_length==15)
        {
         cout<<course[i].course_name<<"|";<<course[i].course_credit_hour<<course[i].course_tutor_hour<<course[i].mark.
        }
         else if(course_name_=15){
            cout<<course[i].course_name<<course[i].course_credit_hour<<course[i].course_tutor_hour<<course[i].mark.
            }

        cout<<"|               |                  |                 |                         |"<<endl;
        cout<<"|_______________|__________________|_________________|_________________________|"<<endl;
        }
        cout<<endl;
     }
int main()
{
   display_student();
   display_course();
}
