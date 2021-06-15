/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO: to ask the type of elements the stack contains
// TODO: to ask the API
struct Stack{
  struct TreeNode ** array;
  unsigned int top;  
  unsigned int capacity;
};

struct Stack * initStack(unsigned int capacity){
  struct Stack * st;
  st = malloc(sizeof(struct Stack));
  st->capacity = capacity;
  st->top = -1;
  st->array = malloc(sizeof(struct TreeNode *) * capacity);
  return st;
}

bool push(struct Stack * st, struct TreeNode * val){
  if (val == NULL){
      return false;
  }
  if (st->top == st->capacity - 1){
    return false;
  }
  st->top++;
  st->array[st->top] = val;
  return true;
}

bool pop(struct Stack * st, struct TreeNode ** val){
  if (st->top == -1){
    return false;
  }
  *val = st->array[st->top];
  st->top--;
  return true;
}

bool isEmpty(struct Stack * st){
    if (st->top == -1){
        return true;
    }
    return false;
}

void freeStack(struct Stack * st){
  free(st->array);
  free(st);
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int GetHigh(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    return 1 + max(GetHigh(root->left), GetHigh(root->right));
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int high;
    struct Stack * oldstack;
    struct Stack * newstack;
    int ** result;
    
    high = GetHigh(root);
    *returnSize = high;
    result = (int**)malloc(sizeof(int*) * high);
    
    // numbero de columns por cada array
    returnColumnSizes[0] = (int *) malloc(sizeof(int) * high);

    oldstack = initStack(2048);
    newstack = initStack(2048);
    
    push(oldstack, root);
    int col = 0;
    
    while (!isEmpty(oldstack)){
        returnColumnSizes[0][col] = (oldstack->top+1);
        int * p = malloc(sizeof(int) * (oldstack->top+1));
        for (int j=0; j < (oldstack->top+1); j++){
          struct TreeNode * tmp = oldstack->array[j];
          p[j] = tmp->val;
          push(newstack, tmp->left);
          push(newstack, tmp->right);
        }
        oldstack->top = -1;
        result[col] = p;
        col++;
        struct Stack * tmp;
        tmp = oldstack;
        oldstack = newstack;
        newstack = tmp;
    }
    
    freeStack(oldstack);
    freeStack(newstack);
    
    return result;
}
