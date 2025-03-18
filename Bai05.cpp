#include <iostream>
using namespace std;

class date
{
public:
    int year,month,day;
// Nap chong toan tu nhap
    friend istream& operator>>(istream &is,date &x)
    {
        cout << "Nhap nam: ";
        is >> x.year;
        do
        {
            cout << "Nhap thang: ";
            is >> x.month;
            if(x.month >12 || x.month <1) cout << "Vui long nhap lai\n";
        }while(x.month >12 || x.month <1);
        do
        {
            cout << "Nhap ngay: ";
            is >> x.day;
            if(x.day < 1 || x.day > x.ktThang()) cout << "Vui long nhap lai \n";
        }while(x.day < 1 || x.day > x.ktThang());
        return is;
    }
// Nap chong toan tu xuat
    friend ostream& operator<<(ostream &os,date x)
    {
        os << (x.day < 10 ? "0" : "") << x.day
        << "/" << (x.month < 10 ? "0" : "" )<< x.month
        << "/" << x.year ;
        return os;
    }
    bool ktNamNhuan();
    int ktThang();
    void chuanhoa();
    int ngaythubaonhieu();
};
bool date::ktNamNhuan()//Ham kiem tra nam nhuan
{
    return (year%400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
//Kiem tra ngay trong thang do
int date::ktThang()
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:return 31;
    case 4:
    case 6:
    case 9:
    case 11:return 30;
    case 2 :return (ktNamNhuan()) ? 29 : 28;
    default: return -1;
    }
}
// Chuan hoa dung dang
void date::chuanhoa()
{
    while(month <=0)
    {
        year--;
        month = 12;
    }

    while(day > ktThang())
    {
        day -=ktThang();
        month++;
        if (month > 12) {
                month = 1;
                year++;
                    }
    }
    while(month > 12)
    {
        month -=12;
        year++;
    }
    while(day <= 0)
    {
        month--;
        if (month < 1) {
                month = 12;
                year--;
            }
        day = ktThang();
    }
}

date ngayketiep(date x) //Ham tim ngay ke tiep
{
    x.day++;
    x.chuanhoa();
    return x;
}
date ngaytruocdo(date x) //Ham tim ngay truoc do
{
    x.day--;
    x.chuanhoa();
    return x;
}

int date::ngaythubaonhieu() //Ham ngay thu bao nhieu cua nam
{
    int sum = day;
    month--;
    while(month > 0)
    {
        sum += ktThang();
        month--;
    }
    return sum;
}

int main()
{
    date a;
    cin >> a;
    cout << "Ngay ban nhap: "<< a << endl;
    cout << "Ngay ke tiep la: " << ngayketiep(a) << endl;
    cout << "Ngay truoc do la: " << ngaytruocdo(a) << endl;
    cout << "Day la ngay thu " << a.ngaythubaonhieu() << " trong nam. \n";
    return 0;
}
