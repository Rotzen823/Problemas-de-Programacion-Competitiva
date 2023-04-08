#include <bits/stdc++.h>

using namespace std;

int main(){
	int s,b;

	while(scanf("%d %d", &s, &b), !(s == 0 && b == 0)){
		int bIzq[s + 2];
		int bDer[s + 2];

		for(int k = 1; k <= s; k++){
			bIzq[k] = k - 1;
			bDer[k] = k + 1;
		}

		bIzq[0] = bIzq[1] = bDer[s + 1] = bDer[s] = 0;

		int l, r;
		while(b--){
			scanf("%d %d", &l, &r);

			if(bIzq[l]){
				printf("%d ", bIzq[l]);
			}
			else{
				printf("* ");
			}

			if(bDer[r]){
				printf("%d\n", bDer[r]);
			}
			else{
				printf("*\n");
			}

			bDer[bIzq[l]] = bDer[r];
			bIzq[bDer[r]] = bIzq[l];
		}

		printf("-\n");
	}
	

	return 0;
}