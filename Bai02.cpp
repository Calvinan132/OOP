#include <iostream>
#include <algorithm>
using namespace std;

struct PS
{
    int tuso;
    int mauso;
    PS(){};
    //Nap chong toan tu nhap
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
    //Nap chong toan tu xuat
    friend ostream& operator<<(ostream &os,PS x)
    {
        os << x.tuso << "/" << x.mauso;
        return os;
    }
};

PS pslonI(PS a,PS b)
{
    double x = (double)a.tuso/a.mauso; //Dua phan so 1 ve so thuc
    double y = (double)b.tuso/b.mauso; //Dua phan so 2 ve so thuc
    if(x > y) return a;
    if(x < y) return b; //so sanh 2 so thuc xuat ps lon nhat
    return a; //Neu bang nhau thi xuat ra 1 trong 2
}

int main()
{
    PS a,b;
    cin >> a >> b;
    cout << "Phan so lon nhat la: " << pslonI(a,b);
    return 0;
}
