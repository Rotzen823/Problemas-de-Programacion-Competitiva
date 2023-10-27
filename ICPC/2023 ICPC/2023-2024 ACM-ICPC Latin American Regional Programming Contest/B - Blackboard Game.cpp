#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    map<int, int> nums;

    for(int k = 0; k < 3 * n; k++){
        int x;
        cin >> x;
        nums[x]++;
    }

    for(auto a : nums){
        if(a.second % 3 != 0){
            cout << "Y\n";
            return 0;
        }
    }

    cout << "N\n";
    return 0;
}
