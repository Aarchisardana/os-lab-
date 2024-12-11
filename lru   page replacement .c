#include <stdio.h>
#include <stdlib.h>

int fsize, ssize, frame[10], arrive[30], rstring[30];

int pagefound(int x);
void display();
int leastused();
int pagelocation(int x);

int main() {
    int i, lfi, idx, cs = 0, ls = 0, pf = 0, j = 0, y, k, z = 0, time = 0;

    printf("\n\n\t\t LRU PAGE REPLACEMENT");
    printf("\n\t\t --------------------");

    printf("\n\n\t Enter the frame size: ");
    scanf("%d", &fsize);

    if (fsize <= 0 || fsize > 10) {
        printf("\nInvalid frame size. Please enter a value between 1 and 10.\n");
        return 1;
    }

    printf("\n\t Enter the reference string size: ");
    scanf("%d", &ssize);

    if (ssize <= 0 || ssize > 30) {
        printf("\nInvalid reference string size. Please enter a value between 1 and 30.\n");
        return 1;
    }

    printf("\n\t Enter the reference string: ");
    for (i = 0; i < ssize; i++)
        scanf("%d", &rstring[i]);

    for (k = 0; k < fsize; k++) {
        frame[k] = -3;  // Initialize frames with -3 to indicate empty slots
        arrive[k] = 0;
    }

    for (i = 0; i < ssize; i++) {
        y = pagefound(rstring[i]);
        if (y == 0) {
            pf++;
            if (cs >= fsize) {
                lfi = leastused();
                frame[lfi] = rstring[i];
                arrive[lfi] = ++time;
            } else {
                frame[cs] = rstring[i];
                arrive[cs] = ++time;
            }
        } else {
            idx = pagelocation(rstring[i]);
            arrive[idx] = ++time;
        }
        cs++;
        display();
    }

    printf("\n\nPage faults = %d\n", pf);
    return 0;
}

int pagefound(int x) {
    int i, val = 0;
    for (i = 0; i < fsize; i++) {
        if (x == frame[i]) {
            val = 1;
            break;
        }
    }
    return val;
}

void display() {
    int i;
    printf("\n");
    for (i = 0; i < fsize; i++) {
        if (frame[i] >= 0) {
            printf("%d\t", frame[i]);
        } else {
            printf("-\t");
        }
    }
}

int leastused() {
    int i, min = 0;
    for (i = 1; i < fsize; i++) {
        if (arrive[i] < arrive[min]) {
            min = i;
        }
    }
    return min;
}

int pagelocation(int pageno) {
    int i;
    for (i = 0; i < fsize; i++) {
        if (frame[i] == pageno) {
            return i;
        }
    }
    return -1;  // This case should never happen
}
