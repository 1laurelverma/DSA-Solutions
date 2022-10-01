class Solution
{
public:
    // Copied solution
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int n = num1.length(), m = num2.length();
        vector<int> sol(n + m, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                sol[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                sol[i + j] += sol[i + j + 1] / 10;
                sol[i + j + 1] %= 10;
            }
        }
        string ans = "";
        int i = 0;
        while (i < sol.size() && sol[i] == 0)
        {
            i++;
        }
        while (i < sol.size())
        {
            ans.push_back(sol[i++] + '0');
        }
        return ans;
    }
};