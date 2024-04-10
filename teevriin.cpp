#include<bits/stdc++.h>

using namespace std;

void print_array(int n, int m, bool *b, double **a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[j] || j == m - 1) cout << a[i][j] << " ";
        }
        cout << "\n";
    }   
}

int main(){
    int n, m;

    cout << "Achaa yvuulah gazariin too?\n";
    cin >> m;

    cout << "Achaa huleen avah gazariin too?\n";
    cin >> n;

    int* a = new int[m + 1];
    int* b = new int[n + 1];
    int* as = new int[m + 1];
    int* bs = new int[n + 1];
    int** c = new int*[m + 1];
    int** ans = new int*[m + 1];

    for(int i = 0; i < m + 1; i++){
        c[i] = new int[n + 1];
        ans[i] = new int[n + 1];
    }
    
    int suma = 0;
    cout << "A n utgiig oruulna uu\n";
    for(int i = 0; i < m; i++){
        cin >> a[i];
        suma += a[i];
        as[i] = a[i];
    }

    int sumb = 0;
    cout << "B n utgiig oruulna uu\n";
    for(int i = 0; i < n; i++){
       cin >> b[i];
       sumb += b[i];
       bs[i] = b[i];
    }

    cout << "C n utgiig oruulba uu\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            ans[i][j] = -1;
        }
    }

    if(suma > sumb){
        b[n] = suma - sumb; 
        bs[n] = b[n];
        for(int i = 0; i < m; i++){
            c[i][n] = 0;
            ans[i][n] = -1;
        }
        n++;
    }
    else if(suma < sumb){
        a[m] = sumb - suma;
        as[m] = a[m];
        for(int i = 0; i < n; i++){
            c[m][i] = 0;
            ans[m][i] = -1;
        }
        m++;
    }

    int count = 0;

    while(count != m + n - 1){
        int mini = -1;
        int minj = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i] > 0 && b[j] > 0 && ans[i][j] == -1){
                    if(mini == -1 && minj == -1){
                        mini = i;
                        minj = j;
                    }
                    else if(c[mini][minj] > c[i][j]){
                        mini = i;
                        minj = j;
                    }
                }
                
            }
        }
        if(mini == -1){
            int k = 1;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(ans[i][j] != -1 && k == 1){
                        ans[i][j] = 0;
                        k = 0;
                    }
                }
            }
        }
        else{
            ans[mini][minj] = min(a[mini], b[minj]);
            a[mini] -= ans[mini][minj];
            b[minj] -= ans[mini][minj];
            cout << mini + 1<< " " << minj + 1<< " " << ans[mini][minj] << "\n";
        }
        count++;
    }

    cout << "- | ";
    for(int i = 0; i < n; i++){
        cout << bs[i] << " ";
    }
    cout << "\n";
    cout << "- | ";
    for(int i = 0; i < n + 2; i++){
        cout << "- ";
    }
    cout << "\n";

    int sum = 0;
    for(int i = 0; i < m; i++){
        cout << as[i] << " | ";
        for(int j = 0; j < n; j++){
            if(ans[i][j] == -1){
                cout << "- ";
            }
            else{
                cout << ans[i][j] << " ";
                sum += ans[i][j] * c[i][j];
            } 
        }
        cout << "\n";
    }

    cout << "Tulguur tuluvluguu nii zardal: ";
    cout << sum <<"\n";

    return 0;
}