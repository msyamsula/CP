#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

ll N, M;
vs words;
vs cur;
string digits = "0123456789";

void search(string p, ll idx){
    if (idx == p.size()){
        return;
    }
    char c = p[idx];
    // cout << c << endl;
    if (c == '#'){
        if (cur.size() == 0){
            cur = words;
            // for(string c : cur){
            //     cout << c << endl;
            // }
            return search(p, idx+1);
        }
        vs new_cur;
        for(ll i=0; i<cur.size(); i++){
            for(ll j=0; j<words.size(); j++){
                new_cur.push_back(cur[i]+words[j]);
            }
        }
        cur = new_cur;
        return search(p, idx+1);
    }

    if (cur.size() == 0){
        cur = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        return search(p, idx+1);
    }

    vs new_cur;
    for(ll i=0; i<cur.size(); i++){
        for(ll j=0; j<digits.size(); j++){
            new_cur.push_back(cur[i]+digits[j]);
        }
    }
    cur = new_cur;
    // for(string c : cur){
    //     cout << c << endl;
    // }
    return search(p, idx+1);
}

void solve(){
    cout << "--" << endl;

    words.resize(0);
    for(ll i=0; i<N; i++){
        string temp; cin>>temp;
        words.push_back(temp);
    }
    // for(string w : words){
    //     cout << w << endl;
    // }
    cin>>M;
    for(ll i=0; i<M; i++){
        string pattern; cin>>pattern;
        // cout << pattern << endl;
        cur.resize(0);
        search(pattern, 0ll);
        for(string c : cur){
            cout << c << endl;
        }
    }
}

int main(){
    while(cin>>N){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
