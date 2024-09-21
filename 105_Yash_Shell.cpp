#include <iostream>
#include <string>
using namespace std;

class Student {

public:
    int Roll_No;
    float CGPA;
    string Name;

    void get_data() {
	    cin>>Roll_No>>Name>>CGPA;
    }

    void display_data()  {
		cout<<"Roll : "<<Roll_No<<endl;
		cout<<"Name : "<<Name<<endl;
		cout<<"CGPA : "<<CGPA<<endl;
                cout<<endl;
    }

    friend void shellSort(Student S[], int n);
};

void shellSort(Student S[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = S[i];
            int j;
            for (j = i; j >= gap && S[j - gap].Name  >  temp.Name; j -= gap) {
                S[j] = S[j - gap];
            }
            S[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students  : ";
    cin >> n;
    Student S[n];
    cout<<"Enter data in format ---> Rollno | Name | CGPA   "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter details of Student " << i + 1 <<"  : ";
        S[i].get_data();
    }

    shellSort(S, n);
    cout << endl << "\nSorted student data : \n" << endl;
    for (int i = 0; i < n; i++) {
        S[i].display_data();
    }

    return 0;
}

