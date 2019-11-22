#include <iostream>
using namespace std;

class solution {
	int count = 0;
public:
	int findnumone(int n)
	{
		while (n)
		{
			if (n & 1) {
				count++;
			}
			n = n >> 1;
		}
		return count;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		solution A;
		cout << A.findnumone(n) << endl;
	}
	
	return 0;
}