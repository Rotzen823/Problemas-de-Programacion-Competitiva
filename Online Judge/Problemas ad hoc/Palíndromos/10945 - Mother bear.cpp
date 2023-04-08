#include <bits/stdc++.h>
 
using namespace std;

bool palindromo(string s){
	int n = s.length();

	for(int k = 0, j = n - 1; k <= j; k++, j--){
		if(s[k] != s[j]){
			return false;
		}
	}

	return true;
}

int main() {
    string op;

	while(getline(cin, op), !(op == "DONE")){
		string senten = "";
		for(char x : op){
			if(x >= 'A' && x <= 'Z'){
				senten += x;
			}
			else if(x >= 'a' && x <= 'z'){
				senten += (x - 32);
			}
		}

		if(palindromo(senten)){
			printf("You won't be eaten!\n"); 
		}
		else{
			printf("Uh oh..\n");
		}
	}
    
    return 0;
}