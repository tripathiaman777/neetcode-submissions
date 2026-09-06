class Solution {
public:

    vector<int> merge(vector<int>&nums1, vector<int>&nums2){
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mergeSortedArrays=merge(nums1, nums2);
        for(int i=0;i<mergeSortedArrays.size();i++){
            cout<<mergeSortedArrays[i]<<" ";
        }
        int size=mergeSortedArrays.size();
        cout<<" the size is "<<size<<endl;
        double sum = 0;
        if(size%2==0){
            sum = (mergeSortedArrays[(size-1)/2]+mergeSortedArrays[((size-1)/2)+1]);
            return sum/2;
        }
        sum = mergeSortedArrays[(size-1)/2];
        return sum;
    }
};
