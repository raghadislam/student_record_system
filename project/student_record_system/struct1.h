
#ifndef STRUCT1_H
#define STRUCT1_H

struct admin
{
    int ID;
    char password[PASS_LEN];
    char name[NAME_LEN];
};
struct admin Admins[NumOfAdmins]={{5250,"#100#","Raghad"},{1010,"##300##","Omar"}};

#endif
