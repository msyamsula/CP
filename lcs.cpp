#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef map<ii, string> miis;

string dp(int i1, int i2, string s1, string s2, miis &mem){
    ii key = make_pair(i1,i2);
    if (mem.find(key) != mem.end()){
        cout << "memo" << endl;
        return mem.at(key);
    }

    cout << "calculate" << endl;
    if (i1 == s1.size() || i2 == s2.size()) return mem[key] = "";
    if (s1[i1] == s2[i2]) return mem[key]=s1[i1]+dp(i1+1,i2+1,s1,s2,mem);

    string one = dp(i1+1,i2,s1,s2,mem);
    string two = dp(i1,i2+1,s1,s2,mem);
    string three = dp(i1+1,i2+1,s1,s2,mem);
    string ans = (one.size() > two.size()) ? one : two;
    ans = (ans.size() > three.size()) ? ans : three;
    return mem[key] = ans;
}

int main(){
    // string a = "ajaib", b = "badai";
    string a,b;
    cin>>a>>b;
    // a = "aaa"; b= "z";
    miis mem;
    cout << dp(0,0,a,b,mem) << endl;

    miis::iterator ii=mem.begin();
    while(ii!=mem.end()){
        cout << ii->first.first << ' ' << ii->first.second << endl;
        cout << ii->second << endl;
        ii++;
    }
    // cout << max(a, b) << endl;

    return 0;
}