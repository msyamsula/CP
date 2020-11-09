#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define um unordered_map
#define vi vector
#define pi pair

void showDic(um<string, vi<string> > v){
    int len = v.size();
    um<string, vi<string> >::iterator it;
    for (it=v.begin(); it != v.end(); it++){
        string key = it->first;
        cout << key << ' ';
        vi<string> value = it->second;
        cout << '[';
        for (int j=0; j<value.size(); j++){
            if (j<value.size()-1){
                cout << value[j] << ", ";
            } else {
                cout << value[j];
            }
        }
        cout << ']' << endl;
    }
}

um<string, vi<string> > createDic(vi<string> str, um<string, vi<string> > d, int size){
    int lenStr = str.size();
    int lenDic = d.size();

    if (lenDic == 0){
        for (int i=0; i<lenStr; i++){
            string key = str[i].substr(0, 1);
            d[key].push_back(str[i]);
        }
    } else {
        for (int i=0; i<lenStr; i++){
            string newKey = str[i].substr(0, size);
            string oldKey = str[i].substr(0, size-1);

            // if (d[oldKey].size() < 3){
            //     continue;
            // }

            int j = 0;
            while(j<d[oldKey].size()){
                // cout << oldKey << ' ' << newKey << ' ' << d[oldKey][j] << ' ' << str[i] << endl;
                if (newKey == d[oldKey][j].substr(0, size) && str[i] != d[oldKey][j]){
                    d[newKey].push_back(d[oldKey][j]);
                    d[oldKey].erase(d[oldKey].begin()+j);
                } else {
                    j++;
                }
            }
        }
    }

    return d;
}

int main(){
    int T;
    cin >> T;

    vi<int> result;
    for (int t=0; t<T; t++){
        int N;
        cin >> N;
        vi<string> myStr;
        for (int i=0; i<N; i++){
            string temp;
            cin >> temp;
            int len = temp.length();
            string tempRev;
            for (int j=1; j<len+1; j++){
                tempRev += temp[len-j];
            }
            myStr.push_back(tempRev);
        }

        um<string, vi<string> > d;
        for (int i=0; i<N; i++){
            d = createDic(myStr, d, i+1);
        }

        // showDic(d);

        um<string, vi<string> >::iterator it;
        int totRhym = 0;
        for (it=d.begin(); it!=d.end(); it++){
            int den = it->first.length();
            int num = it->second.size();
            if (num == 0){
                continue;
            }
            int rhym = (2*den > num) ? int(num/2)*2 : 2*den; 
            // cout << den << ' ' << num << ' ' << rhym << endl;
            totRhym += rhym;
        }
        // cout << totRhym << ' ';
        result.push_back(totRhym);
        // cout << endl;
    }

    for (int t=1; t<T+1; t++){
        cout << "Case #" << t << ": " << result[t-1] << endl;
    }


    return 0;
}