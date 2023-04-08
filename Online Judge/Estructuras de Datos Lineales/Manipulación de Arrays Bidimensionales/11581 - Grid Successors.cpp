#include <bits/stdc++.h>
#define MAX 5
 
using namespace std;

int mat[MAX][MAX];
int mat2[MAX][MAX];

bool convertir(){
    int D[] = {1, 0, -1, 0};
    int d[] = {0, -1, 0, 1};
    bool ceros = false;

    for(int k = 1; k <= 3; k++){
        for(int j = 1; j <= 3; j++){
            mat2[k][j] = 0;
            for(int i = 0; i < 4; i++){
                mat2[k][j] += mat[k + D[i]][j + d[i]];
            }
            mat2[k][j] %= 2;
            if(mat2[k][j]){
                ceros = true;
            }
        }
    }

    for(int k = 1; k <= 3; k++){
        for(int j = 1; j <= 3; j++){
            mat[k][j] = mat2[k][j];
        }
    }

    return ceros;
}

int main() {
    int n;
    char ax;
    scanf("%d", &n);
    scanf("%c", &ax);

    while(n--){
        int c = 0;
        bool ceros = true;
        for(int k = 1; k <= 3; k++){
            scanf("%c", &ax);
            for(int j = 1; j <= 3; j++){
                scanf("%c", &ax);
                mat[k][j] = ax - '0';
                if(mat[k][j]){
                    ceros = false;
                }
            }
        }
        scanf("%c", &ax);

        if(ceros){
            printf("-1\n");
            continue;
        }

        while(convertir()){
            c++;
        }

        printf("%d\n", c);
    }
    
    return 0;
}