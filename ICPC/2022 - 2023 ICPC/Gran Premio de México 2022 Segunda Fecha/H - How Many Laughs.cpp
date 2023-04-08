#include<bits/stdc++.h>
#define MAX 25

using namespace std;

typedef long long ll;

ll num[MAX];
int s = 0;
ll cop[MAX];

ll comb(ll x, int k, ll sig){
    if(k == s){
        return 0;
    }

    ll res = 0;
    for(int i = k; i < s; i++){
        res += (sig * (x / cop[i]));
        res += comb(x / cop[i], i + 1, -sig);
    }

    return res;
}

int main(){
    int n;
    ll x;

    scanf("%d %lld", &n, &x);

    for(int k = 0; k < n; k++){
        scanf("%lld", &num[k]);
    }

    sort(num, num + n);

    for(int k = 0; k < n; k++){
        if(num[k] != -1){
            cop[s] = num[k];
            s++;
            for(int j = k + 1; j < n; j++){
                if(num[j] % num[k] == 0){
                    num[j] = -1;
                }
            }
        }
    }

    ll res = comb(x, 0, 1);
    printf("%lld\n", res);

	return 0;
}