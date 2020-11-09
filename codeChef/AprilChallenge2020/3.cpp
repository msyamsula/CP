#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX (1<<30)
#define MIN (1<<30)

vi primes;
bitset<10000010> bs;

void sieve(long upperbound){
    bs.set();
    bs[0] = bs[1] = 0;
    // cout << bs[2] << endl;
    for(long i=2; i<=upperbound; i++){
        // cout << i << endl;
        if (bs[i]){
            for(long j=i*i; j<=upperbound; j+=i){
                // cout << j << endl;
                bs[j] = 0;
            }
            primes.push_back(int(i));
        }
    }
}

bool isPrime(long number){
    if (number<10000010) return bs[number];
    for(int i=0; i<primes.size(); i++){
        if(number%primes[i] == 0) return 0;
    }
    return 1;
}

void solve(){
    long x,k; cin>>x>>k;
    // int upper = ceil(double(pow(x,0.5)));

    // for(int a=1; a<=upper; a++){
    //     for(int b=1; b<=upper; b++){
    //         if ( (a+1)*(b+1) == x ){
    //             // int ans = pow(2,a)*pow(2,b);
    //             cout << 1 << endl;
    //             return;
    //         }
    //     }
    // }

    cout << !isPrime(x) << endl;
}

int main(){
    sieve(10000000l);
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }
    // cout << bs[10000000] << endl;
    // for(long i=0; i<primes.size(); i++){
    //     cout << primes[i] << ' ';
    // }
    // cout<<endl;
    // cout << isPrime(1000000000l) << endl;
    // cout << primes.size() << endl;

    return 0;
}