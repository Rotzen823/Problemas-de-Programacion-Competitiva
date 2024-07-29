#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define INF 1000000000
#define MOD 1000000009
#define fi first
#define se second
#define ENDL '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int n;
    int sum = 0;
    cin >> n;

    vii exams(n);
    for(int i = 0; i < n; i++){
        cin >> exams[i].fi;
        exams[i].se = i;

        sum += exams[i].fi;
    }

    sort(ALL(exams));

    if(2 * exams.back().fi > sum){
        cout << "impossible\n";
        return 0;
    }

    cout << exams.back().se + 1;
    for(int i = n - 2; i >= 0; i--){
        cout << ' ' << exams[i].se + 1;
    }
    cout << ENDL;
    
    return 0;
}
