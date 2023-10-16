#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

int main(void){
    Queue *queue = create_queue();
    if (is_empty(queue)) printf("Queue is empty\n");

    enqueue(queue, 4);
    if (!is_empty(queue)) printf("Queue is not empty\n");
    return 0;
}

Queue *create_queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue *queue){
    return queue->size;
}

bool is_empty(Queue *queue){
    return (queue->size == 0);
}

int get_head(Queue *queue, bool *status){
    if (is_empty(queue)){
        *status = false;
        return NULL;
    }
    *status = true;
    return queue->head->value;
}

void enqueue(Queue *queue, Vertex value){
    link newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if (is_empty(queue)){
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }


    queue->size++;
}

int dequeue(Queue *queue, bool *status){
    if (is_empty(queue)){
        *status = false;
        return NULL;
    }
    *status = true;

    int value = queue->head->value;

    link oldHead = queue->head;

    if (queue->size == 1){
        queue->head = NULL;
        queue->tail = NULL;
    } 
    else {
        queue->head  = queue->head->next;
    }

    free(oldHead);

    queue->size--;

    return value;
}

void destroy_queue(Queue *queue){
    link currentNode = queue->head;

    while (currentNode != NULL){
        link temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(queue);
}

