/*
Author: Austin Stephens

Date: 07/16/2022

FileName: AStephens_M02LA_07162022

Purpous: 

    Write a C++ program to simulate a service desk. This service desk should be able to service customers that can have one of three different priorities (high, medium, and low). The duration for any customer is a random number (between 5 minutes and 8 minutes).

Input: 
    N/A

Exceptions:

Generate random 100 service requests.

Each service request can be either high, medium, or low priority. (Your program should randomly allocate this priority to each service.)

Each service request may need any time to be serviced between 5 and 8 minutes. (Your program should randomly allocate this time to each service.)

Your program should simulate the case when you have one service station for all customers.
Your program should simulate the case when you have two service stations for these 100 customers.

For each case, output the following statistics:
The number of requests for each priority along with the service time for each request
The waiting time for each service request
The average waiting time for service requests within each priority

*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <bits/stdc++.h>
#include <ctime>
#include <stack>
using namespace std;

void GenServiceReq(int pass, int L, int M, int H);
void GenService(int pass, int L, int M, int H);
void ServiceFeed(string PrioFeed, int Prio, int ServTime, int pass, int L, int M, int H);






void GenServiceReq(int pass, int L, int M, int H)
    {
        GenService(pass, L, M, H);
    }


    void GenService(int pass, int L, int M, int H)
    {
        string PrioFeed;
        int Prio;
        int ServTime = 0;
        Prio = (rand() % 3) + 1;
        // 1 - low, 2 - med, 3 - high
        
        while (ServTime != 5 && ServTime != 6 && ServTime != 7 && ServTime != 8)
        {
            ServTime = (rand() % 8) + 1;
        }

        switch (Prio)
        {
        case 1:
            PrioFeed = "Low";
           
            break;
        case 2:
            PrioFeed = "Medium";
           
            break;
        case 3:
            PrioFeed = "High";
           
            break;
        default:
        cout << "BrokeHERE\n\n";
            break;
        }
        
        
        ServiceFeed(PrioFeed, Prio, ServTime, pass, L, M, H);
    }
      
    void ServiceFeed(string PrioFeed, int Prio, int ServTime, int pass, int L, int M, int H)
      {
            int Cus = pass;
            cout << "Customer " << Cus << " || Has a priority of " << PrioFeed << " || And a Service Time Of: " << ServTime << " Minutes.\n"; 
            
            switch (Prio)
            {
            case 1:
                
                cout << PrioFeed << " Priority Has " << L << " Number of people waiting in line\n\n";
                break;

            case 2:
                cout << PrioFeed << " Priority Has " << M << " Number of people waiting in line\n\n";
                break;

            case 3:
                cout << PrioFeed << " Priority Has " << H << " Number of people waiting in line\n\n";
                break;
            
            default:
                break;
            }
            
            
            
            Cus++;
      }



int main()
{
    int pass = 0;
    int L = 0;
    int M = 0;
    int H = 0;
    srand (time(NULL)); // NTS: include in main, dont call each time
 

    for (int i = 0; i < 100; i++)
    {
        pass++;
        GenServiceReq(pass, L, M, H);

    }
    




    return 0;
}



