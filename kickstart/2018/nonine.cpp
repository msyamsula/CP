#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

long legal(string n){
    long numF = stol(n);
    long lastF = long(n[n.size()-1]) - long('0');
    long F = numF - lastF;
    long legal = numF-F;

    // cout << numF << ' ' << lastF << ' ' << F << endl;

    // cout << "tes" << endl;
    for (long num=F+1; num<=numF; num++){
        // cout << num << endl;
        if (num%9 == 0){
            legal--;
            continue;
        }

        string numStr = to_string(num);
        for(long i=0; i<numStr.size(); i++){
            if (numStr[i] == '9'){
                legal--;
                break;
            }
        }
    }

    vi b(n.size()+1, 0);
    for(long i=1; i<b.size(); i++){
        b[i] = b[i-1]*9 + long(to_string(F)[i-1]) - long('0');
    }
    // b.erase(b.begin());
    // for(int i=0; i<b.size(); i++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    legal += b[b.size()-1]*8/9 - 1;

    return legal;
}

void solve(int tc){
    string f,l; cin>>f>>l;

    long legalF = legal(f), legalL = legal(l);

    long ans = legalL-legalF+1;

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}