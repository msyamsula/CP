#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int tc, int n){
    int balance = 0;
    int value;
    f(i,0,n,1){
        scanf("%i", &value);
        if (value != 0){
            balance++;
        } else if (value == 0){
            balance--;
        }
    }
    // cout << balance << endl;
    printf("Case %i: %i\n",tc,balance);
}

int main(){
    int n;
    scanf("%i", &n);
    int tc = 1;
    while(n != 0){
        solve(tc, n);
        scanf("%i", &n);
        tc++;
    }

    return 0;
}