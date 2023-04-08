#include <bits/stdc++.h>
#define MAX 10

using namespace std;

bool tab[MAX][MAX];
char TAB[MAX][MAX];

bool validar(int x, int y){
    if(x < 0 || x >= 8 || y < 0 || y >= 8){
        return false;
    }
    return true;
}

void peonB(int x, int y){
    if(validar(x - 1, y - 1)){
        tab[x - 1][y - 1] = true;
    }

    if(validar(x - 1, y + 1)){
        tab[x - 1][y + 1] = true;
    }
    tab[x][y] = true;
}

void peonN(int x, int y){
    if(validar(x + 1, y - 1)){
        tab[x + 1][y - 1] = true;
    }

    if(validar(x + 1, y + 1)){
        tab[x + 1][y + 1] = true;
    }
    tab[x][y] = true;
}

void rey(int x, int y){
    if(validar(x + 1, y)){
        tab[x + 1][y] = true;
    }
    if(validar(x + 1, y + 1)){
        tab[x + 1][y + 1] = true;
    }
    if(validar(x + 1, y - 1)){
        tab[x + 1][y - 1] = true;
    }
    if(validar(x, y + 1)){
        tab[x][y + 1] = true;
    }
    if(validar(x, y - 1)){
        tab[x][y - 1] = true;
    }
    if(validar(x - 1, y)){
        tab[x - 1][y] = true;
    }
    if(validar(x - 1, y + 1)){
        tab[x - 1][y + 1] = true;
    }
    if(validar(x - 1, y - 1)){
        tab[x - 1][y - 1] = true;
    }
    
    tab[x][y] = true;
}

void torre(int x, int y){
    int a = x + 1, b = y;

    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a++;
    }

    a = x - 1, b = y;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a--;
    }

    a = x, b = y + 1;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        b++;
    }

    a = x, b = y - 1;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        b--;
    }

    tab[x][y] = true;
}

void alfil(int x, int y){
    int a = x + 1, b = y - 1;

    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a++;
        b--;
    }

    a = x - 1, b = y - 1;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a--;
        b--;
    }

    a = x + 1, b = y + 1;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a++;
        b++;
    }

    a = x - 1, b = y + 1;
    while(validar(a, b)){
        if(TAB[a][b] != '.'){
            break;
        }
        tab[a][b] = true;
        a--;
        b++;
    }
    tab[x][y] = true;
}

void caballo(int x, int y){
    int D[] = {1, -1, 2, -2};
    int d[] = {-2, 2, -1, 1};

    for(int k = 0; k < 4; k++){
        if(validar(x + D[k], y + d[k])){
            tab[x + D[k]][y + d[k]] = true;
        }

        if(validar(x + D[k], y - d[k])){
            tab[x + D[k]][y - d[k]] = true;
        }
    }
    tab[x][y] = true;
}

/*void mostrar(){
    for(int k = 0; k < 8; k++){
        for(int j = 0; j < 8; j++){
            printf("%d", tab[k][j]);
        }
        printf("\n");
    }
    printf("\n");
}*/


int main(){
    string op = "";

    while(cin >> op){
        for(int k = 0; k < 8; k++){
            for(int j = 0; j < 8; j++){
                tab[k][j] = false;
                TAB[k][j] = '.';
            }
        }

        char sal;
        scanf("%c", &sal);

        int x = 0, y = 0;
        for(char ax : op){
            //printf("%c %d %d\n", ax, x, y);
            if(ax == '/'){
                x++;
                y = 0;
            }
            else if(ax >= '1' && ax <= '9'){
                y += (ax - '0');
            }
            else{
                TAB[x][y] = ax;
                y++;
            }
        }

        for(x = 0; x < 8; x++){
            for(y = 0; y < 8; y++){
                switch(TAB[x][y]){
                    case 'K':
                    case 'k':
                    rey(x, y);
                    break;
                    case 'R':
                    case 'r':
                    torre(x, y);
                    break;
                    case 'B':
                    case 'b':
                    alfil(x, y);
                    break;
                    case 'N':
                    case 'n':
                    caballo(x, y);
                    break;
                    case 'Q':
                    case 'q':
                    torre(x, y);
                    alfil(x, y);
                    break;
                    case 'P':
                    peonB(x, y);
                    break;
                    case 'p':
                    peonN(x, y);
                    break;
                }
                /*if(TAB[x][y] != '.'){
                    printf("%c %d %d\n", TAB[x][y], x, y);
                    mostrar();
                }*/
            }
        }

        int res = 0;
        for(int k = 0; k < 8; k++){
            for(int j = 0; j < 8; j++){
                if(!tab[k][j]){
                    res++;
                }
            }
        }

        printf("%d\n", res);
    }

    return 0;
}