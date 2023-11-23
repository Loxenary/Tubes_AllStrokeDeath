#include "../src/adt/liststatik.h"

int main() {
    ListStatik L, L2, L3;

    printf("List 1, input length then list elements: ");
    SreadList(&L);
    printf("List length: %d\n", SlistLength(L));
    printf("First index: %d\n", SgetFirstIdx(L));
    printf("Last index: %d\n", SgetLastIdx(L));

    printf("Input index: ");
    IdxType idx;
    scanf("%d", &idx);
    printf("Is index effective? %d\n", SisIdxEff(L, idx));
    printf("Is the list empty? %d\n", SisEmpty(L));
    printf("Is the list full? %d\n", SisFull(L));
    printf("List: \n");
    SprintList(L);

    printf("\nList 2, input length (length is equal to L1) then list elements: ");
    SreadList(&L2);

    L3 = SplusMinusList(L, L2, TRUE);
    printf("Sum of List 1 and List 2: \n");
    SprintList(L3);

    L3 = SplusMinusList(L, L2, FALSE);
    printf("\nResult of subtracting List 1 and List 2: \n");
    SprintList(L3);

    printf("\nAre List 1 and List 2 equal? %d\n", SisListEqual(L, L2));

    ElType elmt;
    printf("Input element: ");
    scanf("%d", &elmt);

    printf("Input index (must be effective): ");
    scanf("%d", &idx);

    printf("The index of the first occurrence of %d in List 1 is: %d\n", elmt, SindexOf(L, elmt));

    ElType min, max;
    SextremeValues(L, &max, &min);
    printf("Min in List 1: %d\nMax in List 1: %d\n", min, max);

    insertFirst(&L, elmt);
    printf("List 1 after inserting the element at the first index:\n");
    SprintList(L);

    insertAt(&L, elmt, idx);
    printf("\nList 1 after inserting the element at index:\n");
    SprintList(L);

    SinsertLast(&L, elmt);
    printf("\nList 1 after inserting the element at the last index:\n");
    SprintList(L);

    SdeleteLast(&L, &elmt);
    printf("\nList 1 after deleting the element at the last index:\n");
    SprintList(L);

    deleteAt(&L, &elmt, idx);
    printf("\nList 1 after deleting the element at index:\n");
    SprintList(L);

    deleteFirst(&L, &elmt);
    printf("\nList 1 after deleting the element at the first index:\n");
    SprintList(L);

    sortList(&L, TRUE);
    printf("\nList 1 after sorting in ascending order:\n");
    SprintList(L);

    sortList(&L, FALSE);
    printf("\nList 1 after sorting in descending order:\n");
    SprintList(L);

    return 0;
}