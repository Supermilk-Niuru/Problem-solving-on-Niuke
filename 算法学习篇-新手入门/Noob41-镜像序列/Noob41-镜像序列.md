**输入** 在一行内输入n个非负整数，每两个整数之间用空格分隔。需要注意的是，如范围保证，除了最后一个整数为0外，其余整数均为正整数；且至少存在一个整数为0。
**输出** 在一行内按空格分隔输出倒序后的整数序列（不包含结束标志0）
```C++
#include<iostream>
using namespace std;
int main()
{
    long long int a[105]={1};
    int i,j,n=0;
    for(i=0;a[i-1]!=0;i++)
    {
        cin>>a[i];
        n++;
    }
    for(j=0;j<=(n/2);j++)
    {
        a[j]=a[n-1-j];
    }
    for(j=0;j<=n-1;j++)
    {
        cout<<a[j];
    }
}
```
* 刚开始就会造成数组越界，因为`i`从$0$开始取
* 原地交换的时候，没有引入中间变量，没有实现目的

### 处理一 原地交换
```C++
#include<iostream>
using namespace std;
int main()
{
    long long int a[105]={1};
    int i=0,n=0;
    while(cin>>a[i]&&a[i]!=0)
    {
        n++;
        i++;
    }
    for(i=0;i<n/2;i++)
    {
        long long int tmp;
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
```
* `n` `i` 这里必须初始化，否则是随机值
* 这里`n`是一个计数器，数组的下标是从$0$开始
* `while`循环的巧妙之处就是在输入的时候利用短路特性严格控制符合要求的数组

### 处理二 直接倒序输出
```C++
for(i=n-1;i>=0;i--)
{
    cout<<a[i]<<" ";
}
```
* 避免了交换的麻烦

### 处理三 双指针原地反转