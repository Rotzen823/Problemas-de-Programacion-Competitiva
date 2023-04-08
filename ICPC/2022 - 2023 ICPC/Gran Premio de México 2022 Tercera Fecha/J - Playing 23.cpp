#include<bits/stdc++.h>
#define MAX 15

using namespace std;

int cartas[MAX];

int main() {
    int n;
    scanf("%d", &n);
    int j1 = 0, j2 = 0, ax;

    scanf("%d", &ax);
    j1 += ax > 10 ? 10 : ax;
    cartas[ax]++;
    scanf("%d", &ax);
    j1 += ax > 10 ? 10 : ax;
    cartas[ax]++;

    scanf("%d", &ax);
    j2 += ax > 10 ? 10 : ax;
    cartas[ax]++;
    scanf("%d", &ax);
    j2 += ax > 10 ? 10 : ax;
    cartas[ax]++;

    while(n--){
        scanf("%d", &ax);
        j1 += ax > 10 ? 10 : ax;
        j2 += ax > 10 ? 10 : ax;
        cartas[ax]++;
    }

    int r = 24 - j1;
    if(r > 10){
        r = 14;
    }

    while(cartas[r] >= 4 && r < 14){
        r++;
    }

    if(r + j2 > 23 && r != 14){
        r = 14;
    }

    int c = 23 - j2;

    if(c == 10){
        bool ban = true;
        for(int k = 10; k <= 13; k++){
            if(cartas[k] < 4){
                c = k;
                ban = false;
                break;
            }
        }
        if(ban){
            c = 14;
        }
    }
    else if(c > 10){
        c = 14;
    }
    else if(cartas[c] >= 4){
        c = 14;
    }
    int res = min(c, r);

    res == 14 ? printf("-1\n") : printf("%d\n", res);
    
    return 0;
}