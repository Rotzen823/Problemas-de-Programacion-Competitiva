#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll mcdExt(ll a, ll b){
    ll r,y=0,x1=0,y1=1,tx,ty;
    ll x=1;
    while(b>0){
        r=a%b;
        tx=x1, ty=y1;
        x1=x-(a/b)*x1;
        x=tx;
        //Continuación en la siguiente página
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
	
    int n, k;
    cin >> n >> k;

    ll arr[n + 1];
    map<ll, ll> contar;

    ll P = 1;
    ll Q = 1;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        contar[arr[i]]++;
        P = (P * contar[arr[i]]) % MOD;
        Q = (Q * i) % MOD;
    }

    cout << inv_mod(P, Q) << "\n";

    while(k--){
        int i;
        ll a;
        cin >> i >> a;

        P = inv_mod(P, contar[arr[i]]);
        contar[arr[i]]--;
        arr[i] = a;
        contar[arr[i]]++;
        P = (P * contar[arr[i]]) % MOD;

        cout << inv_mod(P, Q) << "\n";
    }

	return 0;
}
