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
 
int memoN[MAX][MAX];
int memo[16777216];
 
int next(int A, int i){
    if(i >= n){
        return INF;
    }
 
    if(v[i] == A){
        return i;
    }
 
    if(memoN[A][i] != -1){
        return memoN[A][i];
    }
 
    return memoN[A][i] = next(A, i + 1);
}
 
int dp(int mask){
    if(mask == 0){
        return -1;
    }
 
    if(memo[mask] != -1){
        return memo[mask];
    }
    
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(mask & (1 << i)){
            int ax = dp(mask & ~(1 << i));
            //cout << mask << " " << i + 1 << " " << ax + 1 << " ";
            //cout << next(i, ax + 1) << "\n";
            ans = max(ans, next(i, ax + 1));
        }
    }
 
    //cout << mask << ": " << ans << "\n";
    return memo[mask] = ans;
}
 
void busq(int mask){
    if(mask == 0){
        return;
    }
 
    int j = -1;
    for(int i = 0; i < k; i++){
        if(mask & (1 << i)){
            int ax = dp(mask & ~(1 << i));
            if(dp(mask) == next(i, ax + 1)){
                j = i;
                break;
            }
        }
    }
    
    busq(mask & ~(1 << j));
    res.push_back(j);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    memset(memoN, -1, sizeof(memoN));
    memset(memo, -1, sizeof(memo));
 
    v.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }
 
    /*for(int A = 0; A < k; A++){
        for(int i = 0; i < n; i++){
            cout << next(A, i) << " ";
        }
        cout << "\n";
    }*/
 
    if(k >= 21){
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
        int ans = dp((1 << k) - 1);
        if(ans != INF){
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
