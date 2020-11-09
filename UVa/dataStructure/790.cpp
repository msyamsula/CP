#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

class ScoreBoard{
    public:
        map<char, int> rejected;
        set<char> solved;
        int totTime;
        int no;

        ScoreBoard(int no=0){
            rejected.clear();
            solved.clear();
            totTime = 0;
            no = no;
        }

        void insert(char p, bool acc, int t, int team){
            if (acc && solved.find(p)==solved.end()){
                int time = t + 20*rejected[p];
                solved.insert(p);
                totTime += time;
            } else if (!acc){
                rejected[p] += 1;
            }
            no = team;
        }
};

struct data {
    int team;
    char p;
    bool acc;
    int time;
};

vector<ScoreBoard> score;
vector<data> d;
set<int> tim;

bool comp(ScoreBoard a, ScoreBoard b){
    if (a.solved.size() > b.solved.size()){
        return 1;
    } else if (a.solved.size() == b.solved.size()){
        return (a.totTime < b.totTime);
    } else if (a.totTime == b.totTime){
        return (a.no < b.no);
    }

    return 0;
}

int timecal(string time){
    // cout << time << endl;
    string h, m;
    int i;
    for(i=0; i<time.size(); i++){
        // cout << i << endl;
        if (time[i] == ':') break;
        h += time[i];
    }

    // cout << h << endl;

    for(i=i+1; i<time.size(); i++){
        // cout << i << ' ';
        m += time[i];
    }
    // cout << endl;

    // cout << h << ' ' << m << endl;

    int hh = stoi(h)*60, mm = stoi(m);
    // cout << hh << ' ' << mm << endl;
    // cout << hh+mm << endl;
    return hh+mm;
}

void solve(int team){
    char prob; cin>>prob;
    string time; cin>>time;
    char stat; cin>>stat;
    bool acc = (stat == 'Y') ? 1 :0;

    int t = timecal(time);
    data itemd;
    tim.insert(team);
    itemd.p = prob;
    itemd.acc = acc;
    itemd.time = t;
    itemd.team = team;
    d.push_back(itemd);
}

int main(){
    // int tc; cin>>tc;
    int team;
    while(cin>>team){
        // cout << "Case #" << i+1 << ": ";
        solve(team);
    }
    score.resize(tim.size());
    for(data item : d){
        cout << item.team << ' ' << item.p << ' ' << item.acc << ' ' << item.time << endl;
        score[item.team-1].insert(item.p, item.acc, item.time, item.team);
    }

    // score[0].insert('A', 1, 80);


    sort(score.begin(), score.end(), comp);

    int rank = 1;
    cout << "RANK " << "TEAM " << "PRO/SOLVED " << "TIME" << endl;
    for(ScoreBoard s : score){
        string sol = (int(s.solved.size()) == 0) ? " " : to_string(s.solved.size());
        string ti = (s.totTime == 0) ? " " : to_string(s.totTime);
        // cout << (s.totTime == 0) << endl;
        cout << setfill(' ') << setw(4) << rank << ' ' << setw(4) << s.no << ' ' << setw(4) << sol << ' ' << setw(10) << ti << endl;
        rank++;
    }

    return 0;
}