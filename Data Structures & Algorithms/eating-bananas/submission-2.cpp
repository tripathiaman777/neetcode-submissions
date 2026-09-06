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
    pair<int, int> minMaxElem(vector<int>&piles){
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<min){
                min=piles[i];
            }
            if(piles[i]>max){
                max=piles[i];
            }
        }
        pair<int, int>p = {min, max};
        return p;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        pair<int, int> p = minMaxElem(piles);
        int start=1;
        int end = p.second;
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
