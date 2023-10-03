#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int num[MAX], der[MAX], id[MAX];
ll cont[MAX];

void histograma(int n){
    stack<int> pila;

    for(int k = n - 1; k >= 0; k--){
        cont[k] = 1;
        while(!pila.empty() && num[pila.top()] >= num[k]){
            if(num[k] == num[pila.top()]){
                cont[k] += cont[pila.top()];
            }
            pila.pop();
        }

        if(!pila.empty()){
            der[k] = pila.top();
        }
        else{
            der[k] = n;
        }

        pila.push(k);
    }
}

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

ll nCk(ll n, ll k){
    ll num = n, den = k;
    while(--k){
        n--;
        num = (num * n) % MOD;
        den = (den * k) % MOD;
    }

    return inv_mod(num, den);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int k = 0; k < n; k++){
        cin >> num[k];
    }

    histograma(n);

    ll res = 1;
    for(int k = 0; k < n; k++){
        if(k >= id[num[k]]){
            //cout << k << " " << num[k] << " " << cont[k] << "\n";
            if(cont[k] > 1){
                ll a = nCk(2 * cont[k], cont[k]);
                ll b = nCk(2 * cont[k], cont[k] - 1);
                ll c = (a - b + MOD) % MOD;
                res *= c; res %= MOD;
            }
            id[num[k]] = der[k];
        }
    }

    cout << res << "\n";
    return 0;
}
