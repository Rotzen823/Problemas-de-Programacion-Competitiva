//Pura gente del coach moy
#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 10000000000
#define ENDL '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;


    int b[n], nOne[n];
    ll dp[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int lastOne = n;
    ll res = 0;
    for(int i = n - 1; i >= 0; i--){
        nOne[i] = lastOne;
        if(b[i] == 1){
            dp[i] = lastOne - i;
            if(lastOne < n && nOne[lastOne] < n){
                dp[i] += dp[nOne[lastOne]];
            }
            lastOne = i;
        }
        else{
            dp[i] = 0;
            if(lastOne < n){
                dp[i] = dp[lastOne];
            }
        }

        res += dp[i];
    }

    cout << res << ENDL;

    return 0;
}
