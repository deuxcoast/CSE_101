/*
 * List.c
 * Implementation of the integer singly linked List ADT.
 */
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/* ==== Private types ===================================================
 * Nothing below is visible to clients; they only see "List".
 */

typedef struct NodeObj* Node;

typedef struct NodeObj {
    int data;
    Node next; /* NULL marks the end of the list */
} NodeObj;

typedef struct ListObj {
    Node head; /* NULL when the list is empty */
    int length;
} ListObj;

/* ==== Private helpers ==================================================
 * "static" = only visible inside this file (C's version of private).
 */

/* Allocates one node on the heap. Every newNode() needs exactly one
 * matching freeNode() somewhere, or the program leaks memory. */
static Node newNode(int data) {
    Node N = malloc(sizeof(NodeObj)); /* size of the struct, NOT sizeof(Node) */
    if (N == NULL) {
        fprintf(stderr, "List Error: newNode() out of memory\n");
        exit(EXIT_FAILURE);
    }
    N->data = data;
    N->next = NULL;
    return N;
}

/* Frees *pN and sets the caller's pointer to NULL, so nobody can
 * accidentally use it afterward (a "dangling pointer"). */
static void freeNode(Node* pN) {
    if (pN != NULL && *pN != NULL) {
        free(*pN);
        *pN = NULL;
    }
}

/* Exits with a message if a client passes a NULL List. */
static void checkList(List L, const char* fn) {
    if (L == NULL) {
        fprintf(stderr, "List Error: calling %s() on NULL List reference\n",
                fn);
        exit(EXIT_FAILURE);
    }
}

/* ==== Constructors / Destructors ====================================== */

List newList(void) {
    List L = malloc(sizeof(ListObj));
    if (L == NULL) {
        fprintf(stderr, "List Error: newList() out of memory\n");
        exit(EXIT_FAILURE);
    }
    L->head = NULL;
    L->length = 0;
    return L;
}

void freeList(List* pL) {
    if (pL != NULL && *pL != NULL) {
        clear(*pL); /* first free every node the list owns... */
        free(*pL);  /* ...then free the ListObj itself        */
        *pL = NULL;
    }
}

/* ==== Access functions ================================================ */

int length(List L) {
    checkList(L, "length");
    return L->length;
}

bool isEmpty(List L) {
    checkList(L, "isEmpty");
    return L->length == 0;
}

bool contains(List L, int x) {
    checkList(L, "contains");
    /* TODO: walk the list with a cursor and return true if any node holds x.
     * Pattern:  for (Node N = L->head; N != NULL; N = N->next) { ... }   */
    (void)x; /* silences "unused parameter"; delete once implemented */
    return false;
}

/* ==== Manipulation procedures ========================================= */

/* Worked example: insert at the front. Note the order of the two pointer
 * updates. Swapping them would lose the rest of the list. */
void prepend(List L, int x) {
    checkList(L, "prepend");
    Node N = newNode(x);
    N->next = L->head; /* 1. new node points at the old first node */
    L->head = N;       /* 2. head now points at the new node       */
    L->length++;
}

void append(List L, int x) {
    checkList(L, "append");
    /* TODO: insert x at the back.
     * Two cases: (1) the list is empty, so this is just like prepend;
     *            (2) otherwise, walk to the node whose next is NULL
     *                and attach the new node there.
     * Don't forget L->length++.                                          */
    (void)x;
}

bool deleteValue(List L, int x) {
    checkList(L, "deleteValue");
    /* TODO: remove the FIRST node holding x and return true, or return
     * false if x isn't in the list.
     * Hard part: in a singly linked list you must stop at the node
     * BEFORE the one you're deleting, so you can relink around it.
     * Handle the special case where the head itself holds x.
     * Use freeNode(&target) and decrement L->length.                     */
    (void)x;
    return false;
}

/* Worked example: free every node. Save next BEFORE freeing the current
 * node. After free(), reading N->next is undefined behavior. */
void clear(List L) {
    checkList(L, "clear");
    Node N = L->head;
    while (N != NULL) {
        Node next = N->next;
        freeNode(&N);
        N = next;
    }
    L->head = NULL;
    L->length = 0;
}

void reverse(List L) {
    checkList(L, "reverse");
    /* TODO: reverse the list in place by re-pointing next pointers.
     * Classic approach uses three cursors: prev (starts NULL),
     * curr (starts at head), and next (saved before you overwrite
     * curr->next). When curr hits NULL, prev is the new head.            */
}

/* ==== Other =========================================================== */

void printList(FILE* out, List L) {
    checkList(L, "printList");
    for (Node N = L->head; N != NULL; N = N->next) {
        fprintf(out, "%d", N->data);
        if (N->next != NULL)
            fprintf(out, " ");
    }
    fprintf(out, "\n");
}
