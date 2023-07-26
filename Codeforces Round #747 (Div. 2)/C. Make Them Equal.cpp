#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,num,div;
	bool bien;
	char a;
	string s;
	cin>>n;
	while(n--){
		bien=true;
		div=0;
		cin>>num>>a>>s;
		for(int k=0; k<num; k++){
			if(s[k]==a) div=k+1;
			else bien=false;
		}
		
		if(bien){
			cout<<"0\n";
		}
		else if(div>num/2) cout<<"1\n"<<div<<"\n";
		else cout<<"2\n"<<num-1<<" "<<num<<"\n";
	}
}
