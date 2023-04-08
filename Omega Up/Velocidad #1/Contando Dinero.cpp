#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;

    cin >> n;

    int meses[n + 1];
    meses[0] = 0;

    for(int k = 1; k <= n; k++){
        cin >> meses[k];
        meses[k] += meses[k - 1];
    }

    int q;

    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << meses[b] - meses[a - 1] << "\n";
    }
 
    return 0;
}