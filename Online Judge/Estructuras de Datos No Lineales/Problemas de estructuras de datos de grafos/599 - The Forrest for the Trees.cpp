#include <bits/stdc++.h>
#define MAX 30
 
using namespace std;

vector<int> grafo[MAX];
int ready;

void dfs(int v){
	if(ready & (1 << v)){
		return;
	}

	ready |=  (1 << v);

	for(int u : grafo[v]){
		dfs(u);
	}
}

int main() {
    int n;
	string ax = "";
	cin >> n;

	while(n--){
		int mask = 0, trees = 0, acorn = 0;
		ready = 0;
		for(int k = 0; k < 26; k++){
			grafo[k].clear();
		}
		
		while(cin >> ax){
			if(ax[0] == '*'){
				break;
			}
			char a, b;

			a = ax[1]; b = ax[3];

			mask |= (1 << (a - 'A'));
			mask |= (1 << (b - 'A'));
			
			grafo[a - 'A'].push_back(b - 'A');
			grafo[b - 'A'].push_back(a - 'A');
		}

		cin >> ax;

		for(char x : ax){
			if(x == ','){
				continue;
			}

			int v = x - 'A';

			if(mask & (1 << v)){
				if(!(ready & (1 << v))){
					trees++;
					dfs(v);
				}
			}
			else{
				acorn++;
			}
		}

		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
	}

    return 0;
}