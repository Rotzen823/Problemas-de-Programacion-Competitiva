#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m, x, y, r, s;

    cin >> n >> m >> x >> y >> r >> s;

    x = (x + r) % n;
    x = (x + n) % n;

    y = (y + s) % m;
    y = (y + m) % m;

    cout << x << " " << y << "\n";
 
    return 0;
}