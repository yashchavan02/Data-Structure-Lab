#include<iostream>
using namespace std;

class Student {
	int Roll_No;
	float CGPA;
	string Name;

	public:
	Student(){
            Roll_No = 0;
           CGPA = 0.0;
           Name = " ";
        }
	void get_data(){
		cin>>Roll_No>>Name>>CGPA;
	}
	void display_data(){
		cout<<"Roll : "<<Roll_No<<endl;
		cout<<"Name : "<<Name<<endl;
		cout<<"CGPA : "<<CGPA<<endl;
                cout<<endl;
	}

	friend void insertionSort(Student S[], int n);
} ;

	void insertionSort(Student S[] , int n){
		for(int i=0;i<n;i++){
		Student curr = S[i];
		int j = i-1;
			while(j >= 0 && S[j].Roll_No > curr.Roll_No ){
			S[j+1] = S[j];
			j--;

			}
			S[j+1] = curr;
		}	

}
int main(){
	int n;
	cout<<"Enter number of student data  : ";
	cin>>n;
	Student S[n];
	cout<<"Enter data in format ---> Rollno | Name | CGPA   "<<endl;
	for(int i=0;i<n;i++){
	cout<<"Enter data of student "<<i+1<<" : ";
	S[i].get_data();
	}
	insertionSort(S , n);
	cout<<"\nStudent Data : "<<endl;
	for(int i=0;i<n;i++){
	S[i].display_data();
	}
return 0;
}
