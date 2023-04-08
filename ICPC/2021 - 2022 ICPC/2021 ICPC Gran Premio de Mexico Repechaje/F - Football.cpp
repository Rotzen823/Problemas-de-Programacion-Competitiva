#include<bits/stdc++.h>
#define MAX 50

char campo[MAX][MAX];
bool visita[MAX][MAX];

using namespace std;

int main(){
	int r,c,e, x, y, pas;
	bool salir;
	
	while(true){
		cin>>r>>c>>e;
		if(r == 0 && c == 0 && e == 0){
			break;
		}
		pas = 0;
		salir = false;
		for(int k=0; k<r; k++){
			for(int j=0; j<c; j++){
				cin >> campo[k][j];
				visita[k][j] = false;
			}
		}
		
		x = 0;
		y = e - 1;
		while(true){
			if(x < 0 || x >= r || y < 0 || y >= c){
				salir = true;
				break;
			}
			if(visita[x][y]){
				break;
			}
			visita[x][y] = true;
			pas++;
			switch(campo[x][y]){
				case 'N':
					x--;
					break;
				case 'W':
					y--;
					break;
				case 'E':
					y++;
					break;
				case 'S':
					x++;
					break;
			}
		}
		
		if(salir){
			cout<<pas<<" step(s) to exit\n";
			continue;
		}
		
		int buc = 0, nX = x, nY = y;
		while(true){
			switch(campo[nX][nY]){
				case 'N':
					nX--;
					break;
				case 'W':
					nY--;
					break;
				case 'E':
					nY++;
					break;
				case 'S':
					nX++;
					break;
			}
			buc++;
			if(nX == x && nY == y){
				break;
			}
		}
		
		cout<<pas - buc<<" step(s) before a loop of "<<buc<<" step(s)\n";
		
	}
	
	return 0;
}
