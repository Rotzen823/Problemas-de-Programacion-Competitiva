#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    iii tareas[n], ax[n];
    for(int k = 0; k < n; k++){
        ll a, b;
        cin >> a >> b;
        tareas[k] = iii(ii(b, a), k);
    }

    sort(tareas, tareas + n);

    ll sum = 0;
    for(int k = 0; k < n; k++){
        sum += tareas[k].first.second;
        if(sum > tareas[k].first.first){
            cout << "*\n";
            return 0;
        }
    }

    vi res(n);
    sum = 0;
    vector<bool> ready(n);
    for(int k = 0; k < n; k++){
        ll sum2 = sum, maxS = 1e9 + 1;
        int i = -1;
        for(int j = 0; j < n; j++){
            if(ready[j]){
                continue;
            }

            if(maxS >= tareas[j].first.second && (i == -1 || tareas[j].second < tareas[i].second)){
                i = j;
            }

            sum2 += tareas[j].first.second;
            maxS = min(maxS, tareas[j].first.first - sum2);
        }

        res[k] = tareas[i].second + 1;
        ready[i] = true;
        sum += tareas[i].first.second;
    }

    cout << res[0];
    for(int k = 1; k < n; k++){
        cout << " " << res[k];
    }
    cout << "\n";    
 
    return 0;
}
