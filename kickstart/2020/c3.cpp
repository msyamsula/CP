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

vl arr;
vl kuadrat; //vector
// vl kuadrat2;
vl prevsum;

ll num_to_idx(ll num){
    return (num+10000000);
}

ll idx_to_num(ll idx){
    return (idx-10000000);
}

void solve(){
    // inisiasi data
    prevsum.resize(0);
    prevsum.assign(20000001, 0);
    ll n; cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    // for(ll temp : arr){
    //     cout << temp << ' ';
    // }
    // cout << endl;

    // untuk setiap k di kuadrat cari banyaknya subarray yang hasilnya k
    ll totcount = 0;
    // for(ll k : kuadrat){
    //     prevsum.clear();
    //     ll csum = 0;
    //     ll count = 0;
    //     // cari subarray yang jumlahnya k
    //     for(ll i=0; i<n; i++){
            
    //         csum += arr[i];
    //         if (csum == k) count++;
    //         count += prevsum[csum-k];
    //         prevsum[csum]++;
    //     }
    //     // cout << "k : " << k << ' ' << count << endl;
    //     totcount+=count;
    // }
    ll csum = 0, count = 0, csumabs=0;
    prevsum[num_to_idx(0)] = 1;
    for(ll i=0; i<n; i++){
        csum+=arr[i];
        csumabs += abs(arr[i]);
        // try{
        //     count += kuadrat.at(csum);
        // } catch (const exception &e){
        //     count += 0;
        // }
        // cout << i << endl;
        // ll idx=0;
        for(ll k : kuadrat){
            // ll k = temp.first;
            if (k > csumabs ) break;
            // if (csum-k < 0) continue;
            ll idx = num_to_idx(csum-k);
            count += prevsum[idx];
            // cout << k << ' ' << csum-k << ' ' << count << endl;
            // idx++;
        }
        ll idx = num_to_idx(csum);
        prevsum[idx]++;

    }

    // for(ll num : prevsum){
    //     cout << num << ' ';
    // }
    // cout << endl;


    cout << count << endl;;
    
}

int main(){

    // bikin set kuadrat
    // batas kuadrat dibuat 10^7 kan ada test case yang n = 10^5 dimana -100 < a[i] < 100
    // kuadrat.resize(0);
    // kuadrat[0] = 1;
    kuadrat.push_back(0);
    for(ll i=1; i*i<=10000000; i++){
        // cout << i*i << endl;
        // kuadrat.insert(i*i);
        // kuadrat[i*i] = 1;
        kuadrat.push_back(i*i);
    }

    ll tc; cin>>tc;
    for(ll i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
