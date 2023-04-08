#include<stdio.h>
#define MOD 1000000007
typedef long long ll;

int main(){
	ll t,pot=1,k,n,r,res=0;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		res=0, pot=1;
		while(k>0){
			r=k%2;
			res=(res%MOD) + ((r*pot)%MOD);
			k/=2;
			pot=(pot%MOD)*n;
		}
		printf("%lld\n",res%MOD);
	}
}

