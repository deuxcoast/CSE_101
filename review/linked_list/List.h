/*
 * List.h
 * Public interface for an integer singly linked List ADT.
 *
 * Clients only ever see the name "List". The struct behind it is defined
 * in List.c, so clients can't reach inside and break the list's invariants.
 * This is the "opaque pointer" pattern, C's substitute for private members.
 */
#ifndef LIST_H_INCLUDE_
#define LIST_H_INCLUDE_

#include <stdbool.h>
#include <stdio.h>

/* List is a pointer to a struct whose contents are hidden in List.c. */
typedef struct ListObj* List;

/* ---- Constructors / Destructors ------------------------------------- */

/* Returns a new, empty List. Caller must eventually call freeList(). */
List newList(void);

/* Frees all memory owned by *pL and sets *pL to NULL.
 * Takes List* (a pointer to the caller's pointer) so it can null it out. */
void freeList(List* pL);

/* ---- Access functions ----------------------------------------------- */

int length(List L);
bool isEmpty(List L);
bool contains(List L, int x); /* true if x appears anywhere in L */

/* ---- Manipulation procedures ---------------------------------------- */

void prepend(List L, int x);     /* insert x at the front */
void append(List L, int x);      /* insert x at the back  */
bool deleteValue(List L, int x); /* delete first x; true if found */
void clear(List L);              /* delete every node; L stays valid */
void reverse(List L);            /* reverse L in place, no new nodes */

/* ---- Other ---------------------------------------------------------- */

/* Prints L to out as: 1 2 3 (followed by a newline). */
void printList(FILE* out, List L);

#endif
