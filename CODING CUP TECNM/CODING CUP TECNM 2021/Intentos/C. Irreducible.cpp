#include<bits/stdc++.h>

using namespace std;

int dig[10];

int mcd(int a, int b){
	int r;
	while(b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

bool enc(int a, int b, int c){
	int d,r;
	bool bol;
	while(a>0){
			d=a%10;
			a/=10;
			bol=true;
			while(b>0){
				r=b%10;
				b/=10;
				if(r==d){
					bol=false;
					break;
				}
				dig[r]+=c;
			}
			if(bol){
				return false;
			}
	}
	while(b>0){
		r=b%10;
		b/=10;
		dig[r]+=c;
	}
	return true;
}

int main(){
	int n,a,b,m,num,den,r,d;
	cin>>n;
	bool bol;
	while(n--){
		cin>>a>>b;
		m=mcd(a,b);
		num=a/m;
		den=b/m;
		for(int k=0; k<10; k++){
			dig[k] = 0;
		}
		cout<<num<<"/"<<den<<" ";
		if(a<10 || b<10){
			cout<<"NO\n";
			continue;
		}
		if(!enc(num,a,1)){
			cout<<"NO\n";
			continue;
		}
		if(!enc(den,b,-1)){
			cout<<"NO\n";
			continue;
		}
		
		bol=true;
		for(int k=0; k<10; k++){
			if(dig[k]){
				bol=false;
				break;
			}
		}
		if(bol){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
