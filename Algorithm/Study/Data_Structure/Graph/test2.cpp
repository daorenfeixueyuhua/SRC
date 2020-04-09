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
    // ����1~n
    int id;
    // �õ�����, ���磨��ʦ��ȵȣ�
    string name;
} V[nmax];

ofstream fout;
ifstream fin;
// ��ʼ����
void init();

// ȫ�ֱ�����ʼ��
void dataInit();

// �ֶ������
void input();
// �����
void save();
// �������·��
void minPath();
// ��ӡ���·��ֵ
void print_min_value();
// ��ӡ·��
void print_path(int i, int j);
//
void get();

//����һ����
void addVertex();

// �鿴����λ����Ϣ
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

    // ����λ����Ϣ
    fin.open("./vecter", ios::in);
    for (int i = 1; i <= n; ++i)
    {
        fin >> V[i].id >> V[i].name;
    }
    fin.close();

    // ���ؼ���������
    fin.open("./value", ios::in);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> value[i][j];
    fin.close();
    // ����·��
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
    // ����λ����Ϣ
    fout.open("./vecter", ios::out);
    for (int i = 1; i <= n; ++i)
    {
        fout << V[i].id << " " << V[i].name << endl;
    }
    fout.close();

    fout.open("./edge", ios::out);
    // �������
    fout << n << endl;
    // �����
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << edge[i][j] << " ";
        fout << endl;
    }
    fout.close();
    fout.open("./value", ios::out);
    // �����Լ���������
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << value[i][j] << " ";
        fout << endl;
    }
    fout.close();
    // ����·��
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
    cout << "�����λ������(end��������!)" << endl;
    while (cin >> name && name != "end")
    {
        cout << "��λ�õı��Ϊ: " << ++n << endl;
        V[n].id = n;
        V[n].name = name;
        cout << "�������λ��������λ��֮��ľ��룬��ʽ��s e 100(0 0����)" << endl;
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
    // ���¼���value
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

// ��ӡ·��
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
        // i->j���м���λ�ã��ҿ�ֱ��
        else if (path[i][j] == -1 && edge[i][i] != inf)
        {
            Q.push(j);
            Q.push(i);
            break;
        }
        // i->j�����ɵ���
        else if (path[i][j] == -1 && edge[i][i] == inf)
        {
            cout << V[i].name << " --> " << V[j].name << "�����ɵ���" << endl;
        }
        // i->j֮�仹��λ��
        else if (path[i][j] != -1)
        {
            Q.push(j);
            j = path[i][j];
        }
    }
    // stackȥ����
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
    // ��ӡλ��·��
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
//����һ����
void addVertex()
{
    // todo ��bug
    cout << "�������λ�õ�����(end����)��";
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
    cout << "��λ�õı��Ϊ: " << n << endl;
    cout << "�������λ��������λ��֮��ľ��룬��ʽ��s e 100(0 0����)" << endl;
    int i, j;
    while (cin >> i >> j && i && j)
    {
        cin >> edge[i][j];
        edge[j][i] = edge[i][j];
    }
    cout << "�������λ�õ�����(end����)��";
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