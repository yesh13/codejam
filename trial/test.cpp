#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <unordered_set>
#include <list>
using namespace std;

class Solution {
    public:
        bool close(string a,string b){
            int n=a.length();
            if(b.length()!=n) return false;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=a[i]!=b[i];
            }
            if(sum==1) return true;
            return false;
        }
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            if(end==start) return 0;
            typedef unordered_set<string>::iterator Iter;
            dict.insert(end);
            int step=0,begin=0;
            vector<string> build;build.push_back(start);
            while(dict.count(end)){
                int size=build.size();
                for(Iter iter=dict.begin();iter!=dict.end();){
                    string pu=*iter;
                    iter++;
                    for(int i=begin;i<size;i++){
                        if(close(build[i],pu)){
                            build.push_back(pu);
                            dict.erase(pu);
                        }
                    }
                }
                if(size==build.size()) return 0;
                step++;begin=size;
            }
            return step+1;
        }
};


int main(int argc, char* argv[]){
    int t,a,b,c;
    ifstream ifs;
    if(argc==2){
        ifs.open(argv[1]);
        cin.rdbuf(ifs.rdbuf());
    }
    ofstream ofs("result.out");
    Solution s;
    vector<int> num;
    string start,end;
    unordered_set<string> dict;
    cin>>start>>end>>t;
    for(int i=0;i<t;i++){
        string str; cin>>str;
        dict.insert(str);
    }
    int len=s.ladderLength(start,end,dict);
    cout<<"maximumGap: "<<len<<endl;
    ofs.close();
    return 0;
}
