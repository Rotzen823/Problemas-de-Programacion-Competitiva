#include <bits/stdc++.h>
 
#define ENDL '\n'
#define MAX 1005
#define MOD 1000000007
#define INF 1000000000
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
 
int main(){
 
    int n;
    cin >> n;
    char c;
    int x,y,res=0,ans=0;
    cin >> c >> x >> c >> y;
    res+=y;
    
    for(int i=0;i<n;i++){
        cin >> c >> x >> c >> y;
        res+=y;
        res%=100;
        
        if(res!=0){
            ans++;
        }
    }
      
    cout<<ans<<ENDL;
    
 
    return 0;
}
