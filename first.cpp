#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ys cout<<"YES\n";
#define no cout<<"NO\n";

int digit(int n)
{
    int m=0;
    while(n>0)
    {
        n/=2;
        m++;
    }
    return m;
}
vector<int> CB(int n)
{
    vector<int>v;
    while(n>0)
    {
        v.push_back(n%2);
        n/=2;
    }
    return v;
}
int CD(vector<int>v)
       {
           int num=0;
           for(int i=0;i<v.size();i++)
            num+=(v[i]*pow(2,i));
           return num;
       }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ress=0; cin>>n;
        int ar[n-1];
        for(int i=0;i<n-1;i++) cin>>ar[i];

        //int ma= *max_element(ar,ar+n-1);

        int fast= digit(ar[0]);
        vector<int> v,res;
        for(int i=0;i<fast;i++) v.push_back(1);
        fast= CD(v);

        res.push_back(fast);
        for(int i=0;i<n-1;i++)
        {
            if(ress==1) break;
            int num= ar[i];
            vector<int>vc;
            vc= CB(num);
            for(int j=0;j<min(v.size(),vc.size());j++)
            {
                if(vc[j]==1 && v[j]==0){ress=1;break;}
               // if(vc[j]==0 && v[j]==0) vc[j]=1;
            }
            if(i<n-2 && digit(ar[i+1])>vc.size())
            {
                int m= digit(ar[i+1])-vc.size();
                while(m--) vc.push_back(1);
            }
            v=vc;
            cout<<CD(vc)<<endl;
            res.push_back(CD(vc));
        }
        if(ress==1) cout<<"-1\n";
        else
        {
            for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
            cout<<"\n";
        }
    }
}
