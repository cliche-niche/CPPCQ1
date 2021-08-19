#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <time.h>
#define ll long long int
using namespace std;
#define cases() int test_case; cin >> test_case; while(test_case--)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.

/****************
Code for solving.
****************/

bool v[10000];
int w[10];

int optk(int x, set<int> (&sn), set<int> (&sk), vector< vector<int> > (&a), vector < vector<int> > (&s), int k){

    bool done=1; int cn;

    for(auto i:a[x]){
        if(sn.find(i)==sn.end()){
            sn.insert(i);
            cn=i;
            done=0;
            break;
        }
    }

    if(done){
        return 0;
    }


    int m=0;
    for(int i=0; i<k; i++){
        if(sk.find(i)==sk.end()){
            sk.insert(i);
            m = max(m, s[cn][i]+optk(x, sn, sk, a, s, k));
            sk.erase(sk.find(i));
        }
    }

    sn.erase(sn.find(cn));

    return m;
}

void dfs(int x, vector< vector<int> > (&a), vector < vector<int> > (&s), int k, int p){
    v[x]=1;

    for(int i=0; i<k; i++){
        s[x][i]=w[i];
    }

    bool leaf=1;
    for(auto i:a[x]){
        if(!v[i]){
            dfs(i, a, s, k, x);
            leaf=0;
        }
    }

    if(leaf){
        return;
    }


    set <int> sn, sk; sn.insert(p);
    for(int i=0; i<k; i++){
        sk.insert(i);
        s[x][i] += optk(x, sn, sk, a, s, k);
        sk.erase(sk.find(i));
    }
    return;
}

void solve(void){
    
    freopen("test.txt", "r", stdin);
    freopen("ans.text", "w", stdout);

    int n, f, k, x, y;
    cin>>n>>f>>k;
    cout<<n<<' '<<f<<' '<<k<<'\n'; //input related

    vector < vector<int> > a(n); v[0]=0;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        cout<<x<<' '<<y<<'\n'; //input related
        x--; y--;
        a[x].push_back(y); a[y].push_back(x);
        v[i+1]=0;
    }


    for(int i=0; i<k; i++){
        cin>>w[i];
        cout<<w[i]<<' '; //input related
    }

    vector < vector<int> > s(n);
    for(int i=0; i<n; i++){
        s[i].resize(k);
    }

    dfs(0, a, s, k, 0);

    int m=0;
    for(int i=0; i<k; i++){
        m = max(m, s[0][i]);
    }

    cout<<"\n\n\n"<<m; //output related

    fclose(stdin);
    fclose(stdout);

    remove("test.txt");
}


/*************************
Code for generating input.
*************************/

#define NMAX 20000
#define FMAX 4
#define KMAX 10

void gen(void){

    freopen("test.txt", "w", stdout);

    srand(time(0));
    int n = 1+(rand())%NMAX;
    int f = 1+(rand())%FMAX;
    int k = 1+(rand())%KMAX;
    int u, v;

    cout<<n<<' '<<f<<' '<<k<<'\n';

    set < pair<int, int> > s;
    map <int, int> m;

    //Printing edges/ friendships.
    for(int PAIRS=n-1; PAIRS;){
        u = 1+(rand())%n;
        v = 1+(rand())%n;
        if(u!=v && m[u]<f && m[v]<f && s.find(make_pair(min(u, v), max(u, v)))==s.end()){
            m[u]++; m[v]++; 
            PAIRS--; 
            s.insert(make_pair(min(u, v), max(u, v)));
            cout<<u<<' '<<v<<'\n';
        }
    }

    //Printing marks for a question.
    for(int i=0; i<k; i++){
        cout<<1+(rand())%1000<<' ';
    }

    fclose(stdout);
}

int main(void)
{

    gen(); //generates input.
    solve(); //writes input and output pair in the same file.
    
    return 0;
}

