typedef int Vertex;
typedef struct Node *link;

typedef struct Node {
    Vertex value;
    link next;
} Node;

typedef struct {
    link head;
    link tail;
    int size;
} Queue;

Queue *create_queue();

int size(Queue *queue);

bool is_empty(Queue *queue);

int get_head(Queue *queue, bool *status);

void enqueue(Queue *queue, Vertex value);

int dequeue(Queue *queue, bool *status);

void destroy_queue(Queue *queue);