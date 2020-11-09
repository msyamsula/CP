#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vvi;
// typedef bitset<1000> bs;
typedef map<vi, long long> mbsi;


void solve(){
    // mem.clear();
    mbsi mem;
    long long n,s; cin>>n>>s;

    vvi person;
    for(long long i=0; i<n; i++){
        long long ci; cin>>ci;
        vi st;
        for(long long j=0; j<ci; j++){
            long long si;
            cin>>si; st.push_back(si);
        }
        mem[st] += 1;
        person.push_back(st);
    }
    // cout << "data: " << endl;
    // for(vi temp : person){
    //     for(long long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "mem: " << endl;
    // for(pair<vi, long long> temp : mem){
    //     for(long long num : temp.first){
    //         cout << num << ' ';
    //     }
    //     cout << ": " << temp.second << endl;
    // }

    long long canTeach = 0;
    for(vi bigset : person){
        long long s = bigset.size();
        long long nsubset = (1LL<<s);
        long long cantTeach = 0;
        // cout << endl << "bigset : ";
        // for(long long num : bigset){
        //     cout << num << ' ';
        // }
        // cout << endl;
        for(long long i=0; i<nsubset; i++){
            bitset<5> bs(i);
            // cout << bs << endl;
            vi subset;
            for(long long j=0; j<5; j++){
                // if (j == bs.size()) break;
                if (bs[j]){
                    subset.push_back(bigset[j]);
                }
            }
            // if (subset == bigset) continue;
            // for(long long num : subset){
            //     cout << num << ' ';
            // }
            // cout << endl;
            // cout << ": " << mem[subset] << endl;
            long long add;
            try{
                add = mem.at(subset);
            } catch (const exception &e){
                add = 0;
            }
            cantTeach += add;
        }
        canTeach += n - cantTeach;
    }
    
    // cout << minus << endl;
    // cout << "case : " << n << endl;
    // for (pair<set<long long>, long long> temp : mem){
    //     set<long long> key = temp.first;
    //     cout << "key : ";
    //     for(long long num : key){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    //     cout << temp.second << endl;
    // }
    // cout << endl;

    // long long unique = mem.size();
    // long long ans = long long(n)*long long(n);
    // ans -= minus;
    // cout << minus << endl;
    cout << canTeach << endl;
}

int main(){
    long long tc; cin>>tc;
    for(long long i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}