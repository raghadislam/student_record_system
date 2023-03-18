
#include <stdio.h>

int input_Validation(void)
{
    int check;
    do{

    printf("For Admin interface press 1\nFor User interface press 2\n");
    scanf("%d",&check);
    }while(check != 1 && check != 2 && printf("Invalid Number, Please try again...\n"));

   return check;
}
