#include<bits/stdc++.h>
using namespace std;

#define iter(a,i) for (i=a.begin(); i!=a.end(); i++)
#define f(i,s,e,inc) for (int i=s; i<e; i+=inc)
typedef vector<int > vi;
typedef map<string, string> mss;


void solve(){
    char word[100];
    scanf("%s", word);
    if (strlen(word) == 5){
        printf("%i\n", 3);
        return;
    }
    string one = "one";
    int wrong = 0;
    f(i,0,3,1){
        if (word[i] != one[i]){
            wrong++;
        }
    }

    if (wrong < 2){
        printf("%i\n", 1);
        return;
    }

    printf("%i\n", 2);
}

int main(){
    int tc = 1;
    scanf("%i", &tc);
    f(t,0,tc,1){
        solve();
    }

    return 0;
}