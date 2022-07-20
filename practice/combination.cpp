#include <bits/stdc++.h>
using namespace std;

void print(const vector<int>& arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << ", " [i==arr.size()-1];
    cout << '\n';
}

void printCompute(int i, int n, int r, vector<int> arr)
{
    if(i > n+1)
        return;
    if(arr.size() == r) 
    {
        print(arr);
        return;
    }
    arr.push_back(i);
    printCompute(i+1,n,r,arr);
    arr.pop_back();
    printCompute(i+1,n,r,arr);
}

int main()
{
    int n,r;
    cin >> n >> r;
    vector<int> arr;
    printCompute(1,n,r,arr);
}