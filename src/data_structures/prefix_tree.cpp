#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct trie_node {
	std::unordered_map<char, trie_node*> edges;
	bool isWord = false;
};

void add_word(std::string word, trie_node* root, int counter) {
	if (counter == word.length()) {
		root->isWord = true;
		return;
	}
	
	auto it = root->edges.find(word[counter]);

	if (it == root->edges.end()) {
		root->edges[word[counter]] = new trie_node();
	}

	add_word(word, root->edges[word[counter]], counter + 1);
}

bool remove_word(std::string word, trie_node* root, int counter) {
	if (root == nullptr) {
		return true;
	}
	
	if (counter == word.length()) {
		root->isWord = false;
	} else {
		auto it = root->edges.find(word[counter]);

		if (it != root->edges.end() && remove_word(word, it->second, counter + 1)) {
			root->edges.erase(it);
		}
	}

	if (!root->isWord && root->edges.size() == 0) {
		delete root;
		return true;
	} else {
		return false;
	}
}

bool contains_word(std::string word, trie_node* root, int counter) {
	if (root == nullptr) {
		return false;
	}

	if (counter == word.length()) {
		return root->isWord;
	}

	auto it = root->edges.find(word[counter]);

	if (it == root->edges.end()) {
		return false;
	}

	return contains_word(word, it->second, counter + 1);
}

void delete_trie(trie_node* root) {
	if (root != nullptr) {
		for (auto& n : root->edges) {
			delete_trie(n.second);
		}
		delete root;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::vector<std::string> dict = {"code", "coder", "coding", "codecs"};

	trie_node* root = new trie_node();

	for (std::string word : dict) {
		add_word(word, root, 0);
		if (!contains_word(word, root, 0)) {
			std::cout << "error when adding word" << std::endl;
			return -1;
		}
	}

	if (contains_word("coder", root, 0)) {
		std::cout << "Trie contains word coder" << std::endl;
	}

	bool removed_tree = remove_word("coder", root, 0);

	if (contains_word("coder", root, 0)) {
		std::cout << "Trie contains word coder" << std::endl;
	} else {
		std::cout << "Trie does not contain word coder" << std::endl;
	}

	delete_trie(root);

	return 0;
}