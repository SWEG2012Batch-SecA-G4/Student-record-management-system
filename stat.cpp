#include<iostream>
using namespace std;
int main(){
    int n;
    double studentgpa[n];
    int exe = 0,vgood = 0,good = 0,ni = 0,fail = 0;
    for(int i = 0; i < n; i++){
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
}