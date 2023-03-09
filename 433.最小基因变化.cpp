/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        for (auto &item : bank)
            hashBank.insert(move(item));
        return bfs(start, end);
    }

    int bfs(string start, string end)
    {
        queue<string> q;
        q.push(start);
        deep[start] = 0;
        while (!q.empty())
        {
            start = move(q.front());
            q.pop();

            for (size_t i = 0; i < 8; i++)
            {
                for (size_t j = 0; j < 4; j++)
                {
                    if (start[i] == dict[j])
                        continue;
                    auto g = start;
                    g[i] = dict[j];
                    if (hashBank.find(g) == hashBank.end())
                        continue;
                    if (deep.find(g) == deep.end())
                    {
                        deep[g] = deep[start] + 1;
                        if (g == end)
                            return deep[g];
                        q.push(move(g));
                    }
                }
            }
        }

        return -1;
    }

    unordered_set<string> hashBank;
    unordered_map<string, int> deep;
    const char dict[4] = {'A', 'C', 'G', 'T'};
};
// @lc code=end
