#include <bits/stdc++.h>

#define ENDL '\n'
#define MOD 1000000007
#define INF 1000000000
#define MAX 10005
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    string ax;
    getline(cin, ax);
    
    map<string, ii> cont;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            getline(cin, ax);
            //cout << i << " " << ax << "\n";
            cont[ax].first++;
            cont[ax].second = i * 3 + j;
        }
    }

    vector<pair<ii, string> > act;
    for(auto e : cont){
        act.push_back({e.second, e.first});
        //cout << e.first << " " << e.second.first<< " " << e.second.second << "\n";
    }

    sort(act.begin(), act.end());

    int lim = max(0, (int) act.size() - k);
    for(int i = act.size() - 1; i >= lim; i--){
        cout << act[i].second << "\n";
    }

    return 0;
}
