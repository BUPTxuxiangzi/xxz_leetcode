/*问题描述：
Search Insert Position Total Accepted: 50334 Total Submissions: 141852

Given a sorted array and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 

*/

/*解法1：二分查找
时间复杂度O(logn)
runtime:18ms
*/
class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        int low = 0, high = n-1;
        if(0 == n )//需要考虑这种情况，因为A为空的时候，是无法进行二分查找的
        {
            return 0;
        }
        if(target>A[n-1])//插入位置在数组之外
        {
            return n;
        }

        //将循环条件low<high 改为 low!=high, runtime立即变成12ms
        //所以以后循环的条件尽量用!=，而非>,<
        while(low<high)//只考虑插入位置在[low, high]的情况
        {
            int mid = (low+high) >> 1;
            if(A[mid]<target)//证明arget在后半段[ A[mid+1], A[high] ]闭区间内。注意，不能带‘=’
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }//low==high时，即是index
        return low;
    }
};


/*解法2：
设置high=n,则查询区间变为[low,mid),[mid, high)双半开区间
runtime:17ms 比上一种慢，且操作繁琐，因此建议用上一种方法
*/
class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        if(0 == n )//需要考虑这种情况，因为A为空的时候，是无法进行二分查找的
        {
            return 0;
        }

        int low = 0, high = n;
        while(low != high-1)
        {
            int mid = (low+high) >> 1;
            if(A[mid]>target)//证明在前半段
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return A[low]<target?low+1:low;
    }
};