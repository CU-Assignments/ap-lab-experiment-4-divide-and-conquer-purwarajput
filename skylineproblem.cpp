class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        
    // NAME:PURWA UID:22BCS13241

        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); 
            events.emplace_back(b[1], b[2]);  
        }
        
        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        multiset<int> heights = {0}; 
        vector<vector<int>> result;
        int prevMax = 0;

        for (auto& e : events) {
            int x = e.first;
            int h = e.second;

            if (h < 0) { 
                heights.insert(-h); 
            } else {    
                heights.erase(heights.find(h)); 
            }

            int currMax = *heights.rbegin(); 

            if (currMax != prevMax) { 
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return result;
    }
};
