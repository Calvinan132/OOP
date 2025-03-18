#include <iostream>

using namespace std;

#define MAX_N 1000

int tim(int A[], int B[], int m, int n, int vt[]) {
    int count = 0;

    for (int i = 0; i <= n - m; i++) //vi tri co the bat dau
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (B[i + j] != A[j])
            {
                match = false;//  Neu khong tim thay se dung tim kiem
                break;
            }
        }
        if (match) //Dung thi count +1
        {
            vt[count] = i;
            count++;
        }
    }
    return count;
}

int main() {
    int m, n;
    cout << "So phan tu mang A: ";
    cin >> m ;
    cout << "So phan tu mang B: ";
    cin >> n;
    int A[m], B[n], vt[MAX_N];
    cout << "Nhap vao mang A: ";
    for (int i = 0; i < m; i++) cin >> A[i];
    cout << "Nhap vao mang B: ";
    for (int i = 0; i < n; i++) cin >> B[i];
    int count = tim(A, B, m, n, vt);
    cout << "So lan xuat hien cua A trong B: "<< count << endl;
    cout << "Danh sach bat dau cua nhung lan xuat hien: ";
    for (int i = 0; i < count; i++) {
        cout << vt[i] << " ";
    }
    cout << endl;

    return 0;
}
