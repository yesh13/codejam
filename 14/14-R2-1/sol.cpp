#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int s[10000];

int solve(int n,int x){
sort(s,s+n);
int i=0,j=n-1;
int ret=0;
while(i<j){
    if(s[i]+s[j]<=x){
        i++;j--;ret++;
    }else{
        ret++;j--;
    }
}
if(i==j) ret++;
return ret;
}

int main(int argc, char* argv[]){
    int t,a,b,c;
    ifstream ifs;
    if(argc!=2){
        cout<<"file not found"<<endl;
        return 1;
    }
    ifs.open(argv[1]);
    ofstream ofs("result.out");
    ifs>>t;
    for(int i=0;i<t;i++){
        ifs>>a>>b;
        for(int j=0;j<a;j++){
            ifs>>s[j]; 
        }
        int num=solve(a,b);
        ofs<<"Case #"<<i+1<<": "<<num<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
