#include<stdio.h>

int empty,x,mutex=1,full=0;

int wait(int s)

{

return --s;

}

int signal(int s)

{

return ++s;

}

void producer()

{

mutex=signal(mutex);

x++;

printf("producer has produced item %d \n",x);

full=signal(full);

empty=wait(empty);

mutex=wait(mutex);

}

void consumer()

{

mutex=signal(mutex);

printf("consumer has consumed item %d \n",x);

x--;

full=wait(full);

empty=signal(empty);

mutex=wait(mutex); 

}

void main() {

int n,ch;

printf("enter the size of buffer : ");

scanf("%d", &n);

empty=n;

printf("1- producer\n");

printf("2- consumer\n");

printf("3- exit\n");

do{

printf("enter your choice : ");

scanf("%d",&ch);

switch(ch) {

case 1:

if((mutex==1) && (empty!=0)) {

producer();

break; 

}

else {

printf("buffer is full\n");

break; 

}

case 2: 

if((mutex==1) && (full!=0))

{

consumer();

break;

}

else

{

printf("buffer is empty\n");

break;

}

case 3:

break;

default:

printf("enter correct choice.....!!!!\n");

}

}while(ch!=3);

}

 

