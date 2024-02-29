#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << (fixed) << setprecision(2);

	int n;
    cin >> n;

    string names[n];
    double calf[n], sum = 0;

    for(int i = 0; i < n; i++){
        cin >> names[i] >> calf[i];
        sum += calf[i];
    }

    double maxC = sum + (0.49 * n);
    double minC = sum - (0.5 * n);

    if(maxC < 100.0 || minC > 100.0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        double a = max(calf[i] - 0.5, 100.0 - (maxC - calf[i] - 0.49));
        double b = min(calf[i] + 0.49, 100.0 - (minC - calf[i] + 0.5));

        if(a < 0.0){
            a = 0.0;
        }
        if(b > 100.0){
            b = 100.0;
        }
        cout << names[i] << " " << a << " " << b << "\n";
    }

    return 0;
}
