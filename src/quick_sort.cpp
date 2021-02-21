#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b);

int partition(vector<int>& v, int low, int high) {
    int first_high = low;
    int p = high;
    int i;

    for(i = low; i < high; i++){
        if(v[i] < v[p]){
            swap(v[i], v[first_high]);
            first_high++;
        }
    }
    swap(v[first_high], v[p]);

    return first_high;
}

void quick_sort(vector<int>& v, int low, int high) {
    if(low >= high)
        return;
    int p = partition(v, low, high);
    quick_sort(v, low, p - 1);
    quick_sort(v, p + 1, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    quick_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
