#include<stdio.h>

int main(){
	int n;
	long int ax,res=0;
	scanf("%d",&n);
	while(n--){
		scanf("%ld",&ax);
		res+=(ax-1);
	}
	printf("%ld",res+1);
	
}

