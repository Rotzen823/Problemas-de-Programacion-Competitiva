#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int mat[MAX][MAX],n,m;
char op[MAX];

/*void mostrar(){
	for(int k=0; k<n; k++){
		for(int j=0; j<m; j++){
			cout<<mat[k][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}*/

int main(){
	int c=0,pos,com,e,max;
	char ax;
	cin>>n>>m;
	
	for(int k=0; k<n; k++){
		for(int j=0; j<m; j++){
			cin>>mat[k][j];
		}
	}
	cin>>op;
	while(op[c]!='\0'){
		ax=op[c++];
		switch(ax){
			case 'N':
				for(int j=0; j<m; j++){
					pos=0,com=0;
					for(int k=0; k<n; k++){
						e=mat[k][j];
						if(e){
							mat[k][j]=0;
							if(e==com) com=0,mat[pos-1][j]*=2;
							else com=mat[pos++][j]=e;	
						}
					}
				}
				break;
			case 'E':
				for(int k=0; k<n; k++){
					pos=m-1,com=0;
					for(int j=m-1; j>=0; j--){
						e=mat[k][j]; 
						if(e){
							mat[k][j]=0;
							if(e==com) com=0,mat[k][pos+1]*=2;
							else com=mat[k][pos--]=e;	
						}
					}
				}
				break;
			case 'S':
				for(int j=0; j<m; j++){
					pos=n-1,com=0;
					for(int k=n-1; k>=0; k--){
						e=mat[k][j];
						if(e){
							mat[k][j]=0;
							if(e==com) com=0,mat[pos+1][j]*=2;
							else com=mat[pos--][j]=e;	
						}
					}
				}
				break;
			case 'O':
				for(int k=0; k<n; k++){
					pos=0,com=0;
					for(int j=0; j<m; j++){
						e=mat[k][j];
						if(e){
							mat[k][j]=0;
							if(e==com) com=0,mat[k][pos-1]*=2;
							else com=mat[k][pos++]=e;	
						}
					}
				}
				break;
		}
		/*cout<<ax<<"\n";
		mostrar();*/
	}
	
	for(int k=0; k<n; k++){
		max=0;
		for(int j=0; j<m; j++){
			if(mat[k][j]>max) max=mat[k][j];
		}
		if(max) cout<<max<<"\n";
	}
	
}
