#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
typedef long LONG;
LONG match(string s){
    string cont="welcome to code jam";
    LONG len=s.length();
    if(len<=18) return 0;
    vector<vector<LONG> > count;
    count.resize(2);
        count[0].push_back(0);
        count[1].push_back(0);
    for(LONG i=0;i<len;i++){
        count[0].push_back(1);
        count[1].push_back(1);
    }
    LONG lenc=cont.length();
    LONG ret;
    for(LONG i=0;i<lenc;i++){
        count[(i+1)%2][0]=0;
        for(LONG j=0;j<len+1;j++){
            count[(i+1)%2][j+1]=(count[(i+1)%2][j]+count[i%2][j+1]*(cont[i]==s[j]))%10000;
        }
        ret=count[(i+1)%2][len];
        cout<<cont[i]<<":"<<ret<<endl;
    }
    return ret;
}

int main(int argc, char* argv[]){
    LONG l,d,n;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    vector<string> cases;
    vector<string> pattern;
    ifs>>l;
    string trial;
    getline(ifs,trial);
    
    for(LONG i=0;i<l;i++){
        string s;
        getline(ifs,s);
        cases.push_back(s);
        cout<<s<<endl;
    }
    ifs.close();
    ofstream ofs("result.out");
    for(LONG i=0;i<l;i++){
            LONG num=match(cases[i])%10000;
        ofs<<"Case #"<<i+1<<": "<<setfill('0')<<setw(4)<<num<<endl;
    }
    ofs.close();
    return 0;
}
