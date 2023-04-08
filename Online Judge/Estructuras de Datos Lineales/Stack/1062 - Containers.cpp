#include <bits/stdc++.h>
 
using namespace std;

typedef struct Nodo{
	char x;
	int pos;
}Nodo;

bool comparacion(Nodo a, Nodo b){
	if(a.x != b.x){
		return a.x > b.x;
	}

	return a.pos < b.pos;
}

int main() {
	string ax;
	int caso = 1;
	while(cin >> ax){
		if(ax == "end"){
			break;
		}

		int n = ax.length();
		Nodo pal[n];
		for(int k = 0; k < n; k++){
			pal[k] = {ax[k], k};
		}
		sort(pal, pal + n, comparacion);

		stack<Nodo> pilas[26];
		int c = 1;

		pilas[0].push(pal[0]);
		for(int k = 1; k < n; k++){
			bool bandera = true;
			for(int j = 0; j < c; j++){
				Nodo ax2 = pilas[j].top();
				//cout << ax2.x << " " << ax2.pos << "\n";
				if(ax2.x == pal[k].x || pal[k].pos > ax2.pos){
					pilas[j].push(pal[k]);
					bandera = false;
					break;
				}
			}

			if(bandera){
				pilas[c].push(pal[k]);
				c++;
			}
		}

		printf("Case %d: %d\n", caso++, c);
		
	}

    return 0;
}