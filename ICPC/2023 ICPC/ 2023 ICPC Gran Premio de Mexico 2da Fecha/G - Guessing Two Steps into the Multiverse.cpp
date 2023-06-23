#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;
    vi  rows, columns;
    rows.assign(n + 1, 0);
    columns.assign(n + 1, 0);

    ll sum = 0, maxT = 0, maxR = 0, maxC = 0;
    while(t--){
        int a, b;
        cin >> a >> b;

        sum += (columns[b] + rows[a]);
        if(a == b){
            sum++;
        }

        columns[a]++;
        rows[b]++;

        maxR = max(rows[b], maxR);
        maxC = max(columns[a], maxC);

        maxT = max({maxT, maxR + maxC, columns[a] + rows[a] + 1, columns[b] + rows[b] + 1});

        cout << sum << " " << maxT << "\n";
    }

	return 0;
}
