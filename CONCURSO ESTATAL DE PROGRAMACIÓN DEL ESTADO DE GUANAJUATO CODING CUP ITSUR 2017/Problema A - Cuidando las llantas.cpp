#include<bits/stdc++.h>
#define MAX 5

using namespace std;

char llan[MAX],llan2[MAX];

int main(){
	cin>>llan>>llan2;
	if(llan[0]==llan2[0] && llan[1]==llan2[1] && llan[2]==llan2[2] && llan[3]==llan2[3]) cout<<"1\n";
	else if(llan[0]==llan2[2] && llan[1]==llan2[3] && llan[2]==llan2[1] && llan[3]==llan2[0]) cout<<"2\n";
	else if(llan[0]==llan2[1] && llan[1]==llan2[0] && llan[2]==llan2[3] && llan[3]==llan2[2]) cout<<"3\n";
	else if(llan[0]==llan2[3] && llan[1]==llan2[2] && llan[2]==llan2[0] && llan[3]==llan2[1]) cout<<"4\n";
	else cout<<"-1\n";
}
