#include <bits/stdc++.h>
#define MAX 2005
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
 
template <typename T>
struct hungarian{ // km
    int n;
    vector<int> matchx;
    vector<int> matchy;
    vector<int> pre;
    vector<bool> visx;
    vector<bool> visy;
    vector<T> lx;
    vector<T> ly;
    vector<vector<T>> g;
    vector<T> slack;
    T inf;
    T res;
    queue<int> q;
    int org_n;
    int org_m;
 
    hungarian(int _n, int _m)
    {
        org_n = _n;
        org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<T>::max();
        res = 0;
        g = vector<vector<T>>(n, vector<T>(n));
        matchx = vector<int>(n, -1);
        matchy = vector<int>(n, -1);
        pre = vector<int>(n);
        visx = vector<bool>(n);
        visy = vector<bool>(n);
        lx = vector<T>(n, -inf);
        ly = vector<T>(n);
        slack = vector<T>(n);
    }
 
    void addEdge(int u, int v, T w)
    {
        g[u][v] = w; 
    }
 
    bool check(int v)
    {
        visy[v] = true;
        if (matchy[v] != -1)
        {
            q.push(matchy[v]);
            visx[matchy[v]] = true;
            return false;
        }
        while (v != -1)
        {
            matchy[v] = pre[v];
            swap(v, matchx[pre[v]]);
        }
        return true;
    }
 
    void bfs(int i)
    {
        while (!q.empty())
        {
            q.pop();
        }
        q.push(i);
        visx[i] = true;
        while (true)
        {
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; v++)
                {
                    if (!visy[v])
                    {
                        T delta = lx[u] + ly[v] - g[u][v];
                        if (slack[v] >= delta)
                        {
                            pre[v] = u;
                            if (delta)
                            {
                                slack[v] = delta;
                            }
                            else if (check(v))
                            {
                                return;
                            }
                        }
                    }
                }
            }
            T a = inf;
            for (int j = 0; j < n; j++)
            {
                if (!visy[j])
                {
                    a = min(a, slack[j]);
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (visx[j])
                { // S
                    lx[j] -= a;
                }
                if (visy[j])
                { // T
                    ly[j] += a;
                }
                else
                { // T'
                    slack[j] -= a;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (!visy[j] && slack[j] == 0 && check(j))
                {
                    return;
                }
            }
        }
    }
 
    T solve()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lx[i] = max(lx[i], g[i][j]);
            }
        }
 
        for (int i = 0; i < n; i++)
        {
            fill(slack.begin(), slack.end(), inf);
            fill(visx.begin(), visx.end(), false);
            fill(visy.begin(), visy.end(), false);
            bfs(i);
        }
 
        for (int i = 0; i < n; i++)
        {
            //cout << g[i][matchx[i]] << "\n";
            if (g[i][matchx[i]] < 0)
            {
                res += g[i][matchx[i]];
            }
            else
            {
                matchx[i] = -1;
            }
        }
        return res;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cout.setf(ios::fixed); cout << setprecision(2);
    
    int n, m;
    cin >> n >> m;
 
    hungarian<ll> h(n, m + n - 1);
 
    vii Bo(n);
    for(int i = 0; i < n; i++){
        cin >> Bo[i].fi >> Bo[i].se;
    }
    vii Em(m);
    for(int k = 0; k < m; k++){
        cin >> Em[k].fi >> Em[k].se;
    }
 
    int x, y; cin >> x >> y;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            h.addEdge(i, j, -(abs(Em[j].fi- Bo[i].fi) + abs(Em[j].se- Bo[i].se) + abs(x - Bo[i].fi) + abs(y - Bo[i].se)));
            //cout << i << " " << j << " " << (abs(Em[j].fi- Bo[i].fi) + abs(Em[j].se- Bo[i].se)) << "\n";
        }
    }

    for(int j = 0; j < n - 1; j++){
        for(int i = 0; i < n; i++){
            h.addEdge(i, m + j, -2 * (abs(x - Bo[i].fi) + abs(y - Bo[i].se)));
            //cout << i << " " << j + m << " " << (abs(x - Bo[i].fi) + abs(y - Bo[i].se)) << "\n";
        }
    }
 
    ll res = -h.solve();
    cout << res << "\n";
 
    return 0;
}
