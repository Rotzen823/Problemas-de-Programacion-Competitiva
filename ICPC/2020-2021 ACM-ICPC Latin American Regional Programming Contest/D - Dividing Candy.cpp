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
 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
 
    int n;
    cin >> n;
 
    if(n == 1){
        cout << "N\n";
        return 0;
    }
 
    priority_queue<int, vi, greater<int> > pq;
 
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }
 
    int sum = 0;
    
 
    while(!pq.empty()){
        int x = pq.top(); pq.pop();
        if(pq.empty()){
            sum++;
            break;
        }
        int ax = pq.top(); pq.pop();
        if(ax == x){
            pq.push(ax + 1);
        }
        else{
            pq.push(ax);
            sum++;
        }
    }
 
    if(sum <= 2){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }
 
    return 0;
}
