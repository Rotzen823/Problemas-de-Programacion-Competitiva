#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    int n;
    cin >> n;

    int res = 0;
    for(int k = 0; k < n; k++){
        char ax;
        cin >> ax;
        if(ax != '6' && ax != '8' && ax != '0'){
            res++;
        }
    }

    cout << res << "\n";
	return 0;
}
