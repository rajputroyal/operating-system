#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cout<<"Enter the Number of Processes : ";
	cin>>N;
	int BT1[N],BT[N],TAT[N],WT[N];
	
	for(int i=0;i<N;i++)
	{
		cout<<"\nEnter the BURST TIME  "<<i+1<<" : ";
		cin>>BT[i];
		BT1[i]=BT[i];
		WT[i]=0;
	}
	sort(BT,BT+N);
	WT[0]=0;
	for(int i=1;i<N;i++)
	{
		WT[i]=WT[i-1]+BT[i-1];
	}
	int pos;
	float AVG_TAT=0,AVG_WT=0,AVG_CT=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;i<N;j++)
	{
		if (BT1[j]==BT[i]){ pos=j+1; break;}
	}
		TAT[i]=BT[i]+WT[i];
		AVG_TAT+=TAT[i];
		AVG_WT+=WT[i];
		cout<<"\n---------------------------------------------";
		cout<<"\nWAITING TIME      "<<pos<<" : "<<WT[i];
		cout<<"\nTURN AROUND TIME "<<pos<<" : "<<TAT[i];
			
	}
	cout<<"\n---------------------------------------------";
	cout<<"\nAverage TURN AROUND TIME "<<AVG_TAT/N;
	cout<<"\nAverage WAITING TIME  "<<AVG_WT/N;
}
