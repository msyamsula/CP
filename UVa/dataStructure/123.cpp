#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

set<string> ban;
map<string, vvs> mem;

void upper(string &a){
    for(int i=0; i<a.size(); i++){
        a[i] = toupper(a[i]);
    }
}

void lower(string &a){
    for(int i=0; i<a.size(); i++){
        a[i] = tolower(a[i]);
    }
}

void solve(){
    string line;
    while(cin>>line){
        if (line == "::") break;
        ban.insert(line);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string title;
    while(getline(cin,title)){
        lower(title);
        // cout << ltitle << endl;
        stringstream ss(title);
        string w;
        vs temp;
        while(ss>>w){
            temp.push_back(w);
        }

        for(int i=0; i<temp.size(); i++){
            string word = temp[i];
            if(ban.find(word) != ban.end()) continue;
            upper(temp[i]);
            mem[temp[i]].push_back(temp);
            lower(temp[i]);
        }
    }

    for(pair<string, vvs> temp : mem){
        string key = temp.first; vvs v = temp.second;
        for(vs sen : v){
            for(int i=0; i< sen.size(); i++){
                if(i!=0) cout << ' ' << sen[i];
                else cout << sen[i];
            }
            cout << endl;
        }
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}