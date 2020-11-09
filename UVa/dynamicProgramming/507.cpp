#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)

vvl dp;
vvl candidate;
vl temp;
vl nice;
int btPtr;

void backtrack(int i, long long m){
    btPtr--;
    if (i < 0) return;
    if (m==0 && (m-nice[i])!=dp[0][i-1] && i!=0) return;
    if (m==0 && i==0 && nice[i] != dp[0][i]) return;

    if (dp[0][i] == m){
        temp.push_back(i);
        backtrack(i-1, m-nice[i]);
    } else if (dp[1][i] == m){
        temp.push_back(i);
        return;
    } else {
        backtrack(i-1,m);
    }
}

void solve(int tc){

    int n; cin>>n; n--;
    // cout << n << endl;
    nice.resize(0); nice.assign(n, 0);
    // cout << "tes" << endl;
    btPtr = n-1;
    dp.resize(0); dp.assign(3,vl(n,0));
    temp.resize(0);
    candidate.resize(0);


    for(int i=0; i<n; i++){
        cin>>nice[i];
    }

    dp[0][0]= max(0ll,nice[0]); dp[1][0] = nice[0]; dp[2][0] = -MAXLL;
    for(int i=1; i<n; i++){
        dp[0][i] = max(0ll,dp[0][i-1]+nice[i]);
        dp[1][i] = nice[i];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[2][i] = max(dp[2][i], dp[2][i-1]);
    }
    long long m = max(dp[0][n-1], dp[1][n-1]);
    m = max(m, dp[2][n-1]);
    // cout << m << endl;


    

    while(btPtr>=0){
        temp.resize(0);
        backtrack(btPtr, m);
        if (temp.size()>0) candidate.push_back(temp);
    }

    // for(vl a : dp){
    //     for(long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // for(vl a: candidate){
    //     for(long long b:a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // for(long long a:nice){
    //     cout << a << ' ';
    // }
    // cout << endl;

    // cout << candidate.size() << endl;

    if (candidate.size() == 0){
        cout << "Route "<<tc<<" has no nice parts" << endl;
        return;
    } else if (candidate.size() == 1){
        cout << "The nicest part of route "<<tc<<" is between stops "<<candidate[0][candidate[0].size()-1]+1<<" and "<<candidate[0][0]+2<<endl;
        return;
    }

    long long mlen = -MAXLL;
    for(vl c : candidate){
        long long sz = stoll(to_string(c.size()));
        if (sz>mlen){
            mlen = sz;
        }
    }

    // cout << mlen << endl;

    vvl maxCan(0);
    for(vl c : candidate){
        long long sz = stoll(to_string(c.size()));
        if (sz == mlen) maxCan.push_back(c);
    }


    // for(vl a: maxCan){
    //     for(long long b:a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    vl target(mlen, 0);
    long long small = MAXLL;
    for(vl c : maxCan){
        if (c[0] < small){
            // cout << "tes" << endl;
            target = c;
            small = c[0];
        }
    }

    // for(long long a:target){
    //     cout << a << ' ';
    // }
    // cout << endl;

    cout << "The nicest part of route "<<tc<<" is between stops "<<target[target.size()-1]+1<<" and "<<target[0]+2<<endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve(i+1);
    }
    // cout << endl;

    return 0;
}