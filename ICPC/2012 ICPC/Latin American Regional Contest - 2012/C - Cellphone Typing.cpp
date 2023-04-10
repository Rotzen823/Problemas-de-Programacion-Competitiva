#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef struct Nodo{
    char x;
    int c;
    vector<int> pref;
}Nodo;

Nodo trie[MAX];
int c = 0;

void update(string pal, int p = 0, int v = 0){
    trie[v].c++;

    if(p == (int) pal.length()){
        return;
    }

    for(int u : trie[v].pref){
        if(trie[u].x == pal[p]){
            update(pal, p + 1, u);
            return;
        }
    }

    c++;
    trie[c].c = 0;
    trie[c].x = pal[p];
    trie[v].pref.push_back(c);
    update(pal, p + 1, c);
}

int query(int p = 0,  int v = 0){
    int res = 0;
    //printf("%d %d %c\n", p, trie[v].c, trie[v].x);
    if(p != trie[v].c){
        res += trie[v].c;
    }

    while(!trie[v].pref.empty()){
        int u = trie[v].pref.back();
        res += query(trie[v].c, u);
        trie[v].pref.pop_back();
    }

    trie[v].c = 0;
    return res;
}

int main() { 
    int n;
    
    while(scanf("%d", &n) != EOF){
        string ax;
        c = 0;
        for(int k = 0; k < n; k++){
            cin >> ax;
            update(ax);
        }
        int res = 0;

        while(!trie[0].pref.empty()){
            int u = trie[0].pref.back();
            res += query(0, u);
            trie[0].pref.pop_back();
        }
        trie[0].c = 0;
        
        double ans = (double) res / n;
        printf("%.2lf\n", ans);
    }

    return 0;
}
