#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

vector <vi> AdjList;

vector <vi> Ax;

vi iron, coal, distC, distH, di;
int n, m, k;

void bfs1(){
    
    queue <int> q;
    
	distC.assign(n + 1, -1);
    
    for(int x : coal){
        q.push(x);
        distC[x] = 0;
    }
    
    while(!q.empty()){
        
        int no = q.front();
        q.pop();
        
        for(int v : Ax[no]){
            if(distC[v] != -1) continue;
            else{
                distC[v] = distC[no] + 1;
                q.push(v);
            }
        }
    }
}

void bfs2(){
    
    queue <int> q;
    
    distH.assign(n + 1, -1);
    
    for(int x : iron){
        q.push(x);
        distH[x] = 0;
    }
    
    while(!q.empty()){
        
        int no = q.front();
        q.pop();
        
        for(int v : Ax[no]){
            if(distH[v] != -1) continue;
            else{
                distH[v] = distH[no] + 1;
                q.push(v);
            }
        }
    }
}

int bfs3(){
    
    queue <int> q;
    
    di.assign(n + 1, -1);
    
    q.push(1);
    di[1] = 0;
    
    while(!q.empty()){
        
        int no = q.front();
        q.pop();
        
        for(int v : AdjList[no]){
            if(di[v] != -1) continue;
            else{
                di[v] = di[no] + 1;
                q.push(v);
            }
        }
    }
    
    int ans = -1;
    
    for(int i = 1; i <= n; i++){
		if(distC[i] == -1 || distH[i] == -1 || di[i] == -1){
			continue;
		}

		if(ans == -1){
			ans = distC[i] + distH[i] + di[i];
		}
		else{
			ans = min(ans, distC[i] + distH[i] + di[i]);
		}
	}
    
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        iron.pb(x);
    }
    
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        coal.pb(x);
    }
    
    AdjList.assign(n + 1, vi());
    Ax.assign(n + 1, vi());
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int b; cin >> b;
            AdjList[i].pb(b);
            Ax[b].pb(i);
        }
    }
    
    bfs1();
    bfs2();
    int ans = bfs3();
    
    if(ans != -1){
        cout << ans << '\n';
    }
    else{
        cout << "impossible\n";
    }
    
    return 0;
}
