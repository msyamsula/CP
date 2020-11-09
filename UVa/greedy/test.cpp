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


int main(){
    string temp;
    // vs output;
    ll i=0;
    while(cin>>temp){
        // output.push_back(temp);
        if(i!=0) cout << ',';
        cout << "'" << "DT-" << temp << "'";
        i++;
    }
    cout << endl;

    return 0;
}
