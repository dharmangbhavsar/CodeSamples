#include <bits/stdc++.h>
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define iOs ios_base::sync_with_stdio(false);
#define INF 111313131 
#define all(x) (x).begin(), (x).end()
#define debug cout<<"here\n"
#define debugin cout<<"inhere\n" 
#define debugname cout<<"dharmang\n";
using namespace std;
#define pb push_back
#define mp make_pair
#define sc second
#define fir first
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int ans = INT_MAX;
bool valid (int i)
{
    if(i<12 and i>=0) return true;
    else return false;
}
void solve(string s, int score)
{
    string t = s, y =s; int scoredup = score, scoredup2 = score;
    //cout<<s<<endl;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='o' and valid(i+1) and t[i+1]=='o' and valid(i-1) and t[i-1]=='-')
        {
            t[i-1]='o'; t[i]='-'; t[i+1]='-';
            scoredup--;
            solve(t,scoredup);
        }
        if(s[i]=='o' and valid(i+1) and s[i+1]=='o' and valid(i+2) and s[i+2]=='-')
        {
            y[i+2] = 'o'; y[i]='-'; y[i+1]='-';
            scoredup2--;
            solve(y, scoredup2);
        }
    }
    ans = min(ans, score);
    //cout<<ans<<endl;
    return; 
}
int main()
{
    //fw; fr;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        ans=INT_MAX;
        string s; cin>>s; int c=0;
        for(int i=0;i<12;i++)
            if(s[i]=='o') c++;
        solve(s, c);
        cout<<ans<<endl;
    }
    return 0;
}
