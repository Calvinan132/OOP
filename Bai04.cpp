#include <iostream>
#include <cmath>
using namespace std;

long long giaithua(int n)
{
    long long  result = 1;
    for(int i = 2;i<=n;i++) result *=i;
    return result;
}

double Sin(double x)
{
    double tmp,sum =0;
    int n =0;
    do{
        tmp = (pow(-1,n)*pow(x,2*n+1))/giaithua(2*n+1);
        sum += tmp;
        n++;
    }while(fabs(tmp) >= 0.0001);
    return sum;
}

int main()
{
    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Sin(" << x << ")= " << Sin(x) <<endl;
    return 0;
}
