class Solution {
public:
    int InversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size()-1);
    }
private:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(l >= r) return 0;
        int mid = l + (r-l)/2;
        int count = (mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid+1, r)) % 1000000007;
        int i = mid, j = r, k = r;
        while(i >= l && j >= mid+1){
            if(nums[i] > nums[j]){
                count = (count + j-mid) % 1000000007;
                tmp[k--] = nums[i--];
            } else {
                tmp[k--] = nums[j--];
            }
        }
        while(i >= l) tmp[k--] = nums[i--];
        while(j >= mid+1) tmp[k--] = nums[j--];
        for(int t = l; t <= r; t++) nums[t] = tmp[t];
        return count;
    }
};
