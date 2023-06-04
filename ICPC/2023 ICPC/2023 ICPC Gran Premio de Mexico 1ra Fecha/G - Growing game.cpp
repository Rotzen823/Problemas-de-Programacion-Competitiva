#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;

    cin >> n;

    if(n == 1){
        cout << "Jane\n";
    }

    int inc = 2;
    n--;
    while(n > 0){
        if(n - inc <= 0){
            cout << "John\n";
            break;
        }
        n -= inc;

        if(n - inc <= 0){
            cout << "Jane\n";
            break;
        }
        n -= inc;
        inc++;
    }

	return 0;
}
