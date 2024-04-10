#include<bits/stdc++.h>

using namespace std;

void print_array(int n, int m, double **a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }   
}

void huvirgalt(int n, int m, int r, int s, double **a){
    double b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == r && j == s){
                b[r][s] = 1 / a[r][s];
            }
            else if(i == r){
                b[r][j] = (a[r][j] / a[r][s]);
            }
            else if(j == s){
                b[i][s] = -a[i][s] / a[r][s];
            }
            
            else{
                b[i][j] = (a[i][j] * a[r][s] - a[i][s] * a[r][j]) / a[r][s];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}

void swap_str(int r, int s, string *bagana, string *mur){
    cout << mur[r] << " " << bagana[s] << "\n";
    string temp = mur[r];
    mur[r] = bagana[s];
    bagana[s] = temp;
}

void print_shiid(string *bagana, string *mur, int n, int m, double **a){
    for(int i = 0; i < m; i++){
        if(mur[i][0] == 'x'){
            cout << mur[i] << " = " << a[i][m - 1] << "\n"; 
        }
    }
    for(int i = 0; i < n; i++){
        if(bagana[i][0] == 'x'){
            cout << mur[i] << " = 0\n"; 
        }
    }
}

int main(){
    int n, m, t;

    cout << "Heden system oruulah ve?\n";
    cin >> n;

    cout << "Heden huvisagchtai ve?\n";
    cin >> m;

    cout << "1) min. 2) max\n";
    cin >> t;

    m++;

    double** a = new double*[n];

    for(int i = 0; i < n; i++){
        a[i] = new double[m];
    }

    string bagana[m];
    string mur[n];
 
    for(int i = 0 ; i < n; i++){
        cin >> mur[i];
    }
    for(int i = 0 ; i < m; i++){
        cin >> bagana[i];
    }

    cout << "Husnegt oruulna uu\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << "1-r husnegt:\n";
    print_array(n, m, a);

    while(1){
        int p = 1;
        int k = 0;
        int g = 0;
        for(int i = 0; i < n - 1; i++){
            if(a[i][m - 1] < 0){
                p = 0;
                k = i;
                break;
            }
        }
        if(p){
            cout << "Tulguur shiid:\n";
            print_shiid(bagana, mur, n, m, a);
            cout << "z = " << a[n - 1][m - 1] << "\n";
            break;
        }
        else{
            int l = 0;
            int r = -1, s = -1;
            for(int j = 0; j < m - 1; j++){
                if(a[k][j] < 0){
                    s = j;
                    break;
                }
            }
            if(s < 0){
                cout << "Niitsgu\n";
                break;
            }
            else{
                float min = INT_MAX;
                for(int i = 0; i < n - 1; i++){
                    if(a[i][m - 1]/a[i][s] > 0 && a[i][m - 1]/a[i][s] < min){
                        min = a[i][m - 1]/a[i][s];
                        r = i;
                    }
                }
                if(r == -1){
                    cout << "Niitsgu\n";
                    break;
                }
                else{
                    cout << r << " " << s << "\n";
                    huvirgalt(n, m, r, s, a);
                    swap_str(r, s, bagana, mur);
                    print_array(n, m, a);
                }
            }
        }
    }

    
} 