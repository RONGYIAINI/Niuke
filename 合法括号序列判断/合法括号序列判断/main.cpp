#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
˼·:	ֱ�ӱ���,�����е������ű�����һ��,�ٽ����е������ű��浽һ��
		��������������ŵ�,ֱ��return false;
		�����������ź��������������,return true;����return false;
*/
class Parenthesis {
	stack<char> left;//���ڱ���������
	stack<char> right;//���ڱ���������

public:
	bool chkParenthesis(string A, int n) {
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
				left.push(A[i]);
			else if (A[i] == ')')
				right.push(A[i]);
			else
				return false;
		}
		if (left.size() == right.size()) { //�ж��������������Ƿ����
			return true;
		}
		else {
			return false;
		}
	}
};
int main()
{
	Parenthesis A;
	string str("()()())");
	int n = str.size();
	cout << A.chkParenthesis(str, n);
	return 0;
}