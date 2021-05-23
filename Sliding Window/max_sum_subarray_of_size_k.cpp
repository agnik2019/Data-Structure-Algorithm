using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

class MaxSumSubarrayOfSizeK
{
    public:
    static int bruteforceSol(vector<int>& arr, int k)
    {
        int maxSum = 0, windowSum;
        for(int i =0; i<= arr.size()-k; i++)
        {
            windowSum = 0;
            for(int j = i; j< i+k; j++)
                windowSum += arr[j];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
    static int slidingWindow(vector<int>& arr, int k)
    {
        int windowSum = 0, maxSum = 0;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd];

            if(windowEnd >= k-1){
                maxSum = max(maxSum, windowSum);
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }
        return maxSum;
    }
};

int main()
{
    cout << "Maximum Sum of a subarray of sike k: "<<
        MaxSumSubarrayOfSizeK::bruteforceSol(vector<int>{2,1,5,1,3,2},3) <<endl;


        cout << "Maximum Sum of a subarray of sike k: "<<
        MaxSumSubarrayOfSizeK::slidingWindow(vector<int>{2,1,5,1,3,2},3) <<endl;
        return 0;
}