#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<numeric>
using namespace std;
int main()
{
cout<<"Enter Number of process"<<endl;
vector<pair<double,double>> v;
int no_p ; cin>>no_p;
double input1,input2;
cout<<"Enter Arrival Time and Brust Time for each process"<<endl;
for(int i = 0;i<no_p;i++){
    cin>>input1>>input2;
    v.push_back(make_pair(input1,input2));}
    sort(v.begin(),v.end());
    double wt [no_p+1];
    wt[0]={0};
    double sum =0;
    for(int i=1;i<no_p;i++){
    for (int j=i ; j>0;j--){
        sum+=v[(j-1)].second;
    }
         wt[i]=sum-v[i].first;
         sum=0;
    }
    double total =0;
    for(int i =0;i<no_p;i++){
        total+=wt[i];

    }
cout << "Processes "<<"Arrival Time"<< " Burst time "
		<< " Waiting time \n";


	for (int i=0; i<no_p; i++)
	{
		cout << " " << i+1 << "\t\t" << v[i].first<<"\t "<<v[i].second<<"\t \t "
			<< wt[i] <<"\t\t "<<endl;
	}

    double avg_wt = total/no_p;
    cout<<"Average Waiting Time  "<<avg_wt;

    return 0;}
