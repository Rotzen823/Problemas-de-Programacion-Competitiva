#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;

    while(scanf("%d %d", &a, &b), !(a == 0 && b == 0)){
        int res = 0;
        if(a == 1 || b == 1){
            res = max(a, b);
        }
        else if(a == 2 || b == 2){
            int x = max(a, b);
            if(x % 4 == 1 || x % 4 == 3){
                x++;
            }
            else if(x % 4 == 2){
                x += 2;
            }
            res = x;
        }
        else{
            res = a * b;
            if(res & 1){
                res++;
            }
            res >>= 1;
        }

        printf("%d knights may be placed on a %d row %d column board.\n", res, a, b);
    }

    return 0;
}