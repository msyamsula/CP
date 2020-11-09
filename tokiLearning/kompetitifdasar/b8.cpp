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

class myque{
    deque<int> arr;
    bool cor;
    public:
    myque(){
        arr.resize(0);
        cor = 1;
    }

    void add(int x, int y){
        if (cor){
            for(int i=0; i<y; i++){
                arr.push_back(x);
            }
        } else {
            for(int i=0; i<y; i++){
                arr.push_front(x);
            }
        }
        cout << arr.size() << endl;
    }

    void del(int y){
        if (cor){
            cout << *arr.begin() << endl;
            for(int i=0; i<y; i++){
                if (arr.empty()) break;
                arr.pop_front();
            }
        } else {
            cout << *arr.rbegin() << endl;
            for(int i=0; i<y; i++){
                if (arr.empty()) break;
                arr.pop_back();
            }
        }
    }

    void rev(){
        cor = !cor;
    }

    void show(){
        for(int num : arr){
            cout << num << ' ';
        }
        cout << endl;
    }
};

int main(){
    // q.resize(0);
    myque q;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string c; cin>>c;
        if (c == "add"){
            int x,y; cin>>x>>y;
            q.add(x,y);
        } else if (c == "del"){
            int y; cin>>y;
            q.del(y);
        } else if (c == "rev") {
            q.rev();
        }
        // cout << "array" << endl;
        // q.show();
        // for(int num : q){
        //     cout << num << ' ';
        // }
        // cout << endl;
    }

    return 0;
}
