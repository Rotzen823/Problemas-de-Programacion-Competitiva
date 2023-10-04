#include <bits/stdc++.h>
 
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000009
#define MAX 200005
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

double iceD[MAX];
ll genteH[MAX];
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;

    genteH[0] = 0;
    for(int k = 1; k <= n; k++){
        cin >> genteH[k];
        genteH[k] += genteH[k - 1];
    }

    for(int k = 0; k < m; k++){
        cin >> iceD[k];
    }

    sort(iceD, iceD + m);

    ll res = 0;
    for(int k = 0; k < n; k++){
        double d = (double) k * 100;
        int i = lower_bound(iceD, iceD + m, d) - iceD - 1;

        double a = d - 0.5;
        double b = 0;
        if(i < 0){
            b = iceD[0] - 1;
        }
        else if(i == m - 1){
            b = (double) n * 100 - 100;
        }
        else{
            b = min(iceD[i + 1] - 1, a + (iceD[i + 1] - iceD[i]) / 2);
            //cout << iceD[k + 1] << " " << iceD[k] << " ";
        }

        int idB = (int) b / 100;
        if(b >= 0){
            idB++;
        }
        if(idB > n){
            idB = n;
        }
        ll gen = genteH[idB] - genteH[k];
        //cout << b << " " << idB << " " << gen << "\n";
        res = max(gen, res);
    }

    cout << res << "\n";
    return 0;
}
