#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   int n;
   
   scanf("%d",&n);
   
   while(n--){
   		int x, k;
   		scanf("%d %d", &x, &k);
   		
   		printf("%d\n", k^(k >> 1));
   }
   
   return 0; 
}
