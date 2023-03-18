#include <stdio.h>
#include "system.h"
#include "admin.h"
#include "struct.h"
struct student Grades[NumOfStudents]={
    {1112,"A+","A","B+","hamed"  },{3148,"B","B+","B","Ali"   },
    {5555,"A+","A+","A+","Mohsen"},{2641,"B+","A","B+","hagar"},
    {6666,"A+","A","A+","Aya"    },{1212,"A","B","B+","Ahmed" },
    {2651,"A","A","B+","maged"   },{3188,"B","B+","B","salma" },
    {7666,"A+","A","A+","kareem" },{2611,"B+","A","B+","mona"}};

    void Get_Grades(int num)
{
    for(int i = 0; i < NumOfStudents; i++)
    {
        if(num == Grades[i].roll_num) {
            printf("Hello %s\n",Grades[i].name);
            printf("\n<--------------Your Grades-------------->\n");
            printf("maths     -->  %s\n"
                   "physics   -->  %s\n"
                   "chemistry -->  %s\n", Grades[i].math , Grades[i].physics , Grades[i].chemistry );
        }
    }
}
