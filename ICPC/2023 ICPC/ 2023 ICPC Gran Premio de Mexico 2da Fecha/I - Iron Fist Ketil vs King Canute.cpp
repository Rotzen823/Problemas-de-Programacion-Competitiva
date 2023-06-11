#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    int n, m, k;

    cin >> n >> m >> k;

    if(n / k >= m){
        cout << "Iron fist Ketil";
    }
    else{
        cout << "King Canute\n";
    }

	return 0;
}
