struct Node {
	int *next;
	int value;
	int *previous;
};

struct StrNode {
	int *next;
	char *value;
	int *previous;
}

int changeNext(struct Node *n, struct Node *next) {
	n->next = next;
	return 0;
}

int changeNext(struct None *n, struct StrNode *next) {
	n->next = next;
	return 0;
}

int changeNext(struct StrNode *n, struct Node *next) {
	n->next = next;
	return 0;
}

int changeNext(struct StrNode *n, struct StrNode *next) {
	n->next = next;
	return 0;
}

int changePrevious(struct Node *n, struct Node *prev) {
	n->previous = prev;
	return 0;
}

int changeValue(struct Node *n, int value) {
	n->value = value;
	return 0;
}