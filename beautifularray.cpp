class Solution {
public:
    vector<int> beautifulArray(int n) {
         vector<int> result = {1}; 
        
    // NAME:PURWA UID:22BCS13241
    
        while (result.size() < n) {
            vector<int> temp;
            for (int x : result) {
                if (2 * x - 1 <= n) temp.push_back(2 * x - 1);
            }
            for (int x : result) {
                if (2 * x <= n) temp.push_back(2 * x);
            }
            result = temp;
        }
        
        return result;
    }
};
