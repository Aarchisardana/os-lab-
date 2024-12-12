#include <stdio.h>
#include <stdlib.h>

int fsize, ssize, frame[10], rstring[30];
int recent[10];  // To track recency of page accesses

int pagefound(int x);
void display();
int findLRU();  // Function to find the least recently used page

int main() {
    int i, pf = 0, time = 0;

    printf("\n\n\t\t LRU PAGE REPLACEMENT");
    printf("\n\t\t ---------------------");

    // Input frame size
    printf("\n\n\t Enter the frame size: ");
    scanf("%d", &fsize);

    if (fsize <= 0 || fsize > 10) {
        printf("\nInvalid frame size. Please enter a value between 1 and 10.\n");
        return 1;
    }

    // Input reference string size
    printf("\n\t Enter the reference string size: ");
    scanf("%d", &ssize);

    if (ssize <= 0 || ssize > 30) {
        printf("\nInvalid reference string size. Please enter a value between 1 and 30.\n");
        return 1;
    }

    // Input reference string
    printf("\n\t Enter the reference string: ");
    for (i = 0; i < ssize; i++)
        scanf("%d", &rstring[i]);

    // Initialize frames with -1 to indicate empty slots
    for (i = 0; i < fsize; i++) {
        frame[i] = -1;
        recent[i] = 0;  // Initialize recency trackers to 0
    }

    // Process each page in the reference string
    for (i = 0; i < ssize; i++) {
        // Check if the page is already in the frame
        if (!pagefound(rstring[i])) {
            pf++;  // Page fault
            int replaceIndex;

            // If there is a free frame slot, use it
            int foundEmpty = 0;
            for (int j = 0; j < fsize; j++) {
                if (frame[j] == -1) {
                    replaceIndex = j;
                    foundEmpty = 1;
                    break;
                }
            }

            // If no empty frame is found, use the LRU replacement strategy
            if (!foundEmpty) {
                replaceIndex = findLRU();
            }

            // Replace the frame with the new page
            frame[replaceIndex] = rstring[i];
            recent[replaceIndex] = ++time;  // Update the recency counter
        }

        // Display the current state of the frames
        display();
    }

    printf("\n\nPage faults = %d\n", pf);
    return 0;
}

// Function to check if a page is already in a frame
int pagefound(int x) {
    for (int i = 0; i < fsize; i++) {
        if (frame[i] == x) {
            recent[i] = ++recent[0];  // Update recency on page hit
            return 1;
        }
    }
    return 0;
}

// Function to display the current state of the frames
void display() {
    printf("\n");
    for (int i = 0; i < fsize; i++) {
        if (frame[i] != -1) {
            printf("%d\t", frame[i]);
        } else {
            printf("-\t");
        }
    }
}

// Function to find the least recently used page
int findLRU() {
    int i, min = recent[0], pos = 0;

    for (i = 1; i < fsize; i++) {
        if (recent[i] < min) {
            min = recent[i];
            pos = i;
        }
    }
    return pos;
}
