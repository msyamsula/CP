#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(){
    int nFarmer;
    scanf("%i", &nFarmer);
    int sum = 0;
    int a,b,c;
    f(i,0,nFarmer,1){
        scanf("%i %i %i", &a, &b, &c);
        sum += a*c;
    }

    printf("%i\n", sum);
}

int main(){
    int tc;
    scanf("%i", &tc);
    f(t,0,tc,1){
        solve();
    }

    return 0;
}