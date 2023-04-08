#include<bits/stdc++.h>

using namespace std;

typedef struct Nodo{
	int id;
	int time;
	int period;
}Nodo;

class Comparacion{
	public:
	bool operator()(Nodo a, Nodo b){
		if(a.time != b.time){
			return a.time > b.time;
		}
		return a.id > b.id;
	}
};

int main(){
	string op;
	priority_queue<Nodo, vector<Nodo>, Comparacion> q;

	while(cin >> op && (op != "#")){
		int a, b;
		scanf("%d %d", &a, &b);
		q.push({a, b, b});
	}

	int n;
	scanf("%d", &n);

	while(n--){
		auto x = q.top(); q.pop();
		printf("%d\n", x.id);
		q.push({x.id, x.time + x.period, x.period});
	}
	
	return 0;
}