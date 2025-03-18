#include <iostream>
#include <algorithm>
using namespace std;

struct PS
{
    int tuso;
    int mauso;
    PS(){};
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
int UCLN(int a,int b) //Ham tim ucln bang thuat toan Euclid
{
    while(b != 0)
    {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

PS rutgon(PS &x) //Truyen vao 1 phan so
{
    int ucln = UCLN(abs(x.tuso),abs(x.mauso)); //tim ucln cua tu va mau
    x.tuso = x.tuso/ucln; //Chia tu voi ucln
    x.mauso = x.mauso/ucln;//Chia mau voi ucln
    if(x.mauso < 0)
    {
        x.tuso = -x.tuso;
        x.mauso = -x.mauso;
    }
    return x; //Xuat ra PS da rut gon
}

int main()
{
    PS a;
    cin >> a;//Nhap 1 PS
    cout << rutgon(a); //Xuat PS da rut gon
    return 0;
}

