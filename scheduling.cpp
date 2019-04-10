#include<iostream>
#include<algorithm>
using namespace std;

void priority()
{
	int n;
	
	cout<<"Assuming arrival time is alwaya 0\n\n\n";
	cout<<" number of processes"<<endl;
	cin>>n;
	
	float prior[n],bT[n],cT[n],wT[n],sumCT=0,sumWT=0;
	
	cout<<"Enter the priority of processes"<<"\n"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>prior[i];
	}
	sort(prior,prior+n);
	
	cout<<" burst time now"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the burst time of process with priority "<<prior[i]<<"=\t";
		cin>>bT[i];
	}
	cT[0]=bT[0];
	wT[0]=0;
	for(int i=1;i<n;i++)
	{
		cT[i]=bT[i-1]+bT[i];
		wT[i]=cT[i]-bT[i];
	}
	for(int i=0;i<n;i++)
	{
		sumCT=sumCT+cT[i];
		sumWT=sumWT+wT[i];
	}
	cout<<"The average completion time of processes is "<<sumCT/2<<endl;
	cout<<"The average completion time of processes is "<<sumWT/2<<endl;
}

main()
{	
	int cont;	
	do{
	cont=0;
	priority();
	cout<<"Enter 1 to continue ";
	cin>>cont;
	}while(cont==1);
}
	
	
	
	
 	
	
	
	
	
	

