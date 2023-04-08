#include<stdio.h>
#define MAX 1005
 
char mat[MAX][MAX];
bool visit[MAX][MAX];
int dis[MAX][MAX];
int n,m;
 
int bs(int x, int y,char d){
	if(x<0 || x>=n || y<0 || y>=m) return 0;
	if(d!=mat[x][y]) return 0;
	if(visit[x][y]) return dis[x][y];
	visit[x][y]=true;
	int max=0,ax;
	ax=bs(x-1,y-1, mat[x][y]+1); //Arriba izquierda
	if(ax>max) max=ax;
	ax=bs(x-1,y, mat[x][y]+1); //Arriba
	if(ax>max) max=ax;
	ax=bs(x-1,y+1, mat[x][y]+1); //Arriba derecha
	if(ax>max) max=ax;
	ax=bs(x,y-1, mat[x][y]+1); // Izquierda
	if(ax>max) max=ax;
	ax=bs(x,y+1, mat[x][y]+1); //Derecha
	if(ax>max) max=ax;
	ax=bs(x+1,y-1, mat[x][y]+1); //Abajo Izquierda
	if(ax>max) max=ax;
	ax=bs(x+1,y, mat[x][y]+1); //Abajo
	if(ax>max) max=ax;
	ax=bs(x+1,y+1, mat[x][y]+1); //Abajo derecha
	if(ax>max) max=ax;
	dis[x][y]=max+1;
	return dis[x][y];
}
 
int main(){
	int res=1,ax;
	scanf("%d %d",&n,&m);
	for(int k=0; k<n; k++){
		scanf("%s",mat[k]);
	}
	
	for(int k=0; k<n; k++){
		for(int j=0; j<m; j++){
			ax=bs(k,j,mat[k][j]);
			if(ax>res) res=ax;
		}
	}
	printf("%d\n",res);
	/*for(int k=0; k<n; k++){
		for(int j=0; j<m; j++){
			printf("%d ",dis[k][j]);
		}
		printf("\n");
	}*/
	return 0;
}
