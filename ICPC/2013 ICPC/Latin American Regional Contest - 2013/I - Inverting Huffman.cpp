#include <bits/stdc++.h>
#define MAX 55
 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int cont[MAX];
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    int lim = 0;
    for(int k = 0; k < n; k++){
        int x;
        cin >> x;
        cont[x]++;
        lim = max(x, lim);
    }

    ll x = 1;
    ll res = 0;
    priority_queue<ll, vi, greater<ll> > pq;
    while(cont[lim]--){
        pq.push(1);
        res++;
    }

    for(int k = lim - 1; k >= 1; k--){
        priority_queue<ll, vi, greater<ll> > px;
        ll ax = x;
        while(!pq.empty()){
            ll a = pq.top(); pq.pop();
            a += pq.top(); pq.pop();
            x = max(a, x);
            px.push(a);
        }

        while(cont[k]--){ 
            px.push(ax);
            res += ax;
        }

        swap(pq, px);
    }

    cout << res << "\n";
    
    return 0;
}
