#include <iostream>
using namespace std;
static int a[1001][1001];
int main()
{
    int i,j,m,n;
    cin>>i;
    cin>>j;
    a[1][1]=1;
    for(m=2;m<=i;m++)
    {
        a[m][1]=a[m-1][1];
    }
    for(n=2;n<=j;n++)
    {
        a[1][n]=a[1][n-1];
    }
    for(m=2;m<=i;m++)
    {
        for(n=2;n<=j;n++)
        {
            a[m][n]=(a[m-1][n]+a[m][n-1])%(int)(1e9+7);
        }
    }
    cout<<a[i][j];
}
