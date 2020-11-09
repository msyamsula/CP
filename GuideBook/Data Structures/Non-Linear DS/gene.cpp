#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef unordered_map<int, int> mii;
typedef deque<int> dqi;
typedef vector<string> vs;
typedef map<string, vector<string>> msvs;
typedef deque< pair<string, string> > dqpss;


int main(){
    mss ans;
    int N;
    msvs fam;
    scanf("%i", &N);
    f(i,0,N,1){
        char t1[100], t2[100];
        scanf("%s %s", t1, t2);
        string f = t1;
        string s = t2;
        if (s == "non-existent" || s == "recessive" || s == "dominant"){
            ans[f]=s;
        } else {
            fam[s].push_back(f);
        }
    }
    msvs::iterator i;
    iter(fam, i){
        string k = i->first;
        string fh = i->second[0];
        string mh = i->second[1];
        string 
    }

    cout << endl;
    mss::iterator ii;
    iter(ans, ii){
        cout << ii->first << ' ' << ii->second << endl;
    }

    return 0;
}