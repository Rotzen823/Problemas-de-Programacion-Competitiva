#include <bits/stdc++.h>

using namespace std;

bool anagrama(string a, string b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return a == b;
}

string A, B;
stack<char> pila;
string res;
int n;
void back_tracking(int a, int b){
	if(b == n){
		cout << res << "\n";
		return;
	}

	if(a < n){
		pila.push(A[a]); res.push_back(' '); res.push_back('i');
		back_tracking(a + 1, b);
		pila.pop(); res.pop_back(); res.pop_back();
	}

	if(pila.empty()){
		return;
	}

	if(pila.top() == B[b]){
		char x = pila.top();
		pila.pop(); res.push_back(' '); res.push_back('o');
		back_tracking(a, b + 1);
		pila.push(x); res.pop_back(); res.pop_back();
	}
}

int main(){

	while(cin >> A >> B){
		printf("[\n");
		if(anagrama(A, B)){
			n = A.length();
			pila.push(A[0]); res.push_back('i');
			back_tracking(1, 0);
			pila.pop(); res.pop_back();
		}
		printf("]\n");
	}
	
	return 0;
}