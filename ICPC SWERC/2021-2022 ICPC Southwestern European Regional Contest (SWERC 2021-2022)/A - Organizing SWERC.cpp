#include <bits/stdc++.h>
 
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000009
#define MAX 10000
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int diff[11] = {0};
        int pen = 0;
        while(n--){
            int a, b;
            cin >> a >> b;
            if(!diff[b]){
                pen++;
            }
            diff[b] = max(diff[b], a);
        }
 
        if(pen == 10){
            int sum = 0;
            for(int k = 1; k <= 10; k++){
                sum += diff[k];
            }
            cout << sum << "\n";
        }
        else{
            cout << "MOREPROBLEMS\n";
        }
    }
 
    return 0;
}
