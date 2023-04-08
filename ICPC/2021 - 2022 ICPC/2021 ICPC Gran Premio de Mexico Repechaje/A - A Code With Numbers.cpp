#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, c = 0;
	string text;
	char a;
	cin>>n;
	scanf("%c",&a);
	while(n--){
		getline(cin,text);
		c = 0;
		while(text[c] != '\0'){
			switch(text[c]){
				case '1':
					text[c] = 'I';
					break;
				case '2':
					text[c] = 'Z';
					break;
				case '3':
					text[c] = 'E';
					break;
				case '4':
					text[c] = 'A';
					break;
				case '5':
					text[c] = 'S';
					break;
				case '6':
					text[c] = 'G';
					break;
				case '7':
					text[c] = 'T';
					break;
				case '8':
					text[c] = 'B';
					break;
				case '9':
					text[c] = 'P';
					break;
				case '0':
					text[c] = 'O';
					break;
			}
			c++;
		}
		cout<<text<<"\n";
	}
	return 0;
}
