#include<iostream> 
using namespace std;
#define max 30 
class LRU
{
	public:
		void getdata()
		{
		    int RS,PF,S[max],C=0,Hit_C;
			cout<<"Number of Page Frames           : ";
		    cin>>PF;
		    cout<<"Number of Page Reference String : ";
		    cin>>RS;
			
			cout<<endl;
		    for(int i=0;i<RS;i++)
		    {
		    	cout<<"The Page Reference String "<<i+1<<" : ";
		    	cin>>S[i];
			}
		
		    int Frames[PF],Frames_C[PF];
		    for(int i=0;i<PF;i++)
		    {
		    	Frames[i]=-1;
		    	Frames_C[i]=0;
			}
			int i=0;
			while(i<RS)
			{
				int j=0,Flag=0;
                while(j<PF)
                {
					if(S[i]==Frames[j])
				   	{    
                    	Flag=1;
                      	Frames_C[j]=i+1;
			       	}
			        j++;
			    }
			    j=0;    
            	if(Flag==0)
            	{
             		int min=0,k=0;
              		while(k<PF-1)
                	{
                		if(Frames_C[min]>Frames_C[k+1]) 
                	    min=k+1;
                	  	k++;
                	}
               		Frames[min]=S[i]; 
               		Frames_C[min]=i+1;    
               		C++;           
           		}
           		i++; 
        	}
        	cout<<"\n";
         	cout<<"Total No.of Page Faults are : "<<C<<endl;
         	Hit_C=RS-C;
        	cout<<"Total No.of Page Hits are   : "<<Hit_C;
		}        
};
int main()
{
	LRU ob;
	ob.getdata();
} 
