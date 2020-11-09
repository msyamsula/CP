#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<string, int> msi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)

void show(vi a){
    int s = a.size();
    f(i,0,s,1){
        cout << a[i] << " \n"[i==s-1];
    }
}

void showMap(msi a){
    msi::iterator i;
    for(i=a.begin(); i!=a.end(); i++){
        cout << i->first << ' ' << i->second << endl;
    }
}

msi preProcess(vi a){
    show(a);
    int size = a.size();
    msi dict;
    for (int l=1; l<=size; l*=2){
        cout << l << endl;
        f(i,0,size-l+1,1){
            int max = 0;
            char code[256];
            sprintf(code, "%i-%i",i,(i+l-1));
            f(j,i,i+l,1){
                if (a[j] > max){
                    max = a[j];
                }
            }
            cout << ' ' << code << ' ' << max << endl;
            dict.insert({code, max});
        }
    }

    return dict;
}

int maxQuer(vi a, msi dict, int i, int j){
    int size = a.size();

    int range = j-i+1;
    int bigPowTwo = log(range)/log(2);
    int length = (1<<bigPowTwo)-1;
    
    char code1[256];
    sprintf(code1, "%i-%i", i, (i+length));
    char code2[256];
    sprintf(code2, "%i-%i", (j-length), j);


    cout << code1 << ' ' << code2 << endl;
    int result = (dict[code1] > dict[code2]) ? dict[code1] : dict[code2];

    return result;

}

int main(){

    vi a = {1,2,3,4,7,5,6,3,2};
    msi dict = preProcess(a);

    showMap(dict);
    cout << maxQuer(a,dict,2,6) << endl;    

    return 0;
}