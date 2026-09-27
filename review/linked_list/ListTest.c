/*
 * ListTest.c
 * Test client for the List ADT. It uses only what List.h exposes.
 * Lines marked "expect" tell you what correct output looks like.
 */
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(void) {
    List L = newList();

    printf("-- starts empty --\n");
    printf("length: %d, isEmpty: %d\n", length(L), isEmpty(L));
    /* expect: length: 0, isEmpty: 1 */

    printf("\n-- prepend 3, 2, 1 --\n");
    prepend(L, 3);
    prepend(L, 2);
    prepend(L, 1);
    printList(stdout, L);              /* expect: 1 2 3 */
    printf("length: %d\n", length(L)); /* expect: length: 3 */

    printf("\n-- append 4, 5 (TODO) --\n");
    append(L, 4);
    append(L, 5);
    printList(stdout, L); /* expect: 1 2 3 4 5 */

    printf("\n-- contains (TODO) --\n");
    printf("contains 3: %d\n", contains(L, 3)); /* expect: 1 */
    printf("contains 9: %d\n", contains(L, 9)); /* expect: 0 */

    printf("\n-- deleteValue: head, middle, tail, missing (TODO) --\n");
    deleteValue(L, 1);
    deleteValue(L, 3);
    deleteValue(L, 5);
    printf("delete 9 found: %d\n", deleteValue(L, 9)); /* expect: 0 */
    printList(stdout, L);                              /* expect: 2 4 */
    printf("length: %d\n", length(L));                 /* expect: length: 2 */

    printf("\n-- reverse (TODO) --\n");
    append(L, 6);
    append(L, 8);
    reverse(L);
    printList(stdout, L); /* expect: 8 6 4 2 */

    printf("\n-- clear --\n");
    clear(L);
    printf("length: %d, isEmpty: %d\n", length(L), isEmpty(L));
    /* expect: length: 0, isEmpty: 1 */

    freeList(&L);
    printf("\nL is NULL after freeList: %d\n", L == NULL); /* expect: 1 */

    return EXIT_SUCCESS;
}
