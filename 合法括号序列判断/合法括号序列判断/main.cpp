#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
思路:	直接遍历,将所有的左括号保存在一起,再将所有的右括号保存到一起
		如果遇到不是括号的,直接return false;
		如果最后左括号和右括号数量相等,return true;否则return false;
*/
class Parenthesis {
	stack<char> left;//用于保存左括号
	stack<char> right;//用于保存右括号

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
		if (left.size() == right.size()) { //判断左右括号数量是否相等
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