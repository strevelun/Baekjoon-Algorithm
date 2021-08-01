#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int time[501];
vector<int> need[501];
int inDegree[501];
int temp[501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input = 0;
    cin >> n;

    for (int i = 1; i<=n; i++)
    {
        cin >> input;
        time[i] = input;

        while (1)
        {
            cin >> input;
            if (input == -1)
                break;
            need[input].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i<=n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    for (int i = 1; i<=n; i++)
    {
        if (q.empty())
            break;

        int front = q.front();
        q.pop();

        for (size_t j = 0; j<need[front].size(); j++)
        {
            int y = need[front].at(j);

            temp[y] = max(temp[y], time[front]);

            if (--inDegree[y] == 0)
            {
                q.push(y);
                time[y] += temp[y];
            }
        }
    }
    
    for(int i=1; i<=n; i++)
        cout << time[i] << '\n';

    return 0;
}