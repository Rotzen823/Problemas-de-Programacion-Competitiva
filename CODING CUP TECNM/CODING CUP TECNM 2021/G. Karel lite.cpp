#include<bits/stdc++.h>
#define MAX 20

using namespace std;

int mat[MAX][MAX];


int main(){
	string ord,dir;
	
	int x,y,bep=0,n,xM,yM;
	bool sintax=false, run=false;
	cin>>x>>y>>bep>>dir>>n;
	
	if(dir[0]=='N'){
		xM=0, yM=1;
	}
	else if(dir[0]=='W'){
		xM=-1, yM=0;
	}
	else if(dir[0]=='S'){
		xM=0, yM=-1;
	}
	else{
		xM=1, yM=0;
	}
	
	while(n--){
		cin>>ord;
		if(!ord.compare("move();")){
			x+=xM;
			y+=yM;
			if(x<1 || x>MAX || y<1 || y>MAX){
				run=true;
				break;
			}
		}
		else if(!ord.compare("turnleft();")){
			int temp;
			if(!xM) yM=-yM;
			temp=xM;
			xM=yM;
			yM=temp;
		}
		else if(!ord.compare("putbeeper();")){
			if(bep<=0){
				run=true;
				break;
			}
			mat[y-1][x-1]++;
			bep--;
		}
		else if(!ord.compare("pickbeeper();")){
			if(mat[y-1][x-1]<=0){
				run=true;
				break;
			}
			mat[y-1][x-1]--;
			bep++;
		}
		else{
			sintax=true;
			break;
		}
	}
	
	while(n>0){
		cin>>ord;
		n--;
	}
	
	if(run){
		cout<<"Run time error\n";
	}
	else if(sintax){
		cout<<"Sintax error\n";
	}
	else{
		cout<<x<<" "<<y<<"\n";
		if(yM==1){
			cout<<"North\n";
		}
		else if(xM==-1){
			cout<<"West\n";
		}
		else if(yM==-1){
			cout<<"South\n";
		}
		else{
			cout<<"East\n";
		}
		cout<<bep<<"\n";
		for(int k=MAX-1; k>=0; k--){
			for(int j=0; j<MAX; j++){
				if(!mat[k][j]){
					cout<<".";
				} 
				else{
					cout<<mat[k][j];
				}
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
