#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* fullName;
    int language;
    int maths;
    int physics;
    int certificate;
    char* passportSerialNumber;
    char* school;
    char* address;
}Applicant;

typedef struct node{
    Applicant* data;
    struct node* next;
    struct node* prev;
}Node;

typedef struct{
    Node* head;
    int size;
}List;

void pushBack(List* l, Applicant* ap);
void removeThis(List* l, int index);
void popFront(List* l);
void clearList(List* l);
void setInfo(Applicant* ap);
void getInfo(Applicant* ap);
int menu();
void addApplicant(char* faculty,char* specialty, List* FKSiS[4],List* FITY[5],List* IEF[4], Applicant* p);
void deleteApplicant(char* name, List* FKSiS[4],List* FITY[5],List* IEF[4]);
void entryPoints(List* spec, int budg);

int main() {

    int m = 1;
    List* FKSiS[4];
    List* FITY[5];
    List* IEF[4];

    for(int i=0; i<4; i++){
        FKSiS[i]=(List*) malloc(sizeof(List));
        FKSiS[i]->size=0;
    }
    for(int i=0; i<5; i++){
        FITY[i]=(List*) malloc(sizeof(List));
        FITY[i]->size=0;
    }
    for(int i=0; i<4; i++){
        IEF[i]=(List*) malloc(sizeof(List));
        IEF[i]->size=0;
    }

    char str[200];
    FILE *f;
    f = fopen("/Users/katasorokina/my projects/sea7/applicants.txt","r");

    while(1){
        char *string = fgets(str, sizeof(str),f);
        Applicant *p = (Applicant*) malloc(sizeof(Applicant));

        if (string==NULL)
            break;

        char* faculty = strtok(string, "|");
        char* specialty = strtok(NULL, "|");

        p->fullName = strtok(NULL, "|");
        p->passportSerialNumber = strtok(NULL, "|");
        p->address = strtok(NULL, "|");
        p->school = strtok(NULL, "|");
        char* num = strtok(NULL, "|");
        p->certificate = atol(num);
        num = strtok(NULL, "|");
        p->language = atol(num);
        num = strtok(NULL, "|");
        p->maths = atol(num);
        num = strtok(NULL, "|");
        p->physics = atol(num);

        addApplicant(faculty, specialty, FKSiS, FITY, IEF, p);

    }

    fclose(f);
    while(m!=5) {
        m = menu();
        switch (m) {
            case 1: {
                Applicant *p = (Applicant*) malloc(sizeof(Applicant));
                setInfo(p);
            }
            case 2: {
                printf("Введите ФИО абитуриента");
                char* name = (char*) malloc(35*sizeof(char));
                scanf("%[^\n]s", name);
                deleteApplicant(name, FKSiS, FITY, IEF);
            }
            case 3: {
                printf("\nФКСиС:");
                printf("\nИиТП:");
                printf("\nПОИТ:");
                printf("\nВМСиС:");
                printf("\nЭВС:");

                printf("\nФИТУ:");
                printf("\nАСОИ:");
                printf("\nИИ:");
                printf("\nИТиУТС:");
                printf("\nПЭ:");
                printf("\nИСиТ:");

                printf("\nИЭФ:");
                printf("\nИСиТ(э):");
                printf("\nИСиТ(л):");
                printf("\nЭЭБ:");
                printf("\nЭМ:");
            }
            case 4: {

            }
            default: break;
        }
    }

    return 0;
}

void entryPoints(List* spec, int budg){


}

void addApplicant(char* faculty,char* specialty, List* FKSiS[4],List* FITY[5],List* IEF[4], Applicant* p){
    if(strcmp(faculty,"ФКСиС")==0){
        if(strcmp(specialty,"ИиТП")==0) {
            FKSiS[0]=(List*) realloc(FKSiS[0],(FKSiS[0]->size)* sizeof(List));
            pushBack(FKSiS[0], p);
        } else if(strcmp(specialty,"ПОИТ")==0) {
            FKSiS[1]=(List*) realloc(FKSiS[1],(FKSiS[1]->size)* sizeof(List));
            pushBack(FKSiS[1], p);
        } else if(strcmp(specialty,"ВМСиС")==0) {
            FKSiS[2]=(List*) realloc(FKSiS[2],(FKSiS[2]->size)* sizeof(List));
            pushBack(FKSiS[2], p);
        } else if(strcmp(specialty,"ЭВС")==0) {
            FKSiS[3]=(List*) realloc(FKSiS[3],(FKSiS[3]->size)* sizeof(List));
            pushBack(FKSiS[3], p);
        }
    } else if(strcmp(faculty,"ИЭФ")==0){
        if(strcmp(specialty,"ИСиТ(э)")==0) {
            IEF[0]=(List*) realloc(IEF[0],(IEF[0]->size)* sizeof(List));
            pushBack(IEF[0], p);
        } else if(strcmp(specialty,"ИСиТ(л)")==0) {
            IEF[1]=(List*) realloc(IEF[1],(IEF[1]->size)* sizeof(List));
            pushBack(IEF[1], p);
        } else if(strcmp(specialty,"ЭЭБ")==0) {
            IEF[2]=(List*) realloc(IEF[2],(IEF[2]->size)* sizeof(List));
            pushBack(IEF[2], p);
        } else if(strcmp(specialty,"ЭМ")==0) {
            IEF[3]=(List*) realloc(IEF[3],(IEF[3]->size)* sizeof(List));
            pushBack(IEF[3], p);
        }
    }else if(strcmp(faculty,"ФИТУ")==0){
        if(strcmp(specialty,"АСОИ")==0) {
            FITY[0]=(List*) realloc(FITY[0],(FITY[0]->size)* sizeof(List));
            pushBack(FITY[0], p);
        } else if(strcmp(specialty,"ИИ")==0) {
            FITY[1]=(List*) realloc(FITY[1],(FITY[1]->size)* sizeof(List));
            pushBack(FITY[1], p);
        } else if(strcmp(specialty,"ИТиУТС")==0) {
            FITY[2]=(List*) realloc(FITY[2],(FITY[2]->size)* sizeof(List));
            pushBack(FITY[2], p);
        } else if(strcmp(specialty,"ПЭ")==0) {
            FITY[3]=(List*) realloc(FITY[3],(FITY[3]->size)* sizeof(List));
            pushBack(FITY[3], p);
        } else if(strcmp(specialty,"ИСиТ")==0) {
            FITY[4]=(List*) realloc(FITY[4],(FITY[3]->size)* sizeof(List));
            pushBack(FITY[4], p);
        }
    }
}

void deleteApplicant(char* name, List* FKSiS[4],List* FITY[5],List* IEF[4]){
    Node* tmp;
    for(int i=0; i<4; i++){
        FKSiS[i]=(List*) malloc(sizeof(List));
        tmp=FKSiS[i]->head;
        for(int j = 0; j<FKSiS[i]->size && tmp!=NULL;j++){
            if(strcmp(name,tmp->data->fullName)==0)
                removeThis(FKSiS[i],j);
        }
    }
    for(int i=0; i<5; i++){
        FITY[i]=(List*) malloc(sizeof(List));
        tmp=FITY[i]->head;
        for(int j = 0; j<FITY[i]->size && tmp!=NULL;j++){
            if(strcmp(name,tmp->data->fullName)==0)
                removeThis(FITY[i],j);
        }
    }
    for(int i=0; i<4; i++){
        IEF[i]=(List*) malloc(sizeof(List));
        tmp=IEF[i]->head;
        for(int j = 0; j<IEF[i]->size && tmp!=NULL;j++){
            if(strcmp(name,tmp->data->fullName)==0)
                removeThis(IEF[i],j);
        }
    }
}

int menu(){
    int ch = 0, var = 0;
    printf("\nВыберите, что вы хотите сделать:");
    printf("\n1 - подать документы в БГУИР"
           "\n2 - забрать документы"
           "\n3 - узнать проходные баллы"
           "\n4 - увидеть списки поступивших"
           "\n5 - выйти");
    while(var!=1 && ch<6 && ch>0) {
        var = scanf("%d", &ch);
        if(var!=1)
            fflush(stdin);
    }
    return ch;
}

void getInfo(Applicant* ap){
    printf("ФИО: %s\tБалл: %d", ap->fullName, ap->certificate+ap->maths+ap->language+ap->physics);
}

void setInfo(Applicant* ap){
    printf("\nВведите информацию об абитуриенте:");
    printf("\nФИО: ");
    scanf("%[^\n]s", ap->fullName);
    printf("\nСерийный номер паспорта: ");
    scanf("%[^\n]s", ap->passportSerialNumber);
    printf("\nАдрес: ");
    scanf("%[^\n]s", ap->address);
    printf("\nУчебное заведение: ");
    scanf("%[^\n]s", ap->school);
    printf("\nБалл из аттестата: ");
    scanf("%d",&ap->certificate);
    printf("\nБалл за ЦТ по языку: ");
    scanf("%d",&ap->language);
    printf("\nБалл за ЦТ по математике: ");
    scanf("%d",&ap->maths);
    printf("\nБалл за ЦТ по физике: ");
    scanf("%d",&ap->physics);
}

void pushBack(List* l, Applicant* ap){
    if(l->head==NULL){
        l->head=(Node*)malloc(sizeof(Node));
        l->head->next=NULL;
        l->head->prev=NULL;
        l->head->data=ap;
    } else{
        Node *tmp = l->head;
        while (tmp->next!=NULL){
            tmp=tmp->next;
        }
        (tmp->next)->next=NULL;
        (tmp->next)->data=ap;
        (tmp->next)->prev=tmp;
    }
    l->size++;
}

void popFront(List* l){
    Node* del = l->head;
    l->head=(l->head)->next;
    if(l->head!=NULL){
        (l->head)->prev=NULL;
    }
    free(del->data);
    free(del);
    l->size--;
}

void removeThis(List* l, int index){
    if(index==0) {
        popFront(l);
    } else if(index<l->size){
        Node *tmp = l->head;
        for (int i = 0; i < index - 1 && tmp->next!=NULL; i++){
            tmp=tmp->next;
        }
        Node *del = tmp->next;
        if(tmp->next!=NULL){
            tmp->next = del->next;
            if(del->next!=NULL){
                (del->next)->prev=tmp;
            }
        }
        free(del->data);
        free(del);
        l->size--;
    }
}

void clearList(List* l){
    while (l->size){
        popFront(l);
    }
}