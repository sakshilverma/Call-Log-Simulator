//  Call Log Simulator
//  Created by Sakshil Verma

#include<iostream>
#include<ctime>
using namespace std;

struct node{
    long tel;
int day,month,year,hour,min,sec;
    string name;
  struct node *next;
};
int t_calls=0;

//for printing the call logs
void print(node *start){
    node *p=start;
    if(p!=NULL){
    while(p->next!=NULL){
        cout<<endl<<p->name<<" "<<p->tel<<" "<<p->day<<"/"<<p->month<<"/"<<p->year<<" "<<p->hour<<":"<<p->min<<":"<<p->sec<<endl<<endl;
        p=p->next;
    }
    cout<<endl<<p->name<<" "<<p->tel<<" "<<p->day<<"/"<<p->month<<"/"<<p->year<<" "<<p->hour<<":"<<p->min<<":"<<p->sec<<endl<<endl;
    }
    else cout<<endl<<"No Call Logs Available"<<endl<<endl;
}

//for deleting the least recent call log
node *del_call(node *start){
    t_calls--;
    node *p=start;
    while(p->next->next!=NULL){
        p=p->next;
    }
    node *q=p->next;
    p->next=NULL;
    free(q);
    return start;
}

//for inserting the call data to the call logs
node *insert_begin(node *start){
struct node *newnode =(struct node*) malloc(sizeof(struct node));
    cout<<"Enter Name : ";
    cin>>newnode->name;
    cout<<"Enter 10 Digit Telephone Number : ";
    cin>>newnode->tel;
    
    time_t now=time(0);
    tm *curr=localtime(&now);
    newnode->day=curr->tm_mday;
    newnode->month=curr->tm_mon+1;
    newnode->year=curr->tm_year+1900;
    newnode->hour=curr->tm_hour;
    newnode->min=curr->tm_min;
    newnode->sec=curr->tm_sec;
    
  if(start==NULL){
  newnode->next=NULL;
    start=newnode;
  }
  else{
  newnode->next=start;
    start=newnode;
  }
  return start;
}
    
int main() {
    cout<<"Hello and Welcome!!"<<endl<<"In this project we can Simulate the call logs in the mobile by making calls and displaying the call logs -"<<endl;
    node *start=NULL;
    int i;
    do{
        cout<<"To make a call enter 1 and press enter"<<endl<<"Or to print the call logs enter 2 and press enter"<<endl<<"Or to End the program enter 0 and press enter : ";
        cin>>i;
        //if user wants to end the program
        if(i==0){
            break;
        }
        //if user wants to make a call
        else if(i==1){
            if(t_calls<10){
                t_calls++;
            }
            else {
                start=del_call(start);
                t_calls++;
            }
        start=insert_begin(start);
            cout<<"Call Successfully Made"<<endl<<endl;
        }
        //if user wants to print the call logs
        else if(i==2){
            print(start);
        }
        //if user enters invalid input
        else{
            cout<<"Wrong Input"<<endl;
        }
    }while(i!=0);
    
    cout<<endl<<"Thankyou!!"<<endl;
    
        return 0;
}


