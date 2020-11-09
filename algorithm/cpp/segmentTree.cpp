#include<bits/stdc++.h>
using namespace std;

#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef deque<int> dqi;

vi segmentTree(vi a){
    vi sTree;
    vvi layer;
    layer.push_back(a);
    int s = a.size();
    // int p = __builtin_ctz(s);
    // int evaSize = 1<<p;
    // cout << s << ' ' << __builtin_ctz(s) << endl;
    int appSize;
    if (__builtin_popcount(s) == 1){
        appSize = s;
    } else {
        int lz = __builtin_clz(s);
        appSize = 1 << (32-lz);
    }
    sTree.push_back(appSize);

    while(layer[0].size() != appSize){
        layer[0].push_back(0);
    }
    // cout<<lz<<endl;
    // if (s%2 == 1){
    //     layer[0].push_back(0);
    // }
    int totLayer = (log(appSize)/log(2));
    // cout << totLayer << endl;
    f(l,1,totLayer+1,1){
        vi newLayer;
        int prevSize = layer[l-1].size();
        // if (prevSize%2 == 1){
        //     layer[l-1].push_back(0);
        // }
        int maxSize = layer[l-1].size()/2;
        // cout << maxSize << endl;
        f(i,0,maxSize,1){
            int index = i*2;
            int value = layer[l-1][index]+layer[l-1][index+1];
            newLayer.push_back(value);
        }
        layer.push_back(newLayer);
    }

    f(l,0,totLayer+1,1){
        int idxLay = totLayer-l;
        int s = layer[idxLay].size();
        f(i,0,s,1){
            sTree.push_back(layer[idxLay][i]);
        }
    }

    return sTree;
}

void show(vi a){
    int s = a.size();
    f(i,0,s,1){
        cout << a[i] << " \n"[i==s-1];
    }
}

int maxQuery(vi st, int i, int j){
    int n = st[0];

    i += n;
    j += n;

    int sum=0;
    while(i<=j){
        // cout << i << ' ' << j <<' ' << sum << endl;
        if (i%2 == 1){
            sum += st[i];
            i++;
        }
        if (j%2 == 0){
            sum += st[j];
            j--;
        }


        i/=2;
        j/=2;
    }

    return sum;
}

int main(){
    vi a={1,2,3,4,5,1,2,5};
    vi st = segmentTree(a);
    show(st);
    int sub = maxQuery(st, 3, 6);
    cout << sub << endl;
    return 0;
}