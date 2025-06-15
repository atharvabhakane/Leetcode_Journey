class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int count = 0;  
        int global_max = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                count++;
            }
            while (count > k) {
                if (nums[i] == 0) {
                    count--;
                }
                i++;
            }
            global_max = max(global_max, j - i + 1);
            j++; 
        }

        return global_max;
    }
};
