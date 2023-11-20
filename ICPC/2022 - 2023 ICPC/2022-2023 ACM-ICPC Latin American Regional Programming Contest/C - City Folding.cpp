#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll p, h;
    cin >> n >> p >> h;

    bool moves[n];
    for(int k = n - 1; k >= 0; k--){
        moves[k] = (h > (1LL << k));
        if(h > (1LL << k)){
            h -= (1LL << k);
            h = (1LL << k) - h + 1;
        }
    }

    for(int k = 0; k < n; k++){
        if(moves[k]){
            if(p > (1LL << (n - k - 1))){
                cout << 'R';
                p -= (1LL << (n - k - 1));
            }
            else{
                cout << 'L';
            }
            p = (1LL << (n - k - 1)) - p + 1;
        }
        else{
            if(p > (1LL << (n - k - 1))){
                cout << 'L';
                p -= (1LL << (n - k - 1));
            }
            else{
                cout << 'R';
            }
        }
    }   
    cout << '\n';
    
    return 0;
}
