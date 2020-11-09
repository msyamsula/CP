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

unordered_map<char, ll> bin;
vs arr;
vector<vector<char>> city;
vl score;
void solve(){
    while(1){
        string s; cin>>s;
        if (s[0]=='e') break;
        arr.push_back(s);
    }
    // for(string temp : arr){
    //     cout << temp << endl;
    // }
    // cout << endl;
    ll n = arr.size();
    city.resize(0); city.assign(n, vector<char>(5, '.'));

    for(ll i=0; i<n; i++){
        string temp = arr[i];
        for(ll j=0; j<temp.size(); j+=4){
            ll idx = bin[temp[j]];
            city[i][idx] = temp[j+2];
        }
    }
    // for(vector<char> temp : city){
    //     for(char a : temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    score.resize(0); score.assign(n, 0);

    for(ll k=0; k<n; k++){
        vector<char> eg = city[k];
        for(ll j=0; j<n; j++){
            for(ll i=0; i<n; i++){
                if (city[i][j] != eg[j]) score[k]++;
            }
        }
    }

    // for(ll num : score){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll minim = MAXLL;
    ll idx;
    for(ll i=0; i<score.size(); i++){
        if (score[i]<=minim){
            minim = score[i];
            idx = i;
        }
    }

    cout << idx+1 << endl;

}

int main(){
    bin['r']=0;
    bin['o']=1;
    bin['y']=2;
    bin['g']=3;
    bin['b']=4;
    string s;
    while(cin>>s){
        if(s=="#") break;
        arr.resize(0);
        arr.push_back(s);
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
