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

string s;
vi under;
vi cap;

void toSnake(){
    int n=s.size();
    int m = cap.size();
    string temp = "";
    for(int i=0; i<cap.size(); i++){
        int prev = (i-1<0) ? 0 : cap[i-1];
        // cout << "tes" << i << ' ' << prev << endl;
        temp += s.substr(prev,cap[i]-prev);
        temp += '_';
    }
    string buf = s.substr(cap[m-1], s.size()-cap[m-1]);
    temp+=buf;

    for(int i=0; i<temp.size(); i++){
        temp[i] = tolower(temp[i]);
    }

    s=temp;
}

void toCamel(){
    int m = under.size();
    string temp = "";
    for(int i=0; i<m; i++){
        int prev = (i-1<0) ? 0 : under[i-1]+1;
        // cout << "tes" << i << ' ' << prev << endl;
        string buf = s.substr(prev,under[i]-prev);
        if(prev != 0) buf[0] = toupper(buf[0]);
        temp += buf;
    }
    string buf = s.substr(under[m-1]+1, s.size()-under[m-1]-1);
    buf[0] = toupper(buf[0]);
    temp += buf;

    s=temp;
}

void solve(){
    under.resize(0); cap.resize(0);
    int n=s.size();
    bool normal = 1;
    bool camel = 0;
    for(int i=0; i<n; i++){
        // cout << i << s[i] << endl;
        
        if (!isalpha(s[i])){
            under.push_back(i);
            normal=0;
        } else if (isupper(s[i])){
            cap.push_back(i);
            camel = 1;
            normal=0;
        }
    }

    // for(int idx : cap){
    //     cout << idx << endl;
    // }

    // cout << camel << endl;
    if (normal){
        
    } else if (!camel) {
        toCamel();
    } else {
        toSnake();
    }

    cout << s << endl;
}

int main(){
    while(cin>>s){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}