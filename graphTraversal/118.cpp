#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<char, vi> mcvi;

void solve(int px, int py, char o, vvi &grid){
    string line; cin>>line;
    int idi = grid.size()-py-1, idj = px;
    // cout << idi << ' ' << idj << endl;
    string state = "NESW";
    int istate;
    for (int i=0; i<4; i++){
        if (state[i] == o) istate=i;
    }

    mcvi dir = {
        {'N',{0,-1}},
        {'E',{1,0}},
        {'S',{0,1}},
        {'W',{-1,0}}
    };

    for (int i=0; i<line.size(); i++){
        if (line[i] == 'L'){
            istate = (istate-1 == -1) ? 3 : istate-1 ;
        } else if (line[i] == 'R'){
            istate = (istate+1 > 3) ? 0 : istate+1;
        } else if (line[i] == 'F'){
            int dx = dir[state[istate]][0];
            int dy = dir[state[istate]][1];
            int nidi = idi+dy;
            int nidj = idj+dx;
            if (nidi < 0 || nidi >=grid.size() || nidj<0 || nidj>=grid[0].size()){
                if (grid[idi][idj] == 0){
                    grid[idi][idj] = 1;
                    py = grid.size()-idi-1;
                    px = idj;
                    cout << px << ' ' << py << ' ' << state[istate] << " LOST" << endl;
                    return;
                }
                continue;
            }
            idi = nidi; idj = nidj;
            // cout << "position : " << idi << ' ' << idj << ' ' << state[istate] << endl;
        }
    }

    py = grid.size()-idi-1;
    px = idj;
    cout << px << ' ' << py << ' ' << state[istate] << endl;
}

int main(){
    int xm, ym;
    cin >> xm; cin>>ym;
    int px, py; char o;
    vi dummy(xm+1, 0);
    vvi grid(ym+1, dummy);    
    while(cin>>px){
        cin>>py; cin>>o;
        solve(px, py, o, grid);
    }

    // cout << ((-4)%2) << endl;
    return 0;
}