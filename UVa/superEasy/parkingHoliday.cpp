#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int tc){
    int p, l ,t;
    scanf("%i %i %i", &p, &l, &t);
    if (p>20 || l>20 || t>20){
        printf("Case %i: bad\n", tc);
        return;
    }

    printf("Case %i: good\n", tc);
}

int main(){
    int tc;
    scanf("%i", &tc);
    f(t,0,tc,1){
        solve(t+1);
    }

    return 0;
}