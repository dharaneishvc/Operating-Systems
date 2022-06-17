#include<iostream>
#include<queue>

using namespace std;
struct process
{
    int pid, at, bt, ct, tat, wt;
    int btr;
    bool iscom, isqu;
};


void bubblesort(process p[], int n)
{
    int i, j;
    struct process temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            } 
        }
    }
}


void checkForNewArrivals(struct process processes[], const int n, int currentTime, queue<int> &readyQueue)
{
	for (int i = 0; i < n; i++)
	{
		struct process p = processes[i];
		
		if (p.at <= currentTime && !p.isqu && !p.iscom)
		{
			processes[i].isqu = true;
			readyQueue.push(i);
		}
	}
}


void RR(struct process processes[], int n, int quantum)
{
	queue<int> readyQueue;
	readyQueue.push(0);
	processes[0].isqu = true;

	int currentTime = 0; 
	int programsExecuted = 0;
	cout<<"Gantt Chart \n [";
	while (programsExecuted != n)
	{
		if(readyQueue.empty())
	{
	    currentTime+=1;
	    if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
	}
	else
	{
	int i = readyQueue.front();
	readyQueue.pop();

	if (processes[i].btr <= quantum)
	{
		processes[i].iscom = true;
		currentTime += processes[i].btr;
		processes[i].ct = currentTime;
		processes[i].wt = processes[i].ct - processes[i].at - processes[i].bt;
		processes[i].tat = processes[i].wt + processes[i].bt;
        cout<<(processes[i].pid)<<", ";
        
		if (processes[i].wt < 0)
			processes[i].wt = 0;

		processes[i].btr = 0;
        programsExecuted += 1;
        
		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
	}
	else
	{
		processes[i].btr -= quantum;
		currentTime += quantum;
        cout<<(processes[i].pid)<<", ";
		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
		readyQueue.push(i);
		
	}
	}
	}
	cout<<"]";
}

int main()
{
    // Input No of process and arrival and Burst Time of each process
    int t,time_slice;
    cin>>t>>time_slice;
    struct process p[t];
    for(int i=0; i<t; i++)
    {
        p[i].pid = i+1;
        cin>>p[i].at>>p[i].bt;
		p[i].btr=p[i].bt;
    }
    bubblesort(p,t);
    RR(p, t, time_slice);
    float avg_wt = 0, avg_tat = 0;
    cout<<"\n ---- OUTPUT ---- \n";
    cout<<"P ID \t Ar T \tBr T \t Cm T\tTA T\t Wt T\n";
    for(int k=0; k<t; k++)
    {
        cout<<(p[k].pid)<<'\t'<<p[k].at<<'\t'<<p[k].bt<<'\t'<<p[k].ct<<'\t'<<p[k].tat<<'\t'<<p[k].wt<<'\n';
        avg_wt += p[k].wt;
        avg_tat += p[k].tat;
    }
    cout<<"Average Waiting Time: "<<avg_wt/t<<"\nAverage Turn around time: "<<avg_tat/t<<"\n";
    return 0;
}
