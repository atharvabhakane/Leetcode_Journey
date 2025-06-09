class Solution {
public:
    int minDeletion(string s, int k) {  // Changed function name to match the caller
        // Count the frequency of each character
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        // If we already have at most k distinct characters, no deletions needed
        if (charCount.size() <= k) {
            return 0;
        }
        
        // Extract frequencies and sort them (ascending order)
        vector<int> frequencies;
        for (const auto& pair : charCount) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.begin(), frequencies.end());
        
        // We need to remove (charCount.size() - k) distinct characters
        // To minimize deletions, we should remove characters with lowest frequencies
        int deletions = 0;
        int charsToRemove = charCount.size() - k;
        
        // Remove the characters with lowest frequencies
        for (int i = 0; i < charsToRemove; i++) {
            deletions += frequencies[i];
        }
        
        return deletions;
    }
};