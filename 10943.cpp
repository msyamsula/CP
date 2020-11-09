#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;
typedef map<ii, long long> miii;


long long solve(long long ck, long long tot, long long n, long long k, miii &mem){
    ii key = {ck,tot};
    if (mem.find(key) != mem.end()){
        // cout << "memo ";
        // cout << ck << ' ' << tot << ' ' << mem.at(key) << endl;
        return mem.at(key);
    }
    // try{
    //     return mem.at(key);
    // } catch(const exception &e){
    // }

    // cout << ck << ' ' << tot << endl;

    if (ck == k){
        if (tot == n){
            mem[key] = 1;
            return 1;
        }
        mem[key] = 0;
        return 0;
    }

    // if (tot > n){
    //     mem[key] = 0;
    //     return 0;
    // }

    long long ans = 0;
    for (long long i=0; i<=n; i++){
        if (tot+i > n) continue;
        ans += solve(ck+1, tot+i, n, k, mem)%1000000;
    }

    mem[key] = ans%1000000;
    return ans;
}

int main(){
    long long n, k;
    while(cin>>n>>k){
        if (n==0 && k==0) break;
        miii mem;
        long long ans = solve(0,0,n,k,mem);
        cout << ans << endl;
    }

    return 0;
}