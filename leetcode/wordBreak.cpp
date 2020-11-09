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

class Solution {
public:
    vl dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        ll c=s.size(), r=wordDict.size();
        dp.assign(c+1, 0);
        queue<ll> q; q.push(0);
        while(!q.empty()){
            ll si = q.front(); q.pop();
            for(ll i=0; i<r; i++){
                ll cur_size = wordDict[i].size();
                if (si+cur_size>c) continue;
                string cur_string(s.begin()+si, s.begin()+si+cur_size);
                if (cur_string == wordDict[i] && dp[si+cur_size] == 0){
                    dp[si+cur_size] = 1;
                    q.push(si+cur_size);
                }
            }
        }

        for(ll num : dp){
            cout << num << ' ';
        }
        cout << endl;
        return 1;
    }
};
