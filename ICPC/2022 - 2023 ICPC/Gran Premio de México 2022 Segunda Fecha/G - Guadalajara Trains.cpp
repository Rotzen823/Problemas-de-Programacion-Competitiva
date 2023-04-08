#include<bits/stdc++.h>
#define MAX 1000005

using namespace std;

typedef long long ll;

pair<ll, ll> t1[MAX], t2[MAX];
ll dist[MAX];
ll wait[MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int k = 0; k < n - 1; k++){
        scanf("%lld", &dist[k]);
    }

    for(int k = 0; k < n; k++){
        scanf("%lld", &wait[k]);
    }

    t1[0].first = 0;
    t1[0].second = wait[0];
    for(int k = 1; k < n; k++){
        t1[k].first = t1[k - 1].second + dist[k - 1];
        t1[k].second = t1[k].first + wait[k];
    }

    t2[n - 1].first = 0;
    t2[n - 1].second = wait[n - 1];
    for(int k = n - 2; k >= 0; k--){
        t2[k].first = t2[k + 1].second + dist[k];
        t2[k].second = t2[k].first + wait[k];
    }

    ll res = 0;
    for(int k = 0; k < n; k++){
        if(t1[k].first > t2[k].first){
            if(t1[k].first < t2[k].second){
                res = t2[k].second - t1[k].first;
                break;
            }
        }
        else{
            if(t2[k].first < t1[k].second){
                res = t1[k].second - t2[k].first;
                break;
            }
        }
    }

    printf("%lld\n", res);

	return 0;
}