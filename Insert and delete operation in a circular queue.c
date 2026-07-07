#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

// Insert Operation
void enqueue(int value)
{
if ((rear + 1) % MAX == front)
{
printf("Queue Overflow\n");
}
else
{
if (front == -1)
{
front = rear = 0;
}
else
{
rear = (rear + 1) % MAX;
}
cqueue[rear] = value;
printf("%d inserted into queue\n", value);
}
}

// Delete Operation
void dequeue()
{
if (front == -1)
{
printf("Queue Underflow\n");
}
else
{
printf("%d deleted from queue\n", cqueue[front]);
if (front == rear)
{
front = rear = -1;
}
else
{
front = (front + 1) % MAX;
}
}
}

// Display Queue
void display()
{
int i;
if (front == -1)
{
printf("Queue is Empty\n");
}
else
{
printf("Circular Queue elements are: ");
i = front;
while (i != rear)
{
printf("%d ", cqueue[i]);
i = (i + 1) % MAX;
}
printf("%d\n", cqueue[rear]);
}
}

// Main Function
int main()
{
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
display();
dequeue();
dequeue();
display();
enqueue(50);
enqueue(60);
display();
return 0;
}
