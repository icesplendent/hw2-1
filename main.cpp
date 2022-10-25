#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);

InterruptIn button(BUTTON1);

// Creates a queue with default size
EventQueue queue;

// Thread
Thread t;

void message() {
    printf("uLCD printing...\n");
    uLCD.color(WHITE);
    uLCD.printf("\nHello uLCD World\n");
    ThisThread::sleep_for(1s);
    printf("Done.\n");
}

void Q() { queue.call(message); }

int main() {
    // Start the event queue
    t.start(callback(&queue, &EventQueue::dispatch_forever));

    button.fall(&Q);
}
