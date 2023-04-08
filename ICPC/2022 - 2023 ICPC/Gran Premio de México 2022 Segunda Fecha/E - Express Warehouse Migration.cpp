#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int c = n / m;

    if(n % m != 0){
        c++;
    }

    printf("%d\n", c);

	return 0;
}