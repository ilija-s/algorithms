#include <iostream>
#include <vector>

using namespace std;

/*
 * Finds two elements in sorted array whose sum is given as target_sum
 * Technique used here is called two pointer technique
 * Time complexity O(n)
 */

bool find_target_sum(vector<int> array, int target_sum) {
    int left_pointer = 0;
    int right_pointer = array.size() - 1;

    while (left_pointer < right_pointer) {
        if (array[left_pointer] + array[right_pointer] == target_sum)
            return true;
        else if (array[left_pointer] + array[right_pointer] < target_sum)
            left_pointer++;
        else
            right_pointer--;
    }
    return false;
}

int main() {
    int length;
    int target_sum;

    cin >> target_sum >> length;

    vector<int> array(length);

    for (int i = 0; i < length; i++) 
        cin >> array[i];

    bool contains_target_sum = find_target_sum(array, target_sum);

    if(contains_target_sum)
        cout << "1";
    else
        cout << "0";
    cout << endl;

    return 0;
}
