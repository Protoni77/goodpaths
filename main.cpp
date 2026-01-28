#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <set>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> adm;

bool doesEdgeExists(int u, int v)
{
    if(u>=adm.size()||v>=adm.size()) return false;
    return binary_search(adm[u].begin(),adm[u].end(),v);
}

vector<int> FiLoGoPa(int n)
{
    if(n==0) return {};
    vector<int> bepa;
    for(int i=0; i<10000; i++)
    {
        uniform_int_distribution<int> dis(0,n-1);
        int sn = dis(rng);
        vector<int> curr_path;
        curr_path.push_back(sn);
        set<int> paset;
        paset.insert(sn);
        while(true)
        {
            int ln = curr_path.back();
            vector<int> cand;
            for(int nn : adm[ln])
            {
                if(paset.count(nn)) continue;
                bool iv = true;
                for(size_t i=0; i<curr_path.size()-1; i++)
                {
                    int vi = curr_path[i];
                    if(doesEdgeExists(nn,vi))
                    {
                        iv=false;
                        break;
                    }
                }
                if(iv) cand.push_back(nn);
            }
            if(cand.empty()) break;
            uniform_int_distribution<size_t> cand_di(0, cand.size()-1);
            int vn = cand[cand_di(rng)];
            curr_path.push_back(vn);
            paset.insert(vn);
        }
        if(curr_path.size()>bepa.size())
            bepa=move(curr_path);
    }
    return bepa;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    adm.resize(n);
    for(int i=0; i<m; i++)
    {
        int u,v; cin>>u>>v;
        if(u>=0 && u<n && v>=0 && v<n)
        {
            adm[u].push_back(v);
            adm[v].push_back(u);
        }
    }
    for(int i=0; i<n; i++)
    {
        sort(adm[i].begin(),adm[i].end());
    }
    vector<int> res_pa = FiLoGoPa(n);

    cout<<res_pa.size()<<"\n";
    if(!res_pa.empty())
    {
        for(size_t i=0; i<res_pa.size(); i++)
        {
            cout << res_pa[i] << (i == res_pa.size() - 1 ? "" : " ");
        }
        cout<<"\n";
    }
    return 0;
}
