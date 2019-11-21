#include <iostream>
using namespace std;

class Date {
	int y = 0;
	int m_day;
public:
	int CalcDay(const int year,const int month,const int day)
	{
		if (Year(year)){
			y = 1;
		}
		if (month > 2 && month < 8) {
			m_day = 31 * (month - 1) - (month - 1) / 2 - 2 + y + day;
		}
		else if (month > 7) {
			m_day = 31 * (month - 8) - (month - 8) / 2  + day + CalcDay(year,7,31);
		}
		else {
			m_day = 31 * (month - 1) + day;
		}
		return m_day;
	}
	bool Year(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	
};
int main()
{
	
	unsigned int year, month, day;
	while (cin >> year >> month >> day) 
	{
		Date a;
		if (a.Year(year) && month == 2 && day > 29)
			cout << -1;
		else if (month > 12 || day > 31)
			cout << -1;
		else
			cout << a.CalcDay(year, month, day) << endl;
	}	
	return 0;
}