#include<bits/stdc++.h>
#define MAX 150

int mat[MAX][MAX];
bool visita[MAX][MAX];
int n,m;

using namespace std;

int regMax(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m) return 0;
	if(mat[x][y] == 0) return 0;
	if(visita[x][y]) return 0;
	visita[x][y] = true;
	int c = 1;
	c += regMax(x-1,y-1);
	c += regMax(x-1,y);
	c += regMax(x-1,y+1);
	c += regMax(x,y-1);
	c += regMax(x,y+1);
	c += regMax(x+1,y-1);
	c += regMax(x+1,y);
	c += regMax(x+1,y+1);
	return c;
}

int main(){
	int cas,max,c;
	cin>>cas;
	for(int k=1; k<=cas; k++){
		cin>>n>>m;
		max = 0;
		for(int j=0; j<n; j++){
			for(int i=0; i<m; i++){
				cin>>mat[j][i];
				visita[j][i] = false;
			}
		}
		
		for(int j=0; j<n; j++){
			for(int i=0; i<m; i++){
				c = regMax(j,i);
				if(c > max){
					max = c;
				}
			}
		}
		cout<< "Case #"<<k<<": "<<max<<"\n";
	}
	return 0;
}
