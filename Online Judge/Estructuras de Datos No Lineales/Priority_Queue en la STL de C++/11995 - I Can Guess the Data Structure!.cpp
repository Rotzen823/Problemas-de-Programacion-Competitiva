#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		stack<int> pila;
		queue<int> cola;
		priority_queue<int> colaP;
		bool estr[] = {true, true, true};
		while(n--){
			int op, x;
			scanf("%d %d", &op, &x);

			switch(op){
				case 1:
				pila.push(x);
				cola.push(x);
				colaP.push(x);
				break;
				case 2:
				if(!pila.empty()){
					if(x != pila.top()){
						estr[0] = false;
					}
					pila.pop();
				}
				else{
					estr[0] = false;
				}

				if(!cola.empty()){
					if(x != cola.front()){
						estr[1] = false;
					}
					cola.pop();
				}
				else{
					estr[1] = false;
				}

				if(!colaP.empty()){
					if(x != colaP.top()){
						estr[2] = false;
					}
					colaP.pop();
				}
				else{
					estr[2] = false;
				}
				
				break;
			}	
		}
		if(estr[0] && !estr[1] && !estr[2]){
			printf("stack\n");
		}
		else if(!estr[0] && estr[1] && !estr[2]){
			printf("queue\n");
		}
		else if(!estr[0] && !estr[1] && estr[2]){
			printf("priority queue\n");
		}
		else if(!estr[0] && !estr[1] && !estr[2]){
			printf("impossible\n");
		}
		else{
			printf("not sure\n");
		}
	}
	
	return 0;
}