#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,sum=0;
        cin>>n;
        while(n!=0){
            sum = sum + (n % 10);
            n = n / 10;
        }
        cout<<sum<<"\n";
    }
    return 0;
}