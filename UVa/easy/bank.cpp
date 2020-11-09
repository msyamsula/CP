#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int c, int B, int N){
    vi reserve;
    int value;
    f(i,0,B,1){
        scanf("%i", &value);
        reserve.push_back(value);
    }

    int from, to, v;
    f(i,0,N,1){
        scanf("%i %i %i", &from, &to, &v);
        reserve[from-1] -= v;
        reserve[to-1] += v;
    }

    vi::iterator i;
    iter(reserve, i){
        // cout << *i << ' ';
        if (*i < 0){
            printf("%s\n", "N");
            return;
        }
    }
    printf("%s\n", "S");
    // cout << endl;
}

int main(){
    int B, N;
    scanf("%i %i", &B, &N);
    int idx = 1;
    while((B+N) > 0){
        solve(idx, B, N);
        scanf("%i %i", &B, &N);
    }

    return 0;
}