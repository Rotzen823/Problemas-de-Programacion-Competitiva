#include <bits/stdc++.h>
#define MAX 100005
 
using namespace std;

typedef long long ll;

typedef struct arista{
    int a;
    ll dis;
    ll costo;
}arista;

class ComparisonClass{
    public:
        bool operator() (arista a, arista b){
            if(a.dis != b.dis){
                return a.dis > b.dis;
            }
            return a.costo > b.costo;
        }
};

vector<pair<int, ll> > grafo[MAX];
bool ready[MAX];

ll prim(int n){
    priority_queue<arista, vector<arista>, ComparisonClass> q;
    q.push({1, 0, 0});
    ll res = 0;
    arista edge;
    for(int k = 0; k < n; k++){
        do{
            edge = q.top();
            q.pop();
        }while(ready[edge.a]);

        res += (edge.costo * edge.dis);
        ready[edge.a] = true;
        
        for(auto cord : grafo[edge.a]){
            int h = cord.first;
            if(!ready[h]){
                //printf("%d %d %d\n", v, h, dis);
                ll dis = edge.dis + 1;
                q.push({h, dis, cord.second});
            }
        }
    }
    return res;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for(int k = 0; k < m; k++){
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }

    ll res = prim(n);

    printf("%lld\n", res);
    
    return 0;
}