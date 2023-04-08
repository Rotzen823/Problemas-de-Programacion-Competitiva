#include<bits/stdc++.h>
#define MAX 1005
#define INF 1000005
 
using namespace std;
 
char mat[MAX][MAX];
int dis[MAX][MAX];
bool visit[MAX][MAX];
int D[] = {0, 1, 0, -1};
int d[] = {-1, 0, 1, 0};
char dir[] = {'L', 'D', 'R', 'U'};
int n,m;
 
bool validar(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m) return false;
	if(mat[x][y]!='.') return false;
	return !visit[x][y];
}
 
void bfs(int x, int y){
	int ax,ay;
	queue<pair<int, int> > q;
	visit[x][y]=true;
	dis[x][y]=0;
	q.push({x, y});

	while(!q.empty()){
		ax=q.front().first;
		ay=q.front().second; q.pop();

		for(int k = 0; k < 4; k++){
			int bx = ax + D[k], by = ay + d[k];
			if(validar(bx, by)){
				visit[bx][by] = true;
				dis[bx][by] = dis[ax][ay] + 1;
				q.push({bx, by});
			}
		}
	}
}
 
int main(){
	int x,y,p,k,j,b;
	char ax;
	scanf("%d %d",&n,&m);
	for(k=0; k<n; k++){
		scanf("%c",&ax);
		for(j=0; j<m; j++){
			scanf("%c",&mat[k][j]);
			dis[k][j]=INF;
			if(mat[k][j]=='E'){
				x=k;
				y=j;
			}
		}
	}
	bfs(x,y);
	
	scanf("%d",&p);
	while(p--){
		scanf("%d %d",&k,&j);
		k--,j--;
		if(mat[k][j]=='#') printf("W\n");
		else if(mat[k][j]=='.'){
			b = INF; 
			ax = '?';
			for(int i = 0; i < 4; i++){
				int x = k + D[i], y = j + d[i];
				if(x >= 0 && y >= 0 && x < n && y < m){
					if(dis[x][y] < b){
						b = dis[x][y];
						ax = dir[i];
					}
				}
			}

			printf("%c\n", ax);
		}
		else printf("%c\n",mat[k][j]);
	}
	
	return 0;
}