struct node{
    int val;
    struct node * next;
};

typedef struct {
    int * stack;
    int capacity;
    int last_idx;
    // this is a simple linked list
    // that is used to implement an stack.
    struct node * minhead;    
} MinStack;

MinStack* minStackCreate() {
    MinStack * tmp;
    tmp = (MinStack*)malloc(sizeof(MinStack));
    tmp->capacity = 30001;
    tmp->stack = (int*)malloc(sizeof(int) * tmp->capacity);
    tmp->last_idx = 0;
    tmp->minhead = NULL;
    return tmp;
}

void minStackPush(MinStack* obj, int val) {
    // do nothing if it is full
    if (obj->last_idx == obj->capacity){
        return;
    }
    obj->stack[obj->last_idx] = val;
    obj->last_idx++;
    // enqueue if the val is the least
    if (obj->minhead == NULL){
        struct node * tmp = malloc(sizeof(struct node));
        tmp->val = val;
        tmp->next = NULL;
        obj->minhead = tmp;
    } else if (obj->minhead->val >= val){
        struct node * tmp = malloc(sizeof(struct node));
        tmp->val = val;
        tmp->next = obj->minhead;
        obj->minhead = tmp;
    }
}

void minStackPop(MinStack* obj) {
    // do nothing if it is empty 
    if (obj->last_idx == 0){
        return;
    }
    
    obj->last_idx--;
    int tmp = obj->stack[obj->last_idx];
    
    if (obj->minhead->val == tmp){
        struct node * k = obj->minhead;
        obj->minhead = obj->minhead->next;
        free(k);
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->last_idx-1];
}

int minStackGetMin(MinStack* obj) {
  return obj->minhead->val;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    while (obj->minhead != NULL){
        struct node * tmp = obj->minhead->next;
        free(obj->minhead);
        obj->minhead = tmp;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/