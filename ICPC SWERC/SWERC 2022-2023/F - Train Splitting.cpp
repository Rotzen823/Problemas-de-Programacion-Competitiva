#include <bits/stdc++.h>

#define ENDL '\n'
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

class UnionFind{
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N){
            setSize.assign(N, 1); numSets = N; rank.assign(N, 0); p.assign(N, 0);
            for(int k = 0; k < N; k++){
                p[k] = k;
            }
        }
        int findSet(int a){
            return a == p[a] ? a : (p[a] = findSet(p[a]));
        }
        bool isSameSet(int a, int b){
            return findSet(a) == findSet(b);
        }
        void unionSet(int a, int b){
            if(isSameSet(a, b)){
                return;
            }

            int x = findSet(a), y = findSet(b);
            if(rank[y] > rank[x]){
                swap(x, y);
            }
            p[y] = x;
            setSize[x] += setSize[y];
            if(rank[x] == rank[y]){
                rank[x]++;
            }
            numSets--;
        }
        int sizeOfSet(int a){
            return setSize[findSet(a)];
        }
        int numDisjointSets(){
            return numSets;
        }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<UnionFind> ufs;
        vi res(m);

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;

            bool flag = true;
            for(int j = 0; j < (int) ufs.size(); j++){
                if(ufs[j].isSameSet(a, b) || ufs[j].numDisjointSets() > 2){
                    res[i] = j + 1;
                    flag = false;
                    ufs[j].unionSet(a, b);
                    break;
                }
            }


            if(flag){
                ufs.push_back(UnionFind(n));
                ufs.back().unionSet(a, b);
                res[i] = ufs.size();
            }

        }

        cout << ufs.size() << "\n" << res[0];
        for(int i = 1; i < m; i++){
            cout << " " << res[i];
        }
        cout << "\n";
    }

    return 0;
}
