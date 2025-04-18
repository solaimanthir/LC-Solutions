#if 0
Approach#1 Brute-force solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) 
    {
        int sz = nums.size();
        vector<int> ans = {};
        bool ansFound = false;

        for(int i = 0; i < sz; ++i)
        {
            for(int j = i+1; j < sz; ++j)
            {
                if((tgt - nums[j]) == nums[i])
                {
                    ansFound = true;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            
            if(ansFound == true)
            {
                break;
            }
        }

        return ans;
    }
};

Approach#2 two-pass hash table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) 
    {
        unordered_map<int, int> numIdxMap;
        vector<int> ans = {};
        int sz = nums.size();
        bool ansFound = false;

        for(int i = 0; i < sz; ++i)
        {
            numIdxMap[nums[i]] = i;
        }

        for(int i = 0; i < sz; ++i)
        {
            int num2 = tgt - nums[i];

            if((numIdxMap.find(num2) != numIdxMap.end()) &&
                (numIdxMap[num2] != i))
            {
                int j = numIdxMap[num2];
                ans.push_back(i);
                ans.push_back(j);
                ansFound = true;
                break;
            }
        }

        return ans;
    }
};
#endif

/*Approach#3 one-pass hash table*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) 
    {
        unordered_map<int, int> numIdxMap;
        vector<int> ans = {};
        int sz = nums.size();
        bool ansFound = false;

        for(int i = 0; i < sz; ++i)
        {
            int num2 = tgt - nums[i];

            if(numIdxMap.find(num2) != numIdxMap.end())
            {
                int j = numIdxMap[num2];
                ans.push_back(i);
                ans.push_back(j);
                ansFound = true;
                break;
            }

            numIdxMap[nums[i]] = i;
        }

        return ans;
    }
};
