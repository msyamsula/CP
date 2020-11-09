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

map<string, string> mem;

int main(){
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++){
        string key,phone; cin>>key>>phone;
        mem[key] = phone;
    }

    for(int i=0; i<q; i++){
        string a; cin>>a;
        string ans;
        try{
            ans = mem.at(a);
        } catch (const exception &e){
            ans = "NIHIL";
        }

        cout << ans << endl;
    }

    return 0;
}
