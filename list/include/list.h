/**
 * @author Ytalo Ramon
 * @date   14/02/2021
*/

#include "stdlib.h"
#include "../../includes/macro.h"

/**
 * Define the prototype of the struct.
 * struct _List List.
*/
typedef struct _List List;

/**
 * Define the prototype of the struct.
 * struct _ItemList ItemList.
*/
typedef struct _ItemList ItemList;

/**
 * Checks if the list is empty.
 * @param list List pointer.
 * @return Or 1 if empty or 0 if not empty.
*/
int is_empty(List *list);

/**
 * Adds an element at the end of the list.
 * @param list List pointer.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
*/
int append(List *list, void *elmnt);

/**
 * Adds an element at the specified position.
 * @param list List pointer.
 * @param posi Insertion position.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
*/
int insert_at(List *list, int posi, void *elmnt);

/**
 * Remove the fist element.
 * @param list List pointer.
 * @return The instance removed or NULL if list is empty.
*/
void *remove_first(List *list);

/**
 * Remove the element at the specified position.
 * @param list List pointer.
 * @param posi Position of the removed element. Value -1 to remove the last element.
 * @return The instance removed or NULL if list is empty.
*/
void *remove_at(List *list, int posi);

/**
 * Removes all items from the list.
 * @param list List pointer.
*/
void clear(List *list);

/**
 * Returns the index of the first element with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return Object index if found, or -1 if not.
*/
int index_of(List *list, void *value, COMPARATOR);

/**
 * Returns the first element with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return The object if found, or NULL if not.
*/
void *find(List *list, void *value, COMPARATOR);

/**
 * Returns the number of elements with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return Number of elements that satisfy the conditions.
*/
size_t count(List *list, void *value, COMPARATOR);

/**
 * String object that represents the list.
 * @param list List pointer.
 * @param to_string Formatting function.
 * @return Representation string.
*/
char *list_to_string(List *list, TOSTRING);