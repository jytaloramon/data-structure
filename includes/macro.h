/**
 * @author Ytalo Ramon
 * @date   15/02/2021
*/

/**
 * Comparison function signature
 * @param elmnt1
 * @param elmnt2
 * @return Result of the comparison of the two values
*/
#define COMPARATOR int(*comparator)(void *const, void *const)

/**
 * ToString function signature
 * @param object
 * @return String representing the data type value.
*/
#define TOSTRING char* (*to_string)(void *const)

#define BUFFER 1024