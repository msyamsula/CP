#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vs arr;

void solve(int n){
    // cout << n << endl;
    int maxlen = -1;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        maxlen = max(maxlen, int(arr[i].size()));
    }

    int col = 62/(maxlen+2);
    int row = ceil(double(arr.size())/col);

    sort(arr.begin(), arr.end());

    string dash(60,'-');
    cout << dash << endl;

    vs temp;
    for(int i=0; i<arr.size(); i++){
        string cs = arr[i];
        string fs;
        int r = i%row, c = i/row;
        int nc = c+1;
        if (nc*row+r >= arr.size() && c!=col-1) fs.assign(maxlen, ' ');
        else if (c==col-1) fs.assign(maxlen, ' ');
        else fs.assign(maxlen+2, ' ');

        for(int j=0; j<cs.size(); j++){
            fs[j]=cs[j];
        }
        temp.push_back(fs);
        // cout << fs << 'a' << endl;
    }

    // vvs mat;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int idx = j*row+i;
            cout << temp[idx];
            // mat[i][j] = arr[idx];
        }
        cout << endl;
    }


}

int main(){
    int n;
    while(cin>>n){
        // cout << "Case #" << i+1 << ": ";
        solve(n);
    }

    return 0;
}