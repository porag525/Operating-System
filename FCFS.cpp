#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=3;
    cout<<"Enter Number of Process : ";
    cin>>n;
    vector<int>process(n);
    // If arrival time is not given by default arrival time is 0 for all
    vector<int>arrivalTime={0,10,15};
    vector<int>brustTime={10,5,8};
    // Enter the process numbers:
    cout<<"Enter the process number : "<<endl;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }
    // Enter the Brust Time:
    cout<<"Enter the Brust Time : "<<endl;
    for(int i=0;i<n;i++){
        cin>>brustTime[i];
    }
    
    // Calculate Completion Time (CT):
    vector<int>completionTime(n);
    completionTime[0]=brustTime[0];
    for(int i=1;i<n;i++){
       completionTime[i]=completionTime[i-1]+brustTime[i];
    }
    //Calculate Turnaround Time (CT-AT)
    vector<int>turnAroundTime(n);
    for(int i=0;i<n;i++){
        turnAroundTime[i]=completionTime[i]-arrivalTime[i];
    }
    
    //Calculate Waiting time (TAT - BT)
    vector<int>waitingTime(n);
    for(int i=0;i<n;i++){
        waitingTime[i]=turnAroundTime[i]-brustTime[i];
    }
    double averageAT=0;
    double averageTAT=0;
    cout<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
    for(int i=0;i<n;i++){
        cout<<arrivalTime[i]<<"\t";
        cout<<brustTime[i]<<"\t";
        cout<<completionTime[i]<<"\t";
        cout<<turnAroundTime[i]<<"\t";
        cout<<waitingTime[i]<<"\t";
        averageAT+=waitingTime[i];
        averageTAT+=turnAroundTime[i];
        cout<<endl;
    }
    cout<<"Average Waiting Time = "<<averageAT/n<<endl;
    cout<<"Average Turn Around Time = "<<averageTAT/n<<endl;


}
