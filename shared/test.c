#include <stdio.h>
#include "vector.h"

int main(void)
{
    Vector v = vectorNew(3);

    // Add some values
    vectorPush(&v, 10);
    vectorPush(&v, 20);
    vectorPush(&v, 30);

    printf("Vector after pushing values:\n");
    vectorStatus(v);

    // Push again to test resizing
    vectorPush(&v, 40);

    printf("\nVector after resize:\n");
    vectorStatus(v);

    // Test length and get
    printf("\nLength: %d\n", vectorLen(v));
    printf("Value at index 1: %d\n", vectorGet(v, 1));

    // Test set
    vectorSet(v, 1, 99);
    printf("New value at index 1: %d\n", vectorGet(v, 1));

    // Test invalid index
    printf("Invalid index: %d\n", vectorGet(v, 10));

    // Test pop
    printf("Popped value: %d\n", vectorPop(v));

    printf("\nFinal vector:\n");
    vectorStatus(v);

    vectorDelete(v);

    return 0;
}
