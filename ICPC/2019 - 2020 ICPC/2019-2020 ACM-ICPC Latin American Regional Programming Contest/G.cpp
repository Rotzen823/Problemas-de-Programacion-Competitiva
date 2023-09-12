#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

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

ii buscarSufijo(char d, ii inter, int i){
    int st = inter.first, end = inter.second;
    while(st < end){
        int mid = (st + end) / 2 + 1;
        int p = suffix[mid] + i;
        if(p >= (int) s.length() || s[p] <= d){
            st = mid;
        }
        else{
            end = mid - 1;
        }
    }
    int a = st;
    st = inter.first, end = inter.second;
    while(st < end){
        int mid = (st + end) / 2;
        int p = suffix[mid] + i;
        if(p >= (int) s.length() || s[p] < d){
            st = mid + 1;
        }
        else{
            end = mid;
        }
    }
    int b = end;

    return ii(b, a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;

    suffix = suffix_array_construction(s);

    int m;
    cin >> m;

    while(m--){
        string t;
        cin >> t;
        int c = 1, i = 0;
        ii ax(0, s.length() - 1);
        for(int k = 0; k < (int) t.length(); k++){
            ax = buscarSufijo(t[k], ax, i);
            int p = suffix[ax.first] + i;
            if(p >= (int) s.length() || t[k] != s[p]){
                if(i == 0){
                    c = -1;
                    break;
                }
                i = 0;
                ax = ii(0, s.length() - 1);
                c++;
                k--;
                continue;
            }
            i++;
        }
        cout << c << "\n";
    }

    return 0;
}
