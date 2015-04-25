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

const int limit=1000000007;

long ladd(int n){
    if(n==0) return 1;
    long ret=n;
    while(--n){
        ret*=n;
        ret%=limit; 
    }
    return ret;
}


int find(long mat[26][26],int k,int direction){
    int ret=-1;
   if(direction==0){
        for(int i=0;i<26;i++){
            if(mat[k][i]&&i!=k){
                if(ret==-1) ret=i;
                else return -2;
            }
        } 
   }else{
        for(int i=0;i<26;i++){
            if(mat[i][k]&&i!=k){
                if(ret==-1) ret=i;
                else return -2;
            }
        } 
   
   } 
   return ret;
}

long time(long a,long b){
long c=a*b;
return c%limit;
}



int solve(vector<string> &ts){
    int ret=1;
    long mat[26][26];
    unordered_set<int> set;
    typedef unordered_set<int>::iterator set_it;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            mat[i][j]=0;
        }
    int n=ts.size();
    for(int i=0;i<n;i++){
        string &s=ts[i];
        int from=s[0]-'a';
        bool chg=false;
        for(int j=0;j<s.length();j++){
            if(s[j]-'a'!=from){
                chg=true;
                mat[from][s[j]-'a']++;
                set.insert(from);set.insert(s[j]-'a');
                from=s[j]-'a';
            }
        }
        if(!chg){
        mat[from][from]++;
        set.insert(from);
        }
    }
    for(int i=0;i<26;i++){
        int col=0,row=0;
        for(int j=0;j<26;j++){
            if(i!=j){
                col+=mat[i][j];
                row+=mat[j][i];
            }
        }
        if(col>1||row>1) return 0;
    }
    for(int i=0;i<26;i++){
            mat[i][i]=ladd(mat[i][i]);
    }
    int root=0;
    for(set_it iter=set.begin();iter!=set.end();iter++){
        int size=set.size();
        bool tail=false;
        for(int i=0;i<26;i++){
            if(mat[i][*iter]!=0&&i!=*iter) {
                tail=true;break;
            }
        }
        if(tail) continue;
        root++;
        unordered_set<int> pass;
        pass.insert(*iter);
        int head=*iter;
        int next=head;
        while((next=find(mat,next,0))>=0){
            if(pass.count(next)) return 0;
            mat[head][head]=time(mat[head][head],mat[next][next]);
           pass.insert(next); 
           set.erase(next);
        }
        if(pass.size()>1) set.erase(next);
    } 
    if(root==set.size()){
     
    for(set_it iter=set.begin();iter!=set.end();iter++){
        ret=time(ret,mat[*iter][*iter]);
    }
    }else return 0;
    
    return time(ret,ladd(root));

}

    int main(int argc, char* argv[]){
        int t,a,b,c;
        ifstream ifs;
        if(argc!=2){
            cout<<"file not found"<<endl;
            return 1;
        }
        ifs.open(argv[1]);
        ofstream ofs("out");
        ifs>>t;
        for(int i=0;i<t;i++){
            vector<string> trains;
            ifs>>a;
            for(int i=0;i<a;i++){
                string s;
                ifs>>s;
                trains.push_back(s);
            }
            int num=solve(trains);
            ofs<<"Case #"<<i+1<<": "<<num<<endl;
        }
        ifs.close();
        ofs.close();
        return 0;
    }
