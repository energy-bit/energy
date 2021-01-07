#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

/*
class Data
{
public :
	//  获取某年某月的天数
	int GetMonthday(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 3130, 31 };
		int day = days[month];
		if (month == 2 && ((year%4==0&&year%100!=0)||year%400==0)))
		{
			day += 1;

		}
		return day;
	}
};
*/
struct Data
{
	int m_year;
	int m_month;
	int m_day;

};
struct Time
{
	int m_hour;
	int m_minute;
	int m_second;
};
class CdataTime;
ostream& operator<<(ostream &out, const CdataTime &dt);
class CdataTime
{
	friend ostream& operator<<(ostream &out, const CdataTime &dt);
public :
	CdataTime();
//public :
//	CdataTime NextDataTime(int n);//  n天之后是几月几号
//	CdataTime PrevDataTime(int n);//  n天前是几月几号
//	int GetWeekByYMD(int year, int month, int day);//  通过年月日判断是星期几
public:
	CdataTime GetcurDataTime();
	void DateTimeShow();
private:
	Data m_data;
	Time m_time;

};

CdataTime::CdataTime()
{
	m_data.m_year = 1;
	m_data.m_month = 1;
	m_data.m_day = 1;

	m_time.m_hour = 1;
	m_time.m_minute = 1;
	m_time.m_second =1;
	
}
ostream& operator<<(ostream &out, const CdataTime &dt)
{
	out << dt.m_data.m_year << "年" << dt.m_data.m_month << "月" << dt.m_data.m_day << "日 "
		<< dt.m_time.m_hour << "时" << dt.m_time.m_minute << "分" << dt.m_time.m_second << "秒";
	return out;
}

CdataTime CdataTime::GetcurDataTime()//   获取当前日期时间
{
	time_t te;
	time(&te);
	struct tm*ptm = localtime(&te);
	CdataTime tmp;
	tmp.m_data.m_year = ptm->tm_year + 1900;
	tmp.m_data.m_month = ptm->tm_mon + 1;
	tmp.m_data.m_day = ptm->tm_mday;

	tmp.m_time.m_hour = ptm->tm_hour;
	tmp.m_time.m_minute = ptm->tm_min;
	tmp.m_time.m_second = ptm->tm_sec;
	return tmp;

}
void CdataTime::DateTimeShow()
{
	CdataTime tmp;
	while (1)
	{
		tmp = GetcurDataTime();
		cout << tmp;
		Sleep(1000);
		system("cls");
	}
}
void main()
{
	CdataTime dt;
//	dt = dt.GetcurDataTime();
	//cout << dt << endl;
	dt.DateTimeShow();
	
}