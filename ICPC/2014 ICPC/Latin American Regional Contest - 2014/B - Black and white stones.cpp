#include <bits/stdc++.h>
#define MAX 5005
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll a, b;
int n;
string s;

ll memo[MAX][MAX];

ll dp(int i, int j){
    if(i >= j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(s[j] == 'W'){
        return memo[i][j] = dp(i, j - 1);
    }
    if(s[i] == 'B'){
        return memo[i][j] = dp(i + 1, j);
    }

    //ll res = A + dp(i + 1, j - 1);
    ll res = 0;
    int d = j;
    for(int k = j - 1; k >= i; k--){
        if(s[k] == 'W'){
            res += b * (d - k);
            d--;
        }
    }

    res = min(res, a + dp(i + 1, j - 1));
    return memo[i][j] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> s;
    b = a - b;
    memset(memo, -1, sizeof(memo));

    n = s.length();

    cout << dp(0, n - 1) << "\n";

    return 0;
}
