#include<bits/stdc++.h>

using namespace std;

int main(){
	string face = "facebook";
	string pal;
	int n,l,c;
	cin>>n;
	for(int k=1; k<=n; k++){
		cin>>pal;
		c=0;
		l=0;
		while(pal[c] != '\0'){
			if(pal[c] == face[l]){
				l++;
			}
			c++;
		}
		if(l >= 8){
			cout<< "Case #"<<k<<": YES\n";
		}
		else{
			cout<< "Case #"<<k<<": NO\n";
		}
	}
	return 0;
}
