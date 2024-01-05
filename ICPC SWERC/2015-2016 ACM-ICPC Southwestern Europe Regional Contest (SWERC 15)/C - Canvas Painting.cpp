#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue<ll, vi, greater<ll> > pq;
        while(n--){
            ll x;
            cin >> x;
            pq.push(x);
        }

        ll res = 0;
        while(pq.size() > 1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();

            res += (a + b);
            pq.push(a + b);
        }

        cout << res << "\n";
    }
    
    return 0;
}
