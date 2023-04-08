#include<bits/stdc++.h>
 
using namespace std;
 
vector < vector<int>> roads;
vector <bool> parVis;
 
queue <int> cola;
 
string res;
 
void bpa(){
 
    while(!cola.empty()){
        int x = cola.front(); cola.pop();
        res[x] = 'B';
 
        for(int i : roads[x]){
            if(!parVis[i]){
                parVis[i] = true;
                cola.push(i);
            }
        }
    }
}
 
 
int main(){
    int n, m, u, v;
 
    cin >> n >> m;
 
    roads.resize(n);
    parVis.resize(n);
    res.resize(n);
 
    for(int k = 0; k < n; k++){
        res[k] = 'A';
    }
 
    while(m--){
        cin >> u >> v;
 
        if(u == n || v == n){
            continue;
        }
 
        roads[u - 1].push_back(v - 1);
        roads[v - 1].push_back(u - 1);
    }
 
    parVis[n - 2] = true;
    cola.push(n - 2);
    bpa();
 
    cout << res << "\n";
 
    return 0;
}
