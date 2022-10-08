class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int count[2001] = {0};
        int check[1000] = {0};
        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i] + 1000]++;
        }
        for (int i = 0; i < 2001; i++)
        {
            if (count[i] && ++check[count[i]] > 1)
                return false;
        }
        return true;
    }
};