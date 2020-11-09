#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef deque<int> dqi;
typedef vector<dqi> vdqi;

vi pos;
vdqi state;
dqi mover;

void solve(string line){
    stringstream ss(line);
    vs word; string temp;
    while(ss>>temp){
        word.push_back(temp);
    }
    int a = stoi(word[1]), b = stoi(word[3]);
    if (pos[a] == pos[b]) return;
    // cout << "tes" << endl;
    if (word[0] == "move" && word[2] == "onto"){
        while(state[pos[a]].back() != a){
            int cb = state[pos[a]].back(); state[pos[a]].pop_back();
            state[cb].push_back(cb);
            pos[cb] = cb;
        }

        mover.push_back(state[pos[a]].back());
        state[pos[a]].pop_back();

        while(state[pos[b]].back() != b){
            int cb = state[pos[b]].back(); state[pos[b]].pop_back();
            state[cb].push_back(cb);
            pos[cb] = cb;
        }
        state[pos[b]].push_back(mover.back());
        mover.pop_back();
        pos[a] = pos[b];
    } else if (word[0] == "move" && word[2] == "over"){
        while(state[pos[a]].back() != a){
            int cb = state[pos[a]].back(); state[pos[a]].pop_back();
            state[cb].push_back(cb);
            pos[cb] = cb;
        }

        mover.push_back(state[pos[a]].back());
        state[pos[a]].pop_back();

        state[pos[b]].push_back(mover.back()); mover.pop_back();
        pos[a] = pos[b];

    } else if (word[0] == "pile" && word[2] == "onto"){
        while(state[pos[a]].back() != a){
            mover.push_back(state[pos[a]].back()); state[pos[a]].pop_back();
        }
        mover.push_back(state[pos[a]].back()); state[pos[a]].pop_back();

        while(state[pos[b]].back() != b){
            int cb = state[pos[b]].back(); state[pos[b]].pop_back();
            state[cb].push_back(cb);
            pos[cb] = cb;
        }

        while(mover.size()>0){
            int cb = mover.back();
            state[pos[b]].push_back(cb); mover.pop_back();
            pos[cb] = pos[b];
        }
    } else if (word[0] == "pile" && word[2] == "over"){
        while(state[pos[a]].back() != a){
            mover.push_back(state[pos[a]].back()); state[pos[a]].pop_back();
        }
        mover.push_back(state[pos[a]].back()); state[pos[a]].pop_back();

        while(mover.size()>0){
            int cb = mover.back();
            state[pos[b]].push_back(cb); mover.pop_back();
            pos[cb] = pos[b];
        }
    }
}

int main(){
    int n; cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i=0; i<n; i++){
        pos.push_back(i);
        dqi temp; temp.push_back(i);
        state.push_back(temp);
    }

    // for (int i=0; i<n; i++){
    //     cout << pos[i] << ' ';
    // } cout << endl;

    string line;
    while(getline(cin, line)){
        if (line == "quit") break;
        // cout << line << endl;
        solve(line);
        // for (int i=0; i<n; i++){
        //     cout << pos[i] << ' ';
        // } cout << endl;
    }

    for(int i=0; i<n; i++){
        cout << i << ":";
        for (int j=0; j<state[i].size(); j++){
            cout << ' ' << state[i][j];
        } cout << endl;
    }


    return 0;
}