#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   int n;
   
   while(scanf("%d", &n) != EOF){
   		int m = 0;
   		
   		for(int k = 0; k < 4; k++){
   			m = (m << 8) ^ ((n >> (8 * k)) & 255);
		}
		
		printf("%d converts to %d\n",n,m);
   }
   
   return 0; 
}
