#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vi sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vi p(n), c(n), cnt(max(alphabet, n), 0);

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vi suffix_array_construction(string s) {
    s += "$";
    vi sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vi suffix;
string s;
int n;

vi kasaiAlgo(){
   vi lcp(n, 0), tmpSuf(n, 0);

   for (int i = 0; i < n; i++)
       tmpSuf[suffix[i]] = i;

   int len = 0;

   for (int i = 0; i < n; i++)
   {
       if (tmpSuf[i] == n - 1)
       {
           len = 0;
           continue;
       }

       int idx = suffix[tmpSuf[i] + 1];
       while (i + len < n && idx + len < n && s[i + len] == s[idx + len])
           len++;
       lcp[tmpSuf[i]] = len;
       if (len > 0)
           len--;
   }

   return lcp;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> s;
	n = SZ(s);
	
	suffix = suffix_array_construction(s);

	vi lcp = kasaiAlgo();

	int res = n, pos = 0;
	for(int i = 1; i < n; i++){
        int ax = max(lcp[i - 1], lcp[i]);
        //cout << suffix[i] << ' ' << ax << ENDL;
        if((ax < res || (ax == res && suffix[i] < pos)) && n - suffix[i] > ax){
            res = ax;
            pos = suffix[i];
            //cout << s.substr(pos, res + 1) << ENDL;
        }
	}

    string ans = s.substr(pos, res + 1);

    cout << ans << ENDL;


  return 0;
}
