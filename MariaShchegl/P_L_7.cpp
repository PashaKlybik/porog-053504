#include <stdio.h>
#include<malloc.h>
#include <string.h>

struct Lessons
{
    char Name[20];
    char Start[11];
    char End[11];
    int parTask;
};

struct Resources
{
    int Money;
    char** NamePeople;
    char specComm[50];
};

struct Project
{
    struct Resources res;
    struct Lessons** tasks;
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

void pushBack(struct List* l, struct Project* data)
{
    if (l->head == NULL)
    {
        l->head = (struct Project*)malloc(sizeof(struct Project));
        l->head->pNext = NULL;
        l->head->pPrev = NULL;
        l->head->amount = data->amount;
        l->head->peopleSize = data->peopleSize;
        l->head->res.NamePeople = (char**)malloc(l->head->peopleSize * sizeof(char*));
        for (int i = 0; i < l->head->peopleSize; i++)
        {
            l->head->res.NamePeople[i] = (char*)malloc(20 * sizeof(char));
        }
        for (int i = 0; i < data->peopleSize; i++)
        {
            strcpy(l->head->res.NamePeople[i], data->res.NamePeople[i]);
        }
        strcpy(l->head->res.specComm, data->res.specComm);
        l->head->res.Money = data->res.Money;
        l->head->tasks = (struct Lessons**)malloc(l->head->amount * sizeof(struct Lessons*));/////////////////
        for (int i = 0; i < l->head->amount; i++)
        {
            l->head->tasks[i] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));
        }
        for (int i = 0; i < data->amount; i++)
        {
            data->tasks[i]->End[10] = '\0';
            data->tasks[i]->Start[10] = '\0';
            strcpy(l->head->tasks[i]->Name, data->tasks[i]->Name);
            strcpy(l->head->tasks[i]->End, data->tasks[i]->End);
            strcpy(l->head->tasks[i]->Start, data->tasks[i]->Start);
        }
        strcpy(l->head->prName, data->prName);
    }
    else
    {
        struct Project* elem = l->head;
        while (elem->pNext != NULL)
        {
            elem = elem->pNext;
        }
        elem->pNext = (struct Project*)malloc(sizeof(struct Project));
        (elem->pNext)->pNext = NULL;
        (elem->pNext)->pPrev = elem;
        (elem->pNext)->amount = data->amount;
        (elem->pNext)->peopleSize = data->peopleSize;
        (elem->pNext)->res.NamePeople = (char**)malloc((elem->pNext)->peopleSize * sizeof(char*));
        for (int i = 0; i < (elem->pNext)->peopleSize; i++)
        {
            (elem->pNext)->res.NamePeople[i] = (char*)malloc(20 * sizeof(char));
        }
        for (int i = 0; i < data->peopleSize; i++)
        {
            strcpy((elem->pNext)->res.NamePeople[i], data->res.NamePeople[i]);
        }
        strcpy((elem->pNext)->res.specComm, data->res.specComm);
        (elem->pNext)->res.Money = data->res.Money;
        (elem->pNext)->tasks = (struct Lessons**)malloc((elem->pNext)->amount * sizeof(struct Lessons*));
        for (int i = 0; i < (elem->pNext)->amount; i++)
        {
            (elem->pNext)->tasks[i] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));///////////////////////////////////////
        }
        for (int i = 0; i < (elem->pNext)->amount; i++)
        {
            strcpy((elem->pNext)->tasks[i]->Name, data->tasks[i]->Name);
            strcpy((elem->pNext)->tasks[i]->End, data->tasks[i]->End);
            strcpy((elem->pNext)->tasks[i]->Start, data->tasks[i]->Start);
        }
        strcpy(elem->pNext->prName, data->prName);
    }
    l->size++;
}

void popFront(struct List* l)
{
    struct Project* proto = l->head;
    l->head = (l->head)->pNext;
    if (l->head != NULL)
    {
        l->head->pPrev = NULL;
    }
    for (int i = 0; i < proto->amount; i++)
    {
        free(proto->tasks[i]);
    }
    for (int i = 0; i < proto->peopleSize; i++)
    {
        free(proto->res.NamePeople[i]);
    }
    free(proto->tasks);
    free(proto->res.NamePeople);
    free(proto);
    l->size--;
}

void clearList(struct List* l)
{
    while (l->size)
    {
        popFront(l);
    }
}

void removeAt(struct List* l, int index)
{
    index--;
    if (index == 0)
    {
        popFront(l);
    }
    else if (index < l->size)
    {
        struct Project* prev = l->head;
        for (int i = 0; i < index - 1 && prev->pNext != NULL; i++)
        {
            prev = prev->pNext;
        }
        struct Project* del = prev->pNext;
        if (prev->pNext != NULL)
        {
            prev->pNext = del->pNext;
            (del->pNext)->pPrev = prev;
        }
        for (int i = 0; i < del->amount; i++)
        {
            free(del->tasks[i]);
        }
        for (int i = 0; i < del->peopleSize; i++)
        {
            free(del->res.NamePeople[i]);
        }
        free(del->tasks);
        free(del->res.NamePeople);
        free(del);
        l->size--;
        if (l->size == 0)
        {
            l->head = NULL;
        }
    }

}
void fromListToFile(struct List* proj)
{
    struct Project* nw = proj->head;
    FILE* test = fopen("C:\\Программирование\\P_L_7\\P_L_7\\C rez.txt", "w");
    if (!test)
    {
        printf("Error open\n");
        return;
    }
    int z = 0;
    int budj = 0;
    char b[17];
    char* r;
    while (z < proj->size)
    {
        budj = nw->res.Money;
        fprintf(test, "'%s %d$ %s\n", &nw->prName, budj, &nw->res.specComm);
        int i = 0;
        while (i < nw->amount)
        {
            if (i != nw->amount - 1)
            {
                fprintf(test, "%s %10s %10s 1 ,\n", &nw->tasks[i]->Name, &nw->tasks[i]->Start, &nw->tasks[i]->End);
            }
            else
            {
                fprintf(test, "%s %10s %10s 0 .\n", &nw->tasks[i]->Name, &nw->tasks[i]->Start, &nw->tasks[i]->End);
            }
            i++;
        }
        fprintf(test, "-People:\n");
        int j = 0;
        char name[20];
        while (j < nw->peopleSize)
        {

            strcpy(name, nw->res.NamePeople[j]);
            if (j != nw->peopleSize - 1)
            {
                fprintf(test, "%s ;\n", &name);
            }
            else
            {
                fprintf(test, "%s .", &name);
            }
            j++;
        }
        if (z != proj->size - 1)
        {
            fprintf(test, "\n+\n\n");
        }

        nw = nw->pNext;
        z++;
    }
    fclose(test);
}

void projInfo(struct List* proj, int index)
{
    index--;
    if (index < proj->size)
    {
        struct Project* proto = proj->head;
        for (int i = 0; i < index; i++)
        {
            proto = proto->pNext;
        }
        printf("Project-> %s Special Comment: %s\n ", proto->prName, proto->res.specComm);
        printf("People amount: %5d\n{\n", proto->peopleSize);
        for (int i = 0; i < proto->peopleSize; i++)
        {
            printf("%d: %s\n", i + 1, proto->res.NamePeople[i]);
        }
        printf("}\n");
        printf("Amount of tasks: %5d\n", proto->amount);
        struct Lessons* prim;///////////////////////////////////////////////////
        char date[11], etad[11];
        int* crit = (int*)malloc(1 * sizeof(int));
        int pday1, pday2, pmon1, pmon2, pyear1, pyear2;
        int maxday = 0, minday = 0, maxmon = 0, minmon = 0, maxyear = 0, minyear = 0;
        int limit = 0;
        int j = 0;
        for (int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            strcpy(etad, prim->End);
            strcpy(date, prim->Start);
            crit = (int*)realloc(crit, (j + 1) * sizeof(int));
            if (!strcmp(date, "0") && !strcmp(date, "0"))
            {
                crit[j] = 0;
            }
            else
            {
                crit[j] = 1;
            }
            j++;
        }
        for (int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if (crit[i] == 1)
            {
                strcpy(etad, prim->End);
                strcpy(date, prim->Start);

                if (!strcmp(date, "0"))
                {
                    pday1 = pmon1 = pyear1 = 0;
                    pday2 = (etad[0] - 48) * 10 + etad[1] - 48;
                    pmon2 = (etad[3] - 48) * 10 + etad[4] - 48;
                    pyear2 = (etad[6] - 48) * 1000 + (etad[7] - 48) * 100 + (etad[8] - 48) * 10 + etad[9] - 48;
                }
                else if (!strcmp(etad, "0"))
                {
                    pday2 = pmon2 = pyear2 = 0;
                    pday1 = (date[0] - 48) * 10 + date[1] - 48;
                    pmon1 = (date[3] - 48) * 10 + date[4] - 48;
                    pyear1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                }
                else
                {
                    pday1 = (date[0] - 48) * 10 + date[1] - 48;
                    pday2 = (etad[0] - 48) * 10 + etad[1] - 48;
                    pmon1 = (date[3] - 48) * 10 + date[4] - 48;
                    pmon2 = (etad[3] - 48) * 10 + etad[4] - 48;
                    pyear1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                    pyear2 = (etad[6] - 48) * 1000 + (etad[7] - 48) * 100 + (etad[8] - 48) * 10 + etad[9] - 48;
                }

                if (pyear1 < minyear)
                {
                    minyear = pyear1;
                    minmon = pmon1;
                    minday = pday1;
                }
                else if (pyear1 == minyear)
                {
                    if (pmon1 < minmon)
                    {
                        minmon = pmon1;
                        minday = pday1;
                    }
                    else if (pmon1 == minmon)
                    {
                        if (pday1 < minday)
                        {
                            minday = pday1;
                        }
                    }
                }
                else
                {
                    if (!minyear)
                    {
                        minyear = pyear1;
                        minmon = pmon1;
                        minday = pday1;
                    }
                }

                if (pyear2 > maxyear)
                {
                    maxyear = pyear1;
                    maxmon = pmon2;
                    maxday = pday2;
                }
                else if (pyear2 == maxyear)
                {
                    if (pmon2 > maxmon)
                    {
                        maxmon = pmon2;
                        maxday = pday2;
                    }
                    else if (pmon2 == maxmon)
                    {
                        if (pday2 > maxday)
                        {
                            maxday = pday2;
                        }
                    }
                    else
                    {
                        if (!maxmon)
                        {
                            maxmon = pmon2;
                        }
                    }
                }

            }
        }

        printf("[Parallel]: \n");
        for (int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if (crit[i] == 0)
            {
                printf("|%20s; ", prim->Name);
            }
        }

        printf("[Critical]: \n");
        for (int i = 0; i < proto->amount; i++)
        {
            prim = proto->tasks[i];
            if (crit[i] == 1)
            {
                strcpy(etad, prim->End);
                strcpy(date, prim->Start);

                if (!strcmp(date, "0"))
                {
                    pday1 = pmon1 = pyear1 = 0;
                    pday2 = (etad[0] - 48) * 10 + etad[1] - 48;
                    pmon2 = (etad[3] - 48) * 10 + etad[4] - 48;
                    pyear2 = (etad[6] - 48) * 1000 + (etad[7] - 48) * 100 + (etad[8] - 48) * 10 + etad[9] - 48;
                }
                else if (!strcmp(etad, "0"))
                {
                    pday2 = pmon2 = pyear2 = 0;
                    pday1 = (date[0] - 48) * 10 + date[1] - 48;
                    pmon1 = (date[3] - 48) * 10 + date[4] - 48;
                    pyear1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                }
                else
                {
                    pday1 = (date[0] - 48) * 10 + date[1] - 48;
                    pday2 = (etad[0] - 48) * 10 + etad[1] - 48;
                    pmon1 = (date[3] - 48) * 10 + date[4] - 48;
                    pmon2 = (etad[3] - 48) * 10 + etad[4] - 48;
                    pyear1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                    pyear2 = (etad[6] - 48) * 1000 + (etad[7] - 48) * 100 + (etad[8] - 48) * 10 + etad[9] - 48;
                }
                if (strcmp(prim->Start, "0") != 0 && strcmp(prim->End, "0") != 0)
                {
                    limit = (pyear2 - pyear1) * 365 + (pmon2 - pmon1) * 31 + (pday2 - pday1);
                }
                else if (strcmp(prim->End, "0") != 0)
                {
                    limit = (maxyear - pyear1) * 365 + (maxmon - pmon1) * 31 + (maxday - pday1);
                }
                else
                {
                    limit = (pyear2 - minyear) * 365 + (pmon2 - minmon) * 31 + (pday2 - minday);
                }

                printf("|%20s; ", prim->Name);
                if (strcmp(prim->Start, "0") != 0)
                {
                    printf("%11s ", prim->Start);
                }
                if (strcmp(prim->End, "0") != 0)
                {
                    printf("%11s Leeway: %d days\n", prim->End, limit);
                }
            }

        }
        printf("\n\n\n");
        free(crit);
    }
}



void addProject(struct List* proj)
{
    struct Project* nw = (struct Project*)malloc(1 * sizeof(struct Project));
    nw->amount = 1, nw->peopleSize = 1;
    bool run = 1;
    char symb = '0', name[20], st[11], end[11], choice[4];
    printf("Enter project's name, budget(int), comment\n");
    scanf("%20s %d %50s", &nw->prName, &nw->res.Money, &nw->res.specComm);
    while (run)
    {
        printf("Enter task's name, start date, end date\n");
        scanf("%s %10s %10s", &name, &st, &end);
        st[10] = '\0';
        end[10] = '\0';
        if (nw->amount == 1)
        {
            nw->tasks = (struct Lessons**)malloc(1 * sizeof(struct Lessons*));/////////////////////////////////////////////////
            nw->tasks[0] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));
        }
        else
        {
            nw->tasks = (struct Lessons**)realloc(nw->tasks, (nw->amount) * sizeof(struct Lessons*));
            nw->tasks[nw->amount - 1] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));
        }
        strcpy(nw->tasks[nw->amount - 1]->Name, name);
        strcpy(nw->tasks[nw->amount - 1]->Start, st);
        strcpy(nw->tasks[nw->amount - 1]->End, end);
        strcpy(name, "");
        strcpy(st, "");
        strcpy(end, "");
        printf("Continue? [yes/no]\n");
        scanf("%s", &choice);
        if (strcmp(choice, "no") == 0)
        {
            run = 0;
        }
        else
        {
            nw->amount++;
        }
    }
    run = 1;
    while (run)
    {
        printf("Enter project's participant name\n");
        scanf("%20s", &name);
        if (nw->peopleSize == 1)
        {
            nw->res.NamePeople = (char**)malloc(1 * sizeof(char*));
            nw->res.NamePeople[0] = (char*)malloc(20 * sizeof(char));
        }
        else
        {
            nw->res.NamePeople = (char**)realloc(nw->res.NamePeople, (nw->peopleSize) * sizeof(char*));
            nw->res.NamePeople[nw->peopleSize - 1] = (char*)malloc(20 * sizeof(char));
        }
        strcpy(nw->res.NamePeople[nw->peopleSize - 1], name);
        strcpy(name, "");
        printf("Continue? [yes/no]\n");
        scanf("%s", &choice);
        if (strcmp(choice, "no") == 0)
        {
            run = 0;
        }
        else
        {
            nw->peopleSize++;
        }
    }
    pushBack(proj, nw);
    for (int i = 0; i < nw->amount; i++)
    {
        free(nw->tasks[i]);
    }
    for (int i = 0; i < nw->peopleSize; i++)
    {
        free(nw->res.NamePeople[i]);
    }
    free(nw->tasks);
    free(nw->res.NamePeople);
    nw->amount = 1;
    nw->peopleSize = 1;
    free(nw);
}

void fromFileToList(struct List* proj)
{
    struct Project* nw = (struct Project*)malloc(1 * sizeof(struct Project));
    nw->amount = 1, nw->peopleSize = 1;
    bool run = 1;
    char symb = '0', name[20], st[11], end[11];
    int par = 1;

    FILE* test = fopen("C:\\Git_rep\\prog-053504\\TimopheiKhasanau\\databaseForLab7.txt", "r");
    if (!test)
    {
        printf("Error open\n");
        return;
    }
    while (run)
    {
        fscanf(test, "\n'%s %d$ %s\n", &nw->prName, &nw->res.Money, &nw->res.specComm);
        while (fscanf(test, "%s %10s %10s %d %c\n", &name, &st, &end, &par, &symb) != EOF)
        {
            name[strlen(name)] = '\0';
            st[10] = '\0';
            end[10] = '\0';
            if (nw->amount == 1)
            {
                nw->tasks = (struct Lessons**)malloc(1 * sizeof(struct Lessons*));////////////////////////////////////////
                nw->tasks[0] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));
            }
            else
            {
                nw->tasks = (struct Lessons**)realloc(nw->tasks, (nw->amount) * sizeof(struct Lessons*));
                nw->tasks[nw->amount - 1] = (struct Lessons*)malloc(1 * sizeof(struct Lessons));
            }
            strcpy(nw->tasks[nw->amount - 1]->Name, name);
            strcpy(nw->tasks[nw->amount - 1]->Start, st);
            strcpy(st, "");
            strcpy(nw->tasks[nw->amount - 1]->End, end);
            strcpy(end, "");
            strcpy(name, "");


            if (symb == '.')
            {
                symb = ',';
                break;
            }
            nw->amount++;
        }
        fscanf(test, "%s\n", name);
        while (fscanf(test, "%s %c", &name, &symb) != EOF)
        {
            if (nw->peopleSize == 1)
            {
                nw->res.NamePeople = (char**)malloc(1 * sizeof(char*));
                nw->res.NamePeople[0] = (char*)malloc(20 * sizeof(char));
            }
            else
            {
                nw->res.NamePeople = (char**)realloc(nw->res.NamePeople, (nw->peopleSize) * sizeof(char*));
                nw->res.NamePeople[nw->peopleSize - 1] = (char*)malloc(20 * sizeof(char));
            }

            strcpy(nw->res.NamePeople[nw->peopleSize - 1], name);
            strcpy(name, "");
            if (symb == '.')
            {
                symb = ',';
                break;
            }
            nw->peopleSize++;
        }
        if (fscanf(test, "%s", &name) == EOF)
        {
            run = 0;
        }
        pushBack(proj, nw);
        for (int i = 0; i < nw->amount; i++)
        {
            free(nw->tasks[i]);
        }
        for (int i = 0; i < nw->peopleSize; i++)
        {
            free(nw->res.NamePeople[i]);
        }
        free(nw->tasks);
        free(nw->res.NamePeople);
        nw->amount = 1;
        nw->peopleSize = 1;
    }
    free(nw);
    fclose(test);
}



int main() {
    struct List bpro, * proj = &bpro;
    bpro.head = NULL;
    bpro.size = 0;
    bool run = 1;
    int choice = 0;
    fromFileToList(proj);
    while (run)
    {
        printf("Make a choice:\n1. Add project\n2. Delete project\n3.Full project's editing \n4.More information about project\n5.Write to file\n 6.Exit\n");
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
            printf("ID of the object:\n");
            scanf("%d", &choice);
            printf("\n\n");
            removeAt(proj, choice);
            addProject(proj);
            break;
            break;
        case 4:
            printf("ID of the object:\n");
            scanf("%d", &choice);
            printf("\n\n");
            projInfo(proj, choice);
            break;
        case 5:
            fromListToFile(proj);
            printf("\n\n");
            break;
        case 6:
            clearList(proj);
            run = 0;
            break;


        default:
            break;
        }
    }
    return 0;
}