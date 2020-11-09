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

vvl mat;
// map<pair<ll, ll>, string> mem;
// queue<>

void solve(){
    ll r,c; cin>>c>>r;
    mat.resize(0); mat.assign(r, vl(c,MAXLL));
    queue<pair<pair<ll,ll>,string>> q;
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            string temp; cin>>temp;
            if (temp[0] != '='){
                mat[i][j] = stoll(temp);
            } else {
                // mem[{i,j}] = temp;
                q.push({{i,j},temp});
            }
        }
    }


    // for(vl temp : mat){
    //     for(ll i=0; i<c; i++){
    //         cout << temp[i] << " \n"[i==c-1];
    //     }
    // }

    while(!q.empty()){
        ll i = q.front().first.first, j = q.front().first.second;
        string s = q.front().second;
        // cout << s << endl;
        q.pop();
        ll value = 0;
        bool success = 1;
        ll ii = 0;
        while(ii<s.size()){
            char sign = s[ii];
            ii++;
            string ccs;
            while(isalpha(s[ii])){
                ccs += s[ii]; ii++;
            }
            ll cc = 0;
            for(ll iii=0; iii<ccs.size(); iii++){
                cc += (ccs[iii]-'A'+1)*(pow(26,ccs.size()-iii-1));
            }
            cc--;
            string rrs;
            while(isdigit(s[ii])){
                rrs += s[ii]; ii++;
            }
            ll rr;
            for(ll iii=0; iii<rrs.size(); iii++){
                rr = stoll(rrs)-1;
            }
            // rr=s[ii+2]-'1';
            // cout << rrs << ' ' << ccs << ' ' << rr << ' ' << cc << endl;
            // cout << rr << ' ' << cc << ' ' << mat[rr][cc] << endl;
            if (mat[rr][cc] == MAXLL){
                q.push({{i,j},s});
                success = 0;
                break;
            }
            // cout << "tes " << ii << ' ' << s[ii+2] << ' ' << rr << ' ' << cc << endl;
            if (sign == '-') value -= mat[rr][cc];
            else value += mat[rr][cc];
        }
        if (success) mat[i][j] = value;
    }

    // for(pair<pair<ll,ll>, string> temp : mem){
    //     cout << i << ' ' << j << endl;
    // }

    for(vl temp : mat){
        for(ll i=0; i<c; i++){
            cout << temp[i] << " \n"[i==c-1];
        }
    }
    // cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
