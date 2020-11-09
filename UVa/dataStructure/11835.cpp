#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi race;
vvi score;

void standing(vi sc){
    int g = race.size(), p = race[0].size(), k = sc.size();
    vi point(p,0);
    for(int i=0; i<g; i++){
        for(int j=0; j<p; j++){
            // cout << i << ' ' << j << endl;
            int fin = race[i][j];
            // if (fin > k) continue;
            point[j] += sc[fin];
        }
    }
    // cout << "tes" << endl;


    int m = *max_element(point.begin(),point.end());
    vi ans;
    for(int i=0; i<p; i++){
        // cout << point[i] << ' ';
        if (point[i] == m) ans.push_back(i+1);
    }
    // cout << endl;

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}

void solve(int g, int p){
    race.resize(0);
    race.assign(g, vi(p,0));
    for(int i=0; i<g; i++){
        for(int j=0; j<p; j++){
            cin>>race[i][j];
            race[i][j]--;
        }
    }

    // cout << g << " gp " << p << endl;
    // for(vi temp : race){
    //     for(int a : temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }

    int s; cin>>s;
    score.resize(0);
    score.resize(s);
    for(int i=0; i<s; i++){
        int k; cin>>k;
        score[i].assign(p,0);
        for(int j=0; j<k; j++){
            cin>>score[i][j];
        }
    }


    for(int i=0; i<score.size(); i++){
        standing(score[i]);
    }
}

int main(){
    int g,p;
    while(cin>>g>>p){
        if (g == 0 && p == 0) break;
        // cout << "Case #" << i+1 << ": ";
        solve(g,p);
    }

    return 0;
}