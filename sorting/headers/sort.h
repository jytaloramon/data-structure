/**
 * @author: Ytalo Ramon 
 * @date: 20/12/2020
 * 
 */

/** 
 * Byte-wise swap two items of size SIZE.
 * The beautiful implementation, by Language-C reference
 */
#define SWAP(a, b, size_type)        \
    int size = size_type;            \
    do {                             \
        char *v1 = a, *v2 = b, temp; \
                                     \
        do {                         \
            temp = *v1;              \
            *v1++ = *v2;             \
            *v2++ = temp;            \
        } while (--size > 0);        \
    } while (0);

#define FUNC_COMPARATOR_SORT int (*func_comparator_sort)(void *const, void *const)