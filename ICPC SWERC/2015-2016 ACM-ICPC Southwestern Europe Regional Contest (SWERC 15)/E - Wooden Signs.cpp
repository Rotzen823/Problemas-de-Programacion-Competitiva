#include <bits/stdc++.h>
#define MAX 2005
#define MOD 2147483647
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
int woods[MAX];
ll memo[MAX][MAX];

bool dentro(int a, int b, int p){
    if(a > b){
        swap(a, b);
    }
    return p > a && p < b;
}

ll dp(int i, int p){
    if(i >= n){
        return 1;
    }

    if(memo[i][p] != -1){
        return memo[i][p];
    }

    ll res = 0;
    if(dentro(woods[i - 1], p, woods[i])){
        res += dp(i + 1, woods[i - 1]);
        res %= MOD;
        res += dp(i + 1, p);
        res %= MOD;
    }
    else if(woods[i] <= min(woods[i - 1], p)){
        res += dp(i + 1, max(woods[i - 1], p));
        res %= MOD;
    }
    else{
        res += dp(i + 1, min(woods[i - 1], p));
        res %= MOD;
    }
    return memo[i][p] = res;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    memset(memo, -1, sizeof(memo));
    
    int a;
    cin >> a;

    for(int i = 0; i < n; i++){
        cin >> woods[i];
    }

    ll res = dp(1, a);

    cout << res << '\n';
    
    return 0;
}
