#include<bits/stdc++.h>
#define MAX 500005

using namespace std;

int nums[MAX];

bool miComparacion(int a, int b){
	if(a < 0){
		a = -a;
	}
	if(b < 0){
		b = -b;
	}
	return a > b;
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		for(int k = 0; k < n; k++){
			scanf("%d", &nums[k]);
		}

		sort(nums, nums + n, miComparacion);

		bool bandera;
		int c = 1;
		if(nums[0] > 0){
			bandera = true;
		}
		else{
			bandera = false;
		}

		for(int k = 1; k < n; k++){
			if(nums[k] < 0 && bandera){
				bandera = false;
				c++;
			}
			else if(nums[k] > 0 && !bandera){
				bandera = true;
				c++;
			}
		}

		printf("%d\n", c);
	}
	
	return 0;
}