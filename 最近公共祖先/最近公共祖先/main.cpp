#include <iostream>
using namespace std;
/*
˼·:	�������֪, �ӽڵ�/2 = ���ڵ�;
		��ô���������нϴ�����2,�ж��������Ƿ����,
		������,����������������������,����,�ظ��˲���ֱ�����������
*/
class LCA {

public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			getMax(&a, &b); 
			a = a / 2;
		}
		return a;
	}
private:	
	void getMax(int* a, int* b)//��aΪ�������нϴ����
	{
		int tmp;
		if (*a > *b)
			return;
		else {
			tmp = *a;
			*a = *b;
			*b = tmp;
		}
	}
};
int main()
{
	LCA a;
	cout << a.getLCA(4, 9);
	return 0;
}