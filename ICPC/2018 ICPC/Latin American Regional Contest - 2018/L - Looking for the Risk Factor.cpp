#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define MAX 100005
#define ENDL '\n'
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

vi a;
vector<int> seg[4*MAX+5];

//build merge sort tree
void build(int node,int l,int r){
    //if range length is 1 there's only one element to add and no children
    if (l==r){
        seg[node].push_back(a[l]);
        return;
    }int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    int i=0,j=0;
    // use two pointers to merge the two vectors in O(r-l+1)
    while (i<seg[node*2].size() && j<seg[node*2+1].size()){
        if (seg[node*2][i]<seg[node*2+1][j]) seg[node].push_back(seg[node*2][i++]);
        else seg[node].push_back(seg[node*2+1][j++]);
    }
    while (i<seg[node*2].size()) seg[node].push_back(seg[node*2][i++]);
    while (j<seg[node*2+1].size()) seg[node].push_back(seg[node*2+1][j++]);
    return;
}
//query
int query(int node,int l,int r,int lx,int rx,int x){
    //if outside -> 0
    if (l>rx || r<lx) return 0;
    //if inside do binary search
    if (l>=lx && r<=rx){
        int L=0,R=seg[node].size()-1,mid,ans=0;
        while (L<=R){
            mid=(L+R)/2;
            if (seg[node][mid]<x){
                ans=mid+1;
                L=mid+1;
            }else R=mid-1;
        }return ans;
    }
    int mid=(l+r)/2;
    return query(node*2,l,mid,lx,rx,x)+query(node*2+1,mid+1,r,lx,rx,x);
}

void criba(){
    a.resize(MAX);
    for(int i = 0; i < MAX; i++){
        a[i] = i;
    }

    for(int i = 2; i < MAX; i++){
        if(a[i] == i){
            for(int j = i * 2; j < MAX; j += i){
                a[j] = i;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   

    criba();
    build(1, 1, MAX - 1);

    int q;
    cin >> q;

    while(q--){
        int n, k;
        cin >> n >> k;
        
        cout << query(1, 1, MAX - 1, 2, n, k + 1) << ENDL;
    }

    return 0;
}
