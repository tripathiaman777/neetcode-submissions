class Solution {
public:

    int isValid(vector<int>&piles, int h, int max){
        long long hour = 0;
        for(int i=0;i<piles.size();i++){
            hour+=(piles[i]+max-1ll)/max; // piles[i]/max => (piles[i]+max-1)/max
            if(hour>h){
                return false;
            }
        }
        return true;
    }
    int maxElem(vector<int>&piles){

        int max=INT_MIN;
        for(int i=0;i<piles.size();i++){

            if(piles[i]>max){
                max=piles[i];
            }
        }
       
        return max;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int end = maxElem(piles);
        int start=1;
        
        int res = -1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(piles, h, mid)){
                res = mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
};
