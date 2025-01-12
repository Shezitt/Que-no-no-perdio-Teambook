const int MAXSIZE = 26;
struct trie {
	struct trie *child[MAXSIZE];
	bool end; 
};
struct trie *getNode() {
	struct trie *node = new trie();
	node->end = false;
	for (int i= 0; i<MAXSIZE; i++) 
		node->child[i] = NULL;
	return node;
}
int search(struct trie *root, string &s) {
	struct trie *proot = root;
	for (int i= 0; i<s.size(); i++) {
		int ind = s[i]-'a';
		if (!proot->child[ind]) return 0;
		proot = proot->child[ind];
	}
	return proot->end;
}
void insert(struct trie *root, string &s) {
	struct trie *proot = root;
	for (int i= 0; i<s.size(); i++) {
		int ind = s[i]-'a';
		if (!proot->child[ind])
			proot->child[ind] = getNode();
		proot = proot->child[ind];
	}
	proot->end = true;
}