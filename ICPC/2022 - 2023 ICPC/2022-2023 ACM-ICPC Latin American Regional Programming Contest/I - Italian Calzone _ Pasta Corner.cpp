#include <bits/stdc++.h>
#define MAX 105
#define MAXN 10005

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int mat[MAX][MAX];
bool ready[MAX][MAX];
ii cords[MAXN];

int n, m;

int dijkstra(int x, int y){
    memset(ready, false, sizeof(ready));
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(mat[x][y], ii(x, y)));

    int D[] = {1, 0, -1, 0};
    int d[] = {0, -1, 0, 1};

    int may = 0;
    int c = 0;
    while (!q.empty()) {
        int v = q.top().first;
        int a = q.top().second.first, b = q.top().second.second;
        q.pop();

        if(ready[a][b] || v < may){
            continue;
        }

        may = v;
        ready[a][b] = true;
        c++;

        for(int k = 0; k < 4; k++){
            int x1 = a + D[k], y1 = b + d[k];

            if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m){
                continue;
            }

            q.push(iii(mat[x1][y1], ii(x1, y1)));
        }
    }

    return c;
}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int k = 0; k < n; k++){
        for(int j = 0; j < m; j++){
            cin >> mat[k][j];
            cords[mat[k][j]] = ii(k, j);
        }
    }

    int may = 0;
    for(int k = 1; k <= (n * m); k++){
        int x = cords[k].first;
        int y = cords[k].second;
        if(ready[x][y]){
            continue;
        }
        may = max(may, dijkstra(x, y));
    }

    cout << may << "\n";

    return 0;
}