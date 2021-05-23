class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int windowSum = 0, minLength = INT_MAX;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd];
            while(windowSum >= target)
            {
                minLength = min(minLength, windowEnd - windowStart+1);
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }
        return minLength == INT_MAX ? 0: minLength;
        
    }
};


/*
Solution #
This problem follows the Sliding Window pattern and we can use a similar strategy as discussed in Maximum Sum Subarray of Size K. There is one difference though: in this problem, the size of the sliding window is not fixed. Here is how we will solve this problem:

First, we will add-up elements from the beginning of the array until their sum becomes greater than or equal to ‘S’.
These elements will constitute our sliding window. We are asked to find the smallest such window having a sum greater than or equal to ‘S’. We will remember the length of this window as the smallest window so far.
After this, we will keep adding one element in the sliding window (i.e. slide the window ahead), in a stepwise fashion.
In each step, we will also try to shrink the window from the beginning. We will shrink the window until the window’s sum is smaller than ‘S’ again. This is needed as we intend to find the smallest window. This shrinking will also happen in multiple steps; in each step we will do two things:
Check if the current window length is the smallest so far, and if so, remember its length.
Subtract the first element of the window from the running sum to shrink the sliding window.
*/