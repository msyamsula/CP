#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

class Robot{
    vs grid;
    int r,c;
    int orientation;
    string orien = "NESW";
    int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
    public:
        Robot(int r, int c, vs grid){
            this->r = r;
            this->c = c;
            this->grid = grid;
            this->orientation = 0;
        };

        void rotateRight(){
            this->orientation = (this->orientation+1)%4;
        }

        void rotateLeft(){
            this->orientation = (this->orientation == 0) ? 3 : this->orientation-1;
        }

        void forward(){
            int o = this->orientation;
            int newr=this->r; newr += dy[o];
            int newc=this->c; newc += dx[o];
            if (newr < 0 || newr >= grid.size() || newc < 0 || newc >= grid[0].size()) return;
            if (grid[newr][newc] == '*') return;
            // cout << o << ' ' << dx[0] << ' ' << dy[o] << endl;
            // cout << this->r << ' ' << this->c << endl;
            // cout << newr << ' ' << newc << endl;
            this->r = newr; this->c = newc;
        }

        void printPos(){
            cout << this->r+1 << ' ' << this->c+1 << ' ' << orien[this->orientation] << endl;
        }
};

void solve(){
    int r,c; cin>>r>>c;
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    vs grid(r);
    for(int i=0; i<r; i++){
        getline(cin,grid[i]);
        // cin>>grid[i];
    }

    // for(int i=0; i<r; i++){
    //     cout << grid[i] << endl;
    // }

    int rp, cp; cin>>rp>>cp;
    Robot myrobot(rp-1,cp-1,grid);
    while(true){
        string scom; cin>>scom;
        // cout << scom << endl;
        bool end = 0;
        for(int i=0; i<scom.size(); i++){
            char command = scom[i];
            if (command == 'R'){
                myrobot.rotateRight();
            } else if (command == 'L'){
                myrobot.rotateLeft();
            } else if (command == 'F'){
                myrobot.forward();
            } else if (command == 'Q') {
                end = 1;
                break;
            } else {
                continue;
            }
        }

        if(end) break;
    }

    myrobot.printPos();
    // cout << endl;
}

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}