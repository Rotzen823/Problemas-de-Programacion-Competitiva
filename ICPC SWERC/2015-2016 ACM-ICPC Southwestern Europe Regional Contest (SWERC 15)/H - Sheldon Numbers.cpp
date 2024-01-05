#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long int ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <ll> vi;
 
int solve(ll a, ll b){
 
    set<ll> nums;
    for(int k = 1; k < 64; k++){
        for(int j = 0; j < 64; j++){
            int n = 0, m = 0;
            bool flag = true;
 
            ll x = 0; //4809
            while((n * k + m * j) < 64){
                nums.insert(x);
                if(flag){
                    x <<= k;
                    x += ((1ULL << k) - 1);
                    flag = false;
                    n++;
                }
                else{
                    x <<= j;
                    flag = true;
                    m++;
                }
            }
        }
    }
 
    nums.erase(0);
 
    int res = 0;
    for(ll x : nums){
        if(x > b){
            break;
        }
        if(x >= a){
            res++;
        }
    }
 
    return res;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll a, b;
    //ll a = 0, b = (1ULL << (63)) - 1;
    cin >> a >> b;
 
    //cout << solve(b) << " " << solve(a - 1) << "\n";
    int res = solve(a, b);
 
    cout << res << "\n";
    
	return 0;
}
