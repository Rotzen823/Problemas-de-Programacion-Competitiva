#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	
	while(scanf("%d", &n), n != 0){
		vector<int> puestos(n + 1, 0);

		bool sirve = true;

		for(int k = 1; k <= n; k++){
			int a, b;
			scanf("%d %d", &a, &b);
			
			if(!sirve){
				continue;
			}

			int x = k + b;
			
			if(x <= 0 || x > n){
				sirve = false;
				continue;
			}

			if(puestos[x]){
				sirve = false;
				continue;
			}

			puestos[x] = a;
		}

		if(sirve){
			printf("%d", puestos[1]);
			for(int k = 2; k <= n; k++){
				printf(" %d", puestos[k]);
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	
	return 0;
}