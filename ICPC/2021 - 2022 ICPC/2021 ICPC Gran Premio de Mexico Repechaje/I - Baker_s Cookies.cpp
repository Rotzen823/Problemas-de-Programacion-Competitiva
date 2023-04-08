#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, t, c, b, w, r, g , v;
	cin>>n;
	while(n--){
		cin>>t>>c>>b>>w>>r>>g;
		
		v = c * b;
		if(t <= v ){
			cout<<t<<"\n";
			continue;
		}
		t -= v;
		if(t <= r){
			cout<<v + (t*c)<<"\n";
			continue;
		}
		
		cout<<"Don't even try!\n";
	}
}
