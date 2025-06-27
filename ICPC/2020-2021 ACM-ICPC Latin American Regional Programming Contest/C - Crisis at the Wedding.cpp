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

    int n, p, may = 0;
    cin >> n;
    ll num[n], num2[n], sum = 0;

    for(int k = 0; k < n; k++){
        cin >> num[k];
        sum += num[k];
        if(num[k] > num[may]){
            may = k;
        }
    }

    sum /= n;

    int neg = 0;
    for(int k = 0; k < n; k++){
        num[k] -= sum;
        num2[k] = num[k];
        if(num[k] < 0){
            neg++;
        }
    }

    queue<int> q;
    q.push(may);

    int i = (may + 1) % n;
    ll res = 0;
    int neg2 = neg;
    while(neg){
        if(num[i] == 0){
            i++;
            i %= n;
            continue;
        }

        if(num[i] > 0){
            q.push(i);
            i++;
            i %= n;
            continue;
        }

        if(q.empty()){
            i++;
            i %= n;
            continue;
        }

        ll x = -num[i];
        ll ax = num[q.front()];

        ll dif = 0;
        if(i > q.front()){
            dif = (ll) i - q.front();
        }
        else{
            dif = (ll) (n - q.front()) + i;
        }
        if(ax > x){
            num[i] = 0;
            num[q.front()] -= x;
            res += (x * dif);
            neg--; 
        }
        else{
            num[q.front()] = 0;
            num[i] += ax;
            q.pop();
            res += (ax * dif);
            if(ax == x){
                neg--; 
                i++;
                i %= n;
            }
        }
    }

    i = (may - 1 + n) % n;
    ll cost = 0;
    while(neg2){
        if(num2[i] == 0){
            i += (n - 1);
            i %= n;
            continue;
        }

        if(num2[i] > 0){
            q.push(i);
            i += (n - 1);
            i %= n;
            continue;
        }

        if(q.empty()){
            i += (n - 1);
            i %= n;
            continue;
        }

        ll x = -num2[i];
        ll ax = num2[q.front()];

        ll dif = 0;
        if(i < q.front()){
            dif = (ll) q.front() - i;
        }
        else{
            dif = (ll) (n - i) + q.front();
        }
        
        if(ax > x){
            num2[i] = 0;
            num2[q.front()] -= x;
            cost += (x * dif);
            neg2--; 
        }
        else{
            num2[q.front()] = 0;
            num2[i] += ax;
            q.pop();
            cost += (ax * dif);
            if(ax == x){
                neg2--; 
                i += (n - 1);
                i %= n;
            }
        }
    }

    cout << min(res, cost) << "\n";
    

    return 0;
}
