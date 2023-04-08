#include<bits/stdc++.h>
#define MAX 1050000
#define INF 1000000

using namespace std;

int x, y, op;

int memo[MAX];

int solve(int p){
    if(p == x){
        return 0;
    }

    if(p == 0 || p & 1){
        return INF;
    }

    if(memo[p] != -1){
        return memo[p];
    }

    int res = INF;
    res = min(res, solve(p / 2));
    res = min(res, solve((p + op) / 2));

    return memo[p] = res + 1;
}

int main() {
    int n;
    scanf("%d %d %d", &n, &x, &y);
    memset(memo, -1, sizeof(memo));

    op = 1 << n;

    int res = solve(1 << (n - 1));
    printf("%d\n", res);
    
    return 0;
}