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
long a1[800];
long a2[800];

void permute(){
    int is=0,js=0;
    long min=1e18;
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            long tem=-a1[i]*a2[i]-a1[j]*a2[j]+a1[j]*a2[i]+a1[i]*a2[j];
            if(tem<min){
                is=i;js=j;min=tem;
            }
        }
    }
    min=a1[is];a1[is]=a1[js];a1[js]=min;
}
long product(){
    long sum=0;
    for(int i=0;i<a;i++){
        sum+=a1[i]*a2[i];
    }
    return sum;
}

int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>a1[i];
        }
        for(int i=0;i<a;i++){
            cin>>a2[i];
        }
        permute();
        permute();
        long num=product();
        cout<<"Case #"<<i+1<<": "<<num<<endl;
    }
    return 0;
}
