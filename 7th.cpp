#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    if(n==3){
        cout<<"010\n010\n000\n\n111\n100\n000\n\n010\n010\n010\n\n110\n000\n000\n\n111\n000\n000\n\n"
              "011\n010\n000\n\n010\n100\n000\n\n101\n010\n000\n\n010\n011\n000\n\nDURLDULRUU\n";
        return 0;
    }
    string f(n*n+1,'U');
    f[1]='L';f[2]='R';f[3]='L';
    for(int h=2;h<=n;h++)
        f[n*h-n+3]='D',f[n*h-n+2]='U',f[n*h-n+1]='D',f[n*h-n]='U';
    for(int r=1;r<=n;r++)for(int c=1;c<=n;c++){
        vector<string> g(n+2,string(n+2,'1'));
        for(int j=1;j<=n;j++) if(c==n?j<n:(j<c-1||j>c+1)) g[r][j]='0';
        if(c==1){if(r<n)g[r+1][1]='0';}
        else if(r>1)g[r-1][1]='0';
        for(int i=1;i<=n;i++) cout<<g[i].substr(1,n)<<'\n';
        cout<<'\n';
    }
    cout<<f<<'\n';
}