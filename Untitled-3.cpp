#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,kn;string st;cin>>n>>kn>>st;
        vector<int> pw(n+2),sz(n+2),cl(n+2);
        int d=0,A=0,B=0;
        for(char c:s){
            if(c=='('){
                int w=cl[d];d++;
                pw[d]=pw[d-1]+w;sz[d]=1;cl[d]=0;
                if(pw[d]<=kn)A=max(A,d);
                int i=lower_bound(pw.begin()+1,pw.begin()+d+1,pw[d]-k)-pw.begin();
                B=max(B,d-i+1);
            }else{
                cl[d-1]+=sz[d];sz[d-1]+=sz[d];d--;
            }
        }
        cout<<max(B,min(n/2,kn+A))<<'\n';
    }
}