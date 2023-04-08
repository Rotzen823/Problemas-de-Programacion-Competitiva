#include<bits/stdc++.h>
#define MAX 1000005
#define MAXT 105

using namespace std;

int players[MAX];
int tablero[MAXT];
 
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for(int k = 0; k < a; k++){
            players[k] = 1;
        }

        for(int k = 1; k <= 100; k++){
            tablero[k] = k;
        }
        
        while(b--){
            int x, y;
            scanf("%d %d", &x, &y);
            tablero[x] = y;
        }
        
        bool finished = false;
        for(int k = 0; k < c; k++){
            int x, res;
            scanf("%d", &x);
            if(finished){
                continue;
            }
            res = players[k % a] + x;
            res = min(res, 100);

            res = tablero[res];
            players[k % a] = res;

            if(res == 100){
                finished = true;
            }
        }
        
        for(int k = 0; k < a; k++){
            printf("Position of player %d is %d.\n", k + 1, players[k]);
        }
    }

    return 0;
}