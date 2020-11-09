#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;

int sum = 0;

void solve(){
    char s[100];
    int donation;
    scanf("%s", s);
    if (strstr(s, "report") != nullptr){
        printf("%i\n", sum);
        return;
    }

    scanf("%i", &donation);
    sum += donation;
}

int main(){
    int tc;
    scanf("%i", &tc);
    f(t,0,tc,1){
        solve();
    }

    return 0;
}