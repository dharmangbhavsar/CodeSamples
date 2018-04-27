#include <bits/stdc++.h>
#include <fstream>
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define iOs ios_base::sync_with_stdio(false);
#define INF 111313131 
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi; 
//int counter[10000001];
int stringtoint(string r)
{
    int num=0;
    int n=r.size();  int i=0;
    //cout<<r<<"               bnskfoanfonairfa\n";
    while(i<n)
    {
        num+=int(r[i]-'0');
        if(i<n-1)
        {//num+=(r[n]-'0');
            num*=10;}
        i++;

    }
    return num;
}
char easytolower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 
int main()
{
    vector<string> stringVec;
    vector<int> intVec;
    //fr; fw;
    iOs;
    int tester;
    cin>>tester; string rest; 
    std::getline(std::cin,rest); 
    while(tester--)
    {
    string s; cout<<s<<endl;
    std::getline(std::cin,s); 
    int cnt=0,ni=s.size(); //cout<<ni<<endl; 
    for(int i=0; ;i++)
    {
        string t="."; int n=0;
        int j=i;
        if(cnt%2==0){ 
        while(s[i]!=' ')
        {
            i++;
        }
        t=s.substr(j,i-j);
        std::transform(t.begin(), t.end(), t.begin(), easytolower);
        stringVec.push_back(t);
        }
        else
        {
            //cout<<"in"<<endl;
            while(s[i]!=' ' && i<ni)
            {
                //cout<<"in"<<endl;
                i++;
            }
            t=s.substr(j,i-j);
            //cout<<i-j-1<<endl; 
            //cout<<stringtoint(t)<<endl;
            intVec.push_back(stringtoint(t));
        }
        cnt++;
        //cout<<"here"<<endl;
        if(i==(int)s.size()) break;
    }
    sort(all(intVec));
    sort(all(stringVec));
    //cout<<"here2"<<endl;
    for(int i=0;i<(int)intVec.size();i++)
    {
        cout<<stringVec[i]<<" ";
        cout<<intVec[i]<<" ";
    }
    vector<int>().swap(intVec);
    vector<string>().swap(stringVec);
    cout<<endl;
}
    return 0;
}