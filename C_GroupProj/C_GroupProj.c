/***************************************************************************************************************************************************************
* Program created by Martin, Sunny, Thomas & Will                                                                                                              *
***************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/***************************************************************************************************************************************************************
* DEFINED ID LEN: upon further discussion, the length may change.                                                                                              *
* DEFINED PW LEN: upon further discussion, the length may change.                                                                                              *
* DEFINED MAX USER: upon further discussion, number of users in database may change.                                                                           *
* //FILE NAME IS CALLED ID&PW.txt// file named 'ID&PW.txt' must already exist for this program to function.                                                    *
***************************************************************************************************************************************************************/
#define MAX_ID_LEN 8
#define MAX_PW_LEN 15
#define MAX_USER 100
#define DB_NAME "ID&PW.txt"

/***************************************************************************************************************************************************************
* Created new type user_t which contains:                                                                                                                      *
* - ID                                                                                                                                                         *
* - PW                                                                                                                                                         *
* - ID length                                                                                                                                                  *
* - PW length                                                                                                                                                  *
***************************************************************************************************************************************************************/
typedef struct user
{
    char ID[MAX_ID_LEN];
    char PW[MAX_PW_LEN];
    int ID_len;
    int PW_len;
}
user_t; 

/***************************************************************************************************************************************************************
* FUNCTION PROTOTYPES                                                                                                                                          *
***************************************************************************************************************************************************************/
void print_menu(void);
void login(void);
void registration(void);
void save2DB(char ID[], char PW[], int ID_len, int PW_len);
void loadDB(void);
int check_ID(char ID[]);
int check_PW(char PW[]);
int check_DUP_ID(char ID[]);
int check_MATCH(char PW[], int match_ID);
user_t encryption(char PW[], int PW_len);

/***************************************************************************************************************************************************************
* GLOBAL VARIABLES (subject to cleaning and editing)                                                                                                           *
***************************************************************************************************************************************************************/
FILE *fp=NULL; /*file declaration*/
user_t USER[MAX_USER];
int num_user;   
char input_ID[MAX_ID_LEN];
char input_PW[MAX_PW_LEN];

/***************************************************************************************************************************************************************
* MAIN FUNCTION                                                                                                                                                *
***************************************************************************************************************************************************************/
int main (void)
{
    int exit=0;
    int choice;

    num_user=0;
    loadDB();
    while (exit==0)
    {
        print_menu();
        scanf("%d", &choice);
        if (choice==1)
        {
            login();
        }
        else if (choice==2)
        {
            registration();
        }
        else if (choice==3)
        {
            exit=1;
        }
        else
        {
            printf("invalid input\n");
        }        
    }

    return 0;
}
/***************************************************************************************************************************************************************
* This function prints the menu when the program starts                                                                                                        *
***************************************************************************************************************************************************************/
void print_menu(void)
{
    printf("This program does ... \n");
    printf("Select from the following options:\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit Program\n");    
}

/***************************************************************************************************************************************************************
* This function loads the database when the program starts                                                                                                     *
***************************************************************************************************************************************************************/
void loadDB(void)
{
    int i, j, k;
    printf("load from DB\n");
    fp = fopen(DB_NAME, "r");
    if (fp==NULL)
    {
        printf("file error\n");
    }
    fscanf(fp, "%d", &num_user);
    for (i=0; i<num_user; i++)
    {
        fscanf(fp, "%d", &USER[i].ID_len);
        for (j=0; j<USER[i].ID_len; j++)
        {
            fscanf(fp, "%c", &USER[i].ID[j]);
        }
        fscanf(fp, "%d", &USER[i].PW_len);
        for (k=0; k<USER[i].PW_len; k++)
        {
            fscanf(fp, "%c", &USER[i].PW[k]);
        }
    }
    fclose(fp);
    printf("%d", num_user);
    for (i=0; i<num_user; i++)
    {
        printf("\n");
        printf("%d ", USER[i].ID_len);
        for (j=0; j<USER[i].ID_len; j++)
        {
            printf("%c", USER[i].ID[j]);
        }
        printf(" %d ", USER[i].PW_len);
        for (k=0; k<USER[i].PW_len; k++)
        {
            printf("%c", USER[i].PW[k]);
        }
    }
    printf("\n");  
}

/***************************************************************************************************************************************************************
* LOGIN FUNCTION                                                                                                                                               *
* INPUTS:                                                                                                                                                      *
* - ID                                                                                                                                                         *
* - PW                                                                                                                                                         *
* OUTPUTS:                                                                                                                                                     *
* - LOGIN SUCCESS                                                                                                                                              *
***************************************************************************************************************************************************************/
void login(void)
{
    int i, valid_ID, valid_PW, match_ID, match;
    user_t ENCRYPT;

    printf("--------LOGIN--------\n");
    printf("Enter ID> ");
    scanf("%s", input_ID);
    printf("Enter password> ");
    scanf("%s", input_PW);

    valid_ID=check_ID(input_ID); /*check format*/
    valid_PW=check_PW(input_PW); /*check format*/
    match_ID=check_DUP_ID(input_ID); /*check if ID exists in DB & find the num_user ID matching*/
    ENCRYPT=encryption(input_PW, strlen(input_PW));
    for (i=0; i<strlen(input_PW); i++)
    {
        input_PW[i]=ENCRYPT.PW[i];
    }
    match=check_MATCH(input_PW, match_ID); /*check if PW exists in DB*/ /*check if there is a match in the DB*/

    if (valid_ID==0)
    {
        printf("login failed. ID format incorrect\n");
    }
    else if (valid_PW==0)
    {
        printf("login failed. PW format incorrect\n");
    }
    else if (match_ID==-1)
    {
        printf("login failed. no matching ID\n");
    }
    else if (match==0)
    {
        printf("login failed. ID and PW dont match\n");
    }
    else
    {
        printf("LOGIN SUCCESSFUL\n");
    }
}

/***************************************************************************************************************************************************************
* REGISTER FUNCTION                                                                                                                                            *
* INPUTS:                                                                                                                                                      *
* - ID                                                                                                                                                         *
* - PW                                                                                                                                                         *
* OUTPUTS:                                                                                                                                                     *
* - REGISTER SUCCESS                                                                                                                                           *
***************************************************************************************************************************************************************/
void registration(void)
{
    int i, j, k, valid_ID, valid_PW, ID_exists;
    user_t ENCRYPT;

    printf("--------REGISTRATION--------\n");
    printf("Requirements:\n");
    printf("ID must have 1-8 characters in total\n");
    printf("Password must have 7-15 characters in total and contain at least one number, one upper case letter, one lower case letter and one special character\n");
    printf("Enter ID> ");
    scanf("%s", input_ID);
    printf("Enter password> ");
    scanf("%s", input_PW);

    valid_ID=check_ID(input_ID); /*check format*/
    valid_PW=check_PW(input_PW); /*check format*/
    ID_exists=check_DUP_ID(input_ID); /*check for duplicates*/

    if (valid_ID==1 && valid_PW==1 && ID_exists==-1)
    {
        USER[num_user].ID_len=strlen(input_ID);
        for (i=0; i<USER[num_user].ID_len; i++)
        {
            USER[num_user].ID[i]=input_ID[i];
        }
        USER[num_user].PW_len=strlen(input_PW);
        for (j=0; j<USER[num_user].PW_len; j++)
        {
            USER[num_user].PW[j]=input_PW[j];
        }
        ENCRYPT=encryption(input_PW, strlen(input_PW));
        for (k=0; k<USER[num_user].PW_len; k++)
        {
            USER[num_user].PW[k]=ENCRYPT.PW[k];
        }
        num_user++; /*After a successful registration, the number of users increases by 1*/
        printf("REGISTER SUCCESS\n");
        save2DB(USER[num_user].ID, USER[num_user].PW, USER[num_user].ID_len, USER[num_user].PW_len); /*After a successful registration, ID and PW is saved to database*/
    }
    else
    {
        printf("invalid formatting or ID already exists\n");
    }
}

/***************************************************************************************************************************************************************
* This function saves the following information:                                                                                                               *
* - ID                                                                                                                                                         *
* - ID length                                                                                                                                                  *
* - PW                                                                                                                                                         *
* - PW length                                                                                                                                                  *
***************************************************************************************************************************************************************/
void save2DB(char ID[], char PW[], int ID_len, int PW_len)
{
    int i, j, k;
    printf("save to DB\n");
    fp = fopen(DB_NAME, "w");
    if (fp==NULL)
    {
        printf("file error\n");
    }
    fprintf(fp, "%d", num_user);
    for (i=0; i<num_user; i++)
    {
        fprintf(fp, "\n");
        fprintf(fp, "%d", USER[i].ID_len);
        for (j=0; j<USER[i].ID_len; j++)
        {
            fprintf(fp, "%c", USER[i].ID[j]);
        }
        fprintf(fp, "%d", USER[i].PW_len);
        for (k=0; k<USER[i].PW_len; k++)
        {
            fprintf(fp, "%c", USER[i].PW[k]);
        }
    }
    fclose(fp);   
}

/***************************************************************************************************************************************************************
* This function checks the format of the ID                                                                                                                    *
* - ID string length                                                                                                                                           *
***************************************************************************************************************************************************************/
int check_ID(char ID[])
{
    printf("check ID\n");
    if (strlen(input_ID)<1 || strlen(input_ID)>MAX_ID_LEN) /*check valid string length*/
    {
        printf("invalid ID len\n");
        return 0;
    }
    else
    {
        printf("valid ID len\n");
        return 1;
    }
}

/***************************************************************************************************************************************************************
* This function checks the format of the PW                                                                                                                    *
* - contains one upper case letter                                                                                                                             *
* - contains one lower case letter                                                                                                                             *
* - contains one number                                                                                                                                        *
* - contains a special character                                                                                                                               *
* - PW string length                                                                                                                                           *
***************************************************************************************************************************************************************/
int check_PW(char PW[])
{
    int cond[4];
    int i, spec_char;

    cond[0]=0; /*condition to check for upper case letter*/
    cond[1]=0; /*condition to check for lower case letter*/
    cond[2]=0; /*condition to check for digit*/
    cond[3]=0; /*condition to check for special character*/

    printf("check PW\n");
    if (strlen(input_PW)<1 || strlen(input_PW)>MAX_PW_LEN)
    {
        printf("invalid PW length\n");
        return 0;
    }
    for (i=0; input_PW[i]!='\0'; i++)
    {
        if (input_PW[i]>='A' && input_PW[i]<='Z')
        {
            cond[0]=1;
        }
    }
    for (i=0; input_PW[i]!='\0'; i++)
    {
        if (input_PW[i]>='a' && input_PW[i]<='z')
        {
            cond[1]=1;
        }
    }
    for (i=0; input_PW[i]!='\0'; i++)
    {
        if (input_PW[i]>='0' && input_PW[i]<='9')
        {
            cond[2]=1;
        }
    }
    for (i=0; input_PW[i]!='\0'; i++)
    {
        if ((input_PW[i]>='a' && input_PW[i]<='z')||(input_PW[i]>='A' && input_PW[i]<='Z'))
        {
            spec_char=0; /*do nothing*/
        }
        else if (input_PW[i]>='0' && input_PW[i]<='9')
        {
            spec_char=0; /*do nothing*/
        }
        else
        {
            spec_char=1;
            cond[3]=spec_char;
        }
    }
    if (cond[0]==1 && cond[1]==1 && cond[2]==1 && cond[3]==1)
    {
        printf("valid PW format\n");
        return 1;
    }
    else
    {    
        printf("invalid PW format\n");    
        return 0;
    }
}

/***************************************************************************************************************************************************************
* This function checks if the ID already exists in the DB                                                                                                      *
***************************************************************************************************************************************************************/
int check_DUP_ID(char ID[])
{
    int i, j;
    int duplicate, match_ID;
    int count[num_user];

    duplicate=0;

    for (i=0; i<num_user; i++)
    {
        if (strlen(input_ID)==USER[i].ID_len)
        {
            count[i]=0;
            for (j=0; j<strlen(input_ID); j++)
            {
                if (input_ID[j]==USER[i].ID[j])
                {
                    count[i]++;
                }
            }
        }
        if (count[i]==strlen(input_ID))
        {
            duplicate=1;
            match_ID=num_user;
        }
    }

    if (duplicate==1)
    {
        printf("duplicate ID found\n");
        return match_ID;
    }
    else
    {
        printf("no duplicate ID found\n");
        return -1;
    }
}

/***************************************************************************************************************************************************************
* This function checks to see if the ID and PW entered during login match what is in the DB                                                                    *
***************************************************************************************************************************************************************/
int check_MATCH(char PW[], int match_ID)
{
    int i, j;
    int PW_exists;
    int count[num_user];

    for (i=0; i<num_user; i++) /*check all users*/
    {
        if (strlen(input_PW)==USER[i].PW_len) /*check PW exists with same string length*/
        {
            count[i]=0;
            for (j=0; j<strlen(input_PW); j++) /*from beginning to end of input PW*/
            {
                if (input_PW[j]==USER[i].PW[j]) /*if each character */
                {
                    count[i]++;
                }
            }
        }
        if (count[i]==strlen(input_PW))
        {
            PW_exists=num_user;
        }
    }

    if (match_ID==PW_exists) /*check if the PW that exists in the DB corresponds to the ID presented*/
    {
        printf("PW matches corresponding ID\n");
        return 1;
    }
    else
    {
        printf("PW doesn't match corresponding ID\n");
        return 0;
    }
}

/***************************************************************************************************************************************************************
* This function encrypts the password                                                                                                                          *
* The type and complexity of encryption is subject to change upon further discussion                                                                           *
***************************************************************************************************************************************************************/
user_t encryption(char PW[], int PW_len)
{
    user_t ENCRYPT;
    int i;

    for (i=0; i<strlen(input_PW); i++)
    {
        input_PW[i]++;
        ENCRYPT.PW[i]=input_PW[i];
    }
    printf("pw encrypted\n");
    return ENCRYPT;
}
