#include<iostream>
using namespace std;

#define MAX 10

class Deque
{
	int arr[MAX];
	int front;
	int rear;
	int size;
public :
	Deque(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
		for(int k=0; k<10; k++)
		{
		    arr[k]=-1;
		}
	}

	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
	int find(int a);
	void erase(int index);
    void view();
};

bool Deque::isFull()
{
	if(rear>front)
	return ((rear - front + 1)==size);
	else
	return ((10-rear+front+1) == size);
}

bool Deque::isEmpty ()
{
	return (front == -1);
}

void Deque::insertfront(int key)
{
	if (isFull())
	{
		cout << "Overflow\n" << endl;
		return;
	}

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	else if (front == 0)
		front = MAX - 1 ;

	else
		front = front-1;

	arr[front] = key ;
}

void Deque ::insertrear(int key)
{
	if (isFull())
	{
		cout << " Overflow\n " << endl;
		return;
	}

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	else if (rear == MAX-1)
		rear = 0;

	else
		rear = rear+1;

	arr[rear] = key ;
}

void Deque ::deletefront()
{
	if (isEmpty())
	{
		cout << "Queue Underflow\n" << endl;
		return ;
	}

	if (front == rear)
	{
		front = -1;
		rear = 0;
	}
	else if (front == MAX -1)
    {
    	front = 0;  
    }
	else
    {
    	front = front+1;   
    }
		
}

void Deque::deleterear()
{
	if (isEmpty())
	{
		cout << " Underflow\n" << endl ;
		return ;
	}

	if (front == rear)
	{
		front = -1;
		rear = 0;
	}
	else if (rear == 0)
		rear = MAX-1;
	else
		rear = rear-1;
}

int Deque::getFront()
{
	if (isEmpty())
	{
		cout << " Underflow\n" << endl;
		return -1 ;
	}
	return arr[front];
}

int Deque::getRear()
{
	if(isEmpty() || rear < 0)
	{
		cout << " Underflow\n" << endl;
		return -1 ;
	}
	return arr[rear];
}
int Deque::find(int a)
{
    if(isEmpty())
    {
        return -1;
    }
    for (int i = front ; i != rear+1; i = (i+1)%10)
    {
        if (a == arr[i])
        return i;
    }
    return -1;
}

void Deque::erase(int index)
{
    if(isEmpty())
    {
        cout<<"Queue Underflow\n";
        return;
    }
    else if (arr[index]==-1)
    {
        cout<<"Element at index doesn't exist\n";
        return;
    }
    
    for(int j=index; j != rear; j=(j+1)%10)
    {
        arr[j] = arr[j+1];
    }
    arr[rear]=-1;
    if (front == rear)
	{
		front = -1;
		rear = 0;
	}
	else if (rear == 0)
		rear = MAX-1;
	else
		rear = rear-1;

}
void Deque::view()
{
    if(isEmpty())
    {
        cout<<"Empty Queue\n";
    }
    else
    {

        cout<<"[";
        
        for(int j=front; j != rear+1; j=(j+1)%10)
        {
            cout<<arr[j]<<",";
        }
        /*
        for(int j=0; j < 10 ; j++)
        {
            cout<<arr[j]<<",";
        }
        */
        cout<<"\b]\n";
        
    }
    
}
int main()
{
int capacity = 4;
int page_count=0;
//int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

cout<<"Enter Capacity of Page slots(frames): ";
cin>>capacity;
cout<<"Enter Total NO of Pages in reference string: ";
cin>>page_count;
int arr[page_count];
cout<<"Enter Values one by one(space-sepaarted): ";
for(int m=0; m<page_count; m++)
cin>>arr[m];

Deque q(capacity);
int page_faults=0, page_hits=0;

for(int i:arr)
{
  q.view();
  int f;
  f = q.find(i);
  if(f == -1)
  {
    cout<<i<<" not found"<<'\n';
    
    ++page_faults;
    
    if(q.isFull())
    {
    q.deletefront();
    q.insertrear(i);
    }
    else
    {
    q.insertrear(i);
    }
  }
  else
  {
	++page_hits;
    cout<<i<<" found"<<'\n';
    q.erase(f);
    q.insertrear(i);    
  }

}q.view();
cout<<"\nTotal Page Faults: "<<page_faults;
cout<<"\nTotal Page Hits: "<<page_hits;
}