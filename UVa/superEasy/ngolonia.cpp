#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)

void solve(int k){
    int n, m;
    scanf("%i %i", &n, &m);
    f(i,0,k,1){
        int x, y;
        string result = "";
        scanf("%i %i", &x, &y);
        if (x-n == 0 || y-m == 0){
            cout << "divisa" << endl;
            continue;
        }

        result += (y>m) ? "N" : "S";
        result += (x>n) ? "E" : "O";
        cout << result << endl;
    }
}


int main(){
    int k;
    while(scanf("%i", &k)){
        if (k == 0){
            break;
        }

        solve(k);
    }

    return 0;
}