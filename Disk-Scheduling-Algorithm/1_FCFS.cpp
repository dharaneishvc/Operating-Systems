
#include <bits/stdc++.h>
using namespace std;

void FCFS(int arr[], int size, int head)
{
	int seek_count = 0;

	for (int i = 0; i < size; i++)
	{
		seek_count += abs(arr[i] - head);
		head = arr[i];
	}

	cout << "Total number of seek operations = "<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
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

	FCFS(tracks, size, head);
	return 0;
}
