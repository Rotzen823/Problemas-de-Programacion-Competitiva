#include <bits/stdc++.h>
#define MAX 1000005
 
using namespace std;

vector<int> tree[MAX];
int n, x;
bool ready[MAX];
int dis[MAX];

int bfs(int v){
  for(int k = 1; k <= n; k++){
    dis[k] = MAX;
  }

  int camino = 0;
  queue<int> q;
  q.push(1);
  dis[1] = 0;

  while(!q.empty()){
    int u = q.front(); q.pop();
    if(ready[u]){
      continue;
    }
    ready[u] = true;
    camino += 2;

    bool destiny = false;
    for(int b : tree[u]){
      if(b == v){
        dis[b] = dis[u] + 1;
        destiny = true;
        break;
      }
    }

    if(destiny){
      continue;
    }

    for(int b : tree[u]){
      if(dis[u] + 1 < dis[b]){
        dis[b] = dis[u] + 1;
        q.push(b);
      }
    }

  }

  return camino - dis[v];
}

int main() {
    scanf("%d %d", &n, &x);

    for(int k = 1; k < n; k++){
      int a, b;
      scanf("%d %d", &a, &b);
      tree[a].push_back(b);
      tree[b].push_back(a);
    }

    if(x == 1){
      printf("0\n");
      return 0;
    }

    printf("%d\n", bfs(x));
    
    return 0;
}