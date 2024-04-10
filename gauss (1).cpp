#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

void print_array(int n, int m, bool *b, double **a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[j] || j == m - 1) 
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }   
}

void huvirgalt(int n, int m, int r, int s, double **a){
    double b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == r){
                b[r][j] = -(a[r][j] / a[r][s]);
            }
            else if(j == s){
                b[i][s] = a[i][s] / a[r][s];
            }
            else{
                b[i][j] = (a[i][j] * a[r][s] - a[i][s] * a[r][j]) / a[r][s];
            }
        }
    }
    b[r][s] = 1 / a[r][s];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){
    int n, m;

    cout << "Heden system oruulah ve?\n";
    cin >> n;

    cout << "Heden huvisagchtai ve?\n";
    cin >> m;

    m++;

    double** a = new double*[n];

    for(int i = 0; i < n; i++){
        a[i] = new double[m];
    }

    bool* bagana = new bool[m];
    int mur[n];

    cout << "Husnegt oruulna uu\n";
    for (int i = 0; i < n; i++) {
        mur[i] = -1;
        for (int j = 0; j < m; j++) {
            bagana[j] = 1;
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }

    bagana[m - 1] = 0;

    cout << "1-r husnegt:\n";
    print_array(n, m, bagana, a);
    
    int f = 1; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(bagana[j] == 1 && a[i][j] != 0){
                huvirgalt(n, m, i, j, a);
                bagana[j] = 0;
                mur[i] = j;
                break;
            }
        }
        if(mur[i] == -1 && a[i][m - 1] != 0){
            cout << "Etssiin hariu: Niitsgu\n";
            f = 0;
            break;
        }
        cout << i + 2 << "-r husnegt:\n"; 
        print_array(n, m, bagana, a);
    }
if (f == 1) {
    cout << "Etssiin hariu:";
    for (int i = 0; i < n; i++) {
        if (mur[i] != -1) {
            cout << "\nx" << mur[i] + 1 << " = ";
            int k = 0;
            for (int j = 0; j < m; j++) {
                if (bagana[j] == 1 && a[i][j] != 0) {
                    if (a[i][j] > 0 ) {
                        cout << "+";
                    } else if (a[i][j] < 0) {
                        cout << "-";
                    }
                    k = 1;
                    cout << abs(a[i][j]) << "*x" << j + 1;
                } else if (j == m - 1) {
                    if (a[i][j] > 0 ) {
                        cout << "-";
                    } else if (a[i][j] < 0 ) {
                        cout << "+";
                    }
                    k = 1;
                    cout << abs(a[i][j]);
                }
            }
        }
    }
    cout << endl;
}

    for (int i = 0; i < n; i++) {
    delete[] a[i];
    }
    delete[] a;
    delete[] bagana;

    return 0;
}