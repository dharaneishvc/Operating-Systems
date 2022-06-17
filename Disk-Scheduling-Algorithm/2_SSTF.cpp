
#include <bits/stdc++.h>
using namespace std;


int findMIN(int diff[][2], int n)
{
	int index = -1;
	int minimum = 1e9;

	for(int i = 0; i < n; i++)
	{
		if (!diff[i][1] && minimum > diff[i][0])
		{
			minimum = diff[i][0];
			index = i;
		}
	}
	return index;
}

void SSTF(int request[], int head, int n)
{
	if (n == 0)
	{
		return;
	}
	
	int diff[n][2] = { { 0, 0 } };
	
	int seekcount = 0;
	
	int seeksequence[n + 1] = {0};
	
	for(int i = 0; i < n; i++)
	{
		seeksequence[i] = head;
		for(int j = 0; j < n; j++)
    	{
    		diff[j][0] = abs(head - request[j]);
    	}
		int index = findMIN(diff, n);
		diff[index][1] = 1;
		
		seekcount += diff[index][0];
		head = request[index];
	}
	seeksequence[n] = head;
	
	cout << "Total number of seek operations = "<< seekcount << endl;
	cout << "Seek sequence is : " << "\n";
	
	for(int i = 0; i <= n; i++)
	{
		cout << seeksequence[i] << "\n";
	}
}

int main()
{
    int size, head;
    cin>>size>>head;
    int tracks[size];
    for(int i=0; i<size; i++)
    {
        cin>>tracks[i];
    }

	SSTF(tracks, head, size);
	return 0;
}
