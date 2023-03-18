#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "struct1.h"
#include "system.h"
#include "student.h"
#include "admin.h"


// check ID for Admin


int check_id_admin(void)
{
    int id;
    printf("\nPlease enter your id : ");
    scanf("%d",&id);

    for(int i = 0; i < NumOfAdmins; i++)
    {
       if(id == Admins[i].ID)  return i;
    }

        printf("\nWrong ID, Try again...");
        return check_id_admin();
}


// check password for Admin

int check_pass_admin(void)
{
    char password[PASS_LEN];
    printf("\nPlease enter your password : ");
    scanf("%s",password);


        for(int i = 0; i < NumOfAdmins; i++)
        {

           if(!strcmp(password,Admins[i].password)) return i;
        }

        printf("\nWrong Password, Try again...");
        return check_pass_admin();
}

// Enter Admin Interface

int admin_Validation(void)
{
    int i = check_id_admin();
    check_pass_admin();
    printf("\nHello %s",Admins[i].name);
}



// Admin's Authorizations


int cnt = 10; struct student s1;


extern struct student Grades[NumOfStudents];

// Adding New Student to the system.

void insert(void)
{
	if(cnt == NumOfStudents) {printf("Database id full, can't take more students."); return;}

    printf("\nEnter the roll_num : ");
    scanf("%d",&s1.roll_num);
    printf("\nEnter the Name : ");
    scanf("%s",s1.name);
    printf("\nEnter the math Grade : ");
    scanf("%s",s1.math);
    printf("\nEnter the physics Grade : ");
    scanf("%s",s1.physics);
    printf("\nEnter the chemistry Grade : ");
    scanf("%s",s1.chemistry);
    Grades[cnt].roll_num=s1.roll_num;
    my_strcpy(Grades[cnt].math,s1.math);my_strcpy(Grades[cnt].physics,s1.physics);my_strcpy(Grades[cnt].chemistry,s1.chemistry);
      for(int i = 0; i < my_strlen(s1.name); i++) Grades[cnt].name[i]=s1.name[i];
    cnt++;
}

// delete
void delet(void)
{
    printf("\nEnter the roll_num : ");
    scanf("%d",&s1.roll_num);
    for(int i = 0; i < NumOfStudents; i++)
    {
        if(Grades[i].roll_num==s1.roll_num)
        {

            Grades[i].roll_num=0;
            for(int j=0;j<NAME_LEN;j++)
            Grades[i].name[j] = '\0';
            for(int j=0;j<NAME_LEN;j++)
            {
            Grades[i].math[j]='\0';
            Grades[i].physics[j]='\0';
            Grades[i].chemistry[j]='\0';
            }

        }
    }
}

// Search for existing Student in the system.

void search(void)
{
    printf("\nEnter the roll_num : ");
    scanf("%d",&s1.roll_num);

    int f = 1;
    for(int i = 0; i < NumOfStudents; i++)
    {
        if(Grades[i].roll_num==s1.roll_num)
        {
            printf("\nStudent name : %s",Grades[i].name);
            printf("\n<--------------Your Grades-------------->\n");
            printf("math       -->  %s\n"
                   "physics    -->  %s\n"
                   "chemistry  -->  %s\n",Grades[i].math,Grades[i].physics,Grades[i].chemistry);
            f = 0;
            break;
        }

    if(f) printf("\nNot found");
}
}

// Modify Student's Grade.

void update(void)
{
    int change;
    printf("\nEnter the roll_num : ");
    scanf("%d",&s1.roll_num);
    int f = 1,i;
    for(i = 0; i < NumOfStudents; i++)
    {
        if(Grades[i].roll_num==s1.roll_num) {f = 0; break;}
    }
    if(!f)
    {
        printf("\nYou 'll use these codes m(math),p(physics), c(chemistry),q(quit) ");
         while(1){
        char ch,change[2];
        printf("\nEnter Subject code : ");
        fflush(stdin);fflush(stdout);
        scanf("%c",&ch);
		fflush(stdin);fflush(stdout);
		if (ch == 'q') break;
        printf("\nEnter New Grade : ");
        scanf("%s",change);
		while(getchar() != '\n');
        switch(ch){
        case 'm' : my_strcpy(Grades[i].math,change); break;
        case 'p' : my_strcpy(Grades[i].physics,change); break;
        case 'c' : my_strcpy(Grades[i].chemistry,change); break;
        default  : printf("\nIllegal code");
        }
		printf("\n");
    }
    }
    else printf("\nNot found");
}

// Print All Students' data.

void print(void)
{
    printf("\nStudent roll_num     Student Name     math     physics     chemistry     ");

    for(int i = 0; i < cnt; i++)
    printf("\n    %d           %-17s %-17s %-17s %-17s  ",Grades[i].roll_num,Grades[i].name,Grades[i].math,Grades[i].physics,Grades[i].chemistry);

}
