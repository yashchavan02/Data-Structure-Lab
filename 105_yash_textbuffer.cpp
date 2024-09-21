#include<iostream>
using namespace std;

struct word {
   string t;
   word *next , *prev;
};

typedef class textBuffer {
   word *head , *tail;
   int size;
   public : 
   textBuffer(){
    size = 0;
    head = nullptr;
    tail = nullptr;
   }
   void appendText(); 
   void prependText();
   void showText();
   void popbackText();
   void popText(); 
   void insertText();
   void removeText(); 

} text;

void text :: appendText(){
       word *nw = new word;
       if(!nw) return;
       string s;
       cout<<"enter text to append $ ";
       cin>>s;
       nw->t = s;
       nw->next = nullptr;
       nw->prev = nullptr;
       if(!head){
         head = nw;
         tail = nw;
         size++;
         return;
       }
       tail->next = nw;
       nw->prev = tail;
       tail = nw;
       size++;
} 

void text :: prependText(){
       word *nw = new word;
       if(!nw) return;
       string s;
       cout<<"enter text to prepend $ ";
       cin>>s;
       nw->t = s;
       nw->next = nullptr;
       nw->prev = nullptr;
       if(!head){
         head = nw;
         tail = nw;
         size++;
         return;
       }
       nw->next = head;
       head->prev = nw;
       head = nw;
       size++;
}

void text :: showText(){
     word* ptr = head;
     while(ptr){
        cout<<ptr->t<<" ";
        ptr = ptr->next; 
     }
    cout<<endl; 
}

void text :: popText(){
      if(!head){
         cout<<"$ text Buffer is Empty can't Pop !"<<endl;
         return;
      }
      word* ptr = head;
      if(head == tail){
         head = nullptr;
         tail = nullptr;
         size--;
         delete ptr;
         return;
      }
      ptr->next->prev = nullptr;
      head = ptr->next;
      size--;
      delete ptr;
} 

void text :: popbackText(){
      if(!head){
         cout<<"$ text Buffer is Empty can't Pop !"<<endl;
         return;
      }
      word* ptr = head;
      if(head == tail){
         head = nullptr;
         tail = nullptr;
         delete ptr;
         size--;
         return;
      }
      word* ptr2 = tail;
      tail = ptr2->prev;
      ptr2->prev->next = nullptr;
      size--;
      delete ptr2; 
} 

void text :: insertText(){
      word *ptr = head;
      int pos;
      cout<<"enter position to insert text $ ";
      cin>>pos;
      int count = size + 1;
      if(count < pos || pos <= 0){
         cout<<"$ "<<pos<<" is not position in word list"<<endl;
         return;
      }
      if(pos == 1){
         prependText();
         return;
      }
      if(pos == count){
         appendText();
         return;
      }
      string s;
      cout<<"enter text to insert $ ";
      cin>>s;
      word *nw = new word;
      if(!nw) return;
      nw->t = s;
      nw->next = nullptr;
      nw->prev = nullptr;
      pos -= 1; 
      while(--pos){
        ptr = ptr->next;
      }
      nw->next = ptr->next;
      nw->prev = ptr;
      ptr->next->prev = nw;
      ptr->next = nw;
      size++;
}

void text :: removeText(){
      word *ptr = head;
      int pos;
      cout<<"enter position to remove $ ";
      cin>>pos;
      if(size < pos || pos <= 0){
         cout<<"$ "<<pos<<" is not position in word list"<<endl;
         return;
      }
      if(pos == 1){
         popText();
         return;
      }
      if(pos == size){
         popbackText();
         return;
      }
      pos -= 1; 
      while(pos--){
        ptr = ptr->next;
      }
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      size--;
      delete ptr;
}

int main(){ 
    text s1;
    s1.appendText();
    s1.appendText();
    s1.insertText();
    s1.showText();
    return 0;
}