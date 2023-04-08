#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        vector<vector<int> > listAdj;
        listAdj.assign(1000001, {});

        for(int k = 1; k <= n; k++){
            int v;
            scanf("%d", &v);
            listAdj[v].push_back(k);
        }

        while(m--){
            int a, b, res;
            scanf("%d %d", &a, &b);

            for(int v : listAdj[b]){
                if(a <= 0){
                    break;
                }
                a--;
                res = v;
            }

            if(a > 0){
                res = 0;
            }

            printf("%d\n", res);
        }
    }

    return 0;
}