#include<stdio.h>
#define MAX 505

int n;
long long int ans;
long long int mat[MAX][MAX];
long long int num[MAX];

void check(){
	long long int temp=0;
	for(int k=0; k<n; k++){
		if(temp<0) temp=0;
		temp+=num[k];
		if(temp>ans) ans=temp;
	}
}

int main(){
	scanf("%d",&n);
	for(int k=0; k<n; k++){
		for(int j=0; j<n; j++){
			scanf("%lld",&mat[k][j]);
		}
	}
	
	ans=mat[0][0];
	for(int k=0; k<n; k++){
		for(int j=0; j<n; j++) num[j]=0;
		
		for(int j=k; j<n; j++){
			for(int i=0; i<n; i++){
				num[i]+=mat[j][i];
			}
			check();
		}
	}
	printf("%lld",ans);
}

