#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
using namespace std;
/*class Median {
public:
    vector<int> getMaxMedian(vector<int> A, int n, int Q, vector<int> l, vector<int> r, vector<int> k) {
        // write code here
        sort(A.begin(),A.end());
        int i = 0;
        int curl,curr,curk;
        while(Q--)
        {
            curl = l.at(i);
            curr = r.at(i);
            curk = k.at(i);
            
        }
    }
};*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class A {
    public:
    ~A() {
        cout << "~A()";
    }
};
class B{
    public:
    virtual ~B() {
    cout << "~B()";
}
};
class C: public A, public B {
    public:
    ~C() {
        cout << "~C()";
    }
};
int r,x,y,x2,y2;
double getLen(int x,int y,int x2,int y2)
{
    double length;
    length = sqrt(pow(abs(x-x2),2.0)+pow(abs(y-y2),2.0));;
    return length;
}
int a[4] = {1,3,5,9};
void Permutation(int A[], int m, int n)
{
    if(m == n)
    {
          //直接输出，因为前n-1个数已经确定，递归到只有1个数。
        for(int i=0;i<n;i++)
           cout<<A[i]<<" ";
        cout<<endl;
        return;
     }
    else
    {
        for(int i=m;i<n;i++)   //进入for循环，对应第一步
        {
            swap(A[m],A[i]);  //交换，对应第二步
            Permutation(A,m+1,n);  //递归调用，对应三至五步
            swap(A[m],A[i]);  //交换，对应第六步
        }
    }
 }
bool comp(string &str1,string &str2){
    string s1 = str1 + str2;
    string s2 = str2 + str1;
    return s1 < s2;

}
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty())
            return 0;
        return mergeSort(data,0,data.size()-1);
    }
    //使用归并排序来求逆序对
    int mergeSort(vector<int> &data,int start,int end){
        if(start == end)
            return 0;
        int mid = (end+start)/2;
        int left = mergeSort(data,start,mid);//前半段的逆序数
        int right = mergeSort(data,mid+1,end);//后半段的逆序数

        //合并
        int n1 = mid - start + 1;//前半段元素个数
        int n2 = end - mid;//后半段元素个数
        int *leftBuf = new int[n1];
        int *rightBuf = new int[n2];
        for(int i=0;i<n1;++i){//复制前半段
            leftBuf[i] = data[start+i];
        }
        for(int i=0;i<n2;++i){//复制后半段
            rightBuf[i] = data[mid+1+i];
        }
        //i 指向前半段最后一位 j指向后半段最后一位
        int i = n1-1;
        int j = n2-1;
        int count = 0;
        int index = end;
        while(i>=0 && j>=0){
            if(leftBuf[i] > rightBuf[j]){//由小至大排列 从后向前填充
                data[index--] = leftBuf[i--];
                count += j+1;//更新逆序对个数
             }
            else{
                data[index--] = rightBuf[j--];
            }

         }
        //将两段中比较完后剩余段元素（如果有）填回
        for(;i>=0;--i)
            data[index--] = leftBuf[i];
        for(;j>=0;--j)
            data[index--] = rightBuf[j];
        delete [] leftBuf;
        delete [] rightBuf;
        return left + right + count;
    }
};
int main()
{

    Solution s;
    vector<int> v ={1,2,3,4,7,6,5};
    int result = s.InversePairs(v);
    cout << result;
    return 0;
}
