#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n),lis(n,1);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int i = 1;
    while(i < n)
    {
        int j = 0;
        while(j < i)
        {
            if(arr[i] > arr[j] && lis[i] <= lis[j])
                lis[i] = 1 + lis[j];
            j++;
        }
        i++;
    }
    // for(int i = 0 ; i < n ; i++)
    //     cout << lis[i] << ' ';
    // cout << '\n';
    cout << *max_element(lis.begin(),lis.end());
}