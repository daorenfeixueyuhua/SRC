#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
#define inf 999999
#ifdef win64
#pragma execution_character_set("utf-8")
#endif
#define nmax 110
int n, m, edge[nmax][nmax], path[nmax][nmax], value[nmax][nmax];

struct vertex
{
    // 点编号1~n
    int id;
    // 该点名字, 例如（贵师大等等）
    string name;
} V[nmax];

ofstream fout;
ifstream fin;
// 初始化边
void init();

// 全局变量初始化
void dataInit();

// 手动输出边
void input();
// 保存边
void save();
// 计算最短路径
void minPath();
// 打印最短路径值
void print_min_value();
// 打印路径
void print_path(int i, int j);
//
void get();

//增加一个点
void addVertex();

// 查看所有位置信息
void showAllVerter();

int main()
{
    dataInit();
    init();
    // input();
    // get();
    addVertex();
    // minPath();
    showAllVerter();
    get();
    // save();
    return 0;
}

void init()
{

    fin.open("./edge", ios::in);
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> edge[i][j];
    fin.close();

    // 加载位置信息
    fin.open("./vecter", ios::in);
    for (int i = 1; i <= n; ++i)
    {
        fin >> V[i].id >> V[i].name;
    }
    fin.close();

    // 加载计算后的数据
    fin.open("./value", ios::in);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> value[i][j];
    fin.close();
    // 加载路径
    fin.open("./path", ios::in);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> path[i][j];
    fin.close();
}

void get()
{
    int i, j;
    cout << "please enter the start and end (0 0 end the enter!):" << endl;
    while (cin >> i >> j && i && j)
    {
        cout << i << " -> " << j << " : ";
        cout << value[i][j] << endl;
        cout << "path"
             << " : ";
        print_path(i, j);
    }
}

void save()
{
    // 保存位置信息
    fout.open("./vecter", ios::out);
    for (int i = 1; i <= n; ++i)
    {
        fout << V[i].id << " " << V[i].name << endl;
    }
    fout.close();

    fout.open("./edge", ios::out);
    // 点的总数
    fout << n << endl;
    // 保存边
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << edge[i][j] << " ";
        fout << endl;
    }
    fout.close();
    fout.open("./value", ios::out);
    // 保存以计算后的数据
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << value[i][j] << " ";
        fout << endl;
    }
    fout.close();
    // 保存路径
    fout.open("./path", ios::out);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << path[i][j] << " ";
        fout << endl;
    }
    fout.close();
}

void input()
{
    memset(edge, inf, sizeof(edge));
    memset(value, inf, sizeof(value));
    memset(path, -1, sizeof(path));
    string name;
    int i, j;
    cout << "输入该位置名称(end结束输入!)" << endl;
    while (cin >> name && name != "end")
    {
        cout << "该位置的编号为: " << ++n << endl;
        V[n].id = n;
        V[n].name = name;
        cout << "请输入该位置与其他位置之间的距离，格式：s e 100(0 0结束)" << endl;
        while (cin >> i >> j && (i && j))
        {
            cin >> edge[i][j];
            edge[j][i] = edge[i][j];
        }
    }
    minPath();
    save();
}

void minPath()
{
    // 重新计算value
    for (int i = 1; i <= n; ++i)
    {
        value[i][i] = edge[i][i] = 0;
        for (int j = 1; j <= n; ++j)
            value[i][j] = edge[i][j];
    }
    memset(path, -1, sizeof(path));
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (value[k][j] < inf && value[i][k] < inf && value[i][j] > value[i][k] + value[k][j])
                {
                    value[i][j] = value[i][k] + value[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

// 打印路径
void print_path(int i, int j)
{
    int flag = 0;
    if (i > j)
    {
        flag = 1;
        swap(i, j);
    }
    stack<int> Q;
    while (true)
    {
        if (i == j)
        {
            cout << V[i].name << " --> " << V[i].name << endl;
            break;
        }
        // i->j　中间无位置，且可直达
        else if (path[i][j] == -1 && edge[i][i] != inf)
        {
            Q.push(j);
            Q.push(i);
            break;
        }
        // i->j　不可到达
        else if (path[i][j] == -1 && edge[i][i] == inf)
        {
            cout << V[i].name << " --> " << V[j].name << "　不可到达" << endl;
        }
        // i->j之间还有位置
        else if (path[i][j] != -1)
        {
            Q.push(j);
            j = path[i][j];
        }
    }
    // stack去倒置
    if (flag)
    {
        stack<int> temp;
        while (!Q.empty())
        {
            temp.push(Q.top());
            Q.pop();
        }
        Q.swap(temp);
    }
    // 打印位置路径
    while (!Q.empty())
    {
        int index = Q.top();
        Q.pop();
        cout << V[index].name;
        if (!Q.empty())
            cout << " -->> ";
        else
        {
            cout << endl;
        }
    }
}
//增加一个点
void addVertex()
{
    // todo 有bug
    cout << "请输入该位置的名称(end结束)：";
    string name;
    cin >> name;
    n++;
    V[n].id = n;
    V[n].name = name;
    for (int i = 1; i <= n; ++i)
    {
        edge[i][n] = edge[n][i] = inf;
    }
    edge[n][n] = 0;
    cout << "该位置的编号为: " << n << endl;
    cout << "请输入该位置与其他位置之间的距离，格式：s e 100(0 0结束)" << endl;
    int i, j;
    while (cin >> i >> j && i && j)
    {
        cin >> edge[i][j];
        edge[j][i] = edge[i][j];
    }
    cout << "请输入该位置的名称(end结束)：";
    minPath();
    save();
}

void showAllVerter()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << V[i].id << " " << V[i].name << endl;
    }
}

void dataInit()
{
    n = 0;
    m = 0;
    memset(edge, inf, sizeof(edge));
    memset(path, -1, sizeof(path));
    memset(value, inf, sizeof(value));
}