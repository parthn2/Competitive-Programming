#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define repd(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define pb push_back
#define ll long long int
#define mod 1000000007
#define inf 100000000000000000

int Partition(int A[], int low, int high, int pi)
{
    int i = low+1;
    for(int j = low+1; j <= high; j++)
    {
        if(A[j] < A[pi])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        }
    }
    int temp = A[pi]; 
    A[pi] = A[i-1];
    A[i-1] = temp;
    return i-1;
}

void quicksort(int A[], int low, int high, int *count)
{
    if(high > low)
    {

        *count = *count + high-low; 

        // int p = ChoosePivot(A, n);
        int p = low;

        int pi = Partition(A, low, high, p);
        quicksort(A, low, pi-1, count);
        quicksort(A, pi+1, high, count);
    }

}


//// Q 3
//void quicksort(int A[], int low, int high, int *count)
//{
//    if(high > low)
//    {
//
//        *count = *count + high-low;
//
//        int change, middle = (low + high)/2;
//        if(A[low] < A[high])
//        {
//            if(A[middle] < A[high])
//            {
//                if(A[low] < A[middle])
//                {
//                    change = middle;
//                }
//                else
//                {
//                    change = low;
//                }
//            }
//            else
//            {
//                change = high;
//            }
//        }
//        else
//        {
//            if(A[middle] < A[low])
//            {
//                if(A[high] < A[middle])
//                {
//                    change = middle;
//                }
//                else
//                {
//                    change = high;
//                }
//            }
//            else
//            {
//                change = low;
//            }
//        }
//        int p = low;
//
//        int temp = A[p];
//        A[p] = A[change];
//        A[change] = temp;
//
//        int pi = Partition(A, low, high, p);
//        quicksort(A, low, pi-1, count);
//        quicksort(A, pi+1, high, count);
//    }
//
//}

void solve()
{
    int n = 10000;
    int A[10000];
    for(int i=0; i< n;i++)
    {
        cin>>A[i];
    }
    int count = 0;
    quicksort(A, 0, n-1, &count);
    cout<<count;
    // rep(i, 0, n-1)
    // cout<<A[i]<<endl;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
}



