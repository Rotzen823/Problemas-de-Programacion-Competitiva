#include <bits/stdc++.h>
 
using namespace std;

char espejo[] = {'1', 'S', 'E', 'a', 'Z', 'a', 'a', '8', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
				'A', 'a', 'a', 'a', '3', 'a', 'a', 'H', 'I', 'L', 'a', 'J', 'M', 'a', 'O', 'a',
				'a', 'a', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};

bool palindromo(string s){
	int n = s.length();

	for(int k = 0, j = n - 1; k <= j; k++, j--){
		if(s[k] != s[j]){
			return false;
		}
	}

	return true;
}

bool mirror(string s){
	int n = s.length();

	for(int k = 0, j = n - 1; k <= j; k++, j--){
		if(espejo[s[k] - '1'] != s[j]){
			return false;
		}
	}

	return true;
}

int main() {
    string op;

	while(cin >> op){
		bool palin, espej;
		palin = palindromo(op);
		espej = mirror(op);
		
		cout << op;

		if(palin && espej){
			printf(" -- is a mirrored palindrome.\n\n");
		}
		else if(palin){
			printf(" -- is a regular palindrome.\n\n");
		}
		else if(espej){
			printf(" -- is a mirrored string.\n\n");
		}
		else{
			printf(" -- is not a palindrome.\n\n");
		}
	}
    
    return 0;
}