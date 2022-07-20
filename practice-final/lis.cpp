#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int lis[n] = {1};
    int i = 1;
    while(i < n)
    {
        int j = 0;
        while(j < i)
        {
            if(arr[j] < arr[i] && lis[j] >= lis[i])
                lis[i] = 1+lis[j];
            j++;
        }
        i++;
    }
    cout << *max_element(lis,lis+n);
}