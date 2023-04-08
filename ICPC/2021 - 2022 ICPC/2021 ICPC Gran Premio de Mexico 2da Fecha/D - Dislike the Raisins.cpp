#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	long long int s,c,r,max,t,min,cuch,res,res2,cal;
	while(n--){
		scanf("%lld %lld %lld",&c,&r,&s);
		max=c/s;
		res=r%s;
		res2=c%s;
		if(res2){
			if(!res) max++;
			else{
				cal=res+res2-1;
				if(cal>=s) max++;
			}
		}
		t=c+r;
		cuch=t/s;
		if(t%s) cuch++;
		min=cuch-r;
		if(min<0) min=0;
		printf("%lld %lld\n",max,min);
	}
	
	return 0;
}



