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
    int budgetPlaces;
    char* specialtyName;
    char* shortSpecialtyName;
}List;

void pushBack(List* l, Applicant* ap);
void removeThis(List* l, int index);
void popFront(List* l);
void clearList(List* l);
void setInfo(Applicant* ap);
void getInfo(Applicant* ap);
int menu();
void addApplicant(Applicant* p, char* faculty, char* specialty, List* FKSiS[4],List* FITY[5],List* IEF[4]);
void deleteApplicant(char* name, List* FKSiS[4],List* FITY[5],List* IEF[4]);
int entryPoints(List* spec);
void showEntryPoints(List* faculty[], int size);
void showEnrolled(List* faculty[], int size);
char* getString();
void writeToFile(List* faculty[], int size, char* fac, FILE* f);
void writeFromFile(List* FKSiS[4],List* FITY[5],List* IEF[4], FILE* f);
void initialization(List* FKSiS[4],List* FITY[5],List* IEF[4]);

int main() {

    int m;
    List* FKSiS[4];
    List* FITY[5];
    List* IEF[4];

    initialization(FKSiS, FITY, IEF);

    FILE *f;
    f = fopen("/Users/katasorokina/my projects/sea7/applicants.txt","r");
    writeFromFile(FKSiS, FITY, IEF, f);
    fclose(f);

    m = menu();
    while(m!=5) {
        switch (m) {
            case 1: {
                char* faculty;
                char* specialty;
                Applicant *p = (Applicant*) malloc(sizeof(Applicant));
                setInfo(p);
                fflush(stdin);
                printf("Факультет: ");
                faculty = getString();
                printf("Специальность: ");
                specialty = getString();
                m = menu();
                addApplicant(p, faculty, specialty, FKSiS, FITY, IEF);
                break;
            }
            case 2: {
                fflush(stdin);
                printf("Введите ФИО абитуриента");
                char* name = getString();
                deleteApplicant(name, FKSiS, FITY, IEF);
                m = menu();
                break;
            }
            case 3: {
                fflush(stdin);
                printf("\nФакультет компьютерных систем и сетей:");
                showEntryPoints(FKSiS, 4);
                printf("\n\nФакультет информационных технологий и управления:");
                showEntryPoints(FITY, 5);
                printf("\n\nИнженерно-экономический факультет:");
                showEntryPoints(IEF, 4);
                m = menu();
                break;
            }
            case 4: {
                fflush(stdin);
                printf("\nСписки поступивших: ");
                printf("\nФакультет компьютерных систем и сетей:");
                showEnrolled(FKSiS, 4);
                printf("\nФакультет информационных технологий и управления:");
                showEnrolled(FITY, 5);
                printf("\nИнженерно-экономический факультет:");
                showEnrolled(IEF, 4);
                m = menu();
                break;
            }
            default: break;
        }
    }

    f = fopen("/Users/katasorokina/my projects/sea7/applicants.txt","w");
    writeToFile(FKSiS, 4, "ФКСиС", f);
    writeToFile(FITY, 5, "ФИТУ", f);
    writeToFile(IEF, 4, "ИЭФ", f);
    fclose(f);

    for(int i=0; i<4; i++){
        clearList(FKSiS[i]);
        free(FKSiS[i]);
    }
    for(int i=0; i<5; i++){
        clearList(FITY[i]);
        free(FITY[i]);
    }
    for(int i=0; i<4; i++){
        clearList(IEF[i]);
        free(IEF[i]);
    }

    return 0;
}

void writeToFile(List* faculty[], int size, char* fac, FILE* f){
    for(int i = 0; i < size; i++){
        Node *tmp = faculty[i]->head;
        for (int j = 0; j < faculty[i]->size; j++) {
            fprintf(f,"%s|",fac);
            fprintf(f,"%s|",faculty[i]->shortSpecialtyName);
            fprintf(f,"%s|",tmp->data->fullName);
            fprintf(f,"%s|",tmp->data->passportSerialNumber);
            fprintf(f,"%s|",tmp->data->address);
            fprintf(f,"%s|",tmp->data->school);
            fprintf(f,"%d|",tmp->data->certificate);
            fprintf(f,"%d|",tmp->data->language);
            fprintf(f,"%d|",tmp->data->maths);
            fprintf(f,"%d\n",tmp->data->physics);
            tmp=tmp->next;
        }
    }
}

void writeFromFile(List* FKSiS[4],List* FITY[5],List* IEF[4], FILE* f){
    char str[200];
    while(1){
        char *string = fgets(str, sizeof(str),f);
        Applicant *p = (Applicant*) malloc(sizeof(Applicant));

        if (string==NULL)
            break;

        char* faculty = strtok(string, "|\n");
        char* specialty = strtok(NULL, "|\n");

        p->fullName = strtok(NULL, "|\n");
        p->passportSerialNumber = strtok(NULL, "|\n");
        p->address = strtok(NULL, "|\n");
        p->school = strtok(NULL, "|\n");
        char* num = strtok(NULL, "|\n");
        p->certificate = atol(num);
        num = strtok(NULL, "|\n");
        p->language = atol(num);
        num = strtok(NULL, "|\n");
        p->maths = atol(num);
        num = strtok(NULL, "|\n");
        p->physics = atol(num);

        addApplicant(p, faculty, specialty, FKSiS, FITY, IEF);
    }
}

void showEntryPoints(List* faculty[], int size){
    for (int i = 0; i < size; i++) {
        printf("\n%s: %d", faculty[i]->specialtyName, entryPoints(faculty[i]));
    }
}

int entryPoints(List* spec){
    if(spec->size==0)
        return 0;
    int res;
    int *ball = (int*) malloc((spec->size)*sizeof(int));
    Node* tmp=spec->head;
    for (int i = 0; i < spec->size; i++) {
        ball[i]=tmp->data->physics+tmp->data->language+tmp->data->certificate+tmp->data->maths;
        tmp=tmp->next;
    }

    for(int i = 0 ; i < spec->size - 1; i++) {
        for(int j = 0 ; j < spec->size - i - 1 ; j++) {
            if(ball[j] < ball[j+1]) {
                int temp = ball[j];
                ball[j] = ball[j+1] ;
                ball[j+1] = temp;
            }
        }
    }

    if(spec->budgetPlaces<spec->size){
        res = ball[spec->budgetPlaces-1];
    } else{
        res = ball[spec->size-1];
    }

    free(ball);
    return res;
}

void showEnrolled(List* faculty[], int size){
    for (int i = 0; i < size; i++) {
        Node *tmp = faculty[i]->head;
        for (int j = 0; j < faculty[i]->size; j++) {
            int score = tmp->data->physics + tmp->data->language + tmp->data->certificate + tmp->data->maths;
            if (score >= entryPoints(faculty[i])) {
                getInfo(tmp->data);
            }
            tmp = tmp->next;
        }
    }
}

void addApplicant(Applicant* p, char* faculty, char* specialty, List* FKSiS[4],List* FITY[5],List* IEF[4]){
    if(strcmp(faculty,"ФКСиС")==0){
        for (int i = 0; i < 4; i++) {
            if(strcmp(specialty, FKSiS[i]->shortSpecialtyName)==0) {
                pushBack(FKSiS[i], p);
                return;
            }
        }
    } else if(strcmp(faculty,"ИЭФ")==0){
        for (int i = 0; i < 4; i++) {
            if(strcmp(specialty, IEF[i]->shortSpecialtyName)==0) {
                pushBack(IEF[i], p);
                return;
            }
        }
    }else if(strcmp(faculty,"ФИТУ")==0){
        for (int i = 0; i < 5; i++) {
            if(strcmp(specialty, FITY[i]->shortSpecialtyName)==0) {
                pushBack(FITY[i], p);
                return;
            }
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
           "\n5 - выйти\n");
    while(var!=1 && (ch>5 || ch<1)) {
        var = scanf("%d", &ch);
        if(var!=1)
            fflush(stdin);
    }
    return ch;
}

void initialization(List* FKSiS[4],List* FITY[5],List* IEF[4]){

    for(int i=0; i<4; i++){
        FKSiS[i]=(List*) malloc(sizeof(List));
        FKSiS[i]->size=0;
        FKSiS[i]->head=NULL;
    }
    for(int i=0; i<5; i++){
        FITY[i]=(List*) malloc(sizeof(List));
        FITY[i]->size=0;
        FITY[i]->head=NULL;
    }
    for(int i=0; i<4; i++){
        IEF[i]=(List*) malloc(sizeof(List));
        IEF[i]->size=0;
        IEF[i]->head=NULL;
    }

    FKSiS[0]->budgetPlaces=65;
    FKSiS[1]->budgetPlaces=60;
    FKSiS[2]->budgetPlaces=75;
    FKSiS[3]->budgetPlaces=25;

    FITY[0]->budgetPlaces=60;
    FITY[1]->budgetPlaces=55;
    FITY[2]->budgetPlaces=60;
    FITY[3]->budgetPlaces=25;
    FITY[4]->budgetPlaces=15;

    IEF[0]->budgetPlaces=60;
    IEF[1]->budgetPlaces=20;
    IEF[2]->budgetPlaces=15;
    IEF[3]->budgetPlaces=15;

    FKSiS[0]->specialtyName="Информатика и технологии программирования";
    FKSiS[1]->specialtyName="Программное обеспечение информационных технологий";
    FKSiS[2]->specialtyName="Вычислительные машины, системы и сети";
    FKSiS[3]->specialtyName="Электронные вычислительные средства";

    FITY[0]->specialtyName="Автоматизированные системы обработки информации";
    FITY[1]->specialtyName="Искусственный интеллект";
    FITY[2]->specialtyName="Информационные технологии и управление в технических системах";
    FITY[3]->specialtyName="Промышленная электроника";
    FITY[4]->specialtyName="Информационные системы и технологии (в игровой индустрии)";

    IEF[0]->specialtyName="Информационные системы и технологии (в экономике)";
    IEF[1]->specialtyName="Информационные системы и технологии (в логистике)";
    IEF[2]->specialtyName="Экономика электронного бизнеса";
    IEF[3]->specialtyName="Электронный маркетинг";

    FKSiS[0]->shortSpecialtyName="ИиТП";
    FKSiS[1]->shortSpecialtyName="ПОИТ";
    FKSiS[2]->shortSpecialtyName="ВМСиС";
    FKSiS[3]->shortSpecialtyName="ЭВС";

    FITY[0]->shortSpecialtyName="АСОИ";
    FITY[1]->shortSpecialtyName="ИИ";
    FITY[2]->shortSpecialtyName="ИТиУТС";
    FITY[3]->shortSpecialtyName="ПЭ";
    FITY[4]->shortSpecialtyName="ИСиТ";

    IEF[0]->shortSpecialtyName="ИСиТ(э)";
    IEF[1]->shortSpecialtyName="ИСиТ(л)";
    IEF[2]->shortSpecialtyName="ЭЭБ";
    IEF[3]->shortSpecialtyName="ЭМ";
}

void getInfo(Applicant* ap){
    printf("\nФИО: %s\t\t\tБалл: %d", ap->fullName, ap->certificate+ap->maths+ap->language+ap->physics);
}

void setInfo(Applicant* ap){
    fflush(stdin);
    printf("\nВведите информацию об абитуриенте:");
    printf("\nФИО: ");
    ap->fullName=getString();
    printf("Серийный номер паспорта: ");
    ap->passportSerialNumber=getString();
    printf("Адрес: ");
    ap->address=getString();
    printf("Учебное заведение: ");
    ap->school=getString();
    printf("Балл из аттестата: ");
    scanf("%d",&(ap->certificate));
    printf("Балл за ЦТ по языку: ");
    scanf("%d",&(ap->language));
    printf("Балл за ЦТ по математике: ");
    scanf("%d",&(ap->maths));
    printf("Балл за ЦТ по физике: ");
    scanf("%d",&(ap->physics));
}

char* getString(){
    char* string=(char*)malloc(60* sizeof(char));
    char symbol = 'a';
    int index = 0;
    while(symbol!='\n'){
        symbol= getc(stdin);
        if(symbol!='\n') {
            string[index] = symbol;
            index++;
        }
    }
    string[index]='\0';
    return string;
}

void pushBack(List* l, Applicant* ap){
    Node *tmp = l->head;
    if(tmp==NULL){
        l->head=(Node*)malloc(sizeof(Node));
        l->head->next=NULL;
        l->head->prev=NULL;
        l->head->data=(Applicant*) malloc(sizeof(Applicant));
        l->head->data->fullName=(char*)malloc(60*sizeof(char));
        strcpy(l->head->data->fullName, ap->fullName);
        strcpy(ap->fullName, "");
        l->head->data->passportSerialNumber=(char*)malloc(10*sizeof(char));
        strcpy(l->head->data->passportSerialNumber, ap->passportSerialNumber);
        strcpy(ap->passportSerialNumber, "");
        l->head->data->address=(char*)malloc(60*sizeof(char));
        strcpy(l->head->data->address, ap->address);
        strcpy(ap->address, "");
        l->head->data->school=(char*)malloc(60*sizeof(char));
        strcpy(l->head->data->school, ap->school);
        strcpy(ap->school, "");
        l->head->data->certificate=ap->certificate;
        l->head->data->language=ap->language;
        l->head->data->maths=ap->maths;
        l->head->data->physics=ap->physics;
    } else{
        while (tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=(Node*)malloc(sizeof(Node));
        (tmp->next)->next=NULL;
        (tmp->next)->prev=tmp;
        (tmp->next)->data=(Applicant*) malloc(sizeof(Applicant));
        (tmp->next)->data->fullName=(char*)malloc(60*sizeof(char));
        strcpy((tmp->next)->data->fullName, ap->fullName);
        (tmp->next)->data->passportSerialNumber=(char*)malloc(10*sizeof(char));
        strcpy((tmp->next)->data->passportSerialNumber, ap->passportSerialNumber);
        (tmp->next)->data->address=(char*)malloc(60*sizeof(char));
        strcpy((tmp->next)->data->address, ap->address);
        (tmp->next)->data->school=(char*)malloc(60*sizeof(char));
        strcpy((tmp->next)->data->school, ap->school);
        (tmp->next)->data->certificate=ap->certificate;
        (tmp->next)->data->language=ap->language;
        (tmp->next)->data->maths=ap->maths;
        (tmp->next)->data->physics=ap->physics;
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
        tmp->next = del->next;
        if(del->next!=NULL) {
            (del->next)->prev = tmp;
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