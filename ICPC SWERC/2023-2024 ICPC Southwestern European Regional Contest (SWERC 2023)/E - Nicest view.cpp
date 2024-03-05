#include<bits/stdc++.h>
#define INF 1000000
#define ENDL '\n';

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

vi num, izq, der;

void histograma(int n){
    izq.assign(n, 0); der.assign(n, 0);
    stack<int> pila;

    for(int k = 0; k < n; k++){
        while(!pila.empty() && num[pila.top()] < num[k]){
            pila.pop();
        }

        if(!pila.empty()){
            izq[k] = pila.top();
        }
        else{
            izq[k] = -1;
        }

        pila.push(k);
    }

    while(!pila.empty()){
        pila.pop();
    }

    for(int k = n - 1; k >= 0; k--){
        while(!pila.empty() && num[pila.top()] < num[k]){
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    num.assign(n, 0);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    histograma(n);

    double maxD = 0;
    ii res(0, 1);
    for(int i = 0; i < n; i++){
        //cout << izq[i] << ' ' << der[i] << '\n';
        if(izq[i] != -1 && izq[i] + 1 < i){
            ll b = num[izq[i]] - num[izq[i] + 1];
            ll a = num[i] - num[izq[i] + 1];
            ll d = i - izq[i] - 1;
            double dk = (double) d + ((double) a / (double) b);
            if(dk > maxD){
                maxD = dk;
                res = ii(d * b + a, b);
            }
        }
        if(der[i] != n && der[i] - 1 > i){
            ll b = num[der[i]] - num[der[i] - 1];
            ll a = num[i] - num[der[i] - 1];
            ll d = der[i] - i - 1;
            double dk = (double) d + (double) a / (double) b;
            if(dk > maxD){
                maxD = dk;
                res = ii(d * b + a, b);
            }
        }
    }

    ll gcd = __gcd(res.first, res.second);
    res.first /= gcd;
    res.second /= gcd;

    if(maxD == 0){
        cout << "0\n";
    }
    else{
        ll gcd = __gcd(res.first, res.second);
        res.first /= gcd;
        res.second /= gcd;
        cout << res.first << "/" << res.second << "\n";
    }
    
    return 0;
}
