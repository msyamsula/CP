#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int tc, char t[100]){
    if (strstr(t, "Hajj") != nullptr){
        printf("Case %i: Hajj-e-Akbar\n", tc);
    } else if (strstr(t, "Umrah") != nullptr){
        printf("Case %i: Hajj-e-Asghar\n", tc);
    }
}

int main(){
    char type[100];
    scanf("%s", type);
    int tc = 1;
    while(type[0] != '*'){
        solve(tc, type);
        scanf("%s", type);
        tc++;
    }

    return 0;
}