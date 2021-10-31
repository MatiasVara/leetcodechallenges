/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

int last_indexA = 0;
int last_indexB = 0;
struct Node ** stackA;
struct Node ** stackB;

void push(int * last_index, struct Node ** stack, struct Node * val){
    if (val == NULL){
        return;
    }
    stack[*last_index] = val;
    (*last_index)++;
}

bool isempty(int last_index){
    if (last_index == 0){
        return true;
    }
    return false;
}

/* CAPACITY is about 2^12 which is the number of node at high 12 */
#define CAPACITY 4096
struct Node* connect(struct Node* root) {
    stackA = (struct Node **)malloc(CAPACITY * sizeof(struct Node *));
    stackB = (struct Node **)malloc(CAPACITY * sizeof(struct Node *));
    push(&last_indexA, stackA, root);
    while (isempty(last_indexA) == false){
        struct Node*  prev = NULL;
        int count = 0;
        // walk the stack from index 0 to index last_indexA
        while (count < last_indexA){
            struct Node * tmp = stackA[count];
            tmp->next = prev;
            count++;
            prev = tmp;
            push(&last_indexB, stackB, tmp->right);
            push(&last_indexB, stackB, tmp->left);
        }
        // swap() last_index and stack
        int tmp = last_indexB;
        last_indexB = 0;
        last_indexA = tmp;
        struct Node ** ptmp;
        ptmp = stackA;
        stackA = stackB;
        stackB = ptmp;
    }
    return root;
}
