#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef double baht;

typedef struct _Member_ {
    char name[100];
    baht asset;

} Member;

typedef struct _Party_{
    char name[100];
    Member members[10];

} Party;

void pay_tax(Member* m, double tax_rate){
    printf("// Before pay: asset = %.2lf\n", m->asset);
    m->asset -= m->asset * (tax_rate / 100);
    printf("// After pay: asset = %.2lf\n", m->asset);

}

void add_member(Party* p, int index, char member_name[], baht asset){
    strcpy(p->members[index].name, member_name);
    p->members[index].asset = asset;


}

char* find_greatest_asset(Party p, int count){
    Member* max_member = p.members;

    for (int i = 1; i < count; i++){

        if ((max_member+i)->asset > max_member->asset) {
            max_member = max_member+i;
        }
    }

    char* name = (char*) malloc(strlen(max_member->name) * sizeof(char));
    strcpy(name, max_member->name);
    return name;

}

int main(){
    Party party1;
    strcpy(party1.name, "Pak pon");

    strcpy(party1.members[0].name, "Prayad");
    party1.members[0].asset = 500000000;

    strcpy(party1.members[1].name, "Pratad");
    party1.members[1].asset = 100000000; 

    add_member(&party1, 2, "Palad", 500000);

    pay_tax(&party1.members[0], 7.5); // 7.5%
    pay_tax(&party1.members[1], 10);
    pay_tax(&party1.members[2], 2);


    printf("--------------------------- Party ---------------------------\n");
    printf("Party Name: %s\n", party1.name);
    for (int i = 0; i < 3; i++){

        printf("[%d] (Name: %s, asset: %.2lf) \n", i+1, party1.members[i].name, party1.members[i].asset);
    }

    printf("%s has greastest asset !!!", find_greatest_asset(party1, 3));



    return 0;
}