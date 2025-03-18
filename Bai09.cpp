#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
class sotietkiem;
void getDate(string date, int &day,int &month,int &year);
bool ktNgay(string date);
bool ktNamNhuan(int year);
int ktThang(int month,int year);
bool ktma(string ma);
bool ktcmnd(string cmnd);
int laythoigianso(sotietkiem x);

class sotietkiem
{
public:
    string ma,loai,ten,ngaymo;
    string cmnd;
    double tiengui;
    friend bool ktma(string ma);
    bool ktloai();
    bool ktten();
    friend bool ktcmnd(unsigned int cmnd);
    bool kttiengui();
    friend bool ktNgay(string date);
    void ruttien();
    friend istream& operator>>(istream &is,sotietkiem &x);
    friend ostream& operator<<(ostream &os,sotietkiem x);
    string getcmnd() { return cmnd;}
    string getma() {return ma;}
    friend int timkiem(vector<sotietkiem> p,int n);
    friend int laythoigianso(sotietkiem x);
};
bool ktma(string ma)
{
    if(ma.length() < 1 || ma.length() > 5) return 0;
    for(char x : ma)
    {
        if(ispunct(x) || x == ' ') return 0;
    }
    return 1;
}
bool sotietkiem::ktloai()
{
    if(loai.length() < 1 || loai.length() > 10) return 0;
    string x = "Ngan han";
    string y = "Dai han";
    if(loai != x && loai != y) return 0;
    return 1;
}
bool sotietkiem::ktten()
{
    if(loai.length() < 1 || loai.length() > 30) return 0;
    for(char x : ma)
    {
        if(ispunct(x) || isdigit(x)) return 0;
    }
    return 1;
}
bool ktcmnd(string cmnd)
{
    if(cmnd.length() != 9 && cmnd.length() != 12) return 0;
    for(char x : cmnd)
    {
        if(!isdigit(x)) return 0;
    }
    return 1;
}
bool sotietkiem::kttiengui()
{
    return tiengui > 0;
}
//Ham kiem tra xem ngay nhap hop le hay khong
bool ktNgay(string date)
{
    if(date.length() != 10) return 0;
    int day,month,year;
    getDate(date,day,month,year);
    if(month >12 || month <1) return 0;
    if(day < 1 || day > ktThang(month,year)) return 0;
    return 1;
}
void getDate(string date, int &day,int &month,int &year)
{
    day = stoi(date.substr(0,2));
    month = stoi(date.substr(3,2));
    year = stoi(date.substr(6,4));
}
bool ktNamNhuan(int year)// Kiem tra nam nhuan
{
    return (year%400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int ktThang(int month,int year)//Kiem tra thang do co nhieu ngay
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
    case 2:return ktNamNhuan(year) ? 29 : 28;
    default: return -1;
    }
}

void sotietkiem::ruttien()
{
    double x;
    cout << "So tien can rut: ";
    do
    {
        cin >> x;
        if(x < 0) cout << "Vui long nhap so tien >0. \n";
        if(x > tiengui) cout << "Khong du tien!!! \n";
    }while(x < 0 || x > tiengui);
    tiengui -=x;
}
istream& operator>>(istream &is,sotietkiem &x)
{
    cout << "======================== \n" ;
    do{
        cout << "Nhap ma so (Toi da 5 ky tu): ";
        getline(is,x.ma);
    if(!ktma(x.ma)) cout << "Vui long nhap lai! \n";
    }while(!ktma(x.ma));
    do{
        cout << "Nhap loai tiet kiem(Ngan han/Dai han): ";
        getline(is,x.loai);
        if(!x.ktloai()) cout << "Vui long nhap lai! \n";
    }while(!x.ktloai());
    do{
        cout << "Nhap ho va ten KH(Toi da 30 ky tu): ";
        getline(is,x.ten);
        if(!x.ktten()) cout << "Vui long nhap lai! \n";
    }while(!x.ktten());
    do{
        cout << "Nhap cmnd(Dung 9 so hoac 12 so): ";
        getline(is,x.cmnd);
        if(!ktcmnd(x.cmnd)) cout << "Vui long nhap lai! \n";
    }while(!ktcmnd(x.cmnd));
    do{
        cout << "Nhap ngay mo so(dd/mm/yy): ";
        getline(is,x.ngaymo);
        if(!ktNgay(x.ngaymo)) cout << "Vui long nhap lai! \n";
    }while(!ktNgay(x.ngaymo));
    do{
        cout << "Nhap so tien gui: ";
        is >> x.tiengui;
        if(!x.kttiengui()) cout << "Vui long nhap lai! \n";
    }while(!x.kttiengui());
    cout << "======================== \n" ;
    return is;
}
ostream& operator<<(ostream &os,sotietkiem x)
{
    os << "======================== \n" ;
    os << "Ma so: " << x.ma << endl;
    os << "Loai tiet kiem: " << x.loai << endl;
    os << "Ho ten khach hang: " << x.ten << endl;
    os << "So cmnd: " << x.cmnd << endl;
    os << "Ngay mo so: " << x.ngaymo << endl;
    os << "So tien: " << x.tiengui << endl;
    os << "------------------------ \n" ;
    return os;
}
int showmenu()
{
    system("cls");
    int choose;
    cout << ">>=========MENU=========<< \n";
    cout << "1. Nhap danh sach so tiet kiem. \n" ;
    cout << "2. In danh sach so tiet kiem. \n";
    cout << "3. Chuc nang nang cao. \n"  ;
    cout << "4. Tim kiem so theo cmnd hoac ma so. \n"  ;
    cout << "5. Liet ke cac so. \n";
    cout << "6. Danh sach theo so tien giam dan. \n";
    cout << "7. Danh sach theo ngay mo tang dan. \n";
    cout << "0. Thoat chuong trinh. \n" ;
    cout << ">>======================<< \n";
    cout << "=> Lua chon cua ban la: " ;
    cin >> choose;
    return choose;
}

int timkiem(vector<sotietkiem> p,int n)
{
    if(!p.empty())
    {
        cout << "=====TimSoTietKiem===== \n" ;
        cout << "1. Tim kiem theo cmnd \n";
        cout << "2. Tim kiem theo ma so \n";
        cout << "Lua chon cua ban la: ";
    }
    string a,b;
    int choice;
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
    case 1:{
        do{
        cout << "Nhap cmnd(Dung 9 so hoac 12 so): ";
        getline(cin,a);
        if(!ktcmnd(a)) cout << "Vui long nhap lai! \n";
    }while(!ktcmnd(a));
        for(int i =0;i<n;i++)
        {
            if(p[i].cmnd == a) return i;
        }
        return -1;
        }
    case 2:{
        do{
        cout << "Nhap ma so (Toi da 5 ky tu): ";
        getline(cin,b);
    if(!ktma(b)) cout << "Vui long nhap lai! \n";
    }while(!ktma(b));
        for(int i =0;i<n;i++)
        {
            if(p[i].ma == b) return i;
        }
        return -1;
}
    default:
        cout << "Lua chon khong hop le";
        break;
    }
}
void sapxep1(vector<sotietkiem> p,int n)
{
    int min;
    for(int i =0;i<n-1;i++)
    {
        min = i;
        for(int j = i+1;j<n;j++)
        {
            if((p[min].tiengui) < (p[j].tiengui)) min =j;
        }
        swap(p[i],p[min]);
    }
    for(int i =0;i<n;i++) cout << p[i];
}
void sapxep2(vector<sotietkiem> p,int n)
{
    int min;
    for(int i =0;i<n-1;i++)
    {
        min = i;
        for(int j = i+1;j<n;j++)
        {
            if(laythoigianso(p[min]) > laythoigianso(p[j])) min =j;
        }
        swap(p[i],p[min]);
    }
    for(int i =0;i<n;i++) cout << p[i];
}
int laythoigianso(sotietkiem x)
{
    int day,month,year,hour,minute;
    getDate(x.ngaymo,day,month,year);
    return year*1000000+month*10000+day*100;
}

void lietke(vector<sotietkiem> p,int n)
{
    string a;
    bool nf = false;
    cin.ignore();
    do{
        cout << "Nhap ngay mo so(dd/mm/yy): ";
        getline(cin,a);
        if(!ktNgay(a)) cout << "Vui long nhap lai! \n";
    }while(!ktNgay(a));
    for(int i =0;i<n;i++)
        {
            if(p[i].ngaymo == a) cout << p[i];
            nf =true;
        }
        if(!nf)
        {
            cout << "Khong tim thay so! \n";
            cin.get();
        }
}

int tinhmonth(string date1,string date2)
{
    int day1,month1,year1;
    int day2,month2,year2;
    getDate(date1,day1,month1,year1);
    getDate(date2,day2,month2,year2);
    return (year2 - year1)*12 +(month2 - month1);
}

void nangcao(vector<sotietkiem> &p,int n,double &lainganhan,double &laidaihan)
{
    if(!p.empty())
    {
        cout << "=====Nang_cao===== \n" ;
        cout << "1. Nhap lai suat(Theo %/nam)\n";
        cout << "2. Xem tien lai \n";
        cout << "3. Rut tien \n";
        cout << "Lua chon cua ban la: ";
    }else return;
    string now = "16/03/2025";

    int choice;
    cin >> choice;
    switch(choice)
    {
    case 1:
        {
            cout << "Nhap vao lai suat ngan han: ";
            cin >> lainganhan;
            cout << "Nhap vao lai suat dai han: ";
            cin >> laidaihan;
            break;
        }
    case 2:
        {
            for(int i =0;i < n;i++)
            {
                cout << p[i];
                int month = tinhmonth(p[i].ngaymo, now);
                double lai =(month > 6 ? laidaihan : lainganhan);
                double   tienlai = p[i].tiengui * (lai/100.0) * (month/12.0);
                cout << "Tien lai nhan duoc la: "<<fixed  << setprecision(2)<< tienlai << endl;
            }
            cin.get();
            break;
        }
    case 3:
        {
            system("cls");
            int index = timkiem(p,n);
            if(index == -1) cout << "Khong tim thay! \n";
            else{
                int month = tinhmonth(p[index].ngaymo, now);
                double lai =(month > 6 ? laidaihan : lainganhan);
                double tienlai = p[index].tiengui * (lai/100.0) * (month/12.0);
                p[index].tiengui += tienlai;
                cout << p[index];
                if(p[index].loai == "Dai han")
                {
                    if(month > 6)
                    {
                        p[index].ruttien();
                        cout << "Rut thanh cong \n";
                    }
                    else
                    {
                        cout << "Neu rut truoc han thi lai se tinh theo lai ngan han! \n";
                        p[index].ruttien();
                    }
                }else
                {
                    p[index].ruttien();
                    cout << "Rut thanh cong \n";
                }
            }
        }
        cin.get();
        break;
    default:
        break;
    }
}

int main()
{
    vector<sotietkiem> ds;
    int sl;
    double lainganhan,laidaihan;
    while(true)
    {
        int choose = showmenu();
        switch(choose)
        {
        case 1://Nhap danh sach so tiet kiem
            system("cls");
            if(!ds.empty()) ds.clear();
            cout << "Nhap so luong so tiet kiem: ";
            cin >> sl;
            for(int i = 0;i<sl;i++)
            {
                if(sl != 0) cin.ignore();
                sotietkiem tmp;
                cin >> tmp;
                ds.push_back(tmp);
            }
            break;
        case 2: //In danh sach so tiet kiem
            system("cls");
            if(ds.empty()) cout << "Danh sach rong \n";
            else
            {
                for(int i =0;i<sl;i++) cout << ds[i];
            }
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 3://Chuc nang nang cao
            system("cls");
            if(ds.empty()){
                    cout << "Danh sach rong \n";
                    cin.get();
            }
            else nangcao(ds,sl,lainganhan,laidaihan);
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 4://Tim kiem so theo cmnd hoac ma so
            system("cls");
            if(ds.empty()){
                    cout << "Danh sach rong \n";
                    cin.get();
            }
            else {
                int index = timkiem(ds,sl);
                if(index == -1) cout << "Khong tim thay! \n";
                else cout << ds[index];
            }
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 5://Liet ke cac so
            system("cls");
            if(ds.empty()){
                    cout << "Danh sach rong \n";
                    cin.get();
            }
            else lietke(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 6://Danh sach theo so tien giam dan
            system("cls");
            if(ds.empty()) cout << "Danh sach rong \n";
            else sapxep1(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 7://Danh sach theo ngay mo tang dan
            system("cls");
            if(ds.empty()) cout << "Danh sach rong \n";
            else sapxep2(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 0:
            return 0;
        default:
            cout << "Lua chon khong hop le";
            break;
        }
    }
    return 0;
}
