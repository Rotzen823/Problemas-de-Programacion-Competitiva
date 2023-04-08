#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int n, m;

	while(scanf("%d %d", &n, &m), !(n == 0 && m == 0)){
		unordered_set<int> cds;
		while(n--){
			int x;
			scanf("%d", &x);
			cds.insert(x);
		}

		int res = 0;
		while(m--){
			int x;
			scanf("%d", &x);

			if(cds.count(x)){
				res++;
			}
		}

		printf("%d\n", res);
	}

    return 0;
}