#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long ll;

pair<ll, ll> cartas[MAX];
map<ll, ll> dentro, fuera;

void borrarDentro(ll x){
    if(dentro[x] > 1){
        dentro[x]--;
    }
    else{
        dentro.erase(x);
    }
}

void borrarFuera(ll x){
    if(fuera[x] > 1){
        fuera[x]--;
    }
    else{
        fuera.erase(x);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int k = 0; k < n; k++){
        scanf("%lld", &cartas[k].first);
    }

    for(int k = 0; k < n; k++){
        scanf("%lld", &cartas[k].second);
    }

    int p, l;
    ll res = 0, maxRes = 0;

    scanf("%d %d", &p, &l);

    priority_queue<ll> cola;

    for(int k = 0; k < p; k++){
        maxRes += cartas[k].first;
        cola.push(cartas[k].second);
    }

    for(int k = 0; k < l; k++){
        dentro[cola.top()]++;
        maxRes += cola.top();
        cola.pop();
    }

    while(!cola.empty()){
        fuera[cola.top()]++;
        cola.pop();
    }

    res = maxRes;
    for(int k = p - 1, j = n - 1; k >= 0; k--, j--){
        res -= cartas[k].first;
        res += cartas[j].first;
        if(dentro.count(cartas[k].second)){
            res -= cartas[k].second;
            borrarDentro(cartas[k].second);
            ll maximo;
            if(fuera.empty()){
                maximo = 0;
            }
            else{
                maximo = fuera.rbegin()->first;
            }

            if(maximo > cartas[j].second){
                res += maximo;
                dentro[maximo]++;
                borrarFuera(maximo);
                fuera[cartas[j].second]++;
            }
            else{
                res += cartas[j].second;
                dentro[cartas[j].second]++;
            }
        }
        else{
            borrarFuera(cartas[k].second);
            ll maximo = dentro.begin()->first;
            if(cartas[j].second > maximo){
                borrarDentro(maximo);
                res -= maximo;
                fuera[maximo]++;

                dentro[cartas[j].second]++;
                res += cartas[j].second;
            }
            else{
                fuera[cartas[j].second]++;
            }
        }
        
        maxRes = max(maxRes, res);
    }

    printf("%lld\n", maxRes);
    return 0;
}