/**
 * @author Ytalo Ramon
 * @date   05/10/2021
 */

#define SWAPVARIABLE(s, v, size_m)                                             \
    do {                                                                       \
        char aux = 0;                                                          \
        char *s_aux = (char *)s, *v_aux = (char *)v;                           \
        for (size_t i = 0; i < size_m; i++) {                                  \
            aux = s_aux[i];                                                    \
            s_aux[i] = v_aux[i];                                               \
            v_aux[i] = aux;                                                    \
        }                                                                      \
    } while (0);
