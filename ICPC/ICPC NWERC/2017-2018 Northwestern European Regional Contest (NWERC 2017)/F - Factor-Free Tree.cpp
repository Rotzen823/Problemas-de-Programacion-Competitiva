#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 10000000000000
#define MOD 998244353
#define MAX 100005

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N;
vi spf;
void sieve(){
    spf.resize(N + 1);
    for(int i = 1; i <= N; i++){
        spf[i] = i;
    }
    for(int i = 2; (i * i) <= N; i++){
        if(spf[i] != i){
            continue;
        }
        for(int j = (i * i); j <= N; j += i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}

vi izq, der;
void calcIzqDer(vi &a){
    sieve();
    vi ids(N + 1, -1);
    int n = sz(a);
    izq.assign(n, -1); der.assign(n, n);

    for(int i = 0; i < n; i++){
        int x = a[i];
        while(x > 1){
            izq[i] = max(izq[i], ids[spf[x]]);
            ids[spf[x]] = i;
            
            int ax = x;
            while(ax % spf[x] == 0){
                ax /= spf[x];
            }
            x = ax;
        }
    }

    ids.assign(N + 1, n);
    for(int i = n - 1; i >= 0; i--){
        int x = a[i];
        
        while(x > 1){
            der[i] = min(der[i], ids[spf[x]]);
            ids[spf[x]] = i;
            
            int ax = x;
            while(ax % spf[x] == 0){
                ax /= spf[x];
            }
            x = ax;
        }
    }
}

bool canBeRoot(int i, int l, int r){
    return (izq[i] < l && der[i] > r);
}

vi ans;
bool solve(int l, int r, int p){
    if(l > r){
        return true;
    }

    for(int i = l, j = r; i <= j; i++, j--){
        if(canBeRoot(i, l, r)){
            ans[i] = p;
            return solve(l, i - 1, i + 1) && solve(i + 1, r, i + 1);
        }
        if(canBeRoot(j, l, r)){
            ans[j] = p;
            return solve(l, j - 1, j + 1) && solve(j + 1, r, j + 1);
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        N = max(N, a[i]);
    }

    calcIzqDer(a);

    ans.resize(n);
    if(solve(0, n - 1, 0)){
        cout << ans[0];
        for(int i = 1; i < n; i++){
            cout << ' ' << ans[i];
        }
        cout << ENDL;
    }
    else{
        cout << "impossible\n";
    }

    return 0;
}
