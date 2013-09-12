#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int NUM_THREADS = 2;
static const int n = 20;
static int tally = 0;

static void *total(void *unused)
{
    int count;
    for (count = 0; count < n; count++) {
        tally = tally + 1;
    }
    return NULL;
}

static int expected_count = 0;

void run_threads()
{
    int i;
    tally = 0;

    pthread_t threads[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, total, NULL);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    if (tally != n * NUM_THREADS) {
        printf("\ntally = %d\n", tally);
        expected_count = 0;
    } else {
        printf("tally = %d (%d times)\r", tally, ++expected_count);
        fflush(stdout);
    }
}

int main(int argc, char *argv[])
{
    if (argc >= 2) NUM_THREADS = atoi(argv[1]);
    printf("%d threads at a time\n", NUM_THREADS);
    while (1) { 
        run_threads();
    }
    return 0;
}
