#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

void solve(){
    vi per;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int val;
    while (ss>>val){
        per.push_back(val);
    }

    vs value;
    string temp;
    getline(cin, line);
    stringstream ss1(line);
    while(ss1>>temp){
        value.push_back(temp);
    }

    vs ans(value.size());
    vi::iterator i=per.begin();
    while(i!=per.end()){
        int idx = i-per.begin();
        ans[*i-1] = value[idx];
        i++;
    }

    vs::iterator ii=ans.begin();
    while(ii!=ans.end()){
        cout << *ii << endl;
        ii++;
    }
    
}

int main(){
    int tc; cin>>tc;
    cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
    for (int i=0; i<tc; i++){
        string blank;
        getline(cin, blank);
        if (i!=0) cout << endl;
        solve();
    }    

    return 0;
}