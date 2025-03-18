#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

bool ktNamNhuan(int year);
int ktThang(int month,int year);
bool ktNgay(string date);
void getDate(string date, int &day,int &month,int &year);
void getTime(string time,int &hour,int &minute);
bool ktMa(string ma);
bool ktGio(string time);
bool ktDiadiem(string address);



class chuyenbay
{
public:
    string ma,ngaybay,giobay,noidi,noiden;
    friend bool ktMa();
    friend bool ktNgay(string date);
    friend bool ktGio(string time);
    friend bool ktDiadiem(string address);
    friend istream& operator>>(istream &is,chuyenbay &x);
    friend ostream& operator<<(ostream &os,chuyenbay x);
    string getMa() { return ma; }
    string getNoiDi() { return noidi; }
    string getNoiDen() { return noiden; }
    string getNgaybay() { return ngaybay;}
};

bool ktMa(string ma)
{
    if(ma.length() > 5) return 0;
    else
    {
        for(char x: ma)
        {
            if(x == ' ' || ispunct(x)) return 0;
        }
    }
    return 1;
}
// Ham tach ngay thang nam
void getDate(string date, int &day,int &month,int &year)
{
    day = stoi(date.substr(0,2));
    month = stoi(date.substr(3,2));
    year = stoi(date.substr(6,4));
}

void getTime(string time,int &hour,int &minute)
{
    hour = stoi(time.substr(0,2));
    minute = stoi(time.substr(3,2));
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
// Kiem tra xem dung dang gio khong
bool ktGio(string time)
{
    if(time.length() != 5) return 0;
    int hour,minute;
    hour = stoi(time.substr(0,2));
    minute = stoi(time.substr(3,2));
    if(hour >23 || hour < 0) return 0;
    if(minute >59 || minute < 0) return 0;
    return 1;
}
// Kiem tra xem co dung dinh dang khong
bool ktDiadiem(string address)
{
    if(address.length() > 20 || address.length() < 1) return 0;
    for(char x: address)
    {
        if(!isalpha(x) && x != ' ' && x != '.') return 0;
    }
    return 1;
}

void timchuyen(vector<chuyenbay> &p,int n)
{
    if(!p.empty())
    {
        cout << "=====TimChuyen===== \n" ;
        cout << "1. Tim kiem theo ma chuyen bay \n";
        cout << "2. Tim kiem theo noi di \n";
        cout << "3. Tim kiem theo noi den \n";
        cout << "Lua chon cua ban la: ";
    }else return;
    string a,b,c;
    int choice;
    cin >> choice;
    switch(choice)
    {
    case 1:{
        do
        {
            cout << "Nhap ma chuyen bay (Toi da 5 ki tu): " ;
            cin.ignore();
            getline(cin,a);
            if(!ktMa(a)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktMa(a));
        int i =0;
        bool nf = false;
        while(i<n)
        {
            string x = p[i].getMa();
            if(x.find(a) == string::npos ) i++;
            else
            {
                cout << p[i];
                i++;
                nf=true;
            }
        }
        if(!nf)
        {
            cout << "Khong tim thay chuyen bay! \n";
            cin.get();
        }
        break;}
    case 2:{
        do
        {
            cout << "Nhap noi di: ";
            cin.ignore();
            getline(cin,b);
            if(!ktDiadiem(b)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(b));
        int i =0;
        bool nf =false;
        while(i<n)
        {
            string x = p[i].getNoiDi();
            if(x.find(b) == string::npos ) i++;
            else
            {
                cout << p[i];
                i++;
                nf=true;
            }
        }
        if(!nf)
        {
            cout << "Khong tim thay chuyen bay! \n";
            cin.get();
        }
        break;}
    case 3:{
        do
        {
            cout << "Nhap noi den: ";
            cin.ignore();
            getline(cin,c);
            if(!ktDiadiem(c)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(c));
        int i =0;
        bool nf=false;
        while(i<n)
        {
            string x = p[i].getNoiDen();
            if(x.find(c) == string::npos ) i++;
            else
            {
                cout << p[i];
                i++;
                nf=true;
            }
        }
        if(!nf)
        {
            cout << "Khong tim thay chuyen bay! \n";
            cin.get();
        }
        break;}
    default:
        cout << "Lua chon khong hop le";
        break;
    }
}

int laythoigianso(chuyenbay x)
{
    int day,month,year,hour,minute;
    getDate(x.ngaybay,day,month,year);
    getTime(x.giobay,hour,minute);
    return year*1000000+month*10000+day*100+hour*10+minute;
}

void sapxep(vector<chuyenbay> &p,int n)
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
}

void timchuyen1(vector<chuyenbay> &p,int n)
{
    string a,b;
    int i=0;
    bool nf = false;
    if(!p.empty())
    {
        cout << "=====TimChuyen===== \n" ;
    }else return;


    do
        {
            cout << "Nhap noi di: ";
            cin.ignore();
            getline(cin,a);
            if(!ktDiadiem(a)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(a));
    do
        {
            cout << "Nhap ngay bay (dd/mm/yyyy): ";
            getline(cin,b);
            if(!ktNgay(b)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktNgay(b));
    while(i<n)
        {
            string x = p[i].getNoiDi();
            string y = p[i].getNgaybay();
            if(x == a && y == b)
            {
                cout << p[i];
                i++;
                nf = true;
            }
            else i++;
        }
     if(!nf)
        {
            cout << "Khong tim thay chuyen bay! \n";
            cin.get();
        }
}

int demchuyen(vector<chuyenbay> &p,int n)
{
    string a,b;
    int dem = 0;
    if(p.empty()) return dem;
    cin.ignore();
    do
        {
            cout << "Nhap noi di: ";
            getline(cin,a);
            if(!ktDiadiem(a)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(a));
    do
        {
            cout << "Nhap noi den: ";
            getline(cin,b);
            if(!ktDiadiem(b)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(b));

    for(int i =0;i < n;i++)
    {
        if(p[i].getNoiDi() == a && p[i].getNoiDen() == b) dem++;
    }
    return dem;
}

// Nhap thong tin chuyen bay
istream& operator>>(istream &is,chuyenbay &x)
    {
        cout << "======================== \n" ;
        do
        {
            cout << "Nhap ma chuyen bay (Toi da 5 ki tu): " ;
            getline(is,x.ma);
            if(!ktMa(x.ma)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktMa(x.ma));
        do
        {
            cout << "Nhap ngay bay (dd/mm/yyyy): ";
            getline(is,x.ngaybay);
            if(!ktNgay(x.ngaybay)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktNgay(x.ngaybay));

        do
        {
            cout << "Nhap gio bay (00:00): ";
            getline(is,x.giobay);
            if(!ktGio(x.giobay)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktGio(x.giobay));

        do
        {
            cout << "Nhap noi di: ";
            getline(is,x.noidi);
            if(!ktDiadiem(x.noidi)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(x.noidi));
        do
        {
            cout << "Nhap noi den: ";
            getline(is,x.noiden);
            if(!ktDiadiem(x.noiden)) cout << "Sai dinh dang vui long nhap lai! \n";
        }while(!ktDiadiem(x.noiden));

        return is;
    }
// xuat thong tin chuyen bay
ostream& operator<<(ostream &os,chuyenbay x)
    {
        os << "======================== \n" ;
        os << "Ma chuyen bay la: " << x.ma << endl;
        os << "Ngay bay la: " << x.ngaybay << endl;
        os << "Gio bay la: " << x.giobay << endl;
        os << "Noi di la: " << x.noidi << endl;
        os << "Noi den la: " << x.noiden << endl;
        os << "======================== \n" ;
        return os;
    }

int showmenu()
{
    system("cls");
    int choose;
    cout << ">>=========MENU=========<< \n";
    cout << "1. Nhap cac chuyen bay. \n" ;
    cout << "2. Cac chuyen bay tu som den muon. \n";
    cout << "3. Tim kiem chuyen bay theo ma,noi di hoac noi den. \n"  ;
    cout << "4. Tim kiem chuyen bay theo dia diem va ngay di. \n"  ;
    cout << "5. So chuyen bay theo yeu cau. \n";
    cout << "0. Thoat chuong trinh. \n" ;
    cout << ">>======================<< \n";
    cout << "=> Lua chon cua ban la: " ;
    cin >> choose;
    return choose;
}
int main()
{
    int sl;
    vector<chuyenbay> ds;
    while(true)
    {
        int choose = showmenu();
        switch(choose)
        {
        case 1://Nhap cac chuyen bay
            system("cls");
            if(!ds.empty()) ds.clear();
            cout << "Nhap so luong chuyen bay: ";
            cin >> sl;
            cin.ignore();
            for(int i = 0;i<sl;i++)
            {
                chuyenbay tmp;
                cin >> tmp;
                ds.push_back(tmp);
            }
            break;
        case 2: //Cac chuyen bay tu som den muon
            system("cls");
            sapxep(ds,sl);
            if(ds.empty()) cout << "Danh sach rong \n";
            else
            {
                for(int i =0;i<sl;i++) cout << ds[i];
            }
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 3://Tim kiem chuyen bay theo ma,noi di hoac noi den
            system("cls");
            if(ds.empty()) cout << "Danh sach rong \n";
            timchuyen(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 4:
            system("cls");
            if(ds.empty()) cout << "Danh sach rong \n";
            else timchuyen1(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 5:
            system("cls");
            cout << demchuyen(ds,sl) << " chuyen \n";
            cout << "Nhan enter de quay lai.";
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
