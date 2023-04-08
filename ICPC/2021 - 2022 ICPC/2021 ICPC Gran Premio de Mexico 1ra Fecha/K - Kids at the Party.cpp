#include<stdio.h>
#include<string.h>
#define MAX 505
 
char num[MAX];
 
int main(){
	int n,l,ax,ax2,c,sum;
	bool bol[5],nop;
	scanf("%d",&n);
	while(n--){
		scanf("%s",num);
		nop=true;
		sum=0;
		l=strlen(num);
		c=ax=num[l-1]-48;
		for(int k=0; k<l; k++){
			ax2=num[k]-48;
			sum+=ax2;
		}
		if(l>1){
			ax2=num[l-2]-48;
			c+=(ax2*10);
		}
		bol[0]=ax%2==0;
		bol[1]=sum%3==0;
		bol[2]=c%4==0;
		bol[3]=ax%5==0;
		bol[4]=bol[0] && bol[1];
		for(int k=0; k<5; k++){
			if(bol[k]){
				if(!nop) printf(" ");
				printf("%d",k+2);
				nop=false;
			}
		}
		if(nop) printf("-1");
		printf("\n");
	}
}


