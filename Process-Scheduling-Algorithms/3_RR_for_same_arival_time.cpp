#include<iostream>
using namespace std;

void RR(int NOP, int quant, int at[], int bt[])
{
    int y = NOP;  
    int tat[NOP], wt[NOP], ct[NOP], temp[NOP]; 
    for(int i=0; i<NOP; i++)    
    temp[i] = bt[i];
    
for(int sum=0, i = 0; y!=0; )  
{  
    if(temp[i] <= quant && temp[i] > 0) // define the conditions   
    {  
        sum = sum + temp[i];  
        temp[i] = 0;  
        y--; //decrement the process no.
        ct[i] = sum;
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }
 
    if(i==NOP-1) // full cycle of all process completed. starting from first
    {  
        i=0;
    }
    else if(at[i+1]<=sum)  // next process has arrived
    {  
        i++;  
    }  
    else  // next process hasn't arrived
    {  
        i=0;  
    }  
}

float avg_wt = 0, avg_tat = 0;
cout<<"P ID \t Ar T \tBr T \t Cm T\tTA T\t Wt T\n";
for(int k=0; k<NOP; k++)
{
    cout<<(k+1)<<'\t'<<at[k]<<'\t'<<bt[k]<<'\t'<<ct[k]<<'\t'<<tat[k]<<'\t'<<wt[k]<<'\n';
    avg_wt += wt[k];
    avg_tat += tat[k];
}
  
avg_wt /= NOP;  
avg_tat /= NOP;  
cout<<"\n Average Turn Around Time: "<<avg_wt;  
cout<<"\n Average Waiting Time: "<<avg_tat;  

}
int main()  
{
    int NOP, quant; 
//Input No of Process, Quantum 
    cin>>NOP;
    cin>>quant;
    int at[NOP], bt[NOP]; 
//Input Arrival, Burst Time
    for(int i=0; i<NOP; i++)  
    {  
    cin>>at[i]>>bt[i];
    }  
    RR(NOP, quant, at, bt);
return 0;  
}  