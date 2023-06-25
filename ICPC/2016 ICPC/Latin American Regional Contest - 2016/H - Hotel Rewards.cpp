#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    priority_queue<int, vi, greater<int> > q;
    int c = 0, sum = 0;

    for(int i = 0; i < n; i++){
        if(c >= k){
            q.push(nums[i]);
            c -= k;
            continue;
        }

        if(!q.empty() && nums[i] > q.top()){
            sum += q.top(); q.pop();
            q.push(nums[i]);
        }
        else{
            sum += nums[i];
        }
        c++;
    }

    cout << sum << "\n";

	return 0;
}
