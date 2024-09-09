#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 1000005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef vector <pi> vii;
typedef vector<vi> vvi;

vi food, ingrFood;
vvi factPrimos;

void criba(){
    vector<bool> esPrimo(MAX, true);
    factPrimos.assign(MAX, vi());

    for(int i = 2; i <= MAX; i++){
        for(int j = i; j <= MAX; j += i){
            if(esPrimo[i]){
                factPrimos[j].pb(i);
            }
            
            ingrFood[i] += food[j];
            if(i != j){
                esPrimo[j] = false;
            }
        }
    }
}

vi fPrim;
int t;

int comb(int num, int i, int s){
    int ans = ingrFood[num] * s;

    if(i == t){
        return ans;
    }

    for(int j = i; j < t; j++){
        ans += comb(num * fPrim[j], j + 1, -s);
    }


    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    food.assign(MAX, 0);
    ingrFood.assign(MAX, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        food[x]++;
    }

    vector<ll> ans(n + 1, 0);
    ans[0] = 1;

    for(int i = 1; i <= n; i++){
        ans[i] = (ans[i - 1] * 2LL) % MOD;
    }

    criba();

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;

        if(x == 1){
            cout << ans[n] << ENDL;
            continue;
        }

        fPrim = factPrimos[x];
        t = SZ(fPrim);

        int pot2 = n - comb(1, 0, -1);

        cout << ans[pot2] << ENDL;
    }

    return 0;
}
