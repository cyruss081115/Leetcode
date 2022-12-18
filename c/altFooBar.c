#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <assert.h>


void printFoo();
void printBar();


typedef struct {
    int n;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    bool isPrintFoo;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));

    obj->n = n;
    pthread_cond_init(&obj->cond, NULL);
    pthread_mutex_init(&obj->mutex, NULL);
    obj->isPrintFoo = true;

    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);

        // wait for isPrintFoo turns true
        while (obj->isPrintFoo == false) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        obj->isPrintFoo = false;
        pthread_cond_broadcast(&obj->cond);

        pthread_mutex_unlock(&obj->mutex);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        
        // printBar() outputs "bar". Do not change or remove this line.
        while (obj->isPrintFoo == true) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printBar();

        obj->isPrintFoo = true;
        pthread_cond_broadcast(&obj->cond);

        pthread_mutex_unlock(&obj->mutex);
    }
}

void fooBarFree(FooBar* obj) {
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);
    free(obj);
}

int main() {
    int n = 10;
    FooBar* obj = fooBarCreate(n);

    pthread_t threads[2];

    int rc = pthread_create(&threads[0], NULL, (void*)&foo, (void*)obj);
    assert(rc == 0);
    rc = pthread_create(&threads[1], NULL, (void*)&bar, (void*)obj);
    assert(rc == 0);

    rc = pthread_join(threads[0], NULL);
    assert(rc == 0);
    rc = pthread_join(threads[1], NULL);
    assert(rc == 0);

    fooBarFree(obj);
    return 0;
}

void printFoo() {
    printf("Foo");
}

void printBar() {
    printf("Bar");
}

