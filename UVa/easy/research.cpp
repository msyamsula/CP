#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(){
    char code[100];
    scanf("%s", code);
    if (strlen(code) < 3){
        printf("%s\n", "+");
    } else if (code[0] == '9'){
        printf("%s\n", "*");
    } else if (code[0] == '1'){
        printf("%s\n", "?");
    } else {
        printf("%s\n", "-");
    }
}

int main(){
    int tc;
    scanf("%i", &tc);
    f(t,0,tc,1){
        solve();
    }

    return 0;
}