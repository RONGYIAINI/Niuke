#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
˼·:	������ѵ�������ν�" "���ڵĿո��˫������Ŀո����ֿ�,
		����һ��count����ʾ�Ƿ���������
		��count�ĳ�ʼֵ��Ϊ0;������һ������ʱ,��count��ֵ���1,Ȼ���2�����Ž���ֵ��Ϊ0;
		Ȼ����[0,1]�����ڵĿո����ڲ�����,����ʱ��Ϊ�����
*/
class solution
{
	int count = 0; //���ŵ�״̬
	string s1;     //�����һ������
public:
	vector<string> CommandResolver(string s)
	{
		vector<string> v; //����ֵ
		int i = 0;
		while (i < s.size())
		{
			if (s[i] != ' ') {
				
				while (i < s.size())
				{
					if (s[i] == '"' && count == 0) {  //������һ������ʱ
						count = 1;
						i++;
					}
					if (s[i] == ' ' && count == 0) {  //����[0,0]�ڵĿո�ʱ
						i++;
						break;
					}
					
					if (s[i] == '"' && count == 1) {   //������2������ʱ,��ʾ�ò����Ѿ�������
						count = 0;
						i++;
						break;
					}
					s1.push_back(s[i]); //���������������,������ַ�
					i++;
					
				}
				v.push_back(s1); //�������
				s1.clear(); //����������������ַ������
			}
			else {
				i++;
			}
		}

		return v;
	}

};


int main()
{
	int count = 0;
	vector<string> save;
	string s;
	char ch;
	while (ch = getchar())
	{
		if (ch == '\n')
			break;
		s.push_back(ch);
	}
	solution a;
	save = a.CommandResolver(s);
	int size = save.size();
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << save[i] << endl;
	}
	return 0;
}