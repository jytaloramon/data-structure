
#define SWAPVARIABLE(s, v, size_m)                                             \
    do {                                                                       \
        char aux = 0;                                                          \
        char *s_aux = (char *)s, *v_aux = (char *)v;                           \
        for (int i = 0; i < size_m; i++) {                                     \
            aux = s_aux[i];                                                    \
            s_aux[i] = v_aux[i];                                               \
            v_aux[i] = aux;                                                    \
        }                                                                      \
    } while (0);