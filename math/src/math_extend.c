/**
 * @author Ytalo Ramon
 * @date   14/02/2021
*/

#include "stdlib.h"
#include "../include/math_extend.h"

size_t mod(int value, int max){
    int rs = value % max;
    return rs >= 0 ? rs : max + rs;
}
