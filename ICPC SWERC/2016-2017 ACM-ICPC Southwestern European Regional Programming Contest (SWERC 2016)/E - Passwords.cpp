#include <bits/stdc++.h>
#define MAXT 25
#define MAX 1005
#define MOD 1000003
 
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
 
const int K = 26;
 
struct Vertex {
    vi next;
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
	int terminal  = -1;
    vi go;
 
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        next.assign(K, -1);
        go.assign(K, -1);
    }
};
 
 
int go(int v, char ch);
 
struct Aho_Corasick{
    vector<Vertex> t;
 
    void init(){
        t.emplace_back(Vertex());
    }
 
    int convert(char ch){
		return ch - 'a';
    }
 
    void add_string(string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = convert(ch);
			//cout << v << " " << c << "\n";
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].output = true;
    }
 
    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
 
    int go(int v, char ch) {
        int c = convert(ch);
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }
 
    int terminal(int v){
        if(t[v].terminal == -1){
            if(v == 0){
                t[v].terminal = 0;
            }
            else{
                t[v].terminal = terminal(get_link(v));
                if(t[get_link(v)].output){
                    t[v].terminal = get_link(v);
                }
            }
        }
        return t[v].terminal;
    }
}; 

ll memo[MAXT][MAX][2][2][2];

Aho_Corasick ah;
int a, b;

ll dp(int i, int j, bool up, bool low, bool dig){
	if(i >= b){
		return !ah.t[j].output && ah.terminal(j) == 0 && up && low && dig;
	}

	if(ah.t[j].output || ah.terminal(j) != 0){
		return 0;
	}

	if(memo[i][j][up][low][dig] != -1){
		return memo[i][j][up][low][dig];
	}

	ll res = i >= a && up && low && dig;

	for(char c = 'a'; c <= 'z'; c++){
		res += dp(i + 1, ah.go(j, c), up, true, dig); res %= MOD;
		res += dp(i + 1, ah.go(j, c), true, low, dig); res %= MOD;

		if(c == 'o' || c == 'i' || c == 'e' || c == 's' || c == 't'){
			res += dp(i + 1, ah.go(j, c), up, low, true); res %= MOD;
		}
	}

	ll ax = dp(i + 1, 0, up, low, true) * 5; ax %= MOD;
	res += ax; res %= MOD;
	return memo[i][j][up][low][dig] = res;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	memset(memo, -1, sizeof(memo));
 
    int n;
	cin >> a >> b >> n;

	ah.init();

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		ah.add_string(s);
	}

 	ll res = dp(0, 0, false, false, false);

	cout << res << "\n";
	
    return 0;
}
