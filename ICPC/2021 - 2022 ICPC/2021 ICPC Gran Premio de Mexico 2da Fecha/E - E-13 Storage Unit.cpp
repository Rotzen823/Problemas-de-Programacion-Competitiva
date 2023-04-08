#include<stdio.h>
#define CONV 1024
#define MAX 1000005
 
long long int vid[MAX];
int max[MAX];
 
int main(){
	int n,limz=0,limd=0,min,l=-1;
	long long int alm,sum=0;
	char t;
	scanf("%d %lld%c",&n,&alm,&t);
	min=n;
	if(t=='T') alm*=(CONV*CONV);
	else if(t=='G') alm*=CONV;
	
	for(int k=0; k<n; k++){
		scanf("%lld",&vid[k]);
	}
	
	for(int i=0,j=0; j<n; j++){
		sum+=vid[j];
		if(sum>alm){
			max[i]=j-i;
			if(max[i]<min){
				min=max[i];
				l=i+1;
			}
			sum-=vid[i++];
			sum-=vid[j--];
		}
	}
	
	printf("%d %d\n",min,l);
	return 0;
}

