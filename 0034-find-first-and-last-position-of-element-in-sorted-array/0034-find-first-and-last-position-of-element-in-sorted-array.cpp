class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
    int findFirst(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int first = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= target) {
                h = mid - 1; 
            } else {
                l = mid + 1;
            }
            if (nums[mid] == target) first = mid;
        }
        return first;
    }
    int findLast(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int last = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1; 
            } else {
                h = mid - 1;
            }
            if (nums[mid] == target) last = mid;
        }
        return last;
    }
};
