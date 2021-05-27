class Solution {
public:
    int rotate(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        while(start < end)
        {
            int mid = start + (end- start)/2;
            if(start<mid  && arr[mid-1]>arr[mid])
                return arr[mid];
            if(mid < end && arr[mid] > arr[mid+1])
                return arr[mid+1];
            if(arr[start]<arr[mid])
                start = mid+1;
            else 
                end = mid-1;
        }
        return -1; // the array is not rotated
    }
    
     int findMin(vector<int>& arr) {
         if(arr.size()==1) return arr[0];
         int r = rotate(arr);
         if(r == -1) {
             if(arr[0] < arr[arr.size()-1]) return arr[0];
             if(arr[0] > arr[arr.size()-1]) return arr[arr.size()-1];
         }
         else
              return r;
         return r;
     }
};