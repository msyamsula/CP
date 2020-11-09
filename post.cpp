#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(int tc){
    int r,c;
    cin>>r>>c;
    vs grid(r);
    for(int i=0; i<r; i++){
        cin>>grid[i];
    }

    vi min_distance(r*c, 0);
    vii pos_location;
    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (grid[i][j] == '1') pos_location.push_back({i,j});
        }
    }

    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int idx = i*c+j;
            if (grid[i][j] == '1') continue;
            int md = 1<<30;
            for(int ii=0; ii<pos_location.size(); ii++){
                int d = abs(pos_location[ii].first - i) + abs(pos_location[ii].second - j);
                if (d < md) md = d;
            }
            min_distance[idx] = md;
        }
    }

    int ans = *max_element(min_distance.begin(), min_distance.end());

    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (grid[i][j] == '1') continue;
            vi min_distance_copy = min_distance;
            pos_location.push_back({i,j});
            // int idx = i*c+j;
            for(int ii=0; ii<r; ii++){
                for(int jj=0; jj<c; jj++){
                    int idx = ii*c+jj;
                    int md = 1<<30;
                    for (int iii=0; iii<pos_location.size(); iii++){
                        int d = abs(pos_location[iii].first - ii) + abs(pos_location[iii].second - jj);
                        // cout << d << endl;
                        if (d < md) md = d;
                    }
                    // int temp = min_distance_copy[idx];
                    min_distance_copy[idx] = md;
                }
            }

            ans = min(ans, *max_element(min_distance_copy.begin(), min_distance_copy.end()));
            // cout << ans << endl;
            pos_location.erase(pos_location.begin()+pos_location.size()-1);
        }
    }

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}