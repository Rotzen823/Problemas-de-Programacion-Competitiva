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

typedef pair<int, ii> iii;

int n, m;
vector<string> mat;
vector<string> s;

bool valid(ii cords){
    int x = cords.fi, y = cords.se;
    return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '0';
}

iii weight(int i, ii cords){
    int dist = 0;
    for(char mov : s[i]){
        ii ax = cords;
        switch(mov){
            case 'U':
            ax.fi--;
            break;
            case 'D':
            ax.fi++;
            break;
            case 'L':
            ax.se--;
            break;
            case 'R':
            ax.se++;
            break;
        }
        if(valid(ax)){
            cords = ax;
            dist++;
        }
    }

    return {dist, cords};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    mat.resize(n);
    for(int i = 0; i < n; i++){
        cin >> mat[i];
    }

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int k;
    cin >> k;
    s.resize(k);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<vi> dist(n, vi(m, INF));
    priority_queue<iii, vector<iii>, greater<iii>> q;
    q.push({0, ii(ax, ay)});
    dist[ax][ay] = 0;

    while(!q.empty()){
        auto edge = q.top(); q.pop();
        ii cords = edge.se;
        if(dist[cords.fi][cords.se] < edge.fi){
            continue;
        }
        
        for(int i = 0; i < k; i++){
            auto way = weight(i, cords);
            ii cordT = way.se;
            int w = way.fi;

            if(dist[cords.fi][cords.se] + w < dist[cordT.fi][cordT.se]){
                dist[cordT.fi][cordT.se] = dist[cords.fi][cords.se] + w;
                q.push({dist[cordT.fi][cordT.se], cordT});
            }
        }
    }

    if(dist[bx][by] == INF){
        cout << "-1\n";
    }
    else{
        cout << dist[bx][by] << ENDL;
    }

    return 0;
}
