#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a, b=1, c=1;
    for(int i = 3; i<=n; i++){
        a = b+c;
        b = c;
        c = a;
    }

    cout<<a;

    return 0;
}
