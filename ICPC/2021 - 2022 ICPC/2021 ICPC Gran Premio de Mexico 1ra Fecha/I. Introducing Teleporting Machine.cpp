#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long ll;

ll num[MAX];
ll dis[MAX];

int main(){
	int n;
	ll c, t, sum = 0, res;

	cin >> n >> c >> t;

	for(int k = n - 1; k >= 0; k--){
		cin >> num[k];
	}

	for(int k = 1; k < n; k++){
		dis[k] = (num[k - 1] - num[k]) + dis[k - 1];
		sum += dis[k];
	}

	int st = 0;
	int x = n, y = n;
	res = sum;
	for(int k = 1; k < n; k++){
		if(st == k){
			continue;
		}
		
		ll dif = dis[k] - dis[st];
		if(dif <= c && t < dif){
			int r = (n - k);
			ll newSum = sum;
			newSum -= (dif * r);
			newSum += (t * r);
			if(newSum <= res ){
				res = newSum;
				x = n - k;
				y = n - st;
			}
		}
		else{
			st++;
			k--;
		}
	}

	if(res < sum){
		printf("%d %d %lld\n", x, y, res);
	}
	else{
		printf("-1\n");
	}

	return 0;
}