#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define stunum 200
void asc_id(int [], double [], double[], double[], double[], double[], double[], char [stunum][50], int);
void asc_names(int [], double [], double[], double[], double[], double[], double[], char [stunum][50], int);
void desc_scores(int [], double [], double[], double[], double[], double[], double[], char [stunum][50], int);
void askuser_id(int [], double [], double[], double[], double[], double[], double[], char [stunum][50], int);
void askuser_name(int [], double [], double[], double[], double[], double[], double[], char [stunum][50],int);
int main()
{
    printf("hi \neng.luai hawi\tid:1200203\nthis is a programme to read students scores and do several processes on them\n");
    char fi[20], data[82], data1[60], *token, name[stunum][50];
    int id[stunum], counter[5], length;
    double assignments[stunum], quiz[stunum], mid[stunum], practical[stunum], finalex[stunum], grade[stunum];
    printf("please enter file name:\n");
    gets(fi);
    FILE *file=fopen(fi, "r");
    FILE *write=fopen("wri.txt", "w");
    FILE *writ;
    int status;
    for(counter[0]=-1; status!=EOF; counter[0]++)
    {
        status=fscanf(file, "%s %s", data, data1);
        if(status!=EOF)
        {
            strcat(data, " ");
            strcat(data, data1);
            token=strtok(data, "$");
            while(token!=NULL)
            {
                fprintf(write,"%s\n", token);
                token=strtok(NULL, "$");
            }
        }
    }

    fclose(write);
    writ= fopen("wri.txt", "r");
    for(counter[1]=0; counter[1]<counter[0]; counter[1]++)
    {
        fscanf(writ, "%d", &id[counter[1]]);
        fscanf(writ, "%s %s", name[counter[1]], data1);
        strcat(name[counter[1]], " ");
        strcat(name[counter[1]], data1);
        fscanf(writ, "%lf", &assignments[counter[1]]);
        fscanf(writ, "%lf", &quiz[counter[1]]);
        fscanf(writ, "%lf", &mid[counter[1]]);
        fscanf(writ, "%lf", &practical[counter[1]]);
        fscanf(writ, "%lf", &finalex[counter[1]]);
        grade[counter[1]]=assignments[counter[1]]*0.15+quiz[counter[1]]*0.15+mid[counter[1]]*0.25+practical[counter[1]]*0.10+finalex[counter[1]]*0.35;
    }
    length=counter[0];
    fclose(writ);
    fclose(file);
    remove("wri.txt");

    do
    {
        printf("\n\nplease enter a number from the menu:\n1-Sort data in ascending order according to students� IDs and then display it.\n2-Sort data in ascending order according to students� names and then display it.\n3-Sort data in descending order according to students� scores and then display it.\n4-search by id.\n5-search by name.\n6-exit.\n");
        scanf("%d", &counter[2]);
        if(counter[2]==1)
            asc_id(id, assignments, quiz, mid, practical, finalex, grade, name, length);
        else if(counter[2]==2)
            asc_names(id, assignments, quiz, mid, practical, finalex, grade, name, length);
        else if (counter[2]==3)
            desc_scores(id, assignments, quiz, mid, practical, finalex, grade, name, length);
        else if (counter[2]==4)
            askuser_id(id, assignments, quiz, mid, practical, finalex, grade, name, length);
        else if (counter[2]==5)
            askuser_name(id, assignments, quiz, mid, practical, finalex, grade, name, length);
        else if(counter[2]==6)
            break;
        else printf("unavailable\n");
    }
    while (counter[3]!=6);
    printf("thank you\neng.luai hawi\tid:1200203\n");
    return 0;
}
void asc_id(int id[], double assignments[], double quiz[], double mid[], double practical[], double finalex[], double grade[], char name[stunum][50],int length)
{
    int counter[5];
    char counter1;
    int temp;
    double scores[6];
    char temp2[50];
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        for(counter[1]=counter[0]+1; counter[1]<length; counter[1]++)
        {
            if(id[counter[0]]>id[counter[1]])
            {
                temp=id[counter[0]];
                scores[0]=assignments[counter[0]];
                scores[1]=quiz[counter[0]];
                scores[2]=mid[counter[0]];
                scores[3]=practical[counter[0]];
                scores[4]=finalex[counter[0]];
                scores[5]=grade[counter[0]];
                strcpy(temp2, name[counter[0]]);
                id[counter[0]]=id[counter[1]];
                id[counter[1]]=temp;
                assignments[counter[0]]=assignments[counter[1]];
                assignments[counter[1]]=scores[0];
                quiz[counter[0]]=quiz[counter[1]];
                quiz[counter[1]]=scores[1];
                mid[counter[0]]=mid[counter[1]];
                mid[counter[1]]=scores[2];
                practical[counter[0]]=practical[counter[1]];
                practical[counter[1]]=scores[3];
                finalex[counter[0]]=finalex[counter[1]];
                finalex[counter[1]]=scores[4];
                grade[counter[0]]=grade[counter[1]];
                grade[counter[1]]=scores[5];
                strcpy(name[counter[0]],name[counter[1]] );
                strcpy(name[counter[1]], temp2);
            }
        }
    }
    printf("   id    \t   name of student   \t assignment \t quizzes \t midterm \t practical \t final \t grade \n");
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        printf(" %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );
    }
    char filename[20], answer2;
    printf("if you want to save these data press y otherwise press n\n");
    scanf("%s", &answer2);
    if(answer2=='y')
    {
        printf("print file name:\n");
        scanf("%s", &filename);
        FILE *savedata=fopen(filename, "a");
        for(counter[0]=0; counter[0]<length; counter[0]++)
        {
            fprintf( savedata, " %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );

        }
        fclose(savedata);
    }

    else if(answer2!='n') printf("error...\n");

    for(counter[4]=0; counter[4]!=1;)
    {
        printf("press 1 to get back to the menu\n");
        scanf("%d", &counter[4]);
        if(counter[4]==1)
            break;
        else printf("error...");
    }
}
void asc_names(int id[], double assignments[], double quiz[], double mid[], double practical[], double finalex[], double grade[], char name[stunum][50],int length)
{
    int counter[5];
    int temp, result;
    double scores[6];
    char temp2[50];
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        for(counter[1]=counter[0]+1; counter[1]<length; counter[1]++)
        {


            temp=id[counter[0]];
            scores[0]=assignments[counter[0]];
            scores[1]=quiz[counter[0]];
            scores[2]=mid[counter[0]];
            scores[3]=practical[counter[0]];
            scores[4]=finalex[counter[0]];
            scores[5]=grade[counter[0]];
            strcpy(temp2, name[counter[0]]);
            result=strcmp(name[counter[0]], name[counter[1]]);
            if(result>0)
            {
                id[counter[0]]=id[counter[1]];
                id[counter[1]]=temp;
                assignments[counter[0]]=assignments[counter[1]];
                assignments[counter[1]]=scores[0];
                quiz[counter[0]]=quiz[counter[1]];
                quiz[counter[1]]=scores[1];
                mid[counter[0]]=mid[counter[1]];
                mid[counter[1]]=scores[2];
                practical[counter[0]]=practical[counter[1]];
                practical[counter[1]]=scores[3];
                finalex[counter[0]]=finalex[counter[1]];
                finalex[counter[1]]=scores[4];
                grade[counter[0]]=grade[counter[1]];
                grade[counter[1]]=scores[5];
                strcpy(name[counter[0]],name[counter[1]] );
                strcpy(name[counter[1]], temp2);
            }
        }
    }
    printf("file does not exist\n");
    printf("   id    \t   name of student   \t assignment \t quizzes \t midterm \t practical \t final \t grade \n");
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        printf(" %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );
    }
    char filename[20], answer2;
    printf("if you want to save these data press y otherwise press n\n");
    scanf("%s", &answer2);
    if(answer2=='y')
    {
        printf("print file name:\n");
        scanf("%s", &filename);
        FILE *savedata=fopen(filename, "a");
        for(counter[0]=0; counter[0]<length; counter[0]++)
        {
            fprintf( savedata, " %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );

        }
        fclose(savedata);
    }

    else if(answer2!='n') printf("error...\n");

    for(counter[4]=0; counter[4]!=1;)
    {
        printf("press 1 to get back to the menu\n");
        scanf("%d", &counter[4]);
        if(counter[4]==1)
            break;
        else printf("error...");
    }
}
void desc_scores(int id[], double assignments[], double quiz[], double mid[], double practical[], double finalex[], double grade[], char name[stunum][50],int length)
{
    int counter[5];
    int temp;
    double scores[6];
    char temp2[50];
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        for(counter[1]=counter[0]+1; counter[1]<length; counter[1]++)
        {
            if(grade[counter[0]]<grade[counter[1]])
            {
                temp=id[counter[0]];
                scores[0]=assignments[counter[0]];
                scores[1]=quiz[counter[0]];
                scores[2]=mid[counter[0]];
                scores[3]=practical[counter[0]];
                scores[4]=finalex[counter[0]];
                scores[5]=grade[counter[0]];
                strcpy(temp2, name[counter[0]]);
                id[counter[0]]=id[counter[1]];
                id[counter[1]]=temp;
                assignments[counter[0]]=assignments[counter[1]];
                assignments[counter[1]]=scores[0];
                quiz[counter[0]]=quiz[counter[1]];
                quiz[counter[1]]=scores[1];
                mid[counter[0]]=mid[counter[1]];
                mid[counter[1]]=scores[2];
                practical[counter[0]]=practical[counter[1]];
                practical[counter[1]]=scores[3];
                finalex[counter[0]]=finalex[counter[1]];
                finalex[counter[1]]=scores[4];
                grade[counter[0]]=grade[counter[1]];
                grade[counter[1]]=scores[5];
                strcpy(name[counter[0]],name[counter[1]] );
                strcpy(name[counter[1]], temp2);
            }
        }
    }
    printf("   id    \t   name of student   \t assignment \t quizzes \t midterm \t practical \t final \t grade \n");
    for(counter[0]=0; counter[0]<length; counter[0]++)
    {
        printf(" %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );
    }
    char filename[20], answer2;
    printf("if you want to save these data press y otherwise press n\n");
    scanf("%s", &answer2);
    if(answer2=='y')
    {
        printf("print file name:\n");
        scanf("%s", &filename);
        FILE *savedata=fopen(filename, "a");
        for(counter[0]=0; counter[0]<length; counter[0]++)
        {
            fprintf( savedata, " %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );

        }
        fclose(savedata);
    }

    else if(answer2!='n') printf("error...\n");

    for(counter[4]=0; counter[4]!=2;)
    {
        printf("press 1 to get back to the menu\n");
        scanf("%d", &counter[4]);
        if(counter[4]==1)
            break;
        else printf("error...");
    }
}
void askuser_id(int id[], double assignments[], double quiz[], double mid[], double practical[], double finalex[], double grade[], char name[stunum][50],int length)
{
    int id1, counter[5];
    for(counter[4]=0; counter[4]!=2;)
    {
        printf("\nplease enter id:\n");
        scanf("%d", &id1);
        for(counter[0]=0; counter[0]<length; counter[0]++)
        {
            if(id[counter[0]]==id1)
            {
                counter[3]=1;
                break;
            }
        }

        if(counter[3]==1)
        {
            printf("   id    \t   name of student   \t assignment \t quizzes \t midterm \t practical \t final \t grade \n");

            printf(" %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );

        }
        else printf("student does not exist\n");
        char filename[20], answer2;
        printf("if you want to save these data press y otherwise press n\n");
        scanf("%s", &answer2);
        if(answer2=='y')
        {
            printf("print file name:\n");
            scanf("%s", &filename);
            FILE *savedata=fopen(filename, "a");

            fprintf( savedata, " %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );


            fclose(savedata);
        }

        else if(answer2!='n') printf("error...\n");


        printf("press 1 to try again or 2 to get back to the menu\n");
        scanf("%d", &counter[4]);
        if(counter[4]==2) break;
        else if(counter[4]==1) continue;
        printf("error...");

    }
}

void askuser_name(int id[], double assignments[], double quiz[], double mid[], double practical[], double finalex[], double grade[], char name[stunum][50],int length)
{
    char name1[50], temp[50];
    int counter[5];
    for(counter[4]=0; counter[4]!=2;)
    {
        printf("\nplease enter name:\n");
        scanf("%s %s", name1, temp);
        strcat(name1, " ");
        strcat(name1, temp);
        for(counter[0]=0; counter[0]<length; counter[0]++)
        {
            counter[1]=  strcmp(name1, name[counter[0]]);
            if(counter[1]==0)
            {
                counter[2]=1;
                break;
            }
        }
        if(counter[2]==1)
        {
            printf("   id    \t   name of student   \t assignment \t quizzes \t midterm \t practical \t final \t grade \n");
            printf(" %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );
        }
        else printf("student does not exist\n");
        char filename[20], answer2;
        printf("if you want to save these data press y otherwise press n\n");
        scanf("%s", &answer2);
        if(answer2=='y')
        {
            printf("print file name:\n");
            scanf("%s", &filename);
            FILE *savedata=fopen(filename, "a");

            fprintf( savedata, " %d \t     %s \t    %.2lf    \t  %.2lf   \t  %.2lf   \t   %.2lf    \t %.2lf \t %.2lf\n", id[counter[0]], name[counter[0]], assignments[counter[0]], quiz[counter[0]], mid[counter[0]], practical[counter[0]], finalex[counter[0]], grade[counter[0]] );


            fclose(savedata);
        }

        else if(answer2!='n') printf("error...\n");

        printf("press 1 to try again or 2 to exit\n");
        scanf("%d", &counter[4]);
        if(counter[4]==2)
            break;
        else if (counter[4]!=1)
            printf("error...");
    }
}
