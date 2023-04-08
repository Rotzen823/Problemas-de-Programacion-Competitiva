#include<bits/stdc++.h>

using namespace std;

int main(){	
	int c;
	cin >> c;

	while(c--){
		int capc, m, res = 0, cargo = 0;
		cin >> capc >> m;
		
		capc *= 100;

		int lado = 0;
		queue<int> colas[2];
		while(m--){
			int x;
			string lad;

			cin >> x >> lad;

			if(lad == "left"){
				colas[0].push(x);
			}
			else{
				colas[1].push(x);
			}
		}

		while(!colas[0].empty() || !colas[1].empty()){
			if(colas[lado].empty()){
				res++;
				cargo = 0;
				lado = (lado + 1) % 2;
				continue;
			}

			if(cargo + colas[lado].front() <= capc){
				cargo += colas[lado].front();
				colas[lado].pop();
			}
			else{
				res++;
				cargo = 0;
				lado = (lado + 1) % 2;
			}
		}

		if(cargo){
			res++;
		}

		cout << res << "\n";
	}
	
	return 0;
}