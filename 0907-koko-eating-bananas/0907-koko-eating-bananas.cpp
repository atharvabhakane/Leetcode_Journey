class Solution {
private:
    long long hoursRequired(vector<int>& piles, int speed) {
        long long cnt = 0; 
        for (int c : piles) {
            cnt += (c + speed - 1) / speed;
        }
        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxElement = *max_element(piles.begin(), piles.end());  

        int ans = -1, low = 1, high = maxElement;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long timeRequired = hoursRequired(piles, mid);

            if (timeRequired <= H) { 
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};