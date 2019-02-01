#include<iostream>
using namespace std;
int main()
{
	int n,Q,count=0;
	cout<<"Enter the No.of Process : ";
	cin>>n;
	cout<<"Enter the Quantum  : ";
	cin>>Q;
	float BT[n],WT[n],TAT[n],RBT[n],t;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter BURST TIME  "<<i+1<<" : ";
		cin>>BT[i];
		RBT[i]=BT[i];
	}
	while(count<n)
	{
		for(int i=0;i<n;i++)
		{
			if(RBT[i]>Q)
			{
				t=t+Q;
				RBT[i]=RBT[i]-Q;
			}
		
			else if(RBT[i]>0)
			{
				t=t+RBT[i];	
				RBT[i]=0;		
				WT[i]=t-BT[i];
				TAT[i]=t;
				count++;
				if(count==n)
				break;
			}
		}
	}
	float avg_WT=0,avg_TAT=0;
	for(int i=0;i<n;i++)
	{
		avg_WT+=WT[i];
		avg_TAT+=TAT[i];
		cout<<"---------------------------------------------\n";
		cout<<"The WAITING TIME  "<<i+1<<"     : ";
		cout<<WT[i]<<endl;
		cout<<"The TURN AROUND TIME  "<<i+1<<" : ";
		cout<<TAT[i]<<endl;
	}
	cout<<"---------------------------------------------\n";
	cout<<"Average WAITING TIME  : "<<avg_WT/n;
	cout<<"\nAverage TURN AROUND TIME  : "<<avg_TAT/n;
}
