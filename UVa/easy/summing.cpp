#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(int num){
    int ans;
    string s = to_string(num);

    while(s.size()>1){
        int value = 0;
        string::iterator i;
        iter(s, i){
            value += (int)(*i)-48;
        }        
        s = to_string(value);
        ans = value;
    }

    printf("%i\n", ans);
}

int main(){
    int num;
    while(scanf("%i", &num) != EOF){
        if (num == 0){
            break;
        }
        solve(num);
    }

    return 0;
}