#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string s){
    vector<string> result;
    int l = s.length();
    string temp;
    for (int i=0; i<l; i++){
        if (i == l-1){
            temp += s[i];
            result.push_back(temp);
        } else if (s[i] != ' '){
            temp += s[i];
        } else if (s[i] == ' ') {
            result.push_back(temp);
            temp = "";
        }
    }

    return result;
}

long aVeryBigSum(vector<long> arr){
    int l = arr.size();
    long sum = 0;
    for (int i=0; i<l; i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr;
    getline(cin, arr);
    int l = arr.length();

    vector<string> arr_temp = split_string(arr);

    vector<long> a;

    for (int i=0; i<arr_temp.size(); i++){
        int temp = stol(arr_temp[i]);
        a.push_back(temp);
    }

    long sum = aVeryBigSum(a);

    for (int i=0; i<n; i++){
        sum += a[i];
    }

    cout << sum << endl;

    // vector<string> ar_temp = split_string(arr);

    // cout << ar_temp[0] << endl;

    return 0;
}

