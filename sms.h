#ifndef _SMS
#define _SMS
using namespace std;
struct Dorm{
    int block,room;
};
struct Users{
    string username,password;
};
struct Course{
    string name,instructor[2],code,pre_request,grade;
    int credit;
    double mark;
};
class Students{
    public:
        string fullName,id;
        string major;
        int no_of_course;
        Dorm dorm;        
        Course courses[10];
};

void sem_load(int [],int);
void status(double [], int);
void course_input(Students);
void cgpa(Course []);
Students registration(Students);
int search(Students[],int);
void sort(Students [],int);

#endif