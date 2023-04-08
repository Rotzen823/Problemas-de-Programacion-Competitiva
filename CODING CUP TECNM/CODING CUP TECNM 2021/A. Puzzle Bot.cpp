#include<bits/stdc++.h>
#define MAXS 50
#define MAX 105

using namespace std;

char ss[MAXS],ssN[MAXS];
char si[MAXS];
int n,m;

int ver(int lar,int x,int y){
	int c=0;
	char let;
	for(int k=0; k<lar; k++){
		let=si[k];
		switch(let){
			case 'U':
				ssN[c++]='U';
				x--;
				break;
			case 'D':
				ssN[c++]='D';
				x++;
				break;
			case 'L':
				ssN[c++]='L';
				y--;
				break;
			case 'R':
				ssN[c++]='R';
				y++;
				break;
			case 'Z':
				c--;
				if(c<0) return -1;
				switch(ssN[c-1]){
					case 'U':
					x++;
					break;
				case 'D':
					x--;
					break;
				case 'L':
					y++;
					break;
				case 'R':
					y--;
					break;
				}
				break;
			case 'X':
				ssN[c++]='X';
				break;
		}
	}
	ssN[c]='\0';
	if(x<=0 || x>n || y<=0 || y>m) return -1;
	return c;
}

int main(){
	int x,y,lar,c=0;
	char let;
	cin>>n>>m;
	cin>>x>>y;
	cin>>ss;
	getc(stdin);
	cin>>si;
	lar=strlen(si);
	c=ver(lar,x,y);
	if(c==-1){
		cout<<"ERROR\n";
	}
	else if(strcmp(ss,ssN)==0){
		cout<<"WIN";
	}
	else{
		cout<<"LOST";
	}
	return 0;
}
