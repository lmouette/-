#include <iostream>
#include <stack>
using namespace std;

#define N 100

typedef char ElemType;

// 图的邻接矩阵声明
typedef struct _MGraph
{
    int edges[N][N]; //边集合
    int n; //顶点数
}MGraph;

// 输出从开始顶点到顶点k的最短路径
void DisplayPath(int k, int path[])
{
    stack<int> s;
    while (path[k] != k)
    {
        s.push(k);
        k = path[k];
    }
    s.push(k);
    int cnt = 0;
    while (!s.empty())
    {
        if (cnt++ > 0) cout << "->";
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

/*
弗洛伊德算法
g存储有向图的边
dis[i][j]存储顶点i到顶点j的最短距离长度
path[i][j]存储顶点j的上一个顶点
*/
void Floyd(MGraph& g, int dis[][N], int path[][N])
{
    for (int i = 1; i <= g.n; i++)
    {
        for (int j = 1; j <= g.n; j++)
        {
            dis[i][j] = (i == j ? 0 : g.edges[i][j]); //初始化距离数组
            path[i][j] = i; //初始化路径数组
        }
    }
    for (int k = 1; k <= g.n; k++)
    {
        for (int i = 1; i <= g.n; i++)
        {
            for (int j = 1; j <= g.n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j]) //如果以K为中间点距离更短，更新距离数组和路径数组
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

// 输出每对顶点的最短路径
void DisplayPath(int n, int path[][N], int dis[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i << "-" << j << "最短路径长度：" << dis[i][j] << " 最短路径：";
            DisplayPath(j, path[i]);
        }
    }
}

int main()
{
    MGraph g;
    while (cin >> g.n)
    {
        for (int i = 0; i < g.n; i++)
            for (int j = 0; j < g.n; j++)
                g.edges[i][j] = INT16_MAX;
        int m, u, v, w;
        cin >> m;
        while (m-- > 0)
        {
            cin >> u >> v >> w;
            g.edges[u][v] = w;
        }
        //Floyd
        int path[N][N], dis[N][N];
        Floyd(g, dis, path);
        DisplayPath(g.n, path, dis);
    }
    return 0;
}
