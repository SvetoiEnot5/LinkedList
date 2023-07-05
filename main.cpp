#include <iostream>
using namespace std;
struct List{
    int elem;
    int line;
    int column;
    List *next = nullptr;
    List *prev = nullptr;
};
void addelem(List **nach, int number, int line, int col, List **kon) {
    struct List *temp;
    temp = new List;
    if (*nach == nullptr) {
        temp->prev= nullptr;
        temp->next=nullptr;
        temp->elem = number;
        temp->line = line;
        temp->column = col;
        *nach=temp;
        *kon=temp;
    } else {
        temp->prev=*kon;
        temp->next= nullptr;
        temp->elem = number;
        temp->line = line;
        temp->column = col;
        (*kon)->next=temp;
        *kon = temp;
    }
}


void prosmotr (List *nach) {
    List* t;
    t = nach;
    while (t!= nullptr) {
        cout << t->elem << " " << t->line << " " << t->column << endl;
        t=t->next;
    }
}
int main() {
    List *nach = nullptr;
    List *kon = nullptr;
    int sumline = 0;
    int m,n;
    int sr = 0;
    int k = 0;
    cout << "Number of lines: "; cin >> m;
    cout << "Number of columns: "; cin >> n;
    cout << "Matrix: ";
    int **a = new int *[m];
    for (int i = 0; i < m; ++i) {
        a[i] = new int [n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            k ++;
            sumline += a[i][j];
            if (a[i][j] >0){
                addelem(&nach,a[i][j],i+1,j+1, &kon);
            }
        }
        sr = sumline/k;
        addelem(&nach,sr,i+1,0, &kon);
        k = 0;
        sr = 0;
        sumline = 0;
    }
    prosmotr(nach);
    return 0;
}
