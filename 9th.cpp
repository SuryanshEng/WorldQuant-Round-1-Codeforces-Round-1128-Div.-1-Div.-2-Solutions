#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Nd{int c[2],n;};
static Nd t[400005*27+5];
int sz;
int mk(){t[sz]={{0,0},0};return sz++;}
int ins(unsigned par,unsigned p){
    int r=mk(),x=r;t[x].n=1;
    int y=mk();t[y].n=1;t[x].c[par]=y;x=y;
    for(int b=24;b>=0;b--){y=mk();t[y].n=1;t[x].c[p>>b&1]=y;x=y;}
    return r;
}
int mg(int a,int b){
    if(!a)return b;
    if(!b)return a;
    t[a].n+=t[b].n;
    t[a].c[0]=mg(t[a].c[0],t[b].c[0]);
    t[a].c[1]=mg(t[a].c[1],t[b].c[1]);
    return a;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        sz=1;
        vector<pair<unsigned,int>> st,ns;
        unsigned P=0;
        ll ans=0;
        for(int r=1;r<=n;r++){
            unsigned a;cin>>a;
            unsigned Pj=P;P^=a;
            ns.clear();
            for(auto&[A,rt]:st){
                A&=a;
                if(!A)continue;
                if(!ns.empty()&&ns.back().first==A) ns.back().second=mg(ns.back().second,rt);
                else ns.push_back({A,rt});
            }
            if(a){
                int rt=ins((r-1)&1,Pj);
                if(!ns.empty()&&ns.back().first==a) ns.back().second=mg(ns.back().second,rt);
                else ns.push_back({a,rt});
            }
            swap(st,ns);
            unsigned par=(r&1)^1;
            for(auto&[A,rt]:st){
                unsigned w=P^A;
                int x=t[rt].c[par];
                if(!x)continue;
                ll s=0;
                for(int b=24;b>=0;b--){
                    x=t[x].c[w>>b&1];
                    if(!x)break;
                    if(A>>b&1)s+=(ll)t[x].n<<b;
                }
                ans+=s;
            }
        }
        cout<<ans<<'\n';
    }
}