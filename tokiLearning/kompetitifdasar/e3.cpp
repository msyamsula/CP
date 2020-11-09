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

vs names;
bool comp(string a, string b){
    if (a.size() != b.size()){
        return a.size() < b.size();
    }

    return a<b;
}

int main(){
    int n; cin>>n;
    names.resize(0);
    for(int i=0; i<n; i++){
        string name; cin>>name;
        names.push_back(name);
    }

    sort(names.begin(), names.end(), comp);
    for(string n : names){
        cout << n << endl;
    }
    return 0;
}
