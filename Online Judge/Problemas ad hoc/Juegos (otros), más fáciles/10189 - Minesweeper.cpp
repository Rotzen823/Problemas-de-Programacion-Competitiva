#include<bits/stdc++.h>
#define MAX 105

using namespace std;

int mat[MAX][MAX];
int n, m;

bool validar(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return false;
    }

    return true;
}

void bomba(int x, int y){
    int D[] = {1, 1, 1, -1, -1, -1, 0, 0};
    int d[] = {1, -1, 0, 1, -1, 0, 1, -1};

    for(int k = 0; k < 8; k++){
        if(validar(x + D[k], y + d[k])){
            if(mat[x + D[k]][y + d[k]] != -1){
                mat[x + D[k]][y + d[k]]++;
            }
        }
    }
}
 
int main() {
    char ax;
    int c = 1;

    while(scanf("%d %d", &n, &m), !(n == 0 && m == 0)){
        if(c != 1){
            printf("\n");
        }

        for(int k = 0; k < n; k++){
            scanf("%c", &ax);
            for(int j = 0; j < m; j++){
                scanf("%c", &ax);
                if(ax == '*'){
                    mat[k][j] = -1;
                }
                else{
                    mat[k][j] = 0;
                }
            }
        }

        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                if(mat[k][j] == -1){
                    bomba(k, j);
                }
            }
        }

        printf("Field #%d:\n", c);
        c++;

        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                if(mat[k][j] == -1){
                    printf("*");
                }
                else{
                    printf("%d", mat[k][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}