#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)

int main(){
    // string isLine;
    string line;
    string result;
    while(getline(cin, line)){
        result += line + "\n";
    }
    cout << result;

    return 0;
}