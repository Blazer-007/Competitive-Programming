// https://binarysearch.com/problems/CPU-Scheduling

class Compare
{
    public:
        bool operator () (vector<int>& v1, vector<int>& v2)
        {
            if (v1[2] == v2[2])
                return v1[0] > v2[0];
            return v1[2] > v2[2];
        }
};

bool cmp(vector<int>& v1, vector<int>& v2)
{
    if (v1[1] == v2[1])
    {
        if (v1[2] == v2[2])
            return v1[0] < v2[0];
        return v1[2] < v2[2];
    }
    return v1[1] < v2[1];
}

vector<int> solve(vector<vector<int>>& tasks) {
    int n = (int)tasks.size();
    sort(begin(tasks), end(tasks), cmp);

    priority_queue<vector<int>, vector<vector<int>>, Compare> min_heap;

    vector<int> ans;
    int idx = 0;
    int queue_time = tasks[0][1];
    min_heap.push(tasks[idx]);
    idx++;
    while (!min_heap.empty())
    {
        vector<int> cur = min_heap.top();
        ans.push_back(cur[0]);
        min_heap.pop();
        queue_time += cur[2];
        while (idx < n && tasks[idx][1] <= queue_time)
        {
            min_heap.push(tasks[idx]);
            idx++;
        }
        if (idx < n && min_heap.empty())
        {
            queue_time = tasks[idx][1];
            min_heap.push(tasks[idx]);
            idx++;
        }
    }
    return ans;
}