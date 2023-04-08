#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, t;

    cin >> n >> t;
    int num[n];

    for(int k = 0; k < n; k++){
        cin >> num[k];
    }

    t %= n;

    printf("%d", num[t]);

    for(int k = t + 1; k < n; k++){
        printf(" %d", num[k]);
    }

    for(int k = 0; k < t; k++){
        printf(" %d", num[k]);
    }

    printf("\n");
 
    return 0;
}