#include <bits/stdc++.h>
#define MAX 305
#define INF 300
 
using namespace std;
 
typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int n, k;
vi v, res;
 
int nxt[MAX][MAX];
int memo[1 << 24];
 
void next(){
    for(int i = 0; i < MAX;  i++){
        for(int j = 0; j < MAX; j++){
            nxt[i][j] = INF;
        }
    }

    for(int A = 0; A < k; A++){
        int ax = INF;
        for(int i = n - 1; i >= 0; i--){
            if(v[i] == A){
                ax = i;
            }
            nxt[A][i] = ax;
        }
    }
}
 
bool dp(){
    int res = -1;
    for(int mask = 1; mask < (1 << k); mask++){
        for(int i = 0; i < k; i++){
            if(mask & (1 << i)){
                int ax = memo[mask & ~(1 << i)];
                memo[mask] = max(memo[mask], nxt[i][ax + 1]);
            }
        }
        
        if(memo[mask] == INF){
            res = mask;
            break;
        }
    }

    if(res == -1){
        return false;
    }

    for(int i = 0; i < k; i++){
        if(!(res & (1 << i))){
            res |= (1 << i);
            memo[res] = INF;
        }
    }

    return true;
}
 
void busq(int mask){
    if(mask == 0){
        return;
    }
 
    int j = -1;
    for(int i = k - 1; i >= 0; i--){
        if(mask & (1 << i)){
            int ax = memo[mask & ~(1 << i)];
            if(memo[mask] == nxt[i][ax + 1]){
                j = i;
                break;
            }
        }
    }

    if(j == -1){
        return;
    }
    
    busq(mask & ~(1 << j));
    res.push_back(j);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
 
    v.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }
 
    if(k >= 25){
        vector<bool> flags;
        int st = 0;
 
        while(st < n){
            flags.assign(k, false);
            for(int p : res){
                flags[p] = true;
            }
 
            for(int i = st; i < n; i++){
                if(!flags[v[i]]){
                    flags[v[i]] = true;
                    st = i;
                }
            }
 
            bool next = false;
            for(int i = 0; i < k; i++){
                if(!flags[i]){
                    next = true;
                    res.push_back(i);
                    break;
                }
            }
 
            if(next){
                break;
            }
 
            res.push_back(v[st]);
            st++;
        }
 
        flags.assign(k, false);
        for(int p : res){
            flags[p] = true;
        }
 
        for(int i = 0; i < k; i++){
            if(!flags[i]){
                res.push_back(i);
            }
        }
    }
    else{
        next();
        if(!dp()){
            cout << "*\n";
            return 0;
        }
 
        busq((1 << k) - 1);
    }
 
    cout << res[0] + 1;
    for(int i = 1; i < (int) res.size(); i++){
        cout << ' ' << res[i] + 1;
    }
    cout << "\n";
    
    return 0;
}
