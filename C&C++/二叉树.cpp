#include <iostream>

using namespace::std;
/*
 * ��ȫ�������ӽڵ�x�ĸ��ڵ���һ��Ϊx/2 
 */
int main()
{
	int x, y;
	while(cin >> x >> y&&(x>0&&y>0))
	{
		while(x!=y)
		{
			if(x<y)
			{
				y /= 2;
			}
			else
			{
				x /= 2;
			}
		}
		cout << x << endl;
	}
	return 0;
}
