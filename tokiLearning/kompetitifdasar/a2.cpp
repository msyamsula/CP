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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

void solve(){

}

vi primes;
bitset<10000007> bs;

void sieve(long long up){
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2; i<up; i++){
        if (bs[i]){
            for(long long j=i*i; j<up; j+=i) bs[j]=0;
            primes.push_back(int(i));
        }
    }
}

bool isPrime(int n){
    if (n<=1000000) return bs[n];
    for(int i=0; i<primes.size(); i++){
        if (n%primes[i] == 0) return 0;
    }
    return 1;
}

int num;
map<int,int> pF;

int main(){
    sieve(1000000);
    // for(int a : primes){
    //     cout << a << endl;
    // }
    cin>>num;
    int pi=0;
    while(num!=1){
        if (num%primes[pi] == 0){
            num /= primes[pi];
            pF[primes[pi]]++;
        } else {
            pi++;
        }
    }

    int i=0;
    for(pair<int, int> temp : pF){
        if (i!=0) cout << " x ";
        if (temp.second == 1){
            cout << temp.first;
        } else {
            cout << temp.first << '^' << temp.second;
        }
        i++;
    }
    cout << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}