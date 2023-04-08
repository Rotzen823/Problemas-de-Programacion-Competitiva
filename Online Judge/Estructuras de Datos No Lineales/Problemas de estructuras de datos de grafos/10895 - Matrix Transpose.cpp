#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        vector<pair<int, int> > mat[m + 1];

        for(int k = 1; k <= n; k++){
            int x;
            vector<int> matId;
            scanf("%d", &x);

            for(int j = 0; j < x; j++){
                int v;
                scanf("%d", &v);
                matId.push_back(v);
            }

            for(int j = 0; j < x; j++){
                int v;
                scanf("%d", &v);
                mat[matId[j]].push_back({k, v});
            }
        }

        printf("%d %d\n", m, n);
        for(int k = 1; k <= m; k++){
            printf("%d", mat[k].size());
            for(auto v : mat[k]){
                printf(" %d", v.first);
            }
            printf("\n");
            if(mat[k].size()){
                printf("%d", mat[k][0].second);
            }

            for(int j = 1; j < (int)mat[k].size(); j++){
                printf(" %d", mat[k][j].second);
            }
            printf("\n");
        }


    }

    return 0;
}