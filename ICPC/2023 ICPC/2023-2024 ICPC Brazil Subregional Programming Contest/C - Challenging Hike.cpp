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

vector<vi> tree;
vector<bool> ready;
vi val, res;

vi lis;

void dfs(int u){
    if(ready[u]){
        return;
    }
    ready[u] = true;

    int id = -1, ax = val[u];
    if(lis.empty() || lis.back() < ax){
        lis.push_back(ax);
    }
    else{
        id = upper_bound(lis.begin(), lis.end(), ax) - lis.begin();
        swap(ax, lis[id]);
    }

    res[u] = lis.size();

    for(int v : tree[u]){
        dfs(v);
    }

    if(id == -1){
        lis.pop_back();
    }
    else{
        swap(ax, lis[id]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    tree.assign(n, vi());
    ready.assign(n, false);
    val.resize(n);
    res.resize(n);

    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }

    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    dfs(0);

    cout << res[1];
    for(int i = 2; i < n; i++){
        cout << ' ' << res[i];
    }
    cout << ENDL;

    return 0;
}
