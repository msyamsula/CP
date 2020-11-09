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
    // show(a);
    int size = a.size();
    msi dict;
    for (int l=1; l<=size; l*=2){
        // cout << l << endl;
        f(i,0,size-l+1,1){
            int max = 0;
            char code[256];
            sprintf(code, "%i-%i",i,(i+l-1));
            f(j,i,i+l,1){
                if (a[j] > max){
                    max = a[j];
                }
            }
            // cout << ' ' << code << ' ' << max << endl;
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


    // cout << code1 << ' ' << code2 << endl;
    int result = (dict[code1] > dict[code2]) ? dict[code1] : dict[code2];

    return result;

}

int main(){
    int T;
    scanf("%i", &T);

    f(t,0, T, 1){
        int N, K;
        scanf("%i %i", &N, &K);
        vi charles, delila;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        f(sword,0, 2, 1){
            // cout << sword << endl;
            string line;
            getline(cin, line);
            stringstream ss(line);
            int idx=0;
            int value;
            while (ss >> value){
                if (sword == 0){
                    charles.push_back(value);
                } else {
                    delila.push_back(value);
                }
            }
        }

        // show(charles);
        // show(delila);

        msi charDict = preProcess(charles);
        msi delDict = preProcess(delila);

        int result = 0;
        f(i,0,N,1){
            f(j,i,N,1){
                int l=i;
                int r=j;
                int maxChar = maxQuer(charles, charDict, i, j);
                int maxDel = maxQuer(delila, delDict, i, j);
                int dif = (maxDel > maxChar) ? maxDel-maxChar : maxChar - maxDel;
                // cout <<l << r <<' '<< dif << endl;
                if (dif <= K){
                    // comb d{l,r,maxChar,maxDel};
                    result++;
                }
            }
        }

        // showComb(result);
        printf("Case %c%i: %i\n", '#', t+1, result);
        // cout << result << endl;
    }

    return 0;
}