#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while(n--){
		int c = 0;
        int rows[5] = {0}, columns[5] = {0}, diag[2] = {0};
        pair<int, int> nums[80];
		bool ready[80] = {0};
        for(int k = 0; k < 5; k++){
            for(int j = 0; j < 5; j++){
                if(k == 2 && j == 2){
                    continue;
                }
                int x;
                scanf("%d", &x);
                nums[x] = {k, j};
				ready[x] = true;
            }
        }

		rows[2]++; columns[2]++; diag[0]++; diag[1]++;

		bool finished = false;
		for(int k = 0; k < 75; k++){
			int d;
			scanf("%d", &d);
			if(finished){
				continue;
			}

			c++;

			if(!ready[d]){
				continue;
			}

			int x, y;
			x = nums[d].first; y = nums[d].second;

			rows[x]++;
			if(rows[x] >= 5){
				finished = true;
				continue;
			}

			columns[y]++;
			if(columns[y] >= 5){
				finished = true;
				continue;
			}

			if(x == y){
				diag[0]++;
				if(diag[0] >= 5){
					finished = true;
					continue;
				}
			}
			else if(x + y == 4){
				diag[1]++;
				if(diag[1] >= 5){
					finished = true;
					continue;
				}
			}
		}

		printf("BINGO after %d numbers announced\n", c);
		
    }
    
    return 0;
}