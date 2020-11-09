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
    vvl dp;
    int twoCitySchedCost(vector<vector<int>>& costs) {
        ll n =costs.size();
        dp.assign(n+1, vl(n+1, MAXLL));
        queue<vl> q; q.push({0,0,0});

        while(!q.empty()){
            vl temp = q.front();
            ll a=q[0], b=q[1], idx=q[2];
            q.pop();
            if (j>n/2 || i>n/2) continue;
            if (a+1<=n/2){
                dp[a+1][b] = min(dp[a+1][b], dp[a][b]+cost[idx][0]);
                q.push({a+1,b,idx+1});
            }
            if (b+1<=n/2){
                dp[a][b+1] = min(dp[a][b+1], dp[a][b]+cost[idx][1]);
                q.push({a,b+1,idx+1});
            }
        }
        
        for(vl temp : dp){
            for(ll num : temp){
                cout << num << ' ';
            }
        }
        cout << endl;

        return 0;
    }
};