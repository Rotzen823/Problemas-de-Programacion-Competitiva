#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, K;
    cin >> n >> K;
    
    int res = 0;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;

        vi pilas(m + 1, 0);
        vi grind(m + 1, 0);

        for(int j = 1; j <= m; j++){
            cin >> pilas[j];
            vector<bool> ready(20, false);
            int mex = 0;
            for(int k = 0; k <= min(K, j - 1); k++){
                if(pilas[j - k] > (j - k)){
                    continue;
                }

                ready[grind[j - k - pilas[j - k]]] = true;
                while(ready[mex]){
                    mex++;
                }
            }
            grind[j] = mex;
        }

        res ^= grind[m];
    }   

    if(res){
        cout << "Alice can win.\n";
    }
    else{
        cout << "Bob will win.\n";
    }

    return 0;
}
