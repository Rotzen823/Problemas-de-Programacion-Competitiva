#include <bits/stdc++.h>
 
using namespace std;

int main() {
    string frase;

    while(cin >> frase){
        list<string> res;
        bool end = true;
        string pal = "";
        for(char x : frase){
            if(x == '[' || x == ']'){
                if(pal != ""){
                    if(end){
                        res.push_back(pal);
                    }
                    else{
                        res.push_front(pal);
                    }
                }
                end = (x == ']');
                pal = "";
                continue;
            }

            pal += x;
        }
        if(pal != ""){
            if(end){
                res.push_back(pal);
            }
            else{
                res.push_front(pal);
            }
        }

        for(auto x : res){
            cout << x;
        }
        printf("\n");
    }
    
    return 0;
}