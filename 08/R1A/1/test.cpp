#include<string>
#include<iostream>
using namespace std;

class ABC{
    public:
        string createString(int N,int K){
            char s[N+1];
            int nb=(N-N/3)/2;
            for(int i=0;i<N/3;i++)s[i]='C';
            for(int i=N/3;i<N/3+nb;i++)s[i]='B';
            for(int i=N/3+nb;i<N;i++)s[i]='A';
            s[N]=0;
            while(K--){
                bool chg=false;
                for(int i=0;i<N-1;i++){
                    if(s[i+1]<s[i]){
                        chg=true;
                        char c=s[i];s[i]=s[i+1];s[i+1]=c;
                        break;
                    }
                }
                if(!chg) return "";
            }
            cout<<s<<endl;
            return string(s);
        }
};
int main(){
    ABC abc;
    cout<<abc.createString(3,3)<<endl;
    return 0;
}
