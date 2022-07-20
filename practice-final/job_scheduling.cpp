#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        pii a[n];
        for(int i = 0; i < n ; i++)
            cin >> a[i].first;
        for(int i = 0; i < n ; i++)
            cin >> a[i].second;
        sort(a,a+n,[](pii a, pii b){return a.first > b.first;});
        int profit = 0;
        bool b[100];
        memset(b,false,sizeof(b));
        for(int i = 0 ; i < n ; i++)
        {
            int j = a[i].second-1;
            while(j >= 0)
            {
                if(!b[j])
                {
                    b[j] = true;
                    profit += a[i].first;
                    break;
                }   
                j--;
            }
        }
        cout << profit;
    }
}