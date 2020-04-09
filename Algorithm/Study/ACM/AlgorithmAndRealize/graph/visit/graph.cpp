#include <bits/stdc++.h>
using namespace std;
/**
 * info[i]为节点i的边集所对应的链表的头指针
 * next[j]为第j条边的指向下一条边的指针
 * to[j]表示第j条边所指向的节点的编号
 * 
 * */
// info 由该点出发的所有边构成的链表的表
// next 链表中下一条边在to数组中的位置
// to   to[i]表示编号为i的边指向的节点
// graph(int n, int m); 初始化图为n个点，m条边
// add(int i, int j);   添加(i,j)之间的边
struct graph
{
    typedef vector<int> VI;
    VI info, next, to;
    graph(int n = 0, int m = 0) : to(0), next(0)
    {
        info.resize(n);
        next.reserve(m);
        to.reserve(m);
    }
    // 返回边的数量
    int edge_size()
    {
        return to.size();
    }
    // 返回值为最大点的编号+1
    int vertex_size()
    {
        return info.size();
    }

    void expand(int i)
    {
        if (info.size() < i + 1)
            info.resize(i + 1);
    }
    // 添加一条i到j的边
    void add(int i, int j)
    {
        expand(i), expand(j);
        to.push_back(j);
        next.push_back(info[i]);
        info[i] = to.size() - 1;
    }
    // 删除最后一次添加的边
    void del_back()
    {
        int i;
        for (int i = 1; i < info.size(); ++i)
            if (info[i] == to.size() - 1)
            {
                info[i] = next.back();
                break;
            }
        to.pop_back();
        next.pop_back();
    }
    void clear()
    {
        info.clear();
        next.resize(0);
        to.resize(0);
    }
};

int main()
{
    graph g(5, 9);
    g.add(0, 1);
    g.add(1, 2);
    g.add(2, 3);
    g.add(3, 4);
    g.add(0, 2);
    g.add(0, 3);
    g.add(1, 3);
    g.add(1, 4);
    g.add(2, 4);
    copy(g.info.begin(), g.info.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(g.next.begin(), g.next.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(g.to.begin(), g.to.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}