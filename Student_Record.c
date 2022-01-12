#include <stdio.h>
#include <stdlib.h>
typedef struct student{
  int rno;
  char name[20];
  int marks;
  float per;
}student;

void Create(){
  student *s;
  FILE *fp;
  int n,i,j;
  printf("Enter Number of Students: ");
  scanf("%d",&n);
  s=(student*)calloc(n,sizeof(student));
  fp=fopen("students.txt","w");
  
  for(i=0;i<n;i++){
    printf("Enter Roll Number: ");
    scanf("%d",&s[i].rno);
    fflush(stdin);
    printf("Enter Name: ");
    scanf("%[^\n]s",s[i].name);
    printf("Enter Marks: ");
    scanf("%d",&s[i].marks);
    s[i].per=s[i].marks;
    fwrite(&s[i],sizeof(student),1,fp);
  }
  fclose(fp);
}

void Display(){
  student s1;
  FILE *fp;
  fp=fopen("students.txt","r");
  printf("\nRoll No.\t\t Name \t\t\t Marks\t\t Percentage\n ");
  while(fread(&s1,sizeof(student),1,fp)){
    printf("\n%-5d\t\t\t%-20s\t",s1.rno,s1.name);
    printf("%4d\t\t",s1.marks);
    printf("%7.2f",s1.per);
  }
  
  fclose(fp);
}
void Update(){
  student *s;
  FILE *fp;
  int n,i,j;
  printf("Enter Number of Students: ");
  scanf("%d",&n);
  s=(student*)calloc(n,sizeof(student));
  fp=fopen("students.txt","a");
  
  for(i=0;i<n;i++){
    printf("Enter Roll Number: ");
    scanf("%d",&s[i].rno);
    fflush(stdin);
    printf("Enter Name: ");
    scanf("%[^\n]s",s[i].name);
    printf("Enter Marks: ");
    scanf("%d",&s[i].marks);
    s[i].per=s[i].marks;
    fwrite(&s[i],sizeof(student),1,fp);
  }
  fclose(fp);
}

void Search(){
  student s1;
  FILE *fp;
  int r,f=0;
  fp=fopen("students.txt","r");
  printf("Enter RollNo. to search:  ");
  scanf("%d",&r);
  printf("\nRoll No.\t\t Name \t\t\t Marks\t\t Percentage\n ");
  while(fread(&s1,sizeof(student),1,fp)){
    if(s1.rno==r){
    f=1;
    printf("\n%-5d\t\t\t%-20s\t",s1.rno,s1.name);
    printf("%4d\t\t",s1.marks);
    printf("%7.2f",s1.per);
  }}
  if(f!=1)
    printf("\nRecord Not Present\n");
  
  fclose(fp);
}

void Delete(){
  student s1;
  FILE *fp, *fp1;
  int r,f=0;
  fp=fopen("students.txt","r");
  fp1=fopen("temp.txt","w");
  printf("Enter RollNo. to Delete:  ");
  scanf("%d",&r);
  while(fread(&s1,sizeof(student),1,fp)){
    if(s1.rno==r)
    f=1;
    else
    fwrite(&s1,sizeof(student),1,fp1);
  }
  fclose(fp);
  fclose(fp1);
  if(f==1){
    fp1=fopen("temp.txt","r");
    fp=fopen("students.txt","w");
    while(fread(&s1,sizeof(student),1,fp1)){
      fwrite(&s1,sizeof(student),1,fp);
    }
    fclose(fp);
    fclose(fp1);
  }
  
}
int main(){
  int ch;
  do{
    printf("\n1.Create Student Record");
    printf("\n2.Display Student Record");
    printf("\n3.Add New Student Record");
    printf("\n4.Search Student Record");
    printf("\n5.Delete Student Record");
    printf("\n0.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&ch);
    
    switch(ch){
      case 1:
      Create();
      break;
      case 2:
      Display();
      break;
      case 3:
      Update();
      break;
      case 4:
      Search();
      break;
      case 5:
      Delete();
      break;
      
    }
    
  }while(ch!=0);
  return 0;
}
