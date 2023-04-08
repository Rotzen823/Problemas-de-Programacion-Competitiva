#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int n;
	cin >> n;

	while(n--){
		int b, sg, sb;

		cin >> b >> sg >> sb;

		priority_queue<int> green, blue;

		while(sg--){
			int x;
			cin >> x;
			green.push(x);
		}

		while(sb--){
			int x;
			cin >> x;
			blue.push(x);
		}

		while(!green.empty() && !blue.empty()){
			vector<int> gr, bl;
			for(int k = 0; k < b; k++){
				if(green.empty() || blue.empty()){
					break;
				}

				int ng = green.top(), nb = blue.top();
				green.pop(); blue.pop();
				if(ng > nb){
					gr.push_back((ng - nb));
				}
				else if(nb > ng){
					bl.push_back((nb - ng));
				}
			}
			
			while(!gr.empty()){
				green.push(gr.back());
				gr.pop_back();
			}
			while(!bl.empty()){
				blue.push(bl.back());
				bl.pop_back();
			}
		}

		if(green.empty() && blue.empty()){
			printf("green and blue died\n");
		}
		else if(green.empty()){
			printf("blue wins\n");
			while(!blue.empty()){
				printf("%d\n", blue.top()); blue.pop();
			}
		}
		else{
			printf("green wins\n");
			while(!green.empty()){
				printf("%d\n", green.top()); green.pop();
			}
		}

		if(n){
			printf("\n");
		}
	}

    return 0;
}