#include<bits/stdc++.h>
#define MAX 55

using namespace std;

queue < pair<int,int> > cola;
int tab[MAX][MAX];
bool visit[MAX][MAX];
int dis[MAX][MAX];
int n,m,a,b;

bool validar(int x, int y, int d){
	if(x<0 || x>=n || y<0 || y>=m) return false;
	if(tab[x][y] || visit[x][y]) return false;
	dis[x][y]=d+1;
	visit[x][y]=true;
	if(x==a && y==b) return true;
	cola.push(make_pair(x,y));
	return false;
}

void bus(){
	pair <int,int> par;
	int x,y,d;
	while(!cola.empty()){
		par=cola.front(), cola.pop();
		x=par.first, y=par.second;
		d=dis[x][y];
		if(validar(x-1,y,d)) break;
		if(validar(x+1,y,d)) break;
		if(validar(x,y-1,d)) break;
		if(validar(x,y+1,d)) break;
	}
}

int main(){
	int x,y;
	cin>>n>>m;
	for(int k=0; k<n; k++){
		for(int j=0; j<m; j++){
			cin>>tab[k][j];
		}
	}
	cin>>x>>y;
	cin>>a>>b;
	dis[x][y]=1;
	visit[x][y]=true;
	cola.push(make_pair(x,y));
	bus();
	cout<<dis[a][b]<<"\n";
}
