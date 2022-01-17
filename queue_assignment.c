# include<stdio.h>
# define MAXIMUM 5

int cqueue[MAXIMUM];
int front=-1;
int rear=-1;

void insert(int item)
{
    if((front==0 && rear==MAXIMUM-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==MAXIMUM-1)
            rear=0;
        else
            rear=rear+1;
    }
    cqueue[rear]=item ;
}

void delete()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is- %d\n",cqueue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==MAXIMUM-1)
            front=0;
        else
            front=front+1;
    }
}

void display() {
  int front_pos = front, rear_pos = rear;

  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements-\n");

  if (front_pos <= rear_pos)
    while (front_pos <= rear_pos) {
      printf("%d ", cqueue[front_pos]);
      front_pos++;
    }
  else {
    
    while (front_pos <= MAXIMUM - 1) {
      printf("%d ", cqueue[front_pos]);
      front_pos++;
    }
    front_pos = 0;

    while (front_pos <= rear_pos) {
      printf("%d ", cqueue[front_pos]);
      front_pos++;
    }
  }
  printf("\n");
}

int main() {
  int choice, item;
  do {
    printf("1.Insert an element-\n");
    printf("2.Delete an element-\n");
    printf("3.Display the Queue-\n");
    printf("4.Exit\n");
    printf("Enter your choice-\n");
    scanf("%d", & choice);
    switch (choice) {
    case 1: {
      printf("Enter an Element-\n");
      scanf("%d", & item);
      insert(item);
      break;
    }
    case 2: {
      delete();
      break;
    }
    case 3: {
      display();
      break;
    }
    case 4: {
      break;
    }
    default: {
      printf("Wrong Input!\n");
    }
    }
  }
  while (choice != 4);
  return 0;
}