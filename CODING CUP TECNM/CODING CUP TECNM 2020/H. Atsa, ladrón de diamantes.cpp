#include<stdio.h>

long long int inter[1000000][2];

void qs(long long int limz, long long int limd){
	long long int izq,der,pivot1,pivot2;
	long long int temp1, temp2;
	izq=limz;
	der=limd;
	pivot1=inter[(izq+der)/2][0];
	pivot2=inter[(izq+der)/2][1];
	do{
		while((inter[izq][0]<pivot1 || (inter[izq][0]==pivot1 && inter[izq][1]<pivot2)) && izq<limd) izq++;
		while((inter[der][0]>pivot1 || (inter[der][0]==pivot1 && inter[der][1]>pivot2)) && der>limz) der--;
		if(izq<=der){
			temp1=inter[izq][0];
			temp2=inter[izq][1];
			inter[izq][0]=inter[der][0];
			inter[izq][1]=inter[der][1];
			inter[der][0]=temp1;
			inter[der][1]=temp2;
			izq++;
			der--;
		}
	}while(izq<=der);
	if(izq<limd){qs(izq,limd);}
	if(der>limz){qs(limz,der);}
}

int main(){
	long long int n,m,c=1,L,R,l,r;
	scanf("%lld %lld",&n,&m);
	for(int k=0; k<m; k++){
		scanf("%lld %lld",&inter[k][0],&inter[k][1]);
	}
	qs(0,m-1);
	L=inter[0][0];
	R=inter[0][1];
	for(int k=1; k<m; k++){
		l=inter[k][0];
		r=inter[k][1];
		if(l==L){
			continue;
		}
		else if(R>=l && R<=r){
			L=l;
		}
		else if(R<l){
			c++;
			L=l;
			R=r;
		}
		else if(R>r){
			L=l;
			R=r;
		}
	}
	printf("%lld",c);
}

