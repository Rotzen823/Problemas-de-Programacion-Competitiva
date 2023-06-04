#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll mcdExt(ll a, ll b){
    ll r,y=0,x1=0,y1=1,tx,ty;
    ll x=1;
    while(b>0){
        r=a%b;
        tx=x1, ty=y1;
        x1=x-(a/b)*x1;
        x=tx;
        y1=y-(a/b)*y1;
        y=ty;
        a=b;
        b=r;
    }
    return x;
}

ll inv_mod(ll a, ll b){
    ll x = mcdExt(b, MOD);
    x=(x + MOD) % MOD;
    return (a * x) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int n, q;
    cin >> n >> q;

    ll sum[n + 1];
    ll sumq[n + 1];
    sum[0] = sumq[0] = 0;
    for(int k = 1; k <= n; k++){
        ll x;
        cin >> x;
        sum[k] = (x + sum[k - 1]) % MOD;

        x = (x * x) % MOD;
        sumq[k] = (x + sumq[k - 1]) % MOD;
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        ll res = (sum[b] - sum[a - 1] + MOD) % MOD;
        res = (res * res) % MOD;

        ll sumQ = (sumq[b] - sumq[a - 1] + MOD) % MOD;
        res = (res - sumQ + MOD) % MOD;
        res = inv_mod(res, 2);

        cout << res << "\n";
    }

	return 0;
}
