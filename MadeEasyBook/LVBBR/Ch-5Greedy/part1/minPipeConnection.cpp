#include <iostream>
#include <vector>
using namespace std;
#define MAXP 99999
class Ans
{
public:
    int start, end, minPipe;
    Ans(int start, int end, int minPipe) : start(start), end(end), minPipe(minPipe) {}
};

int outGoing[1100]; // 3 4 50 = o[3] = 4 // from to
int inComing[1100]; // 3 4 50 = i[4] = 3 // to from
int pipeO_i[1100];  // 3 4 50 = p[3] = 50

int dfs(int j, int &minPipe)
{
    if (outGoing[j] == 0)
        return j;
    minPipe = min(minPipe, pipeO_i[j]);
    return dfs(outGoing[j], minPipe);
}

void calculateMinPipe(int arr[][3], int n, int p)
{
    for (int i = 0; i < p; i++)
    {
        int out = arr[i][0], in = arr[i][1], pipe = arr[i][2];
        inComing[in] = out;

        outGoing[out] = in;
        pipeO_i[out] = pipe;
    }
    vector<Ans> answer;
    for (int j = 1; j <= n; j++)
    {
        if (inComing[j] == 0)
        {
            int minPipe = MAXP;
            int endV = dfs(j, minPipe);
            answer.emplace_back(Ans(j, endV, minPipe));
        }
    }
    cout<<"Tanks Required "<<answer.size()<<'\n';
    for (Ans ans : answer)
        cout << ans.start << " " << ans.end << " " << ans.minPipe << '\n';
}
int main()
{
    int n = 9, p = 6;
    // int arr[p][3];
    int arr[][3] = {{7, 4, 98},
                    {5, 9, 72},
                    {4, 6, 10},
                    {2, 8, 22},
                    {9, 7, 17},
                    {3, 1, 66}};
    int n = 4,p = 2;
    int arr[][3] = {{1,2,60},
                    {3,4,50}};
    calculateMinPipe(arr, n, p);
    return 0;
}