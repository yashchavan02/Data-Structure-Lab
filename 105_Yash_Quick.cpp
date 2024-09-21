#include<iostream>
using namespace std;
class Employee {

	int EmpID;
	string Name;
	int Salary;
	
	public:
        Employee(){
	   EmpID = 0;
	   Name =" ";
	   Salary = 0;
        }
	void getdata() {
	  cin>>EmpID>>Name>>Salary;
	}

	void display() {
		cout<<"EmpID : "<<EmpID<<endl;
		cout<<"Name : "<<Name<<endl;
		cout<<"Salary : "<<Salary<<endl;
                cout<<endl;
	}
		
	friend void quicksort(Employee E[],int n);
	friend int partition(Employee E[],int low, int high);
};
int partition(Employee E[],int low ,int high) {

	int pivot=E[low].EmpID;
	int i=low+1;
	int j=high;
	Employee temp;
	do{
	    while(pivot >= E[i].EmpID) {
		  i++;
	    }
	    while(pivot < E[j].EmpID) {
		 j--;
	    }
	    if(i<j) {
	      temp=E[i];
	      E[i]=E[j];
              E[j]=temp;
	   }
	}
	while(i<j);
	temp=E[low];
	E[low]=E[j];
	E[j]=temp;
return j;
}
void quicksort(Employee E[],int low ,int high) {

	int partindex;
	if (low<high) {
	  partindex=partition(E,low,high);
	  quicksort(E,low,partindex-1);
	  quicksort(E,partindex+1,high);
	}
}

int main(){
	int n;
	cout<<"Enter the number of employee : ";
	cin>>n;
	Employee  E[n];
	cout<<"Enter data in format ---> Empid | Name | Salary  "<<endl;
	for (int i=0; i<n; i++) {
	    cout<<"Enter detail of  "<<i+1<<" : ";
	    E[i].getdata();
	}
	
	cout<<"\nSorting using EMPID : "<<endl;
	quicksort(E,0,n-1);
	for (int i=0; i<n; i++) {
	    E[i].display();
	    cout<<endl;
	}
return 0;
}
