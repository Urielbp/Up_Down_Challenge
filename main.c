#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aStar.h"

int main() {
    bool success = false;

    success = aStar();

    if(success == true) {
        printf("\nSuccessfully finished\n");
        return EXIT_SUCCESS;
    }
    else {
        printf("\nFailed run\n");
        return EXIT_FAILURE;
    }

}