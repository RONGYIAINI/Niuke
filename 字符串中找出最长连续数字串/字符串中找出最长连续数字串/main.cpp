#include <iostream>
#include <string>
using namespace std;
/*
˼·:	���ַ������б���;�����������,��¼�����ֵ�λ��,��Ѱ����һ���������ֵ�λ��
		�ɴ����ǿ��Եõ�һ�����ִ�,��������ִ��ĳ���,�����������ִ����бȽ�,
		���������ִ���Ҫ��,�ͽ��䱣�浽tmp��;�ڱ���֮ǰҪ��tmp�����
*/
class Solu {
	string tmp; //���ڱ��沢���ص��ַ���
public:
	string findnum(string str) {
		int size = str.size(); //�ַ����Ĵ�С
		for (int i = 0; i < size; i++)
		{
			if (str[i] >= '0' && str[i] <= '9') //Ѱ���Ƿ�Ϊ����
			{
				int begin = i;
				while (str[i] >= '0' && str[i] <= '9') //�õ����������ִ������һ�����ֵ�λ��
				{
					i++;
				}
				if ((i - begin) > tmp.size()) //�ж��Ƿ���ѱ�������ִ���,
				{
					tmp.clear(); //���ִ����
					for (int j = begin; j < i; j++)  //���ִ�����
					{
						tmp.push_back(str[j]);
					}
				}
			}
		}
		return tmp;
	}
};
int main()
{
	string str;
	char s;
	while (1)
	{
		s = getchar();
		if (s == '\n') {
			break;
		}
		str.push_back(s);
	}
	Solu b;
	cout << b.findnum(str) << endl;
	return 0;
}