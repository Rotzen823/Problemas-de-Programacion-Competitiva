#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vi a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> b(3, 0), res(3, 0);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        b[i % 3] += x;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int id = (i + j) % 3;
            res[id] += (a[i] * b[j]);
        }
    }

    cout << res[1] << " " << res[2] << " " << res[0] << "\n";


 
	return 0;
}
