#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void acc();
void deposit();
void take();
int login();
void edit();
void delete();
void view();
struct pass
{
    int month;
    int day;
    int year;
    char password[20];
    char username[20];
    int number;
};
struct money
{
    int floos;
};




int main(){

    struct money u2;
    struct pass u1;

    FILE *q;
    q = fopen("infp.txt","r");
    fread(&u2,sizeof(struct money),1,q);


    system("color f1");

    int answer;
    fclose(q);
    printf("|------HELLO TO THE BANK------|\n");
    printf("| 1...  CREANTE AN ACCOUNT    |\n");
    printf("| 2...ALREADY A USER? SIGN IN |\n");
    printf("|______ENTER YOUR CHOICE______|\nn:?");
    scanf("%d",&answer);


    switch (answer)
    {
    case 1:
        acc();
        break;
    

    case 2:
        login();
        break;

        
    case 3:
        view();
        break;
    }

    
    return 0;

    
}


void acc(){
    FILE *info ,*q;
    q = fopen("infp.txt","w");
    info = fopen("info.txt","w");
    struct pass u1;
    struct money u2;
    u2.floos =0;
    printf("YOU CHOOSE 1 CREATING AN ACCOUNT\n");
    printf("---CREATING ACCOUNT---\n");

    printf("WAHTS YOUR NAME:");
    scanf("%s",&u1.username);

    while (strlen(u1.username)<=2){
        printf("THE USER NAME IS TOO SHORT\n");
        printf("WAHTS YOUR NAME:");
        scanf("%s",&u1.username);
    };

    printf("WAHTS YOUR BIRTH DAY:");
    scanf("%d",&u1.day);
    while (u1.day > 30){
        printf("HOW CAN YOUR BIRTH DAY IS LARGER THAN 30\n");
        printf("TRY ANGIN WAHTS YOUR BIRTH DAY:");
        scanf("%d",&u1.day);
    };

    printf("WAHTS YOUR BIRTH MONTH:");
    scanf("%s",&u1.month);
        while (u1.month <= 12){
        printf("HOW CAN YOUR BIRTH MONTH IS LARGER THAN 12\n");
        printf("TRY ANGIN WAHTS YOUR BIRTH MONTH:");
        scanf("%d",&u1.month);
    };


        printf("WAHTS YOUR BIRTH YEAR:");
    scanf("%s",&u1.year);

    
    while (u1.year < 1800 || u1.year < 2024 ){
        printf("HOW CAN YOUR BIRTH YEAR IS LARGER THAN 2024\n");
        printf("TRY ANGIN WAHTS YOUR BIRTH MONTH:");
        scanf("%d",&u1.year);
    };
    
    printf("CHOOSE YOUR PASSWORD");
    scanf("%s",&u1.password);

    printf("MAKE A NUMBER FOR THE ACC AND DONOT FORGET IT");
    printf("ONLY 4 DIGET:");
    scanf("%d",&u1.number);

    printf("----CREATING THE ACC----\n");
    
        printf("[");
    int a;//this number will be used not now tho
    for(int i = 0; i <= 20; i++){//the number that greater than i is how many dots(.) should print before it stops
        for(int j = 0; j <30000 ;j++){//the number that greater than j is the time for each dot 
            a=j;
        }
        printf("#");//it can be somthing else like (#) or anything 
    }
    printf("]");



    printf("\n-----ACCOUNT CREATED SUCCESSFULLY-----\n");

    fwrite(&u1 , sizeof(struct pass), 1,info);
    fwrite(&u2,sizeof(struct money),1,q);
    fclose(info);
    fclose(q);

}

int login(){
    FILE *info;
    info = fopen("info.txt","r");
    int choise;
    char username[20];
    int num;
    char password[20];
    struct pass u1;
    
    printf("WHATS YOUR USERNAME:");
    scanf("%s",&username);

    printf("ENTER YOUR PASSWORD:");
    scanf("%s",&password);

    printf("WHATS THE ACCOUNT NUMBER:");
    scanf("%d",&num);

    while(fread(&u1,sizeof(struct pass),1,info)){
        if(!strcmp(u1.username,username)){
            if(!strcmp(u1.password,password)){
                if(u1.number == num){
                printf("\n\n|------  HELLO MR.%s ------|\n",u1.username);
                printf("| 1...    DEPOSIT MONYE       |\n");
                printf("| 2...     TAKE MONEY         |\n");
                printf("| 3...    EDIT ACCOUNT        |\n");
                printf("| 4...    DELETE ACCOUT       |\n");
                printf("| 5...  VIEW ACCOUNT INFO     |\n");
                printf("|______ENTER YOUR CHOICE______|:?");
                scanf("%d",&choise);
                }else{
                printf("SOMTHNG IS WRONG");
            }
            }
        }
    }
        switch (choise)
        {
        case 1:
            deposit();
            break;
        case 2 :
            take();
            break;
        case 3 :
            edit();
            break;
        case 4: 
            delete();
        case 5: 
            view();
        }
        fclose(info);
        return 0;
    } 





void delete(){
    system("cls");
    FILE *info,*q ;
    info =fopen("info.txt","w");
    q =fopen("infp.txt","w");
    struct money u2;
    struct pass u1;
    fprintf(info ,"f");

    printf("[");
    int y =0;
    for(int i = 0 ; i <= 20 ;i++){
        for(int j = 0;j <4000;j++){
            y=j;
        }
        printf(".");
    }
    printf("]\n");
    printf("YOUR ACCOUNT HAS BEEN SUCCESFUL DELETED :)");




}
void deposit(){
    system("cls");
    FILE *info,*q ;
    info =fopen("info.txt","a+");
    q =fopen("infp.txt","rb");
    int theRealMoney;
    struct money u2;
    struct pass u1;
    fread(&u2,sizeof(u2),1,q);
    fclose(q);

    printf("WE WILL TAKE A 50D FEED :)\n");
    printf("HOW MUCH DO U WANT TO DEPOSIT?:");
    scanf("%d",&theRealMoney);
        while (theRealMoney >100000)
        {
            printf("ITS A LOT OF MONEY");
        }
        
    printf("THIS WILL TAKE A WHILE\n");




    printf("]");
    printf("\n----THE MONEY HAS BEEN TRASFROMED SUCCESSFULLY----\n");

    theRealMoney /= 2;
    u2.floos =  u2.floos + theRealMoney;

    q =fopen("infp.txt","wb");

    printf("---YOU HAVE %d IN YOUR ACCOUNT---",u2.floos);

    fwrite(&u2 , 1, sizeof(struct money),q);
    fclose(info);
    fclose(q);
}
void take(){
    system("cls");
    struct pass u1;
    struct money u2;
    FILE *info,*q;
    info = fopen("info.txt","r");
    q =fopen("infp.txt","rb");
    fread(&u1,sizeof(struct pass),1,info);
    fread(&u2,sizeof(struct pass),1,q);
    fclose(info);
    fclose(q);

    int answer,money;
    printf("HELLO MR.%s\n",u1.username);
    printf("IF YOU WANT TO SEE HOW MUCH MONEY DO YOU HAVE PRESS 1 IF NOT PRESS 2");
    scanf("%d",&answer);
    switch (answer)
    {
    case 1:
        printf("YOU HAVE %d \n",u2.floos);
        break;
    }
    q = fopen("infp.txt","w");
    printf("HOW MUCH DO YOU WANT TO TAKE MONEY:");
    scanf("%d",&money);
    u2.floos = u2.floos - money;
    printf("---THANK YOU ,YOU HAVE TAKEN %d FORM YOUR ACC NOW YOU HAVE %d---",money,u2.floos);
    fwrite(&u2 , 1, sizeof(struct money),q);
    fclose(q);
    
}
void edit(){

    system("cls");
    int choise;
    int number;
    struct pass u1;
    struct money u2;
    FILE *info,*q;
    info = fopen("info.txt","rb");
    q =fopen("infp.txt","rb");


    printf("---YOU CHOSES EDIT ACCOUNT---\n");
    printf("WHAT DO U WNAT TO EDIT\n");
                printf("| 1...      YOUR NAME         |\n");
                printf("| 2...    YOUR PASSWORD       |\n");
                printf("| 3...    ACCOUNT NUMBER      |\n");
                printf("| 4...    YOUR BIRTH DAY      |\n");
                printf("| 5...  YOUR BIRTH MONTH      |\n");
                printf("| 6...    YOUR BIRTH YEAR     |\n");
                printf("|______ENTER YOUR CHOICE______|:?");
                scanf("%d",&choise);
                if(choise >= 1 && choise <= 4){
                    printf("ENTER THE ACCOUNT NUMBER:");
                    scanf("%d",&number);
                    while(fread(&u1,sizeof(struct pass),1,info)){
                        if(u1.number != number){
                            printf("WRONG");
                        }
                    }
                }
                fclose(info);
                fopen("info.txt","w");
                switch (choise) {
                   case 1:
                   printf("ENTER YOUR NEW NAME:");
                   scanf("%s",&u1.username);
                   break; 
                   case 2:
                    printf("ENTER YOUR NEW PASSWORD:");
                   scanf("%s",&u1.password);
                    case 3:
                    printf("ENTER YOUR NEW ACCOUNT NUMBER:");
                   scanf("%s",&u1.number);
                   break;
                    case 4:
                    printf("ENTER YOUR BIRTH DAY:");
                   scanf("%d",&u1.day);
                       while (u1.day > 30){
                        printf("HOW CAN YOUR BIRTH DAY IS LARGER THAN 30\n");
                        printf("TRY ANGIN WAHTS YOUR BIRTH DAY:");
                        scanf("%d",&u1.day);
                        };
                   break;
                    case 5:
                    printf("ENTER YOUR BIRTH MONTH:");
                   scanf("%d",&u1.month);
                        while (u1.month > 12){
                        printf("HOW CAN YOUR BIRTH MONTH IS LARGER THAN 12\n");
                        printf("TRY ANGIN WAHTS YOUR BIRTH MONTH:");
                        scanf("%d",&u1.month);
                        };
                   break;
                    case 6:
                    printf("ENTER YOUR BIRTH YEAR:");
                   scanf("%d",&u1.year);
                       while (u1.year < 1800 || u1.year > 2024 ){
                        printf("HOW CAN YOUR BIRTH YEAR IS LARGER THAN 2024\n");
                        printf("TRY ANGIN WAHTS YOUR BIRTH MONTH:");
                        scanf("%d",&u1.year);
                        };
                   break;
                }


                fseek(info ,0,SEEK_SET);
                fwrite(&u1 , 1, sizeof(struct pass),info);
                fclose(info);
                fclose(q);
}

void view(){
    FILE *info ,*q;
    info = fopen("info.txt","rb");
    q =fopen("info.txt","rb");
    struct money u2;
    struct pass u1;


    fread(&u1,sizeof(struct pass),1,info);
    fread(&u1,sizeof(struct pass),1,q);
    fread(&u1,sizeof(u2),1,q);

      printf("YOUR NAME:%s\n",u1.username);
      printf("YOUR PASSWORD:%s\n",u1.password);
      printf("YOUR BIRTH DAY:%d\n",u1.day);
      printf("YOUR BIRTH MONTH:%d\n",u1.month);
      printf("YOUR BIRTH YEAR:%d\n",u1.year);
      printf("YOUR ACCOUNT NUMBER:%d\n",u1.number);
      printf("YOUR MONEY:%d\n",u2.floos);

    fclose(info);
    fclose(q);
}








