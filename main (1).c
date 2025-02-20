#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void function1(int [], char [][50], float [],int);
void function2(int [], char [][50], float [],int);
void function3(int [], char [][50], float [],int);
void function4(int [], float [],int);
void function5(char [][50], float [],int);
void save_data_function(int [], char [][50], float [],int);
int main()
{
    char filename[20];
    char line[500],*token;
    int ID[1000];
    char names[1000][50];
    float avg[1000];
    printf("please enter the file name\n");
    gets(filename);
    FILE *f_in=fopen(filename ,"r");
    int i=0,size;
    char stunames[50];
    while ( !feof(f_in))
        {
             fgets(line,500,f_in);
            token= strtok (line,"$");
        int id = atoi(token);
        ID[i]=id;

        token = strtok (NULL,"$");
        strcpy(stunames, token);
        strcpy(names[i],stunames);

        token = strtok (NULL, "$");
        float assignment = atof(token);

        token = strtok (NULL, "$");
        float quiz = atof(token);

        token = strtok (NULL, "$");
        float mid = atof(token);

        token = strtok (NULL, "$");
        float practical = atof(token);

        token = strtok (NULL, "$");
        float finall = atof(token);

        float avgg=assignment*15/100 + quiz*15/100 + mid*25/100 + practical*10/100 + finall*35/100;
        avg[i]=avgg;
        i++;
        size=i;
        }


    fclose(f_in);
    int choice;
    printf("choose one of the following choices:\n");
    printf("1) Sort data in ascending order according to students’ IDs.\n");
    printf("2) Sort data in ascending order according to students’ names.\n");
    printf("3) Sort data in descending order according to students’ scores.\n");
    printf("4) Ask the user to enter a student ID and display his score.\n");
    printf("5) Ask the user to enter a student name and display his score.\n");
    printf("6) Exit the program.\n");
    scanf("%d",&choice);
    while(choice!=6)
    {
    if(choice == 1)
     {
        function1(ID,names,avg,size);
        char save_choice;
        printf("\nwould you like to save the current result? enter y if yes or n if no\n");
        scanf("%c",&save_choice);
        if(save_choice=='y')
            save_data_function(ID,names,avg,size);
    }
    else if(choice == 2)
    {
        function2(ID,names,avg,size);
        char save_choice;
        printf("\nwould you like to save the current result? enter y if yes or n if no\n");
        scanf("%c",&save_choice);
        if(save_choice=='y')
            save_data_function(ID,names,avg,size);
    }
    else if(choice == 3)
    {
        function3(ID,names,avg,size);
        char save_choice;
        printf("\nwould you like to save the current result? enter y if yes or n if no\n");
        scanf("%c",&save_choice);
        if(save_choice=='y')
            save_data_function(ID,names,avg,size);
    }
    else if(choice == 4)
        function4(ID,avg,size);
    else if(choice == 5)
       function5(names,avg,size);

    printf("choose one of the following choices:\n");
    printf("1) Sort data in ascending order according to students’ IDs.\n");
    printf("2) Sort data in ascending order according to students’ names.\n");
    printf("3) Sort data in descending order according to students’ scores.\n");
    printf("4) Ask the user to enter a student ID and display his score.\n");
    printf("5) Ask the user to enter a student name and display his score.\n");
    printf("6) Exit the program.\n");
    scanf("%d",&choice);
    }
    if(choice == 6)
        printf("the end\n");


    return 0;
}
void function1(int ID[], char names[][50], float avg[],int size)
{
    int id_temp;
    char name_temp[50];
    float avg_temp;

    for(int x=0;x<size-1;x++)
        for(int y=x+1;y<size;y++)
    {
        if(ID[x]>ID[y])
        {
            id_temp=ID[x];
            ID[x]=ID[y];
            ID[y]=id_temp;

            strcpy(name_temp, names[x]);
            strcpy(names[x], names[y]);
            strcpy(names[y], name_temp);

            avg_temp=avg[x];
            avg[x]=avg[y];
            avg[y]=avg_temp;

        }
    }
    printf("\nstudents id    students names    students grades\n\n");
    for(int i=0;i<size;i++)
        printf("%d\t\t %s\t\t %.2f\n",ID[i],names[i],avg[i]);

}
void function2(int ID[], char names[][50], float avg[],int size)
{
    int id_temp;
    char name_temp[50];
    float avg_temp;

    for(int x=0;x<size-1;x++)
        for(int y=x+1;y<size;y++)
    {
        if(strcmp(names[x],names[y])>0)
        {
            id_temp=ID[x];
            ID[x]=ID[y];
            ID[y]=id_temp;

            strcpy(name_temp, names[x]);
            strcpy(names[x], names[y]);
            strcpy(names[y], name_temp);

            avg_temp=avg[x];
            avg[x]=avg[y];
            avg[y]=avg_temp;

        }
    }
    printf("\nstudents names   students id   students grades\n\n");
    for(int i=0;i<size;i++)
        printf("%d\t\t %s\t\t %.2f\n",ID[i],names[i],avg[i]);

}
void function3(int ID[], char names[][50], float avg[],int size)
{
    int id_temp;
    char name_temp[50];
    float avg_temp;

    for(int x=0;x<size-1;x++)
        for(int y=x+1;y<size;y++)
    {
        if(avg[x]<avg[y])
        {
            id_temp=ID[x];
            ID[x]=ID[y];
            ID[y]=id_temp;

            strcpy(name_temp, names[x]);
            strcpy(names[x], names[y]);
            strcpy(names[y], name_temp);

            avg_temp=avg[x];
            avg[x]=avg[y];
            avg[y]=avg_temp;

        }
    }
    printf("\nstudents grades   students names   students id\n\n");
    for(int i=0;i<size;i++)
        printf("%d\t\t %s\t\t %.2f\n",ID[i],names[i],avg[i]);

}
void function4(int ID[], float avg[],int size)
{
    int id_entered;
    printf("enter the student id\n");
    scanf("%d",&id_entered);
    for(int x=0;x<size;x++)
        if(id_entered==ID[x])
        {
            printf("\nstudent id\t student grade\n\n");
            printf("%d\t\t %.2f\n",ID[x],avg[x]);
        }
}
void function5(char names[][50], float avg[],int size)
{
    char name_entered[50], name_entered2[50];
    printf("enter the student name\n");
    scanf("%s %s",name_entered, name_entered2);
    strcat(name_entered, " ");
    strcat(name_entered, name_entered2);
        for(int x=0;x<size;x++)
        if(strcmp(name_entered,names[x])==0)
        {
            printf("\nstudent name\t student grade\n\n");
            printf("%s\t\t %.2f\n",names[x],avg[x]);
        }
}
void save_data_function(int ID[], char names[][50], float avg[],int size)
{
    char file_to_save[50];
    printf("please enter file name\n");
    scanf("%s",&file_to_save);
    FILE *ptr=fopen(file_to_save,"a");
    for(int i=0;i<size;i++)
        fprintf(ptr,"%d\t\t%s\t\t%.2f\n",ID[i],names[i],avg[i]);
    fclose(ptr);

}
