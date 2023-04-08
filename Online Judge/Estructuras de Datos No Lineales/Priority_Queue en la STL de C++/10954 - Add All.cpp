#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> cola;

int main(){
	int n;

	while(scanf("%d", &n), n != 0){
		while(n--){
			int x;
			scanf("%d", &x);
			cola.push(x);
		}

		int costo = 0;

		while(!cola.empty()){
			int a, b;

			a = cola.top(); cola.pop();

			if(cola.empty()){
				break;
			}

			b = cola.top(); cola.pop();

			costo += (a + b);

			cola.push(a + b);
		}

		printf("%d\n", costo);
	}

	return 0;
}