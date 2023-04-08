#include <bits/stdc++.h>
 
using namespace std;

bool miComparacion(char a, char b){
	char x = a, y = b;
	if(a >= 'a'){
		x = a - 32;
	}
	if(b >= 'a'){
		y = b - 32;
	}

	if(x == y){
		return a < b;
	}

	return x < y;
}

int main() {
	int n;
	scanf("%d", &n);

	while(n--){
		string s;
		cin >> s;

		sort(s.begin(), s.end(), miComparacion);
		do{
			cout << s << "\n";
		}while(next_permutation(s.begin(), s.end(), miComparacion));
	}
    
    return 0;
}