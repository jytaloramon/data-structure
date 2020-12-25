/**
 * @author: Ytalo Ramon
 */

/**
 * Define the prototype of the struct.
 * typedef struct _Stack Stack.
 * 
 */
typedef struct _Stack Stack;

/**
 * Define the prototype of the struct.
 * typedef struct _ItemStack ItemStack.
 */
typedef struct _ItemStack ItemStack;

/**
 * Initialize the stack, set value default.
 * @param stack Stack pointer.
 */
void initialize_stack(Stack *stack);

/**
 * Checks if the stack is empty.
 * @param stack Stack pointer.
 * @return int, or 1 if empty or 0 if not empty.
 */
int is_empty(Stack *stack);

/**
 * Checks if the stack is full.
 * @param stack Stack pointer.
 * @return int, or 1 if full or 0 if not full.
 */
int is_full(Stack *stack);

/**
 * Removes all items from the Stack.
 * @param stack Stack pointer.
 */
void clear(Stack *stack);

/**
 * Instance a new item of the stack.
 * @param value char pointer.
 * @return Item pointer, to new instance.
 */
ItemStack *new_item(char *value);

/**
 * Remove the item at the top of the stack.
 * @param stack Stack pointer.
 * @return char pointer, item removed.
 */
char *pop(Stack *stack);

/**
 * Push a new item onto the stack.
 * @param stack Stack pointer.
 * @param value char.
 * @return char pointer, item added.
 */
char *push(Stack *stack, char *value);

/**
 * Return the item on the top of the stack.
 * @param stack Stack pointer.
 * @return char pointer, top item.
 */
char *peek(Stack *stack);

/**
 * Search for value in the stack.
 * @param stack Stack pointer.
 * @param value char pointer.
 * @return int, if found, its offset from the top of the stack is returned.
 * Otherwise, -1 is returned.
 */
int search(Stack *stack, char *value);

/**
 * Print all elements in stack.
 * @param stack Stack pointer.
 */
void show(Stack *stack);
