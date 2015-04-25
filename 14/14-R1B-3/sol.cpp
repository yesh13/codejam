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
using namespace std;
typedef pair<int,int> int_p;
typedef vector<int_p>::iterator vector_iter;
bool compare(int_p a,int_p b){
    return a.first<b.first;
}
int t,a,b,c;
int mat[50][50];
void solve(vector<int_p> &zips){
    stack<int> stk;
    unordered_set<int> set;
    while(true){
        int last=0;
        for(vector_iter iter=zips.begin();iter!=zips.end();iter++){
            if(iter->first<last){
                continue;
            }
            for(int i=0;i<a;i++){
                if(mat[iter->second-1][i]&&set.count(i)){

                }
            }
        }
    }



}

int main(int argc, char* argv[]){
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
        vector<int_p> zips;
        for(int j=0;j<a;j++){
            ifs>>c;
            zips.push_back(int_p(c,j+1));
        }
        sort(zips.begin(),zips.end(),compare);
        for(int p=0;p<50;p++)
            for(int q=0;q<50;q++){
                mat[p][q]=0;
            }
        for(int j=0;j<b;j++){
            int x,y;
            ifs>>x>>y;
            mat[x-1][y-1]=1;
            mat[y-1][x-1]=1;
        }
        ofs<<"Case #"<<i+1<<": ";
        solve(zips);
        ofs<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
