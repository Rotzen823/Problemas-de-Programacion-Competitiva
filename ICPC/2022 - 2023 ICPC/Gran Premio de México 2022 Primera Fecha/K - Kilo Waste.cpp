#include <bits/stdc++.h>
#define MAX 100005
#define MAXp 55
#define INF 1000000

using namespace std;

int resid[MAX], n, p;
int pres[MAXp];

int residuo(int x){
    if(x < 0){
        return -x;
    }

    if(x == 0){
        return 0;
    }

    if(resid[x] != -1){
        return resid[x];
    }

    int r = INF;

    for(int k = 0; k < p; k++){
        r = min(r, residuo(x - pres[k]));
    }

    return resid[x] = r;
}


int main(){	
    int x;
    scanf("%d %d", &n, &p);

    memset(resid, -1, sizeof(resid));

    for(int k = 0; k < p; k++){
        scanf("%d", &pres[k]);
    }


    while(n--){
        scanf("%d", &x);

        printf("%d\n", residuo(x));
    }

	return 0;
}