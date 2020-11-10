#include "pattern_search.h"

int pattern_search::getProximoEstado(char* pat, int M, int state, int x) {
    // si el char es igual al del patron incrementa el estado
    if (state < M && x == pat[state])
        return state+1;

    // ns guarda el resultado que es siguiente estado
    int ns, indPatron;

    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns-1] == x)
        {
            for (indPatron = 0; indPatron < ns-1; indPatron++)
                if (pat[indPatron] != pat[state-ns+1+indPatron])
                    break;
            if (indPatron == ns-1)
                return ns;
        }
    }

    return 0;
}


