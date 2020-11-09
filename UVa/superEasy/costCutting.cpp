#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;

void solve(int t){
    vector<int> sal;
    sal.resize(3);
    scanf("%i %i %i", &sal[0], &sal[1], &sal[2]);
    sort(sal.begin(), sal.end());
    printf("Case %i: %i\n", t, sal[1]);
}

int main(){
    int T;
    scanf("%i", &T);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    f(t,0,T,1){
        solve(t+1);
    }

    return 0;
}