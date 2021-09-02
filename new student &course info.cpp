 #include<iostream>
 #include<iomanip>
 #include<string.h>
 using namespace std;


    struct student_info // declaration and definition of structure called student info to hold attributes
{
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
void stud_info(student_info stud[],int studNum) // function to accept the student record
{
 stud[studNum];
    for(int i=0;i<studNum;i++) // we use loop as it it is an array structure
   {
       cout<<"enter the name of student number"<<i+1<<": "; // used "i+1" to point to which student the record is being accepted
       cin.ignore();
       cin.get(stud[i].fullname,20);
       cout<<"enter the age of student number"<<i+1<<": ";
       cin>>stud[i].age;
       cout<<"enter the gender of student number"<<i+1<<": ";
       cin>>stud[i].gender;
       cout<<"enter the department of student number"<<i+1<<": ";
       cin>>stud[i].department;
       cout<<"enter the ID of student number"<<i+1<<": ";
       cin>>stud[i].ID;
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
    int studNum; // this is the number of students
    cout<<"enter the number of students to add: ";
    cin>>studNum;
    student_info stu[studNum];
    stud_info(stu,studNum); // calling the function by passing the structure and the number of students

 }
