class Solution {
public:
    int findMin(vector<int> &nums) {
        //to find: the elem smaller than left and right neighbour
        if(nums[0]<=nums[nums.size()-1]){
            return nums[0];
        }
        int start=0;
        int end=nums.size()-1;
        int n = nums.size();
        while(start<=end){
            int mid=(start+end)/2;
            // cout<<start<<" "<<mid<<" "<<end<<endl;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            // cout<<nums[prev]<<" "<<nums[mid]<<" "<<nums[next]<<endl;
            // cout<<endl;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
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
};
