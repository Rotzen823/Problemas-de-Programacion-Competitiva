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

bool palindromo2(string s, int c){
	int n = s.length();
	if(n == 1){
		return true;
	}

	for(int k = 0, j = 0; k < n; k++, j += c){
		j = j % (n - 1);
		//printf("%d %c %d %c\n", k, s[k], j, s[j]);
		if(s[k] != s[j]){
			return false;
		}
	}

	return true;
}

int main() {
	int n;
    string op;
	char ax;
	scanf("%d", &n);
	scanf("%c", &ax);
	for(int i = 1; i <= n; i++){
		op = "";
		getline(cin, op);
		string senten = "";
		for(char x : op){
			if(x >= 'a' && x <= 'z'){
				senten += x;
			}
		}

		int lar = senten.length();
		int res = (int) sqrt(lar);

		printf("Case #%d:\n", i);
		//printf("%d %d %d\n", res, palindromo(senten), palindromo2(senten, res));
		if((lar % res) == 0 && (lar / res) == res){
			if(palindromo(senten) && palindromo2(senten, res)){
				printf("%d\n", res);
				continue;
			}
		}

		printf("No magic :(\n");

	}
    
    return 0;
}