#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll memo[MAX][3];
string ax;
int n;

ll dp(int p, int r){
    if(p >= n){
        if(r == 0){
            return 1;
        }
        return 0;
    }

    if(ax[p] < '0' || ax[p] > '9'){
        if(r == 0){
            return 1;
        }
        return 0;
    }

    if(memo[p][r] != -1){
        return memo[p][r];
    }

    ll res = 0;
    if(!r){
        res++;
    }

    res += dp(p + 1, (r + (ax[p] - '0')) % 3);

    return memo[p][r] = res;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(memo, -1, sizeof(memo));
    cin >> ax;

    n = ax.length();
    ll res = 0;
    for(int k = 0; k < n; k++){
        res += dp(k, 0) - 1;
    }

    cout << res << "\n";   
    return 0;
}
