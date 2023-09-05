#include <bits/stdc++.h>
#define MAX 1000005
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int cont[MAX];
 
int sumD(int x){
    int res = 0;
    while(x){
        res += (x % 10);
        x /= 10;
    }
 
    return res;
}
 
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, k;
    cin >> n >> k;
 
    int maxF = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cont[x]++;
        maxF = max(x, maxF);
    }
    
    for(int i = maxF; i > 0; i--){
        if(k <= cont[i]){
            cout << sumD(i) << "\n";
            return 0;
        }
        k -= cont[i];
        int ax = i - sumD(i);
        cont[ax] += cont[i]; 
    }
 
    cout << "0\n";
    return 0;
}
