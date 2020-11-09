#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef map<string, vector<int> > msvi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)

int size = 5;

int factorial(int num){
    mii d;
    d[0] = 1;
    d[1] = 1;
    f(i,2,num+1,1){
        d[i] = i*d[i-1];
    }

    return d[num];

}

void show(msvi d){
    msvi::iterator i;
    for (i=d.begin(); i!=d.end(); i++){
        cout << i->first << ' ';
        f(j,0,i->second.size(),1){
            cout << i->second[j] << " \n"[j==i->second.size()-1];
        }
    }
    cout << endl;
}

msvi construct(msvi d, int iter){
    
    int totSee = factorial(size-iter) - 1;
    // int totSee = totPer/size;
    string currKey = d.begin()->first;
    // cout << totSee << endl;
    msvi newD;
    f(i,0,totSee,1){
        int seeIdx;
        if (d.size() == 0){
           seeIdx = (i*size)+1+iter;
        } else {
            seeIdx = d[currKey][i]+iter;
        }
        cout << seeIdx << endl << flush;
        string resp, key;
        cin >> resp;
        key = resp;
        if (d.size() != 0) {
            key = currKey + key;
        }
        newD[key].push_back(seeIdx-iter);
        // show(newD);

    }

    msvi::iterator i;
    int lostCount = factorial(size-iter-1);
    lostCount -= 1;
    // cout << lostCount << endl;
    msvi result;
    for (i=newD.begin(); i!= newD.end(); i++){
        if (i->second.size() == lostCount){
            result[i->first] = i->second;
        }
    }

    // show(result);

    return result;
}


void solveCase(int t){
    string ans;
    msvi d;
    // d["A"].push_back(0);
    // d["B"].push_back(0);
    // d["C"].push_back(0);
    // d["D"].push_back(0);
    // d["E"].push_back(0);

    int i =0;
    while(true){
        d = construct(d, i);
        i++;
        if (d.begin()->second.size() == 1){
            break;
        }
    }
    // show(d);

    msvi::iterator dPtr = d.begin();
    ans = dPtr->first;
    cout << dPtr->second[0]+i << endl << flush;
    string last;
    cin >> last;
    cout << dPtr->second[0]+i+1 << endl << flush;
    string beforeLast;
    cin >> beforeLast;
    ans = ans + beforeLast + last;

    // printf("Case %c%i: ", '#', t);
    cout << ans << endl << flush;
    // printf("")
    string verdict;
    cin >> verdict;
    // return;
    // }
    // cout << d.size() << " TES " << ans << endl << flush;
}


int main(){
    int T, F;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int value;
    int idx=0;
    while (ss>>value){
        if (idx == 0){
            T = value;
        } else {
            F = value;
        }
        idx++;
    }
    // scanf("%i %i", &T, &F);

    // cout << T << ' ' << F << endl;
    f(t,0,T,1){
        solveCase(t+1);
    }

}