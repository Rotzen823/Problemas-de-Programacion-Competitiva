#include<stdio.h>

int main(){
	int n;
	double t=0,p,d,ax;
	scanf("%d",&n);
	while(n--){
		scanf("%lf %lf",&p,&d);
		ax=d*0.25*(p/100);
		t+=ax;
	}
	printf("%.2lf",t);
}

