#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define MAX 100005
#define maxlog 20
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define ENDL '\n'

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> ii2;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<set<int> > graph(n, set<int>());

    while(m--){
        int x, y;
        cin >> x >> y; x--; y--;

        graph[x].insert(y);
        graph[y].insert(x);
    }

    set<ii> grados;
    for(int i = 0; i < n; i++){
        grados.insert(ii(SZ(graph[i]), i));
    }

    bool flag = true;
    while(flag){
        flag = false;
        while(!grados.empty() && grados.begin()->fi < a){
            int u = grados.begin()->se;
            grados.erase(grados.begin());

            for(int v : graph[u]){
                grados.erase(ii(SZ(graph[v]), v));
                graph[v].erase(u);
                grados.insert(ii(SZ(graph[v]), v));
            }
        }

        if(grados.empty()){
            break;
        }

        if((SZ(grados) - 1) - grados.rbegin()->fi < b){
            flag = true;
            int u = grados.rbegin()->se;
            grados.erase(ii(SZ(graph[u]), u));

            for(int v : graph[u]){
                grados.erase(ii(SZ(graph[v]), v));
                graph[v].erase(u);
                grados.insert(ii(SZ(graph[v]), v));
            }
        }
    }

    cout << SZ(grados) << ENDL;

    return 0;
}
