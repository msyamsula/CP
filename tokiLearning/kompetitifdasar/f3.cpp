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

set<string> mem;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string name; cin>>name;
        mem.insert(name);
        int j=0;
        for(string n : mem){
            if (name == n) break;
            j++;
        }

        cout << j+1 << endl;
    }
    return 0;
}
