#include<bits/stdc++.h>

int main(){	
	double n,x,m,a,b;
	
	scanf("%lf %lf %lf",&n,&x,&m);
	
  	a=n/pow(2,x);
  	b=n/pow(2,x-m);
  	b=floor(b);
  	a=floor(a);
	printf("%.0lf\n%.0lf\n",a,b);
	
	return 0;
}