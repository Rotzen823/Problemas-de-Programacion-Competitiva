#include <bits/stdc++.h>

#define fi first
#define se second
#define ENDL '\n'
#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100005
#define MAX 1005 

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int aR[MAX], aT[MAX];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int d, r, t;
    cin >> d >> r >> t;

    int lim = 0;
    for(int i = 4; i < 1000; i++){
        aR[i] = i + aR[i - 1];
        if(aR[i] >= r){
            lim = i;
            break;
        }
    }

    for(int i = 3; i <= lim; i++){
        aT[i] = i + aT[i - 1];
    }

    for(int i = 4 + d - 1; i <= lim; i++){
        int dif = r - aR[i];
        //cout << aR[i] << " " << aT[i - d + 1] << "\n";
        if(aT[i - d] == t + dif){
            cout << dif << "\n";
            return 0;
        }
    }


    return 0;
}
