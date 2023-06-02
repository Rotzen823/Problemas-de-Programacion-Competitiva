#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, l;
    cin >> n >> k >> l;

    int res = (n * k) / l;

    if((n * k) % l != 0){
        res++;
    }

    cout << res << "\n";     
    return 0;
}
