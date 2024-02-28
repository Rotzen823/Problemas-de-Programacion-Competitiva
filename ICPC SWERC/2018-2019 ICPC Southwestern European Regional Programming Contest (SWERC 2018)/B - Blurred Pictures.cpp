#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
    cin >> n;

    vii segs(n);
    for(int i = 0; i < n; i++){
        cin >> segs[i].first >> segs[i].second;
    }

    int res = 1;

    int i = 0, j = 0;
    multiset<int> a, b;
    a.insert(segs[0].first);
    b.insert(segs[0].second);

    while(j < n){
        int l = *a.rbegin();
        int r = *b.begin();

        int w = (r - l) + 1;
        int h = (j - i) + 1;

        if(i < j && h >= w){
            a.erase(a.find(segs[i].first));
            b.erase(b.find(segs[i].second));
            i++;
        }
        else{
            j++;
            a.insert(segs[j].first);
            b.insert(segs[j].second);
        }

        res = max(res, min(w, h));
    }

    cout << res << "\n";


    return 0;
}
