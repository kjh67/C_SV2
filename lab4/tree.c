#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
  if (tree != NULL) {
    if (tree->value == x) {
      return 1;
    }
    else if (x < tree->value) {
      return tree_member(x, tree->left);
    }
    else {
      return tree_member(x, tree->right);
    }
  }
  return 0;
}

Tree *tree_insert(int x, Tree *tree) { 
  if (tree == NULL) {
    Tree *node = malloc(sizeof(Tree));
    node->left = empty;
    node->right = empty;
    node->value = x;
    return node;
  }
  else {
    if (x < tree->value) {
      tree->left = tree_insert(x, tree->left);
    }
    else if (tree->value < x) {
      tree->right = tree_insert(x, tree->right);
    }
    // else x is in the tree, so do nothing
    return tree;
  }
}

void tree_free(Tree *tree) { 
  // recursively free the memory!
  if (tree != NULL) {
    tree_free(tree->left);
    tree_free(tree->right);
  }
  free(tree);
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  /* TODO */
  // check if there's a left child
  // if so, follow it down

  // if not, replace the node with its right child
  // do this recursively (pointer updates yay)

  // ASSUME NON-EMPTY TREE
  if (tree->left != NULL) {
    // follow left child
    pop_minimum(tree->left, min, &(tree->left));
    // head of tree is still the same
    new_tree = &(tree);
  }
  else {
    // we're at the minimum
    *min = tree->value;
    // clean up
    free(tree->left);
    *new_tree = tree->right;
    free(tree);
  }
}

Tree *tree_remove(int x, Tree *tree) { 
  // find node to remove (recursively)
  if (tree != NULL) {
    if (tree->value == x) {
      // it's go time gamers

      printf("Removing %d\n", x);
      int *min = &(x);
      Tree **newtree = &(tree);
      pop_minimum(tree, min, newtree);

      printf("Min value on branch is %d\n", *min);

      tree = *newtree;
      if (*min != x) {
        tree->value = *min;
      }
    }
    else if (x < tree->value) {
      tree->left = tree_remove(x, tree->left);
    }
    else {
      tree->right = tree_remove(x, tree->right);
    }
    return tree;
  }

  // return the new tree!
  return tree;
}
