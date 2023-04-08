#include<bits/stdc++.h>
#define MAX 105

using namespace std;

char mat[MAX][MAX], matRes[MAX][MAX];
int n, m;

bool validar(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return false;
    }

    return true;
}

void cambio(){
    for(int k = 0; k < n; k++){
        for(int j = 0; j < m; j++){
            mat[k][j] = matRes[k][j];
        }
        
    }
}

void check(int x, int y){
    int D[] = {1, 0, -1, 0};
    int d[] = {0, -1, 0, 1};

    char enemy;
    switch(mat[x][y]){
        case 'R':
        enemy = 'P';
        break;
        case 'S':
        enemy = 'R';
        break;
        case 'P':
        enemy = 'S';
        break;
    }

    for(int k = 0; k < 4; k++){
        int i = x + D[k], j = y + d[k];
        if(!validar(i, j)){
            continue;
        }

        if(mat[i][j] == enemy){
            matRes[x][y] = enemy;
            return;
        }
    }

    matRes[x][y] = mat[x][y];
}
 
int main() {
    int t;
    scanf("%d", &t);

    while(t--){
        int d;
        char ax;
        scanf("%d %d %d", &n, &m, &d);

        for(int k = 0; k < n; k++){
            scanf("%c", &ax);
            for(int j = 0; j < m; j++){
                scanf("%c", &mat[k][j]);
            }
        }

        while(d--){
            for(int k = 0; k < n; k++){
                for(int j = 0; j < m; j++){
                    check(k, j);
                }
            }

            cambio();
        }

        for(int k = 0; k < n; k++){
            for(int j = 0; j < m; j++){
                printf("%c", mat[k][j]);
            }
            printf("\n");
        }

        if(t != 0){
            printf("\n");
        }
    }

    return 0;
}