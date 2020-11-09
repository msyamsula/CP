#include<bits/stdc++.h>
using namespace std;

typedef map<int, int> mii;
typedef vector<int> vi;

void solve(int tc){

    mii stud[3];
    for (int i=0; i<3; i++){
        int sz; cin>>sz;
        for (int j=0; j<sz; j++){
            int q; cin>>q;
            stud[i][q] = 1;
        }
    }

    // for (int i=0; i<3; i++){
    //     mii::iterator ii=stud[i].begin();
    //     while(ii!=stud[i].end()){
    //         cout << ii->first << ' ';
    //         ii++;
    //     } cout << endl;
    // }

    // try{
    //     int found = stud[1].at(2);
    //     cout << found << endl;
    // } catch (const exception &e){
    //     cout << "not found" << endl;
    // }

    vi ans[3];
    int ms = 0;
    for (int i=0; i<3; i++){
        mii::iterator ii=stud[i].begin();
        while(ii!=stud[i].end()){
            int val = ii->first;
            bool found = 0;
            for (int j=0; j<3; j++){
                if (j==i) continue;
                try{
                    found = stud[j].at(val);
                    break;
                } catch (const exception &e){}
            }

            if (!found){
                ans[i].push_back(val);
            }
            ii++;
        }
        // cout << ans[i].size() << ' ' << ms << ' ' << (ans[i].size() > ms) << endl;
        if (ans[i].size() > ms) ms = ans[i].size();
        // cout << ms << endl;
    }

    // cout << ms << endl;
    cout << "Case #" << tc << ':' << endl;
    for (int i=0; i<3; i++){
        if (ans[i].size() == ms){
            cout << i+1 << ' ' << ms;
            for (int j=0; j<ms; j++){
                cout << ' ' << ans[i][j];
            } cout << endl;
        }
    }

    

    // for (int i=0; i<3; i++){
    //     for (int j=0; j<ans[i].size(); j++){
    //         cout << ans[i][j] << " \n"[j==ans[i].size()-1];
    //     }
    // }
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}