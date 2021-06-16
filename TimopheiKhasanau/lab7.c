#include <stdio.h>
#include<malloc.h>
#include <string.h>

struct Task
{
    char name[20];
    char start[11];
    char end[11];
    int parTask;
};

struct Resources
{
    int budget;
    char **people;
    char specComm[50];
};

struct Project
{
    struct Resources res;
    struct Task **tasks;
    struct Project* pNext;
    struct Project* pPrev;
    char prName[20];
    int amount, peopleSize;
};


struct List
{
    struct Project* head;
    int size;
};

struct List pushBack(struct List *, struct Project *);
struct List removeAt(struct List *, int);
struct List popFront(struct List *);
struct List clearList(struct List *);
void fromFileToList(struct List *);
void addProject(struct List *);
void spreadsheet(struct List *);
void projInfo(struct List *, int);
void fromListToFile(struct List *);

int main() {
    struct List bpro, *proj = &bpro;
    bpro.head = NULL;
    bpro.size = 0;
    _Bool run = 1;
    int choice = 0;
    fromFileToList(proj);
    while(run)
    {
        printf("Make a choice:\n1. Add project\n2. Delete project\n3. Spreadsheet of projects\n4. Full project's editing\n5. More information about project\n6. Write to file\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProject(proj);
                printf("\n\n");
                break;
            case 2:
                printf("ID of the object:\n");
                scanf("%d", &choice);
                printf("\n\n");
                removeAt(proj, choice);
                break;
            case 3:
                spreadsheet(proj);
                break;
            case 4:
                printf("ID of the object:\n");
                scanf("%d", &choice);
                printf("\n\n");
                removeAt(proj, choice);
                addProject(proj);
                break;
            case 5:
                printf("ID of the object:\n");
                scanf("%d", &choice);
                printf("\n\n");
                projInfo(proj, choice);
                break;
            case 6:
                fromListToFile(proj);
                printf("\n\n");
                break;
            case 0:
                clearList(proj);
                run = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

void fromListToFile(struct List *proj)
{
    struct Project *new = proj->head;
    FILE *test = fopen("C:\\Git_rep\\prog-053504\\TimopheiKhasanau\\databaseForLab7.txt","w");
    if(!test)
    {
        printf("Error open\n");
        return;
    }
    int z =0;
    int budj = 0;
    char b[17];
    char *r;
    while (z < proj->size )
    {
        budj = new->res.budget;
        fprintf(test, "'%s %d$ %s\n", &new->prName, budj, &new->res.specComm);
        int i =0;
        while(i < new->amount)
        {
            if(i != new->amount -1)
            {
                fprintf(test, "%s %10s %10s 1 ,\n", &new->tasks[i]->name, &new->tasks[i]->start, &new->tasks[i]->end);
            }
            else
            {
                fprintf(test, "%s %10s %10s 0 .\n", &new->tasks[i]->name, &new->tasks[i]->start, &new->tasks[i]->end);
            }
            i++;
        }
        fprintf(test, "-People:\n");
        int j = 0;
        char name[20];
        while(j < new->peopleSize)
        {

            strcpy(name, new->res.people[j]);
           if(j != new->peopleSize -1 )
           {
               fprintf(test, "%s ;\n", &name);
           }
           else
           {
               fprintf(test, "%s .", &name);
           }
           j++;
        }
        if(z != proj->size -1)
        {
            fprintf(test,"\n+\n\n");
        }

        new = new->pNext;
        z++;
    }
    fclose(test);
}

void projInfo(struct List *proj, int index)
{
    index--;
    if(index < proj->size)
    {
        struct Project* proto = proj->head;
        for(int i = 0; i < index ; i++)
        {
            proto = proto->pNext;
        }
        printf("Project-> %s Special Comment: %s\n ", proto->prName, proto->res.specComm);
        printf("People amount: %5d\n{\n", proto->peopleSize);
        for(int i =0; i < proto->peopleSize; i++)
        {
            printf("%d: %s\n",i+1 ,proto->res.people[i]);
        }
        printf("}\n");
        printf("Amount of tasks: %5d\n", proto->amount);
        struct Task *prim;
        char date[11], etad[11];
        int *crit = (int *) malloc(1*sizeof(int));
        int pday1, pday2, pmon1, pmon2, pyear1, pyear2;
        int maxday = 0, minday = 0, maxmon = 0, minmon = 0, maxyear = 0, minyear = 0;
        int limit = 0;
        int j = 0;
        for(int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            strcpy(etad, prim->end);
            strcpy(date, prim->start);
            crit = (int*) realloc(crit, (j+1)* sizeof(int));
            if(!strcmp(date, "0") && !strcmp(date, "0"))
            {
                crit[j] = 0;
            }
            else
            {
                crit[j] = 1;
            }
            j++;
        }
        for(int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if(crit[i] == 1)
            {
                strcpy(etad, prim->end);
                strcpy(date, prim->start);

                if(!strcmp(date, "0"))
                {
                    pday1 = pmon1 = pyear1 = 0;
                    pday2 = (etad[0]-48)*10 + etad[1]-48;
                    pmon2 = (etad[3]-48)*10 + etad[4]-48;
                    pyear2 = (etad[6]-48)*1000 + (etad[7]-48)*100 + (etad[8]-48)* 10 +etad[9]-48;
                }
                else if(!strcmp(etad, "0"))
                {
                    pday2 = pmon2 = pyear2 = 0;
                    pday1 = (date[0]-48)*10 + date[1]-48;
                    pmon1 = (date[3]-48)*10 + date[4]-48;
                    pyear1 = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)* 10 +date[9]-48;
                }
                else
                {
                    pday1 = (date[0]-48)*10 + date[1]-48;
                    pday2 = (etad[0]-48)*10 + etad[1]-48;
                    pmon1 = (date[3]-48)*10 + date[4]-48;
                    pmon2 = (etad[3]-48)*10 + etad[4]-48;
                    pyear1 = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)* 10 +date[9]-48;
                    pyear2 = (etad[6]-48)*1000 + (etad[7]-48)*100 + (etad[8]-48)* 10 +etad[9]-48;
                }

                if(pyear1 < minyear)
                {
                    minyear = pyear1;
                    minmon = pmon1;
                    minday = pday1;
                }
                else if(pyear1 == minyear)
                {
                    if(pmon1 < minmon)
                    {
                        minmon = pmon1;
                        minday = pday1;
                    }
                    else if(pmon1 == minmon)
                    {
                        if(pday1 < minday)
                        {
                            minday = pday1;
                        }
                    }
                }
                else
                {
                    if(!minyear)
                    {
                        minyear = pyear1;
                        minmon = pmon1;
                        minday = pday1;
                    }
                }

                if(pyear2 > maxyear)
                {
                    maxyear = pyear1;
                    maxmon = pmon2;
                    maxday = pday2;
                }
                else if(pyear2 == maxyear)
                {
                    if(pmon2 > maxmon)
                    {
                        maxmon = pmon2;
                        maxday = pday2;
                    }
                    else if(pmon2 == maxmon)
                    {
                        if(pday2 > maxday)
                        {
                            maxday = pday2;
                        }
                    }
                    else
                    {
                        if(!maxmon)
                        {
                            maxmon = pmon2;
                        }
                    }
                }

            }
        }

        printf("[Parallel]: \n");
        for(int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if(crit[i] == 0)
            {
                printf("|%20s; ", prim->name);
            }
        }

        printf("[Critical]: \n");
        for(int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if(crit[i] == 1)
            {
                strcpy(etad, prim->end);
                strcpy(date, prim->start);

                if(!strcmp(date, "0"))
                {
                    pday1 = pmon1 = pyear1 = 0;
                    pday2 = (etad[0]-48)*10 + etad[1]-48;
                    pmon2 = (etad[3]-48)*10 + etad[4]-48;
                    pyear2 = (etad[6]-48)*1000 + (etad[7]-48)*100 + (etad[8]-48)* 10 +etad[9]-48;
                }
                else if(!strcmp(etad, "0"))
                {
                    pday2 = pmon2 = pyear2 = 0;
                    pday1 = (date[0]-48)*10 + date[1]-48;
                    pmon1 = (date[3]-48)*10 + date[4]-48;
                    pyear1 = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)* 10 +date[9]-48;
                }
                else
                {
                    pday1 = (date[0]-48)*10 + date[1]-48;
                    pday2 = (etad[0]-48)*10 + etad[1]-48;
                    pmon1 = (date[3]-48)*10 + date[4]-48;
                    pmon2 = (etad[3]-48)*10 + etad[4]-48;
                    pyear1 = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)* 10 +date[9]-48;
                    pyear2 = (etad[6]-48)*1000 + (etad[7]-48)*100 + (etad[8]-48)* 10 +etad[9]-48;
                }
                if(strcmp(prim->start,"0") != 0 && strcmp(prim->end,"0") != 0)
                {
                    limit = (pyear2 - pyear1)*365 + (pmon2 - pmon1)*31 + (pday2 - pday1);
                }
                else if(strcmp(prim->end,"0") != 0)
                {
                    limit = (maxyear - pyear1)*365 + (maxmon - pmon1)*31 + (maxday - pday1);
                }
                else
                {
                    limit = (pyear2 - minyear)*365 + (pmon2 - minmon)*31 + (pday2 - minday);
                }

                printf("|%20s; ", prim->name);
                if(strcmp(prim->start,"0") != 0)
                {
                    printf("%11s ", prim->start);
                }
                if(strcmp(prim->end,"0") != 0)
                {
                    printf("%11s Leeway: %d days\n", prim->end, limit);
                }
            }

        }
        printf("\n\n\n");
        free(crit);
    }
}

void spreadsheet(struct List *proj)
{
    int i = 0;
    struct Project *proto = proj->head;
    printf("________________________________________________________________\n");
    printf("................................................................\n");
    while( i < proj->size)
    {
        int j = 0;
        printf("|%2d |Project's name: %20s |Budjet: %10d$ |\n", i+1, proto->prName, proto->res.budget);
        printf("----------------------------------------------------------------\n");
        while(j < proto->amount)
        {
            printf("|Task %2d |   Task's name: %20s |limits in p. 5 | \n", j+1, proto->tasks[j]->name);
            j++;
        }
        printf("................................................................\n");
        proto = proto->pNext;
        i++;
    }
    printf("________________________________________________________________\n\n\n\n");
}

void addProject(struct List *proj)
{
    struct Project *new = (struct Project *)malloc(1*sizeof(struct Project));
    new->amount = 1, new->peopleSize = 1;
    _Bool run = 1;
    char symb = '0', name[20], st[11], end[11], choice[4];
    printf("Enter project's name, budget(int), comment\n");
    scanf( "%20s %d %50s", &new->prName, &new->res.budget, &new->res.specComm);
    while(run)
    {
        printf("Enter task's name, start date, end date\n");
        scanf("%s %10s %10s", &name, &st, &end);
        st[10] = '\0';
        end[10] = '\0';
        if(new->amount == 1)
        {
            new->tasks =  (struct Task **)malloc(1*sizeof(struct Task *));
            new->tasks[0] = (struct Task *)malloc(1*sizeof(struct Task));
        }
        else
        {
            new->tasks = (struct Task **)realloc(new->tasks,(new->amount)*sizeof(struct Task *));
            new->tasks[new->amount - 1] = (struct Task *)malloc(1*sizeof(struct Task));
        }
        strcpy(new->tasks[new->amount - 1]->name, name);
        strcpy(new->tasks[new->amount - 1]->start, st);
        strcpy(new->tasks[new->amount - 1]->end, end);
        strcpy(name, "");
        strcpy(st, "");
        strcpy(end, "");
        printf("Continue? [yes/no]\n");
        scanf("%s", &choice);
        if(strcmp(choice, "no") == 0)
        {
            run = 0;
        }
        else
        {
            new->amount++;
        }
    }
    run = 1;
    while(run)
    {
        printf("Enter project's participant name\n");
        scanf("%20s", &name);
        if(new->peopleSize == 1)
        {
            new->res.people =  (char **)malloc(1*sizeof(char *));
            new->res.people[0] =  (char *)malloc(20*sizeof(char));
        }
        else
        {
            new->res.people = (char **)realloc(new->res.people,(new->peopleSize)*sizeof(char *));
            new->res.people[new->peopleSize-1] =  (char *)malloc(20*sizeof(char));
        }
        strcpy(new->res.people[new->peopleSize - 1],name);
        strcpy(name, "");
        printf("Continue? [yes/no]\n");
        scanf("%s", &choice);
        if(strcmp(choice, "no") == 0)
        {
            run = 0;
        }
        else
        {
            new->peopleSize++;
        }
    }
    pushBack(proj, new);
    for(int i = 0; i < new->amount; i++)
    {
        free(new->tasks[i]);
    }
    for(int i =0; i < new->peopleSize; i++)
    {
        free(new->res.people[i]);
    }
    free(new->tasks);
    free(new->res.people);
    new->amount = 1;
    new->peopleSize = 1;
    free(new);
}

void fromFileToList(struct List *proj)
{
    struct Project *new = (struct Project *)malloc(1*sizeof(struct Project));
    new->amount = 1, new->peopleSize = 1;
    _Bool run = 1;
    char symb = '0', name[20], st[11], end[11];
    int par =1;

    FILE *test = fopen("C:\\Git_rep\\prog-053504\\TimopheiKhasanau\\databaseForLab7.txt","r");
    if(!test)
    {
        printf("Error open\n");
        return;
    }
    while (run )
    {
        fscanf(test, "\n'%s %d$ %s\n", &new->prName, &new->res.budget, &new->res.specComm);
        while(fscanf(test, "%s %10s %10s %d %c\n", &name, &st, &end, &par,&symb) != EOF )
        {
            name[strlen(name)] = '\0';
            st[10] = '\0';
            end[10] = '\0';
            if(new->amount == 1)
            {
                new->tasks =  (struct Task **)malloc(1*sizeof(struct Task *));
                new->tasks[0] = (struct Task *)malloc(1*sizeof(struct Task));
            }
            else
            {
                new->tasks = (struct Task **)realloc(new->tasks,(new->amount)*sizeof(struct Task *));
                new->tasks[new->amount - 1] = (struct Task *)malloc(1*sizeof(struct Task));
            }
            strcpy(new->tasks[new->amount - 1]->name, name);
            strcpy(new->tasks[new->amount - 1]->start, st);
            strcpy(st, "");
            strcpy(new->tasks[new->amount - 1]->end, end);
            strcpy(end, "");
            strcpy(name, "");


            if(symb == '.')
            {
                symb = ',';
                break;
            }
            new->amount++;
        }
        fscanf(test, "%s\n", name);
        while(fscanf(test, "%s %c", &name, &symb) != EOF)
        {
            if(new->peopleSize == 1)
            {
                new->res.people =  (char **)malloc(1*sizeof(char *));
                new->res.people[0] =  (char *)malloc(20*sizeof(char));
            }
            else
            {
                new->res.people = (char **)realloc(new->res.people,(new->peopleSize)*sizeof(char *));
                new->res.people[new->peopleSize-1] =  (char *)malloc(20*sizeof(char));
            }

            strcpy(new->res.people[new->peopleSize - 1],name);
            strcpy(name, "");
            if(symb == '.')
            {
                symb = ',';
                break;
            }
            new->peopleSize++;
        }
        if(fscanf(test,"%s", &name) == EOF)
        {
            run = 0;
        }
        pushBack(proj, new);
        for(int i = 0; i < new->amount; i++)
        {
            free(new->tasks[i]);
        }
        for(int i =0; i < new->peopleSize; i++)
        {
            free(new->res.people[i]);
        }
        free(new->tasks);
        free(new->res.people);
        new->amount = 1;
        new->peopleSize = 1;
    }
    free(new);
    fclose(test);
}

struct List pushBack(struct List *l, struct Project *data)
{
    if(l->head == NULL)
    {
        l->head = (struct Project *) malloc (sizeof(struct Project));
        l->head->pNext = NULL;
        l->head->pPrev = NULL;
        l->head->amount = data->amount;
        l->head->peopleSize = data->peopleSize;
        l->head->res.people = (char **)malloc(l->head->peopleSize*sizeof(char *));
        for(int i = 0; i < l->head->peopleSize; i++)
        {
            l->head->res.people[i] = (char *)malloc(20*sizeof(char ));
        }
        for(int i = 0; i < data->peopleSize; i++)
        {
            strcpy(l->head->res.people[i], data->res.people[i]);
        }
        strcpy(l->head->res.specComm,data->res.specComm);
        l->head->res.budget = data->res.budget;
        l->head->tasks = (struct Task **)malloc(l->head->amount*sizeof(struct Task *));
        for(int i = 0; i < l->head->amount; i++)
        {
            l->head->tasks[i] = (struct Task *)malloc(1*sizeof(struct Task ));
        }
        for(int i = 0; i < data->amount; i++)
        {
            data->tasks[i]->end[10]= '\0';
            data->tasks[i]->start[10]= '\0';
            strcpy(l->head->tasks[i]->name, data->tasks[i]->name);
            strcpy(l->head->tasks[i]->end, data->tasks[i]->end);
            strcpy(l->head->tasks[i]->start, data->tasks[i]->start);
        }
        strcpy(l->head->prName,  data->prName);
    }
    else
    {
        struct Project* elem = l->head;
        while(elem->pNext != NULL)
        {
            elem = elem->pNext;
        }
        elem->pNext = (struct Project*) malloc (sizeof(struct Project));
        (elem->pNext)->pNext = NULL;
        (elem->pNext)->pPrev = elem;
        (elem->pNext)->amount = data->amount;
        (elem->pNext)->peopleSize = data->peopleSize;
        (elem->pNext)->res.people = (char **)malloc((elem->pNext)->peopleSize*sizeof(char *));
        for(int i = 0; i < (elem->pNext)->peopleSize; i++)
        {
            (elem->pNext)->res.people[i] = (char *)malloc(20*sizeof(char ));
        }
        for(int i = 0; i < data->peopleSize; i++)
        {
            strcpy((elem->pNext)->res.people[i], data->res.people[i]);
        }
        strcpy((elem->pNext)->res.specComm,data->res.specComm);
        (elem->pNext)->res.budget = data->res.budget;
        (elem->pNext)->tasks = (struct Task **)malloc((elem->pNext)->amount*sizeof(struct Task *));
        for(int i = 0; i < (elem->pNext)->amount; i++)
        {
            (elem->pNext)->tasks[i] = (struct Task *)malloc(1*sizeof(struct Task ));
        }
        for(int i = 0; i < (elem->pNext)->amount; i++)
        {
            strcpy((elem->pNext)->tasks[i]->name, data->tasks[i]->name);
            strcpy((elem->pNext)->tasks[i]->end, data->tasks[i]->end);
            strcpy((elem->pNext)->tasks[i]->start, data->tasks[i]->start);
        }
        strcpy(elem->pNext->prName, data->prName);
    }
    l->size++;
}

struct List popFront(struct List *l)
{
    struct Project *proto = l->head;
    l->head = (l->head)->pNext;
    if(l->head!= NULL)
    {
        l->head->pPrev = NULL;
    }
    for(int i = 0; i < proto->amount; i++)
    {
        free(proto->tasks[i]);
    }
    for(int i = 0; i < proto->peopleSize; i++)
    {
        free(proto->res.people[i]);
    }
    free(proto->tasks);
    free(proto->res.people);
    free(proto);
    l->size--;
}

struct List clearList(struct List *l)
{
    while(l->size)
    {
        popFront(l);
    }
}

struct List removeAt(struct List *l, int index)
{
    index--;
    if( index == 0)
    {
        popFront(l);
    }
    else if(index < l->size)
    {
        struct Project* prev = l->head;
        for(int i = 0; i < index - 1 && prev->pNext != NULL; i++)
        {
            prev = prev->pNext;
        }
        struct Project* del = prev->pNext;
        if( prev->pNext != NULL)
        {
            prev->pNext = del->pNext;
            (del->pNext)->pPrev = prev;
        }
        for(int i = 0; i < del->amount; i++)
        {
            free(del->tasks[i]);
        }
        for(int i = 0; i < del->peopleSize; i++)
        {
            free(del->res.people[i]);
        }
        free(del->tasks);
        free(del->res.people);
        free(del);
        l->size--;
        if(l->size == 0)
        {
            l->head = NULL;
        }
    }

}
