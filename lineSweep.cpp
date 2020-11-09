#include<bits/stdc++.h>
using namespace std;

#define INF 1<<30
// #define px second
// #define py first
#define px first
#define py second
typedef long long ll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;
// pairll pnts [100];
// int compare(pairll a, pairll b)
// { 
//         return a.px<b.px; 
// }
// double closest_pair(pairll pnts[],int n)
// {
//         // for (int i=0; i<n; i++){
//         //     cout << pnts[i].first << ' ' << pnts[i].second << endl;
//         // } cout << endl;
//         sort(pnts,pnts+n, compare);
//         for (int i=0; i<n; i++){
//             cout << pnts[i].first << ' ' << pnts[i].second << endl;
//         } cout << endl;
//         double best=INF;
//         set<pairll> box;
//         box.insert(pnts[0]);
//         int left = 0;
//         for (int i=1;i<4;++i)
//         {
//             cout << i << " and " << best << endl;
//             while (left<i && pnts[i].px-pnts[left].px > best)
//                 box.erase(pnts[left++]);

//             set<pairll>::iterator jj = box.begin();
//             while(jj!=box.end()){
//                 cout << jj->first << ' ' << jj->second << endl;
//                 jj++;
//             }

//             for( set<pairll>::iterator it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best));it!=box.end() && pnts[i].py+best>=it->py;it++){
//                 // cout << it->py << ' ' << it->px << endl;
//                 best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0)+pow(pnts[i].px - it->px, 2.0)));
//             }
//             box.insert(pnts[i]);
//         }
//         return best;
// }

void cd(vpll points){
    int n = points.size();
    sort(points.begin(), points.end());

    double best = INF;
    int left = 0;
    set<pll> box; box.insert(points[0]);
    for (int i=1;i<n;i++){
        
        bool hbound = points[i].px-points[left].px <= best;
        while(left<i && !hbound ){
            box.erase(points[left]);
            left++;
            hbound = points[i].px-points[left].px <= best;
        }


        pll vbound = {points[i].px-best, points[i].py-best};
        set<pll>::iterator it;
        for(it = box.lower_bound(vbound); it != box.end() && points[i].py+best>=it->py; it++){
            double calculation = sqrt(pow(it->px-points[i].px,2)+pow(it->py-points[i].py,2));
            best = min(best, calculation);
        }
        box.insert(points[i]);
    }

    cout << best << endl;
}

int main(){
    int n=4;
    vpll points = {
        {2,4},
        {3,3},
        {3,4},
        {1,2}
    };

    cd(points);


    // cout << closest_pair(pnts, n) << endl;
    // sort(pnts.begin(), pnts.begin()+n, compare);
    // double best = INF;
    // cout << best << endl;
    // set<pll> box;
    // int left = 0;
    
    // for (int i=1; i<n; i++){
    //     while(left<i && pnts[i].px - pnts[left].px > best ){
    //         box.erase(pnts[left++]);
    //     }

    //     set<pll>::iterator it = box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best));
    //     while(it != box.end() && pnts[i].py+best >= it->py){
    //         double calculation = sqrt(pow(pnts[i].py - it->py, 2)+pow(pnts[i].px - it->px, 2));
    //         best = min(best, calculation);
    //     }

    //     box.insert(pnts[i]);
    // }

    // cout << best << endl;

    return 0;
}