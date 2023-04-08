#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;

	scanf("%d", &n);

	if(n % 2 == 1){
		n--;
	}

	int a,b;
	b = a = n / 4;

	if(n % 4 != 0){
		b++;
	}

	printf("%d\n", a * b);

	return 0;
}