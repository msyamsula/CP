#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)


void solve(){
    int a, b;
    scanf("%i %i", &a, &b);

    if (a>b){
        cout << '>' << endl;
    } else if (a<b){
        cout << '<' << endl;
    } else {
        cout << '=' << endl;
    }

}

int main(){
    int T;
    scanf("%i", &T);
    f(t,0,T,1){
        solve();
    }

    return 0;
}