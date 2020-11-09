#include<bits/stdc++.h>
using namespace std;
#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)


int main(){

    string line;
    int cq = 0;
    string result;
    while(getline(cin, line)){
        char* i = &line[0];
        char* st = &line[0];
        while(*i!='\0'){
            int idx = i - st;
            if (*i == '\"' && cq == 0){
                result += "``";
                cq = 1;
            } else if (*i == '\"' && cq == 1){
                result += "''";
                cq = 0;
            } else {
                result += *i;
            }
            i+=1;
        }
        result += "\n";
    }
    cout << result;
    return 0;
}