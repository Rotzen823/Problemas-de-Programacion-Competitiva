#include<bits/stdc++.h>
#define MAX 1000005

using namespace std;

int alturas[MAX];

int main() {
    int n, ax, c = 0;
    scanf("%d", &n);

    for(int k = 0; k < n; k++){
        scanf("%d", &ax);
        if(alturas[ax + 1]){
            alturas[ax + 1]--;
        }
        else{
            c++;
        }
        alturas[ax]++;
    }
    
    printf("%d\n", c);

    return 0;
}