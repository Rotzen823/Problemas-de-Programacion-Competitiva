#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    if(n > m){
        swap(n, m);
    }
 
    for(int k = n + 1; k <= (m + 1); k++){
        cout << k << "\n";
    }
    
	return 0;
}
