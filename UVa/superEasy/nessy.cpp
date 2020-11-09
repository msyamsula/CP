#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)


void solve(){
    int n, m;
    scanf("%i %i", &n, &m);
    n = n-2;
    m = m-2;
    int p = (n%3==0) ? n/3 : (n/3) + 1;
    int q = (m%3==0) ? m/3 : (m/3) + 1;

    cout << p*q << endl;
}


int main(){
    int T;
    scanf("%i", &T);
    f(t,0,T,1){
        solve();
    }

    return 0;
}