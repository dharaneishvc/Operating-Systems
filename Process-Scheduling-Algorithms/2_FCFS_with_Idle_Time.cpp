#include<iostream>
using namespace std;
struct process
{
    int pid, at, bt, ct, tat, wt;
};

void fcfs(int N, process p[])
{
    for(int i=0; i <N; i++)
    {
        p[i].wt=0;
    }
    for(int i=0; i<N; i++)
    {
        p[i].wt=0;
         for(int j=0; j<i; j++)
         {
             p[i].wt += p[j].bt;
         }
         p[i].wt -= p[i].at;
         if(p[i].wt < 0)
         {
             p[i].ct += -(p[i].wt);
             for(int m=i+1; m<N; m++)
             {
                 p[m].wt += -(p[i].wt);
             }
             p[i].wt = 0;
         }
         p[i].tat = p[i].wt+p[i].bt;
         p[i].ct = p[i].tat + p[i].at;
    }

}
void insertionSort(process p[], int n)
{
    int i, j;
    struct process temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
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
int main()
{
    // Input No of process and arrival and Burst Time of each process
    int t;
    cin>>t;
    process p[t];
    for(int i=0; i<t; i++)
    {
        p[i].pid = i+1;
        cin>>p[i].at>>p[i].bt;
    }
    insertionSort(p,t);
    fcfs(t, p);
    float avg_wt = 0, avg_tat = 0;
    cout<<"\n ---- OUTPUT ---- \n";
    cout<<"P ID \t Ar T \tBr T \t Cm T\tTA T\t Wt T\n";
    for(int k=0; k<t; k++)
    {
        cout<<(k+1)<<'\t'<<p[k].at<<'\t'<<p[k].bt<<'\t'<<p[k].ct<<'\t'<<p[k].tat<<'\t'<<p[k].wt<<'\n';
        avg_wt += p[k].wt;
        avg_tat += p[k].tat;
    }
    cout<<"Average Waiting Time: "<<avg_wt/t<<"\nAverage Turn around time: "<<avg_tat/t<<"\n";
    return 0;
}
