#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

typedef vector<int> vi;

class SegmentTree{
    private:
        int n;
        vi st;
        int left(int v){
            return (v << 1);
        }
        int right(int v){
            return (v << 1) + 1;
        }
        void build(int id, int value, int v, int l, int r){
            if(l == r){
                st[v] = value;
                return;
            }
            int m = (l + r) / 2;
            if(id <= m){
                build(id, value, left(v), l, m);
            }
            else{
                build(id, value, right(v), m + 1, r);
            }
            st[v] = min(st[left(v)], st[right(v)]);
        }

        int query(int sl, int sr, int v, int l, int r){
            if(sl > r || sr < l){
                return INF;
            }
 
            if(l >= sl && r <= sr){
                return st[v];
            }
 
            int m = (l + r) / 2;
 
            return min(query(sl, sr, left(v), l, m), query(sl, sr, right(v), m + 1, r));
        }
 
    public:
        SegmentTree(int N){
            n = N;
            st.assign(4 * n, 0);
        }
 
        int query(int l, int r){
            return query(l, r, 1, 0, n - 1);
        }
 
        void update(int id, int value){
            return build(id, value, 1, 0, n - 1);
        }
};

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

vi suffix, tmpSuf;
string s;
int n;

vi kasaiAlgo(){
   vi lcp(n, 0);
   tmpSuf.assign(n, 0);

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int d;
    cin >> s >> d;
    n = s.length();

    suffix = suffix_array_construction(s);
    vi lcp = kasaiAlgo();

    SegmentTree st(n);

    for(int k = 0; k < n; k++){
        st.update(k, lcp[k]);
    }

    int res = 0, k = 0;
    while(k < (n - d)){
        int maxD = 0;
        for(int j = 1; j <= d; j++){
            int a = tmpSuf[k], b = tmpSuf[k + j];
            if(a > b){
                swap(a, b);
            }
            int ax = st.query(a, b - 1);
            maxD = max(maxD, ax + j);
        }
        k += maxD;
        res++;
    }

    if(k < n){
        res++;
    }

    cout << res << "\n";

    return 0;
}
