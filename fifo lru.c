#include <stdio.h>
#include <stdlib.h>

int fsize, ssize, frame[10], rstring[30];
int front = 0;  // Pointer to track the oldest frame position (FIFO queue)

int pagefound(int x);
void display();

int main() {
    int i, pf = 0 ;
    

    printf("\n\n\t\t FIFO PAGE REPLACEMENT");
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
    for (i = 0; i < fsize; i++)
        frame[i] = -1;

    // Process each page in the reference string
    for (i = 0; i < ssize; i++) {
        // Check if the page is already in the frame
        if (!pagefound(rstring[i])) {
            pf++;  // Page fault

            // Replace the oldest frame with the new page (FIFO)
            frame[front] = rstring[i];
            front = (front + 1) % fsize;  // Move the front pointer circularly
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
        if (frame[i] == x)
            return 1;
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
