#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long ll;

ll num[MAX];
ll sum[MAX];
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int k = 0; k < n; k++){
        scanf("%lld", &num[k]);
    }

    sort(num, num + n);

    sum[0] = num[0];
    for(int k = 1; k < n; k++){
        sum[k] = num[k] + sum[k - 1];
    }

    while(m--){
        ll x;
        scanf("%lld", &x);

        int p = lower_bound(num, num + n, x) - num;
        ll res = (n - p) * x;
        if(p > 0){
            res += sum[p - 1];
        }
        printf("%lld\n", res);
    }

    return 0;
}