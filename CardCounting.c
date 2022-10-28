#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static long iterations = 1000;
static long attempts = 0;
static long successes = 0;
static int deck[40] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10};

void shuffle(int *deck, int size);
void play(int *deck);
// void playHuman(int *deck);  TODO

int main(void) {

    srandom(time(NULL));
    for(int i = 0; i < iterations; i++) {
        shuffle(deck, 40);
        play(deck);
    }
    
    printf("After %ld iterations, you won %ld times (%.2f%%)\n", iterations, successes, (float)successes / (float)iterations * 100.0);
    printf("Cards gone through: %ld\nSuccesses: %ld\n", attempts, successes);
    printf("You managed %ld cards per success\n", attempts / successes);
    printf("You went through %ld cards per iteration\n", attempts / iterations);

   return 0;
}

void shuffle(int *deck, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        j = random() % size;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void play(int *deck) {
    int hasLost = 0;
    while(hasLost == 0) {

        int number = 1;
        int i;
        for(i = 0; i < 40; i++) {
            attempts++;

            if(number == deck[i]) {
                hasLost = 1;
                break;
            }
            number++;
            if(number == 4) number = 1;
        
        }
        if(hasLost == 0) {
            successes++;
            break;
        }
    }
}
