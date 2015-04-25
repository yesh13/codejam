#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int t,a,b,c;

struct cus{
    int num;
    vi un;
    int mal;
    static bool compare(cus a,cus b){
       return a.num<b.num; 
    }
};
cus cust[3000];
int s[3000];

void print(){
    forn(i,a){
        s[i]=0;
    }
    while(true){
        bool chg=false;
        forn(i,b){
            bool match=false;
            cus &tom=cust[i];
            if(tom.mal!=-0){
                if(s[tom.mal-1]==1) continue;
            }
            forn(j,tom.un.size()){
                if(s[tom.un[j]-1]==0){
                    match=true;break;
                } 
            }
            if(!match){
                if(tom.mal!=-0){
                   s[tom.mal-1]=1;chg=true; 
                }else{
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
            }
        }
        if(!chg) break;
    }
    forn(i,a){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}



int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        for(int j=0;j<b;j++){
            cin>>cust[j].num;cust[j].mal=0;
            cust[j].un.clear();
            for(int k=0;k<cust[j].num;k++){
                int x,y;cin>>x>>y;
                if(y==1) cust[j].mal=x;
                else{
                    cust[j].un.push_back(x);
                }
            }
        }
        sort(cust,cust+b,cus::compare);
        
        cout<<"Case #"<<i+1<<": ";
        print();
    }
    return 0;
}
