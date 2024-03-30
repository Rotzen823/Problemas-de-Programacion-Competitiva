#include <bits/stdc++.h>

#define ENDL '\n'
#define MOD 1000000007
#define INF 1000000000
#define MAX 400005
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int n, m, mini, maxi;
int ans=0;
vii grafo[MAX];
bool processed[MAX];
ll dist[MAX];

void dijkstra(int x){
    for(int i=0; i<n;i++){
        dist[i]=INF;
    }
    for(int i = 0; i < m; i++){
        int a = n + (i * 2), b = n + (i * 2) + 1;
        dist[a] = dist[b] = INF;
    }
    dist[x]=0;
    priority_queue<ii>q;
    q.push({0,x});
    while(!q.empty()){
        int a=q.top().second;
        q.pop();
        if(processed[a]){
            continue;
        }
        processed[a]=true;
        for(auto u : grafo[a]){
            int b=u.fi;
            ll w=u.se;
            if(dist[a]+ w < dist[b]){
                dist[b]=dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>mini>>maxi;
    
    for(int i = 0; i < m; i++){
        int x,y,c;
        cin>>x>>y>>c;
        int a = n + (i * 2), b = n + (i * 2) + 1;

        grafo[x].push_back({a, 0});
        grafo[a].push_back({x, 0});

        grafo[y].push_back({b, 0});
        grafo[b].push_back({y, 0});

        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }

    dijkstra(0);
    
    for(int i = 0; i < m; i++){
        int a = n + (i * 2), b = n + (i * 2) + 1;
        ll minD = min(dist[a], dist[b]);
        //cout << a << " " << b << " "  << minD << "\n";
        if(maxi > minD * 2){
            ans++;
        }   
    }

    cout << ans << "\n";

    return 0;
}
