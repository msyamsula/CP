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


void solve(ll n){
    string start = "0123456789";
    bool found = 0;
    for(ll i=1234; i<=98765/n; i++){
        ll b = i*n;
        string test = to_string(i)+to_string(b);
        set<char> totNum;
        if (test.size()<10) totNum.insert('0');
        for(char ctemp : test){
            totNum.insert(ctemp);
        }

        if (totNum.size()==10){
            found = 1;
            cout << setw(5) << setfill('0') << b << " / " <<setw(5) << setfill('0') <<  i << " = " << n << endl;
        }
    }

    if (!found){
        cout << "There are no solutions for " << n << '.' << endl;
    }
}

int main(){
    ll num;
    int i=0;
    while(cin>>num){
        if (num == 0) break;
        if (i!=0) cout << endl;
        solve(num);
        i++;
    }
    // for(ll i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
