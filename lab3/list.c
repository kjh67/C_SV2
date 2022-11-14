#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  if (list == NULL) {
    return 0;
  }
  else {
    return list->head + sum(list->tail);
  }
}

void iterate(int (*f)(int), List *list) {
  if (list != NULL) {
    // Apply operation to current list element
    list->head = f(list->head);
    iterate(f, list->tail);
  }
}

void print_list(List *list) { 
  // MAY BE BUGGY IF THE LIST HEAD IS EMPTY
  if (list->tail == NULL) {
    printf("%d\n", list->head);
  }
  else {
    printf("%d,",list->head);
    print_list(list->tail);
  }
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) { 
  if (list1 == NULL) {
    return list2;
  }
  else {
    // ensure list1 starts with lowest item
    if (list2->head < list1->head) {
      List *newhead = list2;
      list2 = list2->tail;
      newhead->tail = list1;
      list1 = newhead;
    }

    // copy a progress pointer so we don't lose the
    // head of the list
    List *pp = list1;
    while (pp->tail != NULL && list2 != NULL) {
      if (pp->tail->head > list2->head) {
        // store pointer to next list1 item *
        List *temp_tail = pp->tail;

        // reroute tail of list1 to head of list2
        pp->tail = list2;

        // store new head of list2
        list2 = list2->tail;

        // reroute from inserted item back to *
        pp->tail->tail = temp_tail;
      }
      pp = pp->tail;
    }
    // If we haven't exhausted list2, append to pp
    if (list2 != NULL) {
      pp->tail = list2;
    }
  }
  return list1;  
}

void split(List *list, List **list1, List **list2) { 
  if (list != NULL) {
    if (list->tail != NULL) {
      // at least two items
      *list1 = list;
      *list2 = list->tail;
      // carry on splitting
      split(list->tail->tail, &((*list1)->tail), &((*list2)->tail));
    }
    else {
      // only one item
      *list1 = list;
      if (*list2 != NULL) {
        *list2 = NULL;
      }
    }
  }
  else {
    if (*list1 != NULL) {
      *list1 = NULL;
    }
    if (*list2 != NULL) {
      *list2 = NULL;
    }
  }
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}
