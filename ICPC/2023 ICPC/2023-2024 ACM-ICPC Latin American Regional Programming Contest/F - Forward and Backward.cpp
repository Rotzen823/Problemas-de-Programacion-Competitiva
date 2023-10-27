#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
ll ax[100];
 
bool base(ll n, ll b){
    int lim = 0;
    while(n > 0){
        ax[lim++] = n % b;
        n /= b;
    }
 
    for(int k = 0, j = lim - 1; k < j; k++, j--){
        if(ax[k] != ax[j]){
            return false;
        }
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
    if(n == 2){
        cout << "*\n";
        return 0;
    }
 
    vi res;
    for(ll k = 2; (k * k) <= (n - 1); k++){
        if(n % k == 0){
            continue;
        }
        if(base(n, k)){
            res.push_back(k);
        }
    }
 
    ll lim = (ll) sqrt(n + 1);
    for(ll d = lim - 1; d >= 1; d--){
        if(n % d == 0){
            res.push_back((n / d) - 1);
        }
    }
 
    cout << res[0];
    for(int k = 1; k < (int) res.size(); k++){
        cout << " " << res[k];
    }
    cout << "\n";
    
    return 0;
}
