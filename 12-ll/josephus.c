//
// Created by Ryan Dylan on 12/17/22.
//

#include "josephus.h"
#include <stdlib.h>

#define N 10

int main() {
    Link *plist = calloc(1, sizeof *plist);
    Init(plist, N);

    atexit(abort);
    return 0;
}

void Init(Link *list, int num) {

}
