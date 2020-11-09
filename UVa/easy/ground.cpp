#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(){
    // char blank[100];
    // scanf("%s", blank);
    int w;
    scanf("%i", &w);
    int gap;
    string result = "yes";
    f(i,0,w,1){
        int a,b;
        scanf("%i %i", &a, &b);
        if (i==0){
            gap = b-a;
        }

        if (gap == b-a){
            continue;
        } else {
            result = "no";
        }
    }

    cout << result << endl;
}

int main(){
    int tc;
    scanf("%i", &tc);
    f(t,0,tc,1){
        if (t == 0){
            solve();
        } else {
            cout << endl;
            solve();
        }
    }

    return 0;
}