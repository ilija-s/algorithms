#include <vector>
#include <iostream>
#include <cmath>

std::vector<int> build_segment_tree_it(std::vector<int> arr) {
	int n = arr.size();
	int height = ceil(log2(n));
	int segment_tree_size = 2 * pow(2, height);

	std::vector<int> segment_tree(segment_tree_size, 0);

	std::copy(arr.begin(), arr.end(), segment_tree.begin() + n);

	for (int i = n - 1; i > 0; i--) {
		segment_tree[i] = segment_tree[2*i] + segment_tree[2*i+1];
	}

	return segment_tree;
}

/* Updates an element with new value 'el' on position 'pos' */
void update(int el, int pos, std::vector<int> &segment_tree, int n) {
	pos += n;
	int diff = el - segment_tree[pos];
	segment_tree[pos] = el;

	for (int i = pos / 2; i > 0; i /= 2) {
		segment_tree[i] += diff;
	}
}

int range_sum(int left, int right, std::vector<int> segment_tree, int n) {
	left += n;
	right += n;

	int sum = 0;

	for (; left <= right; left /= 2, right /= 2) {
		if (left % 2 == 1) {
			sum += segment_tree[left++];
		}
		if (right % 2 == 0) {
			sum += segment_tree[right--];
		}
	}

	return sum;
}

int main() {
	std::vector<int> array = { 1, 2, 3, 4, 5, 6 };

	int n = array.size();

	std::vector<int> segment_tree = build_segment_tree_it(array);

	for (int x : segment_tree)
		std::cout << x << " ";
	std::cout << "\n";

	update(11, 2, segment_tree, n);

	for (int x : segment_tree)
		std::cout << x << " ";
	std::cout << "\n";

	std::cout << range_sum(0, n-1, segment_tree, n) << "\n";

	return 0;
}