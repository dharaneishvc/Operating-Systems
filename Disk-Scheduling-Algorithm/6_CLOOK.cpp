#include <bits/stdc++.h>
using namespace std;

void CLOOK(int arr[], int head, string direction, int size )
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    for (int i = 0; i < right.size(); i++)
    {
        cur_track = right[i];
 
        seek_sequence.push_back(cur_track);
 
        distance = abs(cur_track - head);
 
        seek_count += distance;
 
        head = cur_track;
    }
 
    seek_count += abs(head - left[0]);
    head = left[0];
 
    for (int i = 0; i < left.size(); i++)
    {
        cur_track = left[i];
 
        seek_sequence.push_back(cur_track);
 
        distance = abs(cur_track - head);
 
        seek_count += distance;
 
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "<< seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++)
    {
        cout << seek_sequence[i] << endl;
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
    string direction;
    cin>>direction;
	CLOOK(tracks, head, direction, size);
	return 0;
}
