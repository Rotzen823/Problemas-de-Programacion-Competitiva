// Pura Gente del Coach Moy
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
#define INF 1000000000
#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vi goodSet(1 << 21);
    ii dominos[] = {{0, 0}, {1, 0}, {1, 1}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 1}, {3, 2}, {3, 3},
                    {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, 
                    {5, 4}, {5, 5}};

    for(int mask = 1; mask < (1 << 21); mask++){
        DSU dsu;
        dsu.init(6);
        vi cont(6, 0);

        for(int i = 0; i < 21; i++){
            if(mask & (1 << i)){
                dsu.join(dominos[i].fi, dominos[i].se);
                cont[dominos[i].fi]++;
                cont[dominos[i].se]++;
            }
        }

        int father = 0;
        for(int i = 0; i < 6; i++){
            if(cont[i] > 0){
                father = dsu.get(i);
            }
        }

        bool connected = true;
        int odds = 0;
        for(int i = 0; i < 6; i++){
            if(cont[i] & 1){
                odds++;
            }
            
            if(cont[i] > 0 && father != dsu.get(i)){
                connected = false;
                break;
            }
        }

        if(connected && odds <= 2){
            goodSet[mask] = 1;
        }
    }

    for(int i = 0; i < 21; i++){
        for(int mask = 0; mask < (1 << 21); mask++){
            if(mask & (1 << i)){
                goodSet[mask] += goodSet[mask ^ (1 << i)];
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int mask = 0;
        while(n--){
            int a, b;
            cin >> a >> b; a--; b--;
            if(a < b){
                swap(a, b);
            }

            for(int i = 0; i < 21; i++){
                if(dominos[i] == ii(a, b)){
                    mask |= (1 << i);
                    break;
                }
            }
        }

        cout << goodSet[mask] << ENDL;
    }

    return 0;
}
