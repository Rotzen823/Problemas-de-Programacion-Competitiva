#include <bits/stdc++.h>
#define MAX 100
 
using namespace std;

char mat1[MAX][MAX];
char mat2[MAX][MAX];

int main() {
    int n, m;

    while(scanf("%d %d", &n, &m), !(n == 0 && m == 0)){
        char ax;
        for(int k = 0; k < n; k++){
            scanf("%c", &ax);
            for(int j = 0; j < n; j++){
                scanf("%c", &mat1[k][j]);
            }
        }

        for(int k = 0; k < m; k++){
            scanf("%c", &ax);
            for(int j = 0; j < m; j++){
                scanf("%c", &mat2[k][j]);
            }
        }

        int res[4] = {0};
        for(int i = 0; i <= (n - m); i++){
            for(int r = 0; r <= (n - m); r++){
                bool bandera[4] = {true, true, true, true};
                for(int k = 0; k < m; k++){
                    for(int j = 0; j < m; j++){
                        if(mat1[i + k][r + j] != mat2[k][j]){
                            bandera[0] = false;
                        }
                        if(mat1[i + k][r + j] != mat2[j][m - k - 1]){
                            bandera[3] = false;
                        }
                        if(mat1[i + k][r + j] != mat2[m - k - 1][m - j - 1]){
                            bandera[2] = false;
                        }
                        if(mat1[i + k][r + j] != mat2[m - j - 1][k]){
                            bandera[1] = false;
                        }
                    }
                }
                for(int k = 0; k < 4; k++){
                    if(bandera[k]){
                        res[k]++;
                    }
                }
            }
        }

        printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);
    }
    
    return 0;
}