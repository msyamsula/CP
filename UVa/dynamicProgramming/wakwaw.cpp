#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;
typedef map<long, long> mll;
vl primes;
bitset<10000005> bs;

void sieve(long upperbound){
    bs.set();
    bs[0] = bs[1] = 0;
    for(long i=2; i<=upperbound; i++){
        if(bs[i]){
            for(long j=i*i; j<=upperbound; j+=i){
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(long num){
    if (num < 10000000) return bs[num];
    for(long i=0; i<primes.size(); i++){
        if (num%primes[i] == 0) return 0;
    }

    return 1;
}

void solve(){
    int num; cin>>num;
    cout << "number : " << num << endl;
    if (num == 0 || num == 1){
        cout << 0 << endl;
        return;
    }
    mll pf;
    long idx = 0;
    while(!isPrime(num)){
        if (num%primes[idx] == 0){
            // cout << "division" << endl;
            pf[primes[idx]]++;
            num /= primes[idx];
            // cout << num << endl;
        } else {
            idx++;
        }
    }
    pf[num]++;

    long ans = 1;
    for(pair<long,long> temp : pf){
        cout << temp.first << ' ' << temp.second << endl;
        if(temp.first == 2) ans *= temp.second;
        else ans *= (1+temp.second);
    }
    if (pf.find(2) == pf.end()){
        cout << 0 << endl;
        return;
    }


    cout << ans << endl;
}

int main(){
    sieve(100);
    for(long num : primes){
        cout << num << ' ';
    }
    cout << endl;
    vl even;
    for (int i=2; i<=100; i+=2){
        even.push_back(i);
    }

    for(long num : even){
        cout << num << ' ';
    }
    cout << endl;
    cout << primes.size() << ' ' <<even.size() << endl;
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}