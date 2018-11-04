#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdlib.h>
#include<math.h>
#define Student struct student

FILE *fp;
struct student{
    int serial;
    char name[50];
    char department[50];
    int ID;
    char gender[20];
    char name_of_courses[100];
    int credit_completed;
    float CGPA[20];
    int com;

};
struct student stu[100];
void printChar(char ch,int n);
void box();
void display(struct student[], int);
void search(struct student[], int, int);
void cgpa_calculator();
void_grade();
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}




void box(){
char array[200][200];int i,j;
char a[100]="1) Add";
char b[100]="2) Check list";
char c[100]="3) Search";
char d[100]="4) Delete";
char e[100]="5) CGPA ";
char f[100]="6) Grade ";
for(i=0;i<=24;i++)
{
    for(j=0;j<=118;j++)
    { if(i==0 || i==24 || j==0 || j==59 || j==118)
            {

                array[i][j]='*';
                printf("%c",array[i][j]);
            }


            else if(array[i][j]=' '){
                printf("%c",array[i][j]);


            }

    }
    printf("\n");

}
system("cls");
for(i=4;i<11;i++)
{
    for(j=20;j<35;j++)
    {
        array[4][j]=a[j-20];
        array[5][j]=b[j-20];
        array[6][j]=c[j-20];
        array[7][j]=d[j-20];
        array[8][j]=e[j-20];
        array[9][j]=f[j-20];
    }
}

for(i=0;i<=24;i++)
{
    for(j=0;j<=118;j++)
    {
        printf("%c",array[i][j]);

    }
    printf("\n");
}


return  0;

}


void add(FILE * fp)
{
char another='y';
Student s;
int i; int com;
float CGPA;

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
    {fseek(fp,0,SEEK_END);
    system("cls");
    printf("\n\n\t\tEnter serial number\t");
    scanf("%d",&s.serial);
    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter ID number \t");
    scanf("%d",&s.ID);
    printf("\n\n\t\tEnter department\t");
    fflush(stdin);
    fgets(s.department,50,stdin);
    printf("\n\n\t\tEnter M for Male or F for Female\t");
    scanf("%c",&s.gender);
printf("\n\n\t\tSemesters completed \t");
scanf("%d",&s.com);
fflush(stdin);
    printf("\n\n\t\tEnter TGPA for %d semesters :\t",s.com);
    for(i=0;i<s.com;i++)
    {scanf("%f",&s.CGPA[i]);
    printf("\n\n\t\t\t\t\t\t");

    }
fwrite(&s,sizeof(s),1,fp);
fclose(fp);
printf("\n\n\t\tStudent record added successfully!");
system("pause");
system("cls");
printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);

    another=getch();

        fclose(fp);
    }
}


void displayList()
{
   FILE *fp;
   Student s; int i;
    fp=fopen("studentInfo.txt","rb");
    if(fp==NULL)
    {
        printf("can't read file");
        getch();
        exit(1);
    }
        while(fread(&s,sizeof(s),1,fp)==1)
        {   printf("\nSerial:= %d",s.serial);
            printf("\nName := %s",s.name);
            printf("\nID := %d",s.ID);
            printf("\nDepartment := %s",s.department);
            fflush(stdin);
            printf("\nSemesters completed:= %d",s.com);
            for(i=0;i<12;i++)
            {
                if(s.CGPA[i]!=0)
                {
                    printf("\nCGPA for semester %d:= %.2f",i+1,s.CGPA[i]);

                }
                else break;
            }
            printf("\n********************\n");
        }
fclose(fp);
system("pause");
int a;
printf("Press 0 to go back to menu.");
scanf("%d",&a);
if(a==0)
{
    box();
}
}

FILE * del(FILE * fp)
{


Student s;
int flag=0,tempSerial,siz=sizeof(s);
FILE *ft;

if((ft=fopen("temp.txt","wb+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter Serial number of Student to Delete the Record");
printf("\n\n\t\t\tSerial No. : ");
scanf("%d",&tempSerial);

rewind(fp);


while((fread(&s,siz,1,fp))==1)
{
    if(tempSerial==s.serial)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.department,s.ID);
    continue;
    }

    fwrite(&s,siz,1,ft);
}


fclose(fp);
fclose(ft);

remove("studentInfo.txt");
rename("temp.txt","studentInfo.txt");

if((fp=fopen("studentInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printf("\n\t");
system("pause");
return fp;
}


void searchRecord(FILE *fp)
{
    int tempSerial,flag,siz,i;
Student s;
char another='y';

siz=sizeof(s);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter Serial Number of Student to search the record : ");
scanf("%d",&tempSerial);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(tempSerial==s.serial)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
        printf("\n\n\t\tSerial : %d",s.serial);
    printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepartment : %s",s.department);
        printf("\n\n\t\tID : %d",s.ID);
        printf("\n\n\tGender: %c",s.gender);
        printf("\n\n\tSemesters completed : %d",s.com);

        for(i=0;i<s.com;i++)
          {
              if(s.CGPA[i]!=0){
                 printf("\n\n\t\tTGPA : %f\n\t",s.CGPA[i]);}
          }


}
else printf("\n\n\t\tRECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

void cgpa_calculator(){
 float arr[1000];
    int i,m, N,total=0;
    float sum=0.0,g;


    printf("Enter The Number Of course taken: ");
    scanf("%d", &N);


    printf("Enter Grades earned and credit for the subject: \n\n");

    for(i=0; i<N; i++)
    {
        scanf("%f %d", &arr[i],&m);
        if (m==3)
            {
                g=arr[i]*3;
                }
        else if (m==4){
            g=arr[i]*4;
        }
        else {
            g=arr[i];
        }

     sum=sum+g;
     total=total+m;
    }


printf("               Total grade point is: %.2f                \n",sum);
printf("               Total credit completed is: %d            \n",total);
printf("        \n CGPA is equal to (Total grade points/Total credit completed)\n ");
printf("           CGPA is : %.2f\n",sum/total);
system("pause");
getch();
}


void grade(){

int i;
printf("Enter Your marks:");
scanf("%d",&i);
if (i>=93 && i<=100){
    printf("Your grade is A !\n");
}
else if(i>=90 && i<=92){
    printf("Your grade is A- !\n");
}
else if(i>=87 && i<=89){
    printf("Your grade is B+ !\n");
}
else if(i>=83 && i<=86){
    printf("Your grade is B !\n");
}
else if(i>=80 && i<=82){
    printf("Your grade is B- !\n");
}

else if(i>=77 && i<=79){
    printf("Your grade is C+ !\n");
}
else if(i>=73 && i<=76){
    printf("Your grade is C !\n");
}
else if(i>=70 && i<=72){
    printf("Your grade is C- !\n");
}
else if(i>=67 && i<=69){
    printf("Your grade is D+ !\n");
}
else if(i>=60 && i<=66){
    printf("Your grade is D !\n");
}

else {
    printf("Your grade is F !\n");

}
system("pause");
getch();
}





int main(){
    FILE * fp;
int option;
char another;

if((fp=fopen("studentInfo.txt","rb+"))==NULL)
{
    if((fp=fopen("studentInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}

printf("\n\n\t\tCREATED BY");
printf("\n\n\t\tMOHAMMED WASEK-UR RAHMAN\n\n\t\t");
printf("\n\n\n\n\t\tSUBMITTED TO: NAHEENA HAQ");
printf("\n\t\tpress any key to continue");
getch();

while(1)
{
box();
printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);
    system("cls");

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: displayList();
                break;
        case 3: searchRecord(fp);
                break;
        case 4: fp=del(fp);
                break;
        case 5: cgpa_calculator();
                break;
        case 6: grade();
                break;

        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
return 0;
}

