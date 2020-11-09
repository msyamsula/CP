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

ll n;

void solve(){
    // cout << "tes" << endl;
    cin>>n;
    string sufix="", prefix="";
    vs pattern;
    for(ll i=0; i<n; i++){
        string temp; cin>>temp;
        pattern.push_back(temp);
    }


    for(ll i=0; i<n; i++){
        string temp = pattern[i];
        // cout << temp << endl;
        ll ast=0;
        for(ll j=0; j<temp.size(); j++){
            if (temp[j]=='*'){
                ast = j; break;
            };
        }
        string p = temp.substr(0,ast);
        string s = temp.substr(ast+1,temp.size());

        if (sufix == "") sufix = s;
        else{
            ll minlen =(sufix.size()<s.size()) ? sufix.size() : s.size();
            for(ll ii=0; ii<minlen; ii++){
                if (sufix[sufix.size()-ii-1] != s[s.size()-ii-1]){
                    cout << '*' << endl;
                    return;
                }
            }
            sufix = (sufix.size()<s.size()) ? s : sufix;
        }

        if (prefix=="") prefix = p;
        else {
            ll minlen =(prefix.size()<p.size()) ? prefix.size() : p.size();
            for(ll ii=0; ii<minlen; ii++){
                if (prefix[ii] != p[ii]){
                    cout << '*' << endl;
                    return;
                }
            }
            prefix = (prefix.size()<p.size()) ? p : prefix;
        }
    }

    ll totlen = sufix.size() + prefix.size();

    if (totlen >= 10000){
        cout << '*' << endl;
        return;
    } else if (totlen == 10000){
        cout << prefix+sufix << endl;
        return;
    }

    cout << prefix+sufix << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
