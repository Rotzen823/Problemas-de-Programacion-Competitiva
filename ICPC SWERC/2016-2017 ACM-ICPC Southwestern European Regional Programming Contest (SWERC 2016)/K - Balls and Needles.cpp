#include <bits/stdc++.h>

#define fi first
#define se second
#define ENDL '\n'
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005
#define MAXK 1005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair<int, ii> iii;
typedef vector <int> vi;
typedef vector <ii> vii;

vi grafo3[MAX], grafo2[MAX];
int ready[MAX];

bool dfs3(int u, int p, int c){
    if(ready[u] != -1){
        return ready[u] == c;
    }
    ready[u] = c;

    for(int v : grafo3[u]){
        if(v == p){
            continue;
        }
        if(dfs3(v, u, c)){
            return true;
        }
    }
    return false;
}

bool dfs2(int u, int p, int c){
    if(ready[u] != -1){
        return ready[u] == c;
    }
    ready[u] = c;

    for(int v : grafo2[u]){
        if(v == p){
            continue;
        }
        if(dfs2(v, u, c)){
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;
    memset(ready, -1, sizeof(ready));

    map<iii, int> id3;
    map<ii, int> id2;

    set<ii> edges;

    for(int i = 0; i < k; i++){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        if(!id3.count(iii(x1, ii(y1, z1)))){
            id3[iii(x1, ii(y1, z1))] = id3.size();
        }
        if(!id3.count(iii(x2, ii(y2, z2)))){
            id3[iii(x2, ii(y2, z2))] = id3.size();
        }

        if(!id2.count(ii(x1, y1))){
            id2[ii(x1, y1)] = id2.size();
        }
        if(!id2.count(ii(x2, y2))){
            id2[ii(x2, y2)] = id2.size();
        }

        int a = id3[iii(x1, ii(y1, z1))], b = id3[iii(x2, ii(y2, z2))];
        grafo3[a].push_back(b);
        grafo3[b].push_back(a);

        a = id2[ii(x1, y1)]; b = id2[ii(x2, y2)];
        if(a == b || edges.count(ii(a, b))){
            continue;
        }

        edges.insert(ii(a, b)); edges.insert(ii(b, a));
        grafo2[a].push_back(b);
        grafo2[b].push_back(a);
    }

    bool flag = true;
    for(int i = 0; i < (int) id3.size(); i++){
        if(ready[i] == -1){
            if(dfs3(i, -1, i)){
                cout << "True closed chains\n";
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout << "No true closed chains\n";
    }

    memset(ready, -1, sizeof(ready));
    flag = true;
    for(int i = 0; i < (int) id2.size(); i++){
        if(ready[i] == -1){
            if(dfs2(i, -1, i)){
                cout << "Floor closed chains\n";
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout << "No floor closed chains\n";
    }



    return 0;
}
