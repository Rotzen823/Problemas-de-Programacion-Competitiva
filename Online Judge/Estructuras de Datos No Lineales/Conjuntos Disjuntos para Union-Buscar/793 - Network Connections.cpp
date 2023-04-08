#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int numSets;
vi f, rango, tams;

int findSet(int v){
	return f[v] == v ? v : (f[v] = findSet(f[v]));
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
	if(isSameSet(a, b)){
		return;
	}
	numSets--;
	int x = findSet(a), y = findSet(b);

	if(rango[x] > rango[y]){
		f[y] = x;
		tams[x] += tams[y];
	}
	else{
		f[x] = y;
		tams[y] += tams[x];
		if(rango[x] == rango[y]){
			rango[y]++;
		}
	}
}

int sizeOfSet(int v){
	return tams[findSet(v)];
}

int main(){
	int n;
	char op;
	string s;
	scanf("%d", &n);

	for(int k = 0; k < n; k++){
		int N, succ = 0, fail = 0;
		scanf("\n%d\n", &N);

		numSets = N;
		rango.assign(N + 1, 0); tams.assign(N + 1, 1);
		f.assign(N + 1, 0);
		for(int k = 1; k <= N; k++){
			f[k] = k;
		}

		while(getline(cin, s) && !s.empty()){
			//printf("%d\n", op);
			int a, b;
			sscanf(s.c_str(), "%c %d %d", &op, &a, &b);
			switch (op)
			{
			case 'c':	
				unionSet(a, b);
				break;
			
			case 'q':
				if(isSameSet(a,b)){
					succ++;
				}
				else{
					fail++;
				}
				break;
			}
		}

		if(k != 0){
			printf("\n");
		}
		printf("%d,%d\n", succ, fail);
	}

	return 0;
}