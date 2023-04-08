#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
    bool bandera = false;
	
	while(scanf("%d", &n), !(n == 0)){

		while(scanf("%d", &m), !(m == 0)){
			int orden[n];
			orden[0] = m;
			
			for(int k = 1; k < n; k++){
				scanf("%d", &orden[k]);
			} 
			
			int st = 1;
			stack<int> station;
			bool ban = true;
			for(int k = 0; k < n; k++){
				while(orden[k] > st){
					station.push(st);
					st++;
				}
				
				if(orden[k] == st){
					st++;
					continue;
				}
				
				if(station.empty()){
					ban = false;
					break;
				}
				
				if(station.top() == orden[k]){
					station.pop();
				}
				else{
					ban = false;
					break;
				}
			}
			
			if(ban){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}

        printf("\n");
	}
	
	return 0;
}