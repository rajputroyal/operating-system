#include<bits/stdc++.h>
#define max 10
using namespace std;

int s=1,e=10,f=0,a[max];
int wait(int s)
{   
	int c=s;
	return(--c);
}
int signal(int s)
{   
	int v=s;
	return(++v);
}

void produce()
{
	cout<<"F is "<<f<<"\n"<<"E is "<<e<<"\n";
	cout<<"\nEnter an element : ";
	cin>>a[f];
	cout<<"Elements present are :\n";
	for(int i=0;i<=f;i++)
	cout<<a[i]<<"  ";
	cout<<endl;
}

void consume()
{   
	a[f]=0;
	cout<<"f is "<<f<<"\n"<<"E is "<<e<<"\n";
	cout<<"Remaining elements are\n";
	for(int i=0;i<f;i++) cout<<a[i]<<"  ";
	cout<<endl;
}

void producer()
{
	cout<<"After producing \n";
    e=	wait(e);
	s=wait(s);
	produce();
	s=signal(s);
    f=signal(f);
}
void consumer()
{	
	cout<<"After consuming \n";
	f=wait(f);
	s=wait(s);
	consume();
	s=signal(s);
	e=signal(e);	
}

main()
{   
 	int cho;
	while(1)
	{
		cout<<"Enter 1 to Produce \n";
		cout<<"Enter 2 to Consume \n";
		cout<<"Enter 3 to Exit \n";
		cout<<"Enter Your Choice = ";
		cin>>cho;
		cout<<endl;
		switch(cho)
		{
		case 1: if(s==1 && e!=0)
		producer();
		else cout<<"Buffer is full....\n";
		cout<<"------------------------------\n";
		break;
		
		case 2: if(s==1&& f!=0)
		consumer();
		
		else cout<<"Buffer is empty....\n";
		cout<<"------------------------------\n";
		break;
		
		case 3: exit(0);
		break;
		
		default:
			cout<<"Invalid Input...\n";
			cout<<"------------------------------\n";
		}
	}	
}
