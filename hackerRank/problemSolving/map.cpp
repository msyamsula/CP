#include<bits/stdc++.h>
using namespace std;

typedef map<string, string> mii;

int main(){
    mii a;
    a.insert({"abc","xyz"});
    a.insert({"abc","abc"});

    cout << a["abc"] << endl;

    return 0;
}