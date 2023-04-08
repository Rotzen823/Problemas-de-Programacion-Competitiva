#include<bits/stdc++.h>

using namespace std;

map<string, int> nums;
 
int main() {
    int n, m;
    string op;

    scanf("%d %d", &n, &m);

    while(n--){
        cin >> op;
        string num = "";
        for(char x : op){
            switch(x){
                case 'a':
                case 'b':
                case 'c':
                num += "2";
                break;
                case 'd':
                case 'e':
                case 'f':
                num += "3";
                break;
                case 'g':
                case 'h':
                case 'i':
                num += "4";
                break;
                case 'j':
                case 'k':
                case 'l':
                num += "5";
                break;
                case 'm':
                case 'n':
                case 'o':
                num += "6";
                break;
                case 'p':
                case 'q':
                case 'r':
                case 's':
                num += "7";
                break;
                case 't':
                case 'u':
                case 'v':
                num += "8";
                break;
                case 'w':
                case 'x':
                case 'y':
                case 'z':
                num += "9";
                break;
            }
        }
        nums[num]++;
    }

    while(m--){
        cin >> op;
        printf("%d\n", nums[op]);
    }

    return 0;
}