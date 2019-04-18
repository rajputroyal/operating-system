#include<iostream>
using namespace std;
main()
{
	int P,R,C=0;
	cout<<"Processes : ";
	cin>>P;
	cout<<"Resourcess : "; 
	cin>>R;
	
	int CA[P][R],MA[P][R],AV[R],N[P][R],flag[P],ans=0;
	C=P;
	cout<<endl;
	for(int i=0;i<P;i++)
	{
		cout<<"Enter Current-Allocation Resources to Process "<<i+1<<" : ";
		for(int j=0;j<R;j++)
		cin>>CA[i][j];
	}
	cout<<endl;
	for(int i=0;i<P;i++)
	{ 
	  	flag[i]=0;
		cout<<"Enter Maximum Allocation Resources to Process "<<i+1<<" : ";
		for(int j=0;j<R;j++)
		{
			cin>>MA[i][j];
		}
	}
	
	cout<<"\nEnter Initially Available Resources : \n";
	for(int j=0;j<R;j++)
	cin>>AV[j];
	
	cout<<endl;	
	for(int i=0;i<P;i++)
	{
		cout<<"Resources for Process "<<i+1<<" : ";
		for(int j=0;j<R;j++)
		{
			N[i][j]=MA[i][j]-CA[i][j];
			cout<<N[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	while(C!=0)
	{
		for(int i=0;i<P;i++)
		{   
 			int flag1=0;
			for(int j=0;j<R;j++)
			{
				if(AV[j]>=N[i][j]&&flag[i]!=1)
				flag1++;
			}
			if(flag1==R)
			{
				for(int j=0;j<R;j++)
				AV[j]+=MA[i][j];
								
				flag[i]=1;
				ans++;
			}
			if(flag1==R) break;
		}
		C--;
	}
	cout<<"\nOUTPUT\n";	
	if(ans==P)
	cout<<"\nSystem is in Safe State\n";
		
	cout<<"\nFree Resources at last\n";
	for(int i=0;i<R;i++)
	cout<<AV[i]<<" ";
	cout<<endl;
}
