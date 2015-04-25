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

int solve(int a){
    int s2[10000];
    int left[10000];
    int right[10000];
    int u[10000];
    for(int i=0;i<a;i++){
        s2[i]=s[i];
        left[i]=right[i]=0;
    }
    for(int i=1;i<a;i++){
        int j=i;
        while(j>0&&s[j-1]>s[j]){
            int c=s[j];s[j]=s[j-1];s[j-1]=c;
            j--;
        }
        left[i]=left[i-1]+i-j;
    }
    for(int i=1;i<a;i++){
        int j=i;
        while(j>0&&s2[a-j]>s2[a-1-j]){
            int c=s2[a-j];s2[a-j]=s2[a-j-1];s2[a-j-1]=c;
            j--;
        }
        right[i]=right[i-1]+i-j;
    }
    for(int i=1;i<=a-1;i++){
        u[i-1]=left[i-1]+right[a-i-1];
    }
    return *min_element(u,u+a-1);
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
        ifs>>a;
        for(int j=0;j<a;j++){
            ifs>>b;s[j]=b;
        }
        int num=solve(a);
        ofs<<"Case #"<<i+1<<": "<<num<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
