#include<bits/stdc++.h>

using namespace std;
 
int main() {
    int n, res;
    scanf("%d", &n);

    res = 3000 / n;
    if(3000 % n){
        res++;
    }

    res = min(res, 15);

    printf("%d\n", res);

    return 0;
}