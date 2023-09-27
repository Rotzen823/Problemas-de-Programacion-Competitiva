#include <bits/stdc++.h>
#define MAX 1005
#define MAXB 105
#define INF 1000000
 
using namespace std;
 
#define ENDL '\n'
typedef long long ll;
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
 
int memo[MAXB][MAX];
ii paradas[MAX];
vii links[MAX];
 
int tr[MAXB];
bool ready[MAXB][MAX];
int bt, m;
 
int dist(int a, int b){
    return ceil(sqrt((a*a) + (b*b)));
}
 
int dp(int bx, int i){
    if(bx > bt){
        return INF;
    }
 
    if(i == m){
        return 0;
    }
 
    if(memo[bx][i] != -1){
        return memo[bx][i];
    }
    ready[bx][i] = true;
 
    int res = INF;
    for(auto e : links[i]){
        int j = e.first, mt = e.second;
        if(ready[bx][j]){
            continue;
        }
        int dis = dist(paradas[i].first - paradas[j].first, paradas[i].second - paradas[j].second);
        int c = dis * tr[mt];
        int op = dp(bx + dis, j) + c;
        res = min(res, op);
    }
 
    ready[bx][i] = false;
    return memo[bx][i] = res;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    memset(memo, -1, sizeof(memo));
 
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf >> bt >> tr[0];
 
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> tr[k];
    }
 
    cin >> m;
    paradas[0] = ii(xs, ys);
    for(int k = 1; k <= m; k++){
        int a, b, l;
        cin >> a >> b >> l;
        paradas[k] = ii(a, b);
        while(l--){
            int j, mt;
            cin >> j >> mt;
            j++;
            links[k].push_back(ii(j, mt));
            links[j].push_back(ii(k, mt));
        }
        links[k].push_back(ii(m + 1, 0));
    }
    m++;
    paradas[m] = ii(xf, yf);
    for(int k = 1; k <= m; k++){
        links[0].push_back(ii(k, 0));
    }
 
    int res = dp(0, 0);
    if(res == INF){
        cout << "-1\n";
    }
    else{
        cout << res << "\n";
    }
    return 0;
}
