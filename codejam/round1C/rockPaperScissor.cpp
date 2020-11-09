#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<string, int> msi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)

void addTrie(int trie[255*500][4], string a, int &ns){
    
    char c;
    int n = 0;
    f(i,0,a.length(),1){
        c = a[i];
        int s;
        if (c=='R'){
            s = 0;
        } else if (c=='P'){
            s = 1;
        } else if (c=='S'){
            s = 2;
        }

        if (trie[n][s] == 0){
            ns++;
            trie[n][s] = ns;
            trie[n][3]++;
        }

        n = trie[n][s];
    }
}

void solveCase(int t){
    string ans = "";
    int A;
    scanf("%i", &A);
    string other[A];
    int trie[255*500][4]={{0}};
    int status[3] = {0,0,0};
    int ns = 0;
    int depth = 0;
    f(a,0,A,1){
        string value;
        cin >> value;
        addTrie(trie, value, ns);
        depth = (value.length()>depth) ? value.length() : depth;
    }

    int node = 0;
    f(i,0,ns,1){
        if (trie[node][3] == 1){
            if (trie[node][0] != 0){
                ans += "P";
            } else if (trie[node][1] != 0){
                ans += "S";
            } else {
                ans += "R";
            }
            break;
        } else if (trie[node][3] == 2){
            if (trie[node][0] == 0){
                ans += "S";
                node = trie[node][2];
            } else if (trie[node][1] == 0){
                ans += "R";
                node = trie[node][0];
            } else {
                ans += "P";
                node = trie[node][1];
            }
        } else if (trie[node][3] == 3){
            printf("Case %c%i: %s\n",'#',t,"IMPOSSIBLE");
            return;
        }
    }

    // cout << ans.length() << ' ' << depth << endl;
    string add;
    if (ans[0] == 'R'){
        add = "P";
    } else if (ans[0] == 'P'){
        add = "S";
    } else if (ans[0] == 'S'){
        add = "R";
    }
    ans += add;
    // if (ans.length() == depth) {
    // }
    printf("Case %c%i: ",'#',t);
    cout << ans << endl;
}

int main(){
    int T;
    scanf("%i", &T);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    f(t,0,T,1){
        solveCase(t+1);
    }

    return 0;
}