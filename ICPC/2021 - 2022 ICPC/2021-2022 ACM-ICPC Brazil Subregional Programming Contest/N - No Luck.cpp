#include<bits/stdc++.h>
#define MAX 300005
 
using namespace std;
 
typedef struct Nodo{
	int l;
	int r;
	int val;
	int id;
}Nodo;
 
class SegmentTree{
	private:
		int n;
		vector<int> st;
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
 
			st[v] = st[left(v)] + st[right(v)];
		}
 
		int query(int sl, int sr, int v, int l, int r){
			if(sl > r || sr < l){
				return 0;
			}
 
			if(l >= sl && r <= sr){
				return st[v];
			}
 
			int m = (l + r) / 2;
 
			return query(sl, sr, left(v), l, m) + query(sl, sr, right(v), m + 1, r);
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
 
Nodo a[MAX], b[MAX];
 
bool comparacion(Nodo a, Nodo b){
	return a.val < b.val;
}
 
int res[MAX];
 
int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
 
	for(int k = 0; k < n; k++){
		cin >> a[k].val;
		a[k].id = k;
	}
	memset(res, -1, sizeof(res));
 
	for(int k = 0; k < m; k++){
		cin >> b[k].l >> b[k].val >> b[k].r;
 
		b[k].r += b[k].l;
		b[k].id = k;
		if(a[b[k].l - 1].val >= b[k].val){
			res[k] = 0;
		}
	}
 
	sort(a, a + n, comparacion);
	sort(b, b + m, comparacion);
 
	int q = 0;
	SegmentTree st(n);
	for(int k = 0; k < m; k++){
		
		while(a[q].val < b[k].val && q < n){
			st.update(a[q].id, 1);
			q++;
		}
 
		if(res[b[k].id] == 0){
			continue;
		}
 
		res[b[k].id] = (b[k].r - b[k].l) - (st.query(b[k].l, b[k].r - 1));
	}
 
	for(int k = 0; k < m; k++){
		cout << res[k] << "\n";
	}
	
 
	return 0;
}