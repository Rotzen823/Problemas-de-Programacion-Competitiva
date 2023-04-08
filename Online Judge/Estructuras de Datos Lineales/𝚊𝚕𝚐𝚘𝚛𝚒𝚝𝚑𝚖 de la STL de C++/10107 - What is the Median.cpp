#include <bits/stdc++.h>
 
using namespace std;

int main() {
    vector<int> nums;
    int x, c = 0;

    while(scanf("%d", &x) != EOF){
        nums.push_back(x);
        c++;
        if(c & 1){
            nth_element(nums.begin(), nums.begin() + (c / 2), nums.end());
            printf("%d\n", nums[c / 2]);
        }
        else{
            nth_element(nums.begin(), nums.begin() + (c / 2), nums.end());
            int ax = nums[c / 2];
            nth_element(nums.begin(), nums.begin() + ((c / 2) - 1), nums.end());
            int res = (ax + nums[(c / 2) - 1]) / 2;
            printf("%d\n", res);
        }
    }
    
    return 0;
}