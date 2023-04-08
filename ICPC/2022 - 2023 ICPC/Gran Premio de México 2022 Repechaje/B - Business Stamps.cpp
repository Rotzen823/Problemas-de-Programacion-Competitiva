#include <bits/stdc++.h>
#define MAX 105
 
using namespace std;

vector<pair<int, int> > grafo[MAX];

int mat[MAX][MAX];
bool ready[MAX][MAX];
int n, m, d1, d2;

int D[] = {-1, 0, 1, 0};
int d[] = {0, 1, 0, -1};

int tags(int mask){
  int c = 0;
  while(mask > 0){
    if(mask & 1){
      c++;
    }
    mask >>= 1;
  }

  return c;
}

bool busqueda(int x, int y, int mask){
  if(x < 0 || y < 0 || x >= n || y >= m){
    return false;
  }

  if(!(mask & (1 << mat[x][y]))){
    return false;
  }

  if(ready[x][y]){
    return false;
  }

  if(x == d1 && y == d2){
    return true;
  }

  ready[x][y] = true;

  for(int k = 0; k < 4; k++){
    if(busqueda(x + D[k], y + d[k], mask)){
      return true;
    }
  }

  return false;
}

int main() {
    int o1, o2;
    scanf("%d %d %d %d %d %d", &n, &m, &o1, &o2, &d1, &d2);

    for(int k = 0; k < n; k++){
      for(int j = 0; j < m; j++){
        scanf("%d", &mat[k][j]);
      }
    }

    o1--; o2--; d1--; d2--;
    int lim = (1 << 11);
    int res = 11;
    for(int k = 1; k < lim; k++){
      memset(ready, false, sizeof(ready));
      if(busqueda(o1, o2, k)){
        res = min(res, tags(k));
      }
    }

    printf("%d\n", res);
    return 0;
}