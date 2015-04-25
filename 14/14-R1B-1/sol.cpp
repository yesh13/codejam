#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cstdlib>
using namespace std;

int solve(string s[],int n){
    int p[n];
    int num[n];
    for(int i=0;i<n;i++){
        p[i]=0;
    }
    int sum=0;
    while(p[0]<s[0].length()){
        char c=s[0][p[0]];
        for(int i=0;i<n;i++){
            int k=p[i];
            while(s[i][k]==c){
                k++;if(k==s[i].length())break;
            }
            if(k==p[i]) return -1;
            num[i]=k-p[i];
            p[i]=k;
        } 
        sort(num,num+n);
        for(int i=0;i<n;i++){
           sum+=abs(num[i]-num[n/2]);
        }
    }
    for(int i=0;i<n;i++){
        if(p[i]<s[i].length())return -1;
    }
    return sum;
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
        string s[100];
        ifs>>a;
        for(int j=0;j<a;j++){
            ifs>>s[j];
        }
       int num=solve(s,a); 
        ofs<<"Case #"<<i+1<<": "<<(num>=0?to_string(num):"Fegla Won")<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
