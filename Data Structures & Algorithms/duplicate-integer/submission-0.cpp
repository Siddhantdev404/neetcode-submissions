#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //hash set to store unique elements
        unordered_set<int> seen;
        // normal loop 
        for(int i=0;i<nums.size();i++)
        {
            //conditional statement to check if current number is already in the set 
            if(seen.find(nums[i]) != seen.end())
            {return true; // duplicate found 
            }

            //otherwise add it to set  to check in the future
            seen.insert(nums[i]);

        }
        return false; 
        
    }
};