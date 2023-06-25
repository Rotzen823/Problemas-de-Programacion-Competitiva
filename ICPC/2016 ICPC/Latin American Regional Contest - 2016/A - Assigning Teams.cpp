#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int nums[4];
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

    sort(nums, nums + 4);

    cout << abs((nums[0] + nums[3]) - (nums[1] + nums[2])) << "\n";

	return 0;
}
