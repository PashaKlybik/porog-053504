#include <stdio.h>
#define N 8

void check(int k_xpos, int k_ypos, int x_sign, int y_sign, int arr[N][N]){
    int i = 1;
    while(k_xpos + i * x_sign > 0 && k_ypos + i * y_sign > 0 && i < N) {
            if (arr[k_xpos + i * x_sign][k_ypos + i * y_sign] == 2){
                printf("[%d, %d]", k_xpos + i * x_sign, k_ypos + i * y_sign);
                break;
            }
            i++;
    }
}

void show_arr(int arr[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[N][N]= {0,0,0,0,0,0,0,0,
                    0,0,2,0,0,0,0,0,
                    2,0,2,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,2,0,0,
                    0,0,0,0,0,0,0,0};
    int k_ypos, k_xpos;
    int x_pos[N] = {-1, 1, 0, 0, -1, 1, 1, -1};
    int y_pos[N] = {0, 0, -1, 1, -1, 1, -1, 1};
    show_arr(arr);

    printf("input king x pos: ");
    scanf("%d", &k_xpos);
    printf("input king y pos: ");
    scanf("%d", &k_ypos);
    arr[k_xpos][k_ypos] = 1;

    printf("king can be attacked by: ");
    for (int i = 0; i < N; i++){
        check(k_xpos, k_ypos, x_pos[i], y_pos[i], arr);
    }

    return 0;
}
