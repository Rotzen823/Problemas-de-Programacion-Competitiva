#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a;
    cin >> n >> m >> a;

    int res = (n + 1) * (m + 1);
    res /= (a + 1);
    res--;

    cout << res << "\n";
	
    return 0;
}
