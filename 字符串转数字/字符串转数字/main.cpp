#include <iostream>
#include <string>
using namespace std;
/*
˼·:	���ȿ��ַ�����һλ�ǲ���'-'����'+';�����'-'���������һ��-1;�����'+'���������һ��1;
		Ȼ������ַ���,�����ַ�ֱ�ӷ���0;������,����ת��Ϊint����;�ַ����͵�����ת��Ϊ�������͵�������Ҫ  -48;
		ת��Ϊ���ֺ�,����������Ҫ���Ե�10��n�η�(�������ǰ�λ�ϵ����־ͳ���100)
		Ȼ������Ӳ�����;
*/
class Solution {
	long long int num = 0; //�������������,Ϊ�������㹻��,�������longlong����
	int size; //����������ǵڼ�λ���ֵ�
	int i = 0, a = 1, tmp; //a ��ʾ��һ����������һ������
public:
	int StrToInt(string str) {
		size = str.size() - 1;
		if (str[i] == '+') { //�����һλ�ǣ�, a����;
			i++;
			size--;
		}
		else if (str[i] == '-') { // �����һλ�� -, a = -1;
			a = -1;
			i++;
			size--;
		}
		while (i < str.size() && size >= 0)
		{
			if (str[i] >= '0' && str[i] <= '9') //�ж��ǲ����ַ����͵�����
			{
				tmp = str[i] - 48; //���ַ����͵�����ת��Ϊint����
				num += tmp * pow(10, size);//�������ֳ���10��n�η������
			}
			else {  //�������һ���ַ����͵�����,ֱ�ӷ���0;
				num = 0;
				break;
			}
			i++;
			size--;
		}
		return num * a;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution a;
	cout << a.StrToInt(s);
	return 0;
}