// Pura Gente del Coach Moy
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < n; i++)
#define forns(i, s, n) for(int i = s; i < n; i++)
#define ENDL '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 1005
#define LOG 20

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, k;
map<string, int> wordsID;
vector<pair<string, int>> words;
vector<tuple<int, int, int>> dictionary;
vi base;

vi candidates(vi &query, int f){
    vi cand;
    for(int i = 0; i < (m - f + 1); i++){
        bool flag = true;
        for(int j = query.sz() - f, b = i; j < query.sz(); j++, b++){
            if(base[b] != query[j]){
                flag = false;
                break;
            }
        }
        if(flag && (i + f) < m){
            cand.pb(base[i + f]);
        }
    }

    return cand;
}

string trad(vi &phrase){
    string ans = words[phrase[0]].fi;
    for(int i = 1; i < phrase.sz(); i++){
        if(phrase[i] == -1){
            ans += " *";
            continue;
        }
        ans += (" " + words[phrase[i]].fi);
    }

    return ans;
}

string solve(vi &query){
    vi cand;
    for(int i = k; i >= 1; i--){
        cand = candidates(query, i);
        if(cand.sz() > 0){
            break;
        }
    }

    vi phrase = query;
    if(cand.sz() == 0){
        phrase.pb(-1);
        return trad(phrase);
    }

    int sumX = 0, sumY = 0;
    for(int c : cand){
        int id = words[c].se;
        if(id == -1){
            continue;
        }
        auto [ax, x, y] = dictionary[id];
        sumX += x; sumY += y;
    }

    int idD = 0;
    int SId = 0;
    for(int i = 0; i < n; i++){
        auto [ax, x, y] = dictionary[i];

        int Si = (sumX * x + sumY * y);
         if(i == 0 || Si > SId){
            idD = i;
            SId = Si;
        }
    }

    auto [idW, x, y] = dictionary[idD];
    phrase.pb(idW);

    return trad(phrase);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        int x, y;
        cin >> s >> x >> y;

        int id = words.sz();
        if(!wordsID.count(s)){
            wordsID[s] = words.sz();
            words.pb({s, i});
        }
        else{
            id = wordsID[s];
        }

        dictionary.pb({id, x, y});
    }

    cin >> m;
    base.resize(m);
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;

        base[i] = words.sz();
        if(!wordsID.count(s)){
            wordsID[s] = words.sz();
            words.pb({s, -1});
        }
        else{
            base[i] = wordsID[s];
        }
    }

    int q;
    cin >> q >> k;

    while(q--){
        int f;
        cin >> f;
        vi query(f);
        for(int i = 0; i < f; i++){
            string s;
            cin >> s;

            query[i] = words.sz();
            if(!wordsID.count(s)){
                wordsID[s] = words.sz();
                words.pb({s, -1});
            }
            else{
                query[i] = wordsID[s];
            }
        }

        string ans = solve(query);
        cout << ans << ENDL;
    }

    return 0;
}
