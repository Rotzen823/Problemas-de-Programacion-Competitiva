#include<stdio.h>
#define MAX 1000005
 
bool esPrimo[MAX];
int cPrimos[MAX];
 
void criba(){
	int k;
	for(k=2; (k*k)<MAX; k++){
		if(!esPrimo[k]){
			for(int j=k*k; j<MAX; j+=k){
				esPrimo[j]=true;
			}
		}
	}
}
 
int main(){
	int n,max=1,r1,r2,c;
	scanf("%d",&n);
	criba();
	cPrimos[0]=cPrimos[1]=0;
	while(n--){
		scanf("%d %d",&r1,&r2);
		if(r2>max){
			c=cPrimos[max];
			for(int k=max+1; k<=r2; k++){
				if(!esPrimo[k]) c++;
				cPrimos[k]=c;
			}	
			max=r2;
		}
		printf("%d\n",cPrimos[r2]-cPrimos[r1-1]);
	}
}


