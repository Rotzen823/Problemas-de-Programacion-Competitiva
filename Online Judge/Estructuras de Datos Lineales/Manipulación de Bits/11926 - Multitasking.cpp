#include <bits/stdc++.h>
#define MAX 1000005
 
using namespace std;

bitset<MAX> calendar;

bool conflict(int s, int e){
	for(int k = s + 1; k <= e; k++){
		if(calendar[k]){
			return true;
		}
		else{
			calendar.set(k);
		}
	}
	return false;
}
 
int main() {
   int n,m;
   
   while(scanf("%d %d", &n, &m), !(n == 0 && m == 0)){
   		int s, e, r;
   		bool conf = false;
   		calendar.reset();
   		while(n--){
			scanf("%d %d", &s, &e);
			if(!conf){
				if(conflict(s,e)){
					conf = true;
				}
			}  			
		}
		
		while(m--){
			scanf("%d %d %d", &s, &e, &r);
			
			while(s < 1000000 && !conf){
				if(conflict(s,e)){
					conf = true;
				}
				
				s += r;
				
				e = min(e + r, 1000000);
			}
		}
		
		if(conf){
			printf("CONFLICT\n");
		}
		else{
			printf("NO CONFLICT\n");
		}
   }
   
   return 0; 
}
