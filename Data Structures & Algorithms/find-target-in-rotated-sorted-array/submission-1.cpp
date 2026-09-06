class Solution {
public:
    int BS(vector<int>&nums, int start, int end, int target){
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
    int findPivot(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int N = nums.size();
        if(nums[start]<=nums[end]){
            return 0; //already sorted
        }
        while(start<=end){
            int mid=(start+end)/2;
            int prev = (mid-1+N)%N;
            int next = (mid+1)%N;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid;
            }
            else if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int pivot = findPivot(nums, target);
       int leftRes = BS(nums, 0, pivot-1, target);
       int rightRes = BS(nums, pivot, nums.size()-1, target);
    //    cout<<"pivot "<<pivot<<" leftRes "<<leftRes<<" rightRes "<<rightRes<<endl;
       return leftRes!=-1 ? leftRes : rightRes; 
    }
};
