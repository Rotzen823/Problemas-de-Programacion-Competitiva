#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;

    while(scanf("%d", &n) != EOF){
        int v = 1 << n;

        int vert[v];
        int potV[v];
        int sum[v];
        for(int k = 0; k < v; k++){
            scanf("%d", &vert[k]);
            potV[k] = 0;
        }

        for(int k = 0; k < v; k++){
            //printf("%d", k);
            for(int j = 0; j < n; j++){
                int x;
                if(k & (1 << j)){
                    x = k & (~(1 << j));
                }
                else{
                    x = k | (1 << j);
                }
                potV[k] += vert[x];
                //printf(" %d", x);
            }
            //printf(" P:%d\n", potV[k]);
        }

        int res = 0;

        for(int k = 0; k < v; k++){
            for(int j = 0; j < n; j++){
                int x;
                if(k & (1 << j)){
                    x = k & ~(1 << j);
                }
                else{
                    x = k | (1 << j);
                }
                res = max(res, potV[k] + potV[x]);
            }
        }

        printf("%d\n", res);

    }
    
    return 0;
}