#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    map<string, bool> apodos;
    int n;
    cin >> n;

    int res = 0;
    while(n--){
        int m;
        cin >> m;
        string ax, name;
        ax.assign(m, ' ');
        for(int k = 0; k < m; k++){
            cin >> name;
            ax[k] = name[0];
        }
        if(apodos.count(ax)){
            if(apodos[ax]){
                res--;
                apodos[ax] = false;
            }
        }
        else{
            apodos[ax] = true;
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}
