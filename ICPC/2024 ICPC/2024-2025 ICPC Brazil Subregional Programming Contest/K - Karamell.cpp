#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007

using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int n;
vi bags;
vi aliceBags;
bool memo[105][10005];

int dp(int i, int sum){
    if(sum == 0){
        return true;
    }

    if(i == n || sum < 0){
        return false;
    }

    if(memo[i][sum]){
        return false;
    }

    memo[i][sum] = true;
    if(dp(i + 1, sum - bags[i])){
        aliceBags.pb(i);
        return true;
    }

    return dp(i + 1, sum);
}

signed main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(nullptr);

	cin >> n;
    bags.assign(n, 0);

    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> bags[i];
        sum += bags[i];
    }

    if(sum % 2 == 1 || !dp(0, sum / 2)){
        cout << "-1\n";
        return 0;
    }

    sort(ALL(aliceBags));
    vi bobBags;

    int j = 0;
    for(int i = 0; i < SZ(aliceBags); i++){
        //cout << "A: " << aliceBags[i] << ENDL;
        while(j < aliceBags[i]){
            bobBags.pb(j);
            //cout << "B: " << j << ENDL;
            j++;
        } 
        j++;
    }

    while(j < n){
        bobBags.pb(j);
        j++;
    }


    int alice = 0, bob = 0;
    vi ans;
    for(int i = 0, j = 0; (i + j) < n; ){
        if(alice <= bob){
            ans.pb(bags[aliceBags[j]]);
            alice += bags[aliceBags[j]];
            j++;
        }
        else{
            ans.pb(bags[bobBags[i]]);
            bob += bags[bobBags[i]];
            i++;
        }
    }

    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout << " " << ans[i];
    }
    cout << ENDL;

 	return 0;
}
