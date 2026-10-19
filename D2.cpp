#include <bits/stdc++.h>
using namespace std;
int p[200005];
int fnd(int x){return p[x]==x?x:p[x]=fnd(p[x]);}
struct S{int s,e;bool in;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        for(int i=0;i<=n;i++) p[i]=i;
        for(int i=0;i<m;i++){int l,r;cin>>l>>r;p[fnd(l-1)]=fnd(r);}
        vector<int> lo(n+1,INT_MAX),hi(n+1,-1);
        for(int i=0;i<=n;i++){int r=fnd(i);lo[r]=min(lo[r],i);hi[r]=max(hi[r],i);}
        int d0=fnd(0),dn=fnd(n);
        vector<S> st;
        vector<int> cov(n+2,0),a;
        for(int j=1;j<n;j++){
            int r=fnd(j),L=lo[r],R=hi[r];
            if(r==d0||r==dn){st.clear();continue;}
            if(L<j){
                int k=int(upper_bound(st.begin(),st.end(),L,[](int v,const S&x){return v<x.s;})-st.begin())-1;
                if(k<0) st.clear();
                else{
                    while((int)st.size()>k+1){
                        st[k].e=max(st[k].e,st.back().e);
                        st[k].in|=st.back().in;
                        st.pop_back();
                    }
                    st[k].e=max(st[k].e,R);
                }
            }else st.push_back({j,R,false});
            while(!st.empty()&&st.back().e==j){
                S c=st.back();st.pop_back();
                cov[c.s]++;cov[j+1]--;
                if(!c.in) a.push_back(c.s);
                if(!st.empty()){st.back().in=true;st.back().e=max(st.back().e,c.e);}
            }
        }
        int s=a.size(),q=0,cur=0;
        bool prev=false;
        for(int i=1;i<n;i++){
            cur+=cov[i];
            bool c=cur>0;
            if(c&&!prev) q++;
            prev=c;
        }
        vector<pair<int,int>> res;
        auto link=[&](int x,int y){res.push_back({x+1,y});};
        auto lnk0=[&](int x){res.push_back({1,x});};
        if(s){
            if(s&1){
                int c=(s+1)/2;
                lnk0(a[c-1]);
                for(int i=1;i<c;i++) link(a[i-1],a[c+i-1]);
            }else if(q>=2){
                int h=s/2;
                for(int i=1;i<=h;i++) link(a[i-1],a[h+i-1]);
            }else{
                int c=s/2;
                lnk0(a[c-1]);lnk0(a[c]);
                for(int i=1;i<c;i++) link(a[i-1],a[c+i]);
            }
        }
        cout<<res.size()<<"\n";
        for(auto&x:res) cout<<x.first<<" "<<x.second<<"\n";
    }
}