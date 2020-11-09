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

vl squares;

void solve(ll sz){
    string base(sz,'0');
    for(ll i=0; i<squares.size(); i++){
        ll abcdefgh = squares[i]; string temp = to_string(abcdefgh);
        if (abcdefgh >= pow(10,sz)) break;
        ll nsz = temp.size();
        string abcdefgh_s=base; abcdefgh_s.replace(sz-nsz,nsz,temp);
        string abcd_s = abcdefgh_s.substr(0,sz/2), efgh_s = abcdefgh_s.substr(sz/2,sz/2);
        ll abcd = stoll(abcd_s), efgh = stoll(efgh_s);
        if ( pow(abcd+efgh,2) == abcdefgh ) cout << abcdefgh_s << endl;
    }
    // for(ll abcd=0; abcd<pow(10,sz/2); abcd++){
    //     string temp = to_string(abcd); ll nsz = temp.size();
    //     string abcd_s = base; abcd_s.replace(sz/2-nsz,nsz,temp);
    //     for(ll efgh=0; efgh<pow(10,sz/2)-abcd; efgh++){
    //         if (abcd+efgh >= pow(10,sz/2)) break;
    //         string temp2 = to_string(efgh); ll nsz2 = temp2.size();
    //         string efgh_s = base; efgh_s.replace(sz/2-nsz2,nsz2,temp2);
    //         // cout << abcd_s << ' ' << efgh_s << endl;
    //         if ( pow(abcd+efgh, 2) == stod(abcd_s+efgh_s) ) cout << abcd_s+efgh_s << endl;
    //     }
    // }
    // for(int i=0; i<(1ll<<(sz/2)); i++){
    //     string nums = to_string(i), temp = base;
    //     ll nsz = nums.size();
    //     temp.replace(sz-nsz,nsz,nums);
    //     string efgh_s = temp.substr(sz/2,sz/2);
    //     ll efgh = stoll(efgh_s);
    //     string abcd_s = temp.substr(0,sz/2);
    //     ll abcd = stoll(abcd_s);
    //     if ( pow(i,0.5)-efgh == double(abcd) ){
    //         cout << abcd_s + efgh_s << endl;
    //     }
    // }
}

int main(){
    for(ll i=0; i*i<(pow(10,8)); i++){
        squares.push_back(i*i);
    }

    // for(ll num : squares){
    //     cout << num << endl;
    // }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    ll sz;
    while(cin>>sz){
        solve(sz);
    }

    return 0;
}
