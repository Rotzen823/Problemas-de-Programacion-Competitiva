#include <bits/stdc++.h>

#define INF 1000000000
#define MOD 1000000007
#define MAX 30
#define fi first
#define se second
#define ENDL '\n'

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

typedef struct Team{
    string c;
    int s;
    int i;

    bool operator<(Team t) const { 
        return s > t.s || (s == t.s && i < t.i);
    } 
}Team;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<Team> teams;
    for(int i = 0; i < n; i++){
        string c;
        int p, e1, e2, e3, e4, e5, e6;
        cin >> c >> p >> e1 >> e2 >> e3 >> e4 >> e5 >> e6;

        int s = (p * 10) + (e1 + e2 + e3 + e4 + e5 + e6) -
            (max({e1, e2, e3, e4, e5, e6}) + min({e1, e2, e3, e4, e5, e6}));
        
        teams.push_back({c, s, i});
    }

    sort(teams.begin(), teams.end());

    int c = 0;
    int ax = -1;
    bool flag = false;
    for(int i = 0; i < min(n, 1000); i++){
        if(teams[i].s != ax){
            c++;
        }

        if(c == 2 && i <= 2){
            flag = true;
        }

        if(c == 1 || (c == 2 && flag) || i < 3){
            cout << teams[i].c << " " << teams[i].s << ENDL;
        }
        else{
            break;
        }
        ax = teams[i].s;
    }

    return 0;
}
