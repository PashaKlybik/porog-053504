#include <stdio.h>
#include <time.h>

int date_comparison(char date_now[20],char pill_date[20]);
int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *file;
    struct tm *u;
    char date_now[10];
    time_t t=time(NULL);
    u=localtime(&t);
    strftime(date_now, 10, "%d.%m.%y",u);
    printf("Date is %s\n\n", date_now);
    if ((file = fopen("YOUR FILE LOCATION","r")) == NULL){//FILE LOCATION
        printf("Error! opening file ");
        return 0;
    }
    int pills_lose=0, pill_price, pill_quantity;
    char pill_name[100], pill_date[10];
    while(!feof(file)){
        fscanf(file,"%s %s %d %d", pill_name, pill_date, &pill_quantity, &pill_price);
        if(date_comparison(date_now, pill_date)==1){
            pills_lose+=pill_price*pill_quantity;
            printf("%s %s %d %d \n", pill_name, pill_date, pill_quantity, pill_price);
        }
        
    }
    printf("\nYou lose %d\n", pills_lose);
    
    fclose(file);
    return 0;
}
int date_comparison(char date_now[10],char pill_date[10]){
    int d,m,y, pill_d, pill_m, pill_y;
    d=date_now[0]*10+date_now[1];
    m=date_now[3]*10+date_now[4];
    y=date_now[6]*10+date_now[7];
    pill_d=pill_date[0]*10+pill_date[1];
    pill_m=pill_date[3]*10+pill_date[4];
    pill_y=pill_date[6]*10+pill_date[7];
    if(y<pill_y) return 0;
    else if(y>pill_y) return 1;
    else {
        if(m<pill_m) return 0;
        else if (m>pill_m) return 1;
        else{
            if (d<=pill_d) return 0;
            else return 1;
        }
    }
}