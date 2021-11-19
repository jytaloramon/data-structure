/**
 * @author Ytalo Ramon
 * @date 13/06/2021
 *
 */

#include "../include/arithmetic.h"

size_t divmodular(int a, int b) {

    int v = a % b;

    return v >= 0 ? v : v + b;
}