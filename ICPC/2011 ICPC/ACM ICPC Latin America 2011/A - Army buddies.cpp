#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s, b;

    while(cin >> s >> b){
        if(s == 0 && b == 0){
            break;
        }

        ii soldados[s + 2];

        for(int k = 1; k <= s; k++){
            soldados[k] = ii(k == 1 ? -1 : k - 1, k == s ? -1 : k + 1);
        }

        while(b--){
            int l, r;
            cin >> l >> r;
            int al = soldados[l].first;
            int ar = soldados[r].second;
            if(al == -1){
                cout << "* ";
            }
            else{
                cout << al << " ";
            }

            if(ar == -1){
                cout << "*\n";
            }
            else{
                cout << ar << "\n";
            }

            if(al == -1 && ar == -1){
                continue;
            }

            if(al != -1){
                soldados[al].second = ar;
            }
            
            if(ar != -1){
                soldados[ar].first = al;
            }
        }
        cout << "-\n";
    }
    
    return 0;
}
