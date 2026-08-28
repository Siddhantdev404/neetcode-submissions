#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to hold <Signature String, List of Anagrams>
        unordered_map<string, vector<string>> anagramGroups;
        
        for (int i = 0; i < strs.size(); i++) {
            // Count characters using the 26-letter array trick
            int count[26] = {0};
            for (int j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a']++;
            }
            
            // Build the unique signature string for this character count
            string signature = "";
            for (int j = 0; j < 26; j++) {
                signature += to_string(count[j]) + "#";
            }
            
            // Add the original string to its matching signature group
            anagramGroups[signature].push_back(strs[i]);
        }
        
        // Prepare the final 2D vector to return
        vector<vector<string>> result;
        
        // Loop through the map and pull out each grouped list
        for (auto it = anagramGroups.begin(); it != anagramGroups.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};