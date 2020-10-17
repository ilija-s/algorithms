#include "../headers/common_functions.h"
#include "../headers/insertion_sort.h"

using namespace asp;
using namespace std;

int main() {
    int array[MAX];

    int i;
    for(i = 0; i < MAX; i++)
        array[i] = rand()%100;

    cout << "Before sorting: ";
    print_array(array, MAX);
    cout << '\n';

    insertion_sort(array, MAX);

    cout << "After sorting: ";
    print_array(array, MAX);
    cout << '\n';

    return 0;
}