#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "state.h"
#include "aStar.h"

int main() {
    bool sucess = false;

    sucess = aStar();

    if(sucess == true) {
        printf("\nSuccessfully finished\n");
        return EXIT_SUCCESS;
    }
    else {
        printf("\nFailed run\n");
        return EXIT_FAILURE;
    }
}