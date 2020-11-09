#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int N, int B, int H, int W){
    int minCost = (1<<30);
    f(h,0,H,1){
        int price;
        scanf("%i", &price);
        int c = 0;
        f(w,0,W,1){
            int value;
            scanf("%i", &value);
            if (value >= N){
                c = N*price;
            }
        }
        if (c < minCost && c != 0){
            minCost = c;
        }
    }

    if (minCost == (1<<30) || minCost > B){
        printf("stay home\n");
    } else {
        printf("%i\n", minCost);
    }

}

int main(){
    int N, B, H, W;
    while (scanf("%i %i %i %i", &N, &B, &H, &W) != EOF){
        solve(N,B,H,W);
    }
    return 0;
}