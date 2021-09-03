/*
    Determine student status (pass/warning/dismissal)
    Produce various Statistical report (number of students passed, number of warned
                                        number of student dismissed number of  no of.)

            *****Assuming that the marks,  GPA and GCPA********
            */

#include <iostream>
#include <cstring>

using namespace std;
struct stud{//assuming the structure name is stud
 float CGPA;
 char accademiStatus[15];
};
void statusAndStatReport(stud x[], int n, int p, int w, int d){

for(int i = 0; i < n; i++){

  if(x[i].CGPA >= 2){
        strcpy(x[i].accademiStatus , "PROMOTED");
        p++;
  }
  else if (x[i].CGPA >= 1.5 && x[i].CGPA < 2)
  {
      strcpy(x[i].accademiStatus ,"ACADEMIC WARNING");
      w++;
  }
  else if (x[i].CGPA < 1.5){
     strcpy(x[i].accademiStatus , "ACADEMIC DISMISSAL");
     d++;
  }

}
}
int main(){
    int numOfs;

cout<<"Enter number of students: "; cin>>numOfs;
stud stud1[numOfs];

int numOfpassed=0;
int numOfwarning=0;
int numOfdismissed=0;

statusAndStatReport(stud1 , numOfs, numOfpassed, numOfwarning, numOfdismissed);




return 0;
}
