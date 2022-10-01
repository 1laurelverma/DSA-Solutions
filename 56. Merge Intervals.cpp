class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &vals)
    {
        int n = vals.size();
        if (n == 1)
        {
            return vals;
        }
        sort(vals.begin(), vals.end());
        vector<vector<int>> ans;
        int next = 1, max = vals[0][1], min = vals[0][0];
        while (next < n)
        {
            if (max < vals[next][0])
            {
                if (max < vals[next][1])
                {
                    ans.push_back({min, max});
                    min = vals[next][0];
                    max = vals[next][1];
                }
            }
            else
            {
                if (max < vals[next][1])
                    max = vals[next][1];
            }
            if (min > vals[next][0])
            {
                min = vals[next][0];
            }
            next++;
        }
        ans.push_back({min, max});
        return ans;
    }
};