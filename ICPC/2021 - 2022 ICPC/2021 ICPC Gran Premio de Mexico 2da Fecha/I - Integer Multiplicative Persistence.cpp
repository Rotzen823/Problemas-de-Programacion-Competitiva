#include<stdio.h>
 
int im(long long int x){
	if(x<10) return 0;
	long long int r,m=1;
	int c=1;
	while(x>0){
		r=x%10;
		m*=r;
		x/=10;
	}
	c+=im(m);
	return c;
}
 
int main(){
	int n;
	scanf("%d",&n);
	long long int x;
	while(n--){
		scanf("%lld",&x);
		printf("%d\n",im(x));
	}
	return 0;
}



