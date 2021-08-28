 #include<iostream>
 #include<iomanip>
 #include<string.h>
 using namespace std;
  class student_info
{
    public:
    char fullname[17];
    int age;
    string ID;
    char gender;
    int academic_year;
    char department[15];
    float GPA;
    int dorm_building_number;
    int dorm_room_number;
};
 void stud_info(student_info stud[],int studNum,int name_length,int dep_length) // name length and dep length are created to hold the string length of name and department respectively
  {
  stud[studNum];
 for(int i=0;i<studNum;i++)
   {
       cout<<"enter the name of student number"<<i+1<<": ";
       cin.ignore();
       cin.get(stud[i].fullname,20);
       cout<<"enter the age of student number"<<i+1<<": ";
       name_length=strlen(stud[i].fullname);
       cin>>stud[i].age;
       cout<<"enter the gender of student number"<<i+1<<": ";
       cin>>stud[i].gender;
       cout<<"enter the department of student number"<<i+1<<": ";
       cin>>stud[i].department;
       dep_length=strlen(stud[i].department);
       cout<<"enter the GPA of student number"<<i+1<<": ";
       cin>>stud[i].GPA;
       cout<<"enter the dorm building number of student number"<<i+1<<": ";
       cin>>stud[i].dorm_building_number;
       cout<<"enter the dorm room number of student number"<<i+1<<": ";
       cin>>stud[i].dorm_room_number;
       cout<<"enter the academic year of student number"<<i+1<<": ";
       cin>>stud[i].academic_year;
   }
}
 int main()
 {
    int studNum;
    int name_length,dep_length;
    cout<<"enter the number of students to add: ";
    cin>>studNum;
student_info stud[studNum];
stud_info(stud,studNum,name_length,dep_length);



 }



