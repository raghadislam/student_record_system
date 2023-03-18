#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "system.h"
#include "admin.h"
#include "student.h"
#include "app.h"



int main()
{

    if(input_Validation() == 2)
    {
        int id;
        printf("Please enter your id : \n");
        scanf("%d",&id);
        Get_Grades(id);
    }
    else{

        admin_Validation();
         printf("\nYou 'll use these codes i(insert),s(search), u(update), p(print), q(quit).");
    while(1){
        char ch;
        printf("\nEnter operation code : ");
        fflush(stdin);fflush(stdout);
        scanf("%c",&ch);
        fflush(stdin);fflush(stdout);
		while(getchar() != '\n');
        switch(ch){
        case 'i' : insert(); break;
        case 's' : search(); break;
        case 'u' : update(); break;
        case 'p' : print();  break;
        case 'q' : return 0;
        default  : printf("\nIllegal code");
        }
		printf("\n");
    }

    }

    return 0;
}
