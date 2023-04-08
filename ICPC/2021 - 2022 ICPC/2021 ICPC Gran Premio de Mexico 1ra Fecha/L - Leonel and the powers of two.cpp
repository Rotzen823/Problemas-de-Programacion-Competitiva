#include<stdio.h>
 
void pot(long long int k){
	if(k==1) printf("2");
	else if(k%2){
		printf("(2*");
		pot(k-1);
		printf(")");
	}
	else{
		printf("(");
		pot(k/2);
		printf(")^2");
	}
}
 
int main(){
	int n;
	long long int k;
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&k);
		pot(k);
		printf("\n");
	}
}


