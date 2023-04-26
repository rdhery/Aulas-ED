#include <iostream>

using namespace std;

// fila - msm ideia de uma fila de banco. o primeiro a chegar eh o primeiro a ser servido
// devemos criar um ponteiro temporario para apontar os elementos que saem da fila
// vamos implentar um elemento p inicio e um p final da fila

struct Node
{
    int iData;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

struct Queue* newQueue()
{
    struct Queue* temp = (struct Queue*) malloc(sizeof(struct Queue));
    temp->front = nullptr;
    temp->rear = nullptr;

    return temp;
}

struct Node* newNode(int iVal)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->iData = iVal;
    temp->next = nullptr;

    return temp;
}

void firstElement(struct Queue* queue)
{
    cout << "Primeiro da Fila: " << ((queue -> front != nullptr) ? (queue -> front) -> iData : -1) << endl;
}

void lastElement(struct Queue* queue)
{
    cout << "Ultimo da Fila: " << ((queue -> rear != nullptr) ? (queue -> rear) -> iData : -1) << endl;
}

void enQueue(struct Queue* queue, int iVal)
{
    struct Node* temp = newNode(iVal);
    if (queue -> rear == nullptr)
    {
        queue -> front = temp;
        queue -> rear = temp;
        return;
    }
    else
    {
        queue -> rear -> next = temp;
        queue -> rear = temp;
    }

}

void deQueue(struct Queue* queue)
{
    if (queue -> front == nullptr)
    {
        cout << "Fila Vazia" << endl;
        return;
    }

    struct Node* temp = queue -> front;

    queue -> front = queue -> front -> next;
    if (queue -> front == nullptr) queue->rear = nullptr;

    cout << "deQueue: " << temp->iData<<endl;
    free(temp);
    return;
    //Dever 1: arrumar rear em casa de fila vazia
}

//Dever 2: funcao printQueue
int main()
{
    struct Queue* queue = newQueue();

    firstElement(queue);
    lastElement(queue);
    cout << "==========================" << endl;

    enQueue(queue, 3);

    firstElement(queue);
    lastElement(queue);
    cout << "==========================" << endl;

    enQueue(queue, 7);
    enQueue(queue, 10);
    enQueue(queue, 42);
    enQueue(queue, 666);

    firstElement(queue);
    lastElement(queue);
    cout << "==========================" << endl;

    deQueue(queue);

    firstElement(queue);
    lastElement(queue);
    cout << "==========================" << endl;

    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);

    firstElement(queue);
    lastElement(queue);
    cout << "==========================" << endl;

    return 0;
}
