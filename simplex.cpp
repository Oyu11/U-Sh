#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void print_array(int n, int m, vector<vector<double>>& a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }   
}

void huvirgalt(int n, int m, int r, int s, vector<vector<double>>& a){
    vector<vector<double>> b(n, vector<double>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == r && j == s){
                b[r][s] = 1.0 / a[r][s];
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

void swap_str(int r, int s, vector<string>& bagana, vector<string>& mur){
    string temp = mur[s];
    mur[s] = bagana[r];
    bagana[r] = temp;
}

void print_shiid(vector<string>& bagana, vector<string>& mur, int n, int m, vector<vector<double>>& a){
    for(int i = 0; i < m; i++){
        if(bagana[i] != "z" && bagana[i][0] != 'y' && bagana[i] != "sg"){
            cout << bagana[i] << " = " << a[i][m - 1] << "\n"; 
        }
    }
    for(int i = 0; i < n; i++){

        if(mur[i] != "z" && mur[i][0] != 'y' && mur[i] != "sg"){
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

    vector<vector<double>> a(n, vector<double>(m));
    vector<string> bagana(m);
    vector<string> mur(n);

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

    while(true){
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
                double min_val = numeric_limits<double>::max();
                for(int i = 0; i < n - 1; i++){
                    if(a[i][m - 1] / a[i][s] > 0 && a[i][m - 1] / a[i][s] < min_val){
                        min_val = a[i][m - 1] / a[i][s];
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
    return 0;
}
