#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi grafo[MAX];
int grupos[MAX], contGrupo[MAX], res[MAX];
int general = 0;

void dfs(int u){

    if(!contGrupo[grupos[u]]){
        general++;
    }
    contGrupo[grupos[u]]++;

    res[u] = general;

    for(int v : grafo[u]){
        dfs(v);
    }

    contGrupo[grupos[u]]--;
    if(!contGrupo[grupos[u]]){
        general--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    int n;
    cin >> n;

    for(int k = 1; k <= n; k++){
        int x;
        cin >> x;
        grafo[x].push_back(k);
    }

    for(int k = 1; k <= n; k++){
        cin >> grupos[k];
    }
    contGrupo[0] = 1;
    dfs(0);

    cout << res[1];
    for(int k = 2; k <= n; k++){
        cout << " " << res[k];
    }
    cout << "\n";

	return 0;
}
