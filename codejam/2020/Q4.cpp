#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<char> vc;

string construct(vi mybit){
    int b=mybit.size();
    string ans;
    for(int i=0; i<b; i++){
        ans += to_string(mybit[i]);
    }
    return ans;
}

void getDb(int s, int e, vi &mybit){
    for(int i=s; i<=e;i++){
        cout << i << endl << flush;
        cin >> mybit[i-1];
    }
}

bool comp(vi oldBit, vi newBit){
    int b = oldBit.size();
    for(int i=0; i<4; i++){
        if (oldBit[i] == newBit[i]) return 0;
    }

    for(int i=b-5; i<b; i++){
        if (oldBit[i] == newBit[i]) return 0;
    }

    return 1;
}

bool sw(vi oldBit, vi newBit){
    int b = oldBit.size();
    for(int i=0; i<4; i++){
        if (oldBit[i] != newBit[b-i-1]) return 0;
    }

    for(int i=b-5; i<b; i++){
        if (oldBit[i] != newBit[b-i-1]) return 0;
    }

    return 1;
}

bool compsw(vi oldBit, vi newBit){
    int b = oldBit.size();
    for(int i=0; i<4; i++){
        if (oldBit[i] == newBit[b-i-1]) return 0;
    }

    for(int i=b-5; i<b; i++){
        if (oldBit[i] == newBit[b-i-1]) return 0;
    }

    return 1;
}

void solve(int b){
    vi mybit(b);
    string ans = "";
    int bit;
    int half = b/2;
    getDb(1,half,mybit);
    getDb(half+1,b,mybit);
    // for(int i=b; i>b-5;i--){
    //     cout << i << endl << flush;
    //     cin >> mybit[i-1];
    // }
    if (b == 10){
        string ans = construct(mybit);
        cout << ans << endl << flush;
    } else if (b == 20) {
        vi newBit(b);
        for(int i=0; i<10; i++){
            getDb(1,4,newBit);
            getDb(b-4,b,newBit);
        }
    } else {

    }
    char y; cin>>y;
    if ( y == 'N') exit(1);
    return;
}

int main(){
    // int tc; cin>>tc;
    // int t; cin>>t;
    int t,b; cin>>t>>b;
    for(int i=0; i<t; i++){
        // cout <<"Case #" << i+1 << ": ";
        solve(b);
    }

    return 0;
}