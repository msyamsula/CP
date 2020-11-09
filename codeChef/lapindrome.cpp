#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;

mci count(string s){
    mci ans;
    for(int i=0; i<s.size(); i++){
        ans[s[i]] += 1;
    }
    return ans;
}

void solve(){
    string s; cin>>s;
    int n = s.size();
    mci left, right;
    string ans;
    int mid = (n-1)/2;
    int ll = (n%2==0) ? mid+1 : mid;
    int rl = mid+1;
    string ls = s.substr(0,ll), rs = s.substr(rl,n);
    // cout << ls << ' ' << rs << endl;
    left = count(ls), right = count(rs);
    ans = (left == right) ? "YES" : "NO";
    
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}