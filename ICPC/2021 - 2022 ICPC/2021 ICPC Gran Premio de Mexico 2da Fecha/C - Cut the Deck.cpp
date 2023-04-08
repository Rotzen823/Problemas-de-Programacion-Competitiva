#include<stdio.h>
#define MAXS 1000005
 
char st[MAXS];
 
int main(){
	int n,r,b,c,k;
	scanf("%d",&n);
	while(n--){
		scanf("%s",st);
		r=0, b=0, c=0;
		k=0;
		while(st[k]!='\0'){
			if(st[k]=='R') r++;
			else b++;
			if(r>b){
				c=k+1;
				r=0, b=0;
			}
			k++;
		}
		printf("%d\n",c);
	}
	
	return 0;
}



