#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class hocsinh
{
private:
    string hoten;
    double toan,van,anh;
public:
    bool ktTen();
    double diemtb();
    void xeploai();
    friend void timkiem(hocsinh *p,int n);
    string getTen() {return hoten;}
    friend void hsyeutoan(hocsinh *p,int n);
    friend istream& operator>>(istream &is,hocsinh &x);
    friend ostream& operator<<(ostream &os,hocsinh x);
};

istream& operator>>(istream &is,hocsinh &x)
    {
        cout << "======================== \n" ;
        do
        {
            cout << "Nhap ho va ten: ";
            getline(is,x.hoten);
            if(!x.ktTen()) cout << "Vui long nhap lai!" << endl;
        }while(!x.ktTen());

        do
        {
            cout << "Nhap diem toan: ";
            is >> x.toan;
            if(x.toan < 0 || x.toan > 10) cout << "Vui long nhap lai!" <<endl;
        }while(x.toan <0 || x.toan > 10);

        do
        {
            cout << "Nhap diem van: ";
            is >> x.van;
            if(x.van < 0 || x.van > 10) cout << "Vui long nhap lai!" <<endl;
        }while(x.van <0 || x.van > 10);
        do
        {
            cout << "Nhap diem anh: ";
            is >> x.anh;
            if(x.anh < 0 || x.anh > 10) cout << "Vui long nhap lai!" <<endl;
        }while(x.anh <0 || x.anh > 10);
        cout << "======================== \n" ;
        return is;
    }
ostream& operator<<(ostream &os,hocsinh x)
    {
        os << "======================== \n" ;
        os << "Ho va ten: "<< x.hoten << endl;
        os << "Diem toan: " << x.toan << endl;
        os << "Diem van: " << x.van << endl;
        os << "Diem anh: " << x.anh << endl;
        os << "Diem trung binh: " << x.diemtb()<<endl;
        x.xeploai();
        os << endl;
        os << "======================== \n" ;
        return os;
    }
bool hocsinh::ktTen()
{
    for(int i = 0;i<hoten.length() -1;i++)
    {
        if(hoten[i] == ' ' && hoten[i+1] == ' ') return 0; // Hai ki tu trang lien tiep = sai
        if(hoten[i] == ' ' && !isupper(hoten[i+1])) return 0; // Khong viet hoa chu sau dau cach = sai
        if(isupper(hoten[i]) && isupper(hoten[i+1])) return 0; // Hai ki tu viet hoa lien tiep = sai
    }

    if(hoten[0] == ' ') return 0; //Co khoang trang o dau = sai
    if(!isupper(hoten[0])) return 0; //Chu dau khong viet hoa = sai



    if(hoten.length() < 1 || hoten.length() >100 ) return 0; //Nhap ki tu it hon 1 hoac lon hon 100 = sai
    // Begin - kiem tra xem co so hoac ki tu dac biet khong
    bool hasDigit = false,hasPunct =false;
    for(char c : hoten)
    {
        if(isdigit(c)) hasDigit =true;
        if(ispunct(c)) hasPunct = true;
    }
    if(hasDigit || hasPunct) return 0;
    // End - kiem tra xem co so hoac ki tu dac biet khong
    return 1;
}

double hocsinh::diemtb()
{
    return (2*toan+van+anh)/4;
}

void hocsinh::xeploai()
{
    if(diemtb() >=9) cout << "Xep loai: Xuat sac";
    else if(diemtb() >= 8 ) cout << "Xep loai: Gioi";
    else if(diemtb() >=6.5 ) cout << "Xep loai: Kha";
    else if(diemtb() >= 5) cout << "Xep loai: Trung binh";
    else cout << "Yeu";
}
// Begin - Ham tim vi tri hoc sinh co diem tb cao nhat
int top1(hocsinh *x,int n)
{
    int index = 0;
    double diemcaonhat = x[0].diemtb();
    for(int i= 1;i<n;i++)
    {
        if(x[i].diemtb() > diemcaonhat)
        {
            diemcaonhat = x[i].diemtb();
            index = i;
        }
    }
    return index;
}
// End - Ham tim vi tri hoc sinh co diem tb cao nhat


void timkiem(hocsinh *p,int n)
{
    int i =0;
    bool nf = false;
    string a;
    cout << "Ten can tim: ";
    cin.ignore();
    getline(cin,a);
    for(int i = 0;i<a.length();i++) a[i] = tolower(a[i]);

    while(i<n)
    {
        string x = p[i].getTen();
        for(int i = 0;i<x.length();i++) x[i] = tolower(x[i]);
        if(x.find(a) == string::npos ) i++;
        else
        {
            cout << p[i];
            i++;
            nf = true;
        }
    }
    if(!nf) cout << "Khong tim thay! \n";
}

void hsyeutoan(hocsinh *p,int n)
{
    double m = p[0].toan;
    for(int i = 1;i<n;i++)
    {
        if(m > p[i].toan) m = p[i].toan;
    }
    for(int i = 0;i<n;i++)
    {
        if(p[i].toan == m) cout << p[i];
    }
}



int showmenu()
{
    system("cls");
    int choose;
    cout << ">>=========MENU=========<<"<<endl;
    cout << "1. Nhap danh sach hoc sinh." << endl;
    cout << "2. In danh sach sinh vien." << endl;
    cout << "3. Hoc sinh co diem tb cao nhat." << endl ;
    cout << "4. Tim kiem hoc sinh." << endl ;
    cout << "5. Danh sach hs co diem toan thap nhat." << endl ;
    cout << "0. Thoat chuong trinh." << endl;
    cout << ">>======================<<"<<endl;
    cout << "=> Lua chon cua ban la: " ;
    cin >> choose;
    return choose;
}

int main()
{
    int sl = 0,index;
    hocsinh *ds = new hocsinh[100];
    while(true)
    {
        int choose = showmenu();
        switch(choose)
        {
        case 1: //Nhap danh sach hoc sinh
            system("cls");
            if(sl != 0)
            {
                sl = 0;
                delete[] ds;
                ds = nullptr;
            }
            cout << "Nhap so luong hoc sinh: ";
            cin >> sl;
            cin.ignore();
            ds = new hocsinh[sl];
            for(int i = 0;i<sl;i++)
            {
                if(i != 0) cin.ignore();
                cin >> ds[i];
            }
            break;
        case 2: //In danh sach hoc sinh
            system("cls");
            if(sl == 0) cout << "Danh sach rong \n";
            else
            {
                for(int i =0;i<sl;i++) cout << ds[i];
            }
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 3: // Hoc sinh co diem tb cao nhat
            system("cls");
            if(sl == 0) cout << "Danh sach rong \n";
            else{
                cout << "==========Top1========== \n";
                cout << ds[top1(ds,sl)];
            }
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 4: // Tim kiem hoc sinh
            system("cls");
            if(sl == 0)
            {
                cout << "Danh sach rong \n";
                cin.ignore();
            }
            else timkiem(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.get();
            break;
        case 5: // Danh sach hs co diem toan thap nhat
            system("cls");
            if(sl == 0) cout << "Danh sach rong \n";
            hsyeutoan(ds,sl);
            cout << "Nhan enter de quay lai.";
            cin.ignore();
            cin.get();
            break;
        case 0:
            delete[] ds;
            return 0;
        default:
            cout << "Lua chon khong hop le";
            break;
        }
    }
    return 0;
}
