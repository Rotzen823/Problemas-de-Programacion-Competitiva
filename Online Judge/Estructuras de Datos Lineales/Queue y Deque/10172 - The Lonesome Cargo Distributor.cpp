#include <bits/stdc++.h>
 
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--){
		int n, s, q, res = -2;
		cin >> n >> s >> q;

		stack<int> carrier;
		queue<int> plataforms[n + 1];
		int cargos = 0;
		for(int k = 1; k <= n; k++){
			int m, x;
			cin >> m;
			cargos += m;
			while(m--){
				cin >> x;
				plataforms[k].push(x);
			}
		}

		int x = 1;
		while(cargos){
			
			while(!carrier.empty()){
				if(carrier.top() == x){
					carrier.pop();
					cargos--;
					res++;
				}
				else if(plataforms[x].size() < q){
					plataforms[x].push(carrier.top());
					carrier.pop();
					res++;
				}
				else{
					break;
				}
			}

			while(carrier.size() < s && !plataforms[x].empty()){
				carrier.push(plataforms[x].front());
				plataforms[x].pop();
				res++;
			}

			x = x + 1 > n ? 1 : x + 1;
			res += 2;
		}

		cout << res << "\n";
	}

    return 0;
}