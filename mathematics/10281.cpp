#include<bits/stdc++.h>
using namespace std;

int v = 0;
string pivot = "00:00:00";
double dist_pivot = 0;

double elapsed(string tb, string ta){
    int sa = stoi(ta.substr(0,2).c_str())*3600 + stoi(ta.substr(3,5).c_str())*60 + stoi(ta.substr(6,8).c_str());
    int sb = stoi(tb.substr(0,2).c_str())*3600 + stoi(tb.substr(3,5).c_str())*60 + stoi(tb.substr(6,8).c_str());
    return double(sb-sa)/3600;
}

void changeSpeed(string line){
    pivot = line.substr(0,8);
    v = stoi(line.substr(9,line.size()).c_str());
}

int main(){
    string line;
    while(getline(cin,line)){
        if (line.size()>8){
            double dt = elapsed(line.substr(0,8), pivot);
            dist_pivot += double(v)*dt;
            changeSpeed(line);
        } else {
            double dt = elapsed(line,pivot);
            // dist = dist + double(v)*dt;
            cout << line << ' ' << fixed << setprecision(2) << dist_pivot+double(v)*dt << " km" << endl;
        }
    }

    return 0;
}