#include<bits/stdc++.h>

using namespace std;

int dir (int x1, int y1, int x2, int y2, int x3, int y3){
	int r = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	
	return r;
}

int main(){
	int n;
	int x,y,ax,ay,bx,by,cx,cy,t1,t2,t3;
	bool bol;
	cin>>n;
	for(int k=1; k<=n; k++){
		cin>>x>>y>>ax>>ay>>bx>>by>>cx>>cy;
		t1 = dir(x,y,ax,ay,bx,by);
		t2 = dir(x,y,bx,by,cx,cy);
		t3 = dir(x,y,cx,cy,ax,ay);
		
		if(t1 > 0 && t2 > 0 && t3 > 0){
			bol = true;
		}
		else if(t1 < 0 && t2 < 0 && t3 < 0){
			bol = true;
		}
		else{
			bol = false;
		}
		if(bol){
			cout<< "Case #"<<k<<": IN\n";
		}
		else{
			cout<< "Case #"<<k<<": OUT\n";
		}
	}
	return 0;
}
