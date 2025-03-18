#include <iostream>
#include <algorithm>
using namespace std;

struct PS
{
    int tuso;
    int mauso;
    PS(){}
    // Nạp chồng toán tử nhập xuất
    friend istream& operator>>(istream &is,PS &x)
    {
        cout << "Nhap tu: ";
        is >> x.tuso;
        do
        {
        cout << "Nhap mau: ";
        is >> x.mauso;
        if(x.mauso == 0) cout << "Loi!! Vui long nhap lai. \n";
        }while(x.mauso == 0);
        return is;
    }
    friend ostream& operator<<(ostream &os,PS x)
    {
        os << x.tuso << "/" << x.mauso;
        return os;
    }
};
// Ham tim ucln
int UCLN(int a,int b)
{
    if(a == 0 || b == 0) return a + b ;
    while(a !=b)
    {
        if(a > b) a -=b;
        else b -=a;
    }
    return a ;
}
//Ham rut gon phan so
PS rutgon(PS &x)
{
    int ucln = UCLN(abs(x.tuso),abs(x.mauso));
    x.tuso = x.tuso/ucln;
    x.mauso = x.mauso/ucln;
    if(x.mauso <0)
    {
        x.tuso = -x.tuso;
        x.mauso = -x.mauso;
    }
    return x;
}


//Ham cong 2 phan so
PS operator+(PS a,PS b)
{
    PS c;
    c.tuso = a.tuso*b.mauso + b.tuso*a.mauso;
    c.mauso = a.mauso*b.mauso;
    return rutgon(c);
}


//Ham tru 2 phan so
PS operator-(PS a,PS b)
{
    PS c;
    c.tuso = a.tuso*b.mauso - b.tuso*a.mauso;
    c.mauso = a.mauso*b.mauso;
    return rutgon(c);
}

// Ham nhan 2 phan so
PS operator*(PS a,PS b)
{
    PS c;
    c.tuso = a.tuso*b.tuso;
    c.mauso = a.mauso*b.mauso;
    return rutgon(c);
}
//Ham chia 2 phan so
PS operator/(PS a,PS b)
{
    PS c;
    c.tuso = a.tuso*b.mauso;
    c.mauso = a.mauso*b.tuso;
    return rutgon(c);
}

int main()
{
    PS a,b;
    cin >> a >> b;
    cout << "Tong: " << a+b << endl;
    cout << "Hieu: " << a-b << endl;
    cout << "Tich: " << a*b << endl;
    cout << "Thuong: " << a/b << endl;
    return 0;
}
