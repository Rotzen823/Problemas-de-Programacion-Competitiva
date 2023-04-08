#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   int n;
   
   while(scanf("%d", &n) != EOF){
   		vector<bool> difs(n, false);
   		
   		int x, ax, dif;
   		bool jolly = true;
   		cin >> ax;
   		
   		for(int k = 1; k < n; k++){
   			cin >> x;
   			dif = x - ax;
   			ax = x;
   			
   			if(!jolly){
   				continue;
			}
   			
   			if(dif < 0){
   				dif = -dif;
			}
			
			if(dif == 0 || dif >= n){
				jolly = false;
				continue;
			}
			
			if(difs[dif]){
				jolly = false;
				continue;
			}
			
			difs[dif] = true;
		}
		
		if(jolly){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}
   }
   
   return 0; 
}
