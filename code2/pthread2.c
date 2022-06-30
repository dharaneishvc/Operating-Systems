#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter=0;
int x=0,k;
void* trythis(void* arg)
{
while(1){
   
    if(counter==1){
        printf("Started Executing sleep");
        sleep(2);
        printf("Finished Executing sleep");
    }else{
        break;
    }
}
counter=1;
x++;
printf("\nProcess %d has finished it's execution",x);
counter=0;

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	while (i < 2) {
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if (error != 0)
			printf("\nThread can't be created : [%s]", strerror(error));
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
