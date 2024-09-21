#include<iostream>
#include<limits.h>

using namespace std;

class Student {
    public:
	int roll_no;
	string name;
	float cgpa;

	Student(){
            roll_no = 0;
           cgpa = 0.0;
           name = " ";
        }
	void getdata(){
	    cin>>roll_no>>name>>cgpa;
	}	
	void display(){
		cout<<"Roll : "<<roll_no<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"CGPA : "<<cgpa<<endl;
                cout<<endl;
	}

	friend void radixsort(Student S[] ,int n);
};

int maximum(Student S[],int n){

	int max=INT_MIN;
	for (int i=0; i<n; i++){
	    if(S[i].roll_no>max){
		max=S[i].roll_no;
	    }
	}
   return max;
}
void countsort(Student S[],int n,int exp){
	int i;
	int count[10]={0};
	Student b[n];
	for (int i=0; i<n; i++) {
	    count[(S[i].roll_no/exp)%10]++;
	}

	for (int i=1 ;i<10; i++) {
	    count[i]=count[i]+count[i-1];
	}

	for (int i=n-1; i>=0; i--){
	    b[count[(S[i].roll_no/exp)%10]-1]=S[i];
	    count[(S[i].roll_no/exp)%10]--;
	}

	for (int i=0; i<n; i++) {
	    S[i]=b[i];
 	}

}
void radixsort(Student S[],int n){
	int max=maximum(S,n);
	for (int exp=1; max/exp>0; exp*=10){
	    countsort(S,n,exp);
	}
}

int main(){
	int n;
	cout<<"Enter the number of students : ";
	cin>>n;
	Student S[n];
        cout<<"Enter data in format ---> Rollno | Name | CGPA   "<<endl;
	for (int i=0; i<n; i++){
	   cout<<"Enter data for Student "<<i+1<<" : ";
	   S[i].getdata();
	}

	radixsort(S,n);
	cout<<endl;
	cout<<"\nAfter sorting with Roll No :  "<<endl;

	for (int i=0; i<n; i++){
	    cout<<endl;
	    S[i].display();
	}
return 0;
}
