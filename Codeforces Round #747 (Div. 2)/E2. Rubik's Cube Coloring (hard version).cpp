#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 600005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int color[6][4] = {{2, 3, 4, 5}, {2, 3, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5}, {0, 1, 2, 3}, {0, 1, 2, 3}};

int c[MAX];
vector<vi> adj;
ll memo[MAX][6];

ll modpow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;

    ll u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n % 2 == 1){
        u = (u * x) % m;
    }

    return u;
}

ll dp(int i, int j){
    //cout << i << " " << j << "\n";
    if(c[i] != -1 && c[i] != j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    ll sum[2] = {0};
    for(int k = 0; k < (int) adj[i].size(); k++){
        for(int x = 0; x < 4; x++){
            sum[k] += dp(adj[i][k], color[j][x]);
            sum[k] %= MOD;
        }
    }

    if(adj[i].empty()){
        sum[0] = sum[1] = 1;
    }
    else if(adj[i].size() == 1){
        sum[1] = 1;
    }

    ll res = (sum[0] * sum[1]) % MOD;
    return memo[i][j] = res;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<string, int> mp;
    map<ll, int> label;
    memset(memo, -1, sizeof(memo));
    memset(c, -1, sizeof(c));
    mp["white"] = 0;
    mp["yellow"] = 1;
    mp["green"] = 2;
    mp["blue"] = 3;
    mp["orange"] = 4;
    mp["red"] = 5;
    ll k;
    int n;
	cin >> k >> n;
	ll pot = (1LL << k) - 1;
    
    int id = 0;
    map<ll, int> ar;
    while(n--){
        ll x;
        string s;
        cin >> x >> s;

        ar[x] = mp[s];
        while(x >= 1 && !label.count(x)){
            label[x] = id++;
            pot--;
            x /= 2;
        }
    }

    adj.assign(id, vi());
    for(auto ax : label){
        ll x = ax.first; int lab = ax.second;
        if(ar.count(x)){
            c[lab] = ar[x];
        }

        if(label.count(x * 2)){
            adj[lab].push_back(label[x * 2]);
        }
        if(label.count((x * 2) + 1)){
            adj[lab].push_back(label[(x * 2) + 1]);
        }
    }

    ll res = modpow(4, pot, MOD);
    ll sum = 0;
    //cout << "Entra dp\n";
    for(int k = 0; k < 6; k++){
        sum += dp(label[1], k);
        sum %= MOD;
    }

    res *= sum;
    res %= MOD;

    cout << res << "\n";
    return 0;
}
