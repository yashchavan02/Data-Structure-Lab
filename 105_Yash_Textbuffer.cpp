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
   void insertAfterText();
   void searchText();
   void removeText();
   void deleteText();
   void emptyText();

   ~textBuffer(){
     emptyText();
   }

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
     if(!head){
        cout<<"$ list is empty can't show"<<endl;
        return;
     }
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

void text :: deleteText(){
  if(head == nullptr){
    cout<<"$ list is empty can't search for your key and delete"<<endl;
    return;
  }
  string key;
  cout<<"enter the text to delete $ ";
  cin>>key;
  if(head == tail && head->t == key){
        word *temp = head;
        delete temp;
        head = nullptr;
        tail = nullptr;
        return;  
  }
  word *ptr = head;
  if(ptr->t == key){
     word *temp = head;
     head = temp->next;
     delete temp;
     return;
  }
  ptr = ptr->next;
  while(ptr){
     if(ptr->t == key){
       if(ptr->next == nullptr){
         ptr->prev->next == nullptr;
         delete ptr;
         return;
       }
       ptr->next->prev = ptr->prev;
       ptr->prev->next = ptr->next;
       delete ptr;
       return;
     }
     else {
       ptr = ptr->next;
     }
  }
 cout<<"$ "<<key<<" is not found !"<<endl;  
}

void text :: insertAfterText(){
    string st;
    cout<<"enter the text to insert after $ ";
    cin>>st;
    word *ptr = head;
    if(!ptr){ 
        prependText(); 
        return;
    }
    while(ptr->t != st){
         ptr = ptr->next;
         if(ptr == nullptr) break;
    }
    if(ptr->t == st ){
        string s;
        cout<<"enter the text to insert $ ";
        cin>>s;
        word *nw = new word;
        if(!nw) return;
        nw->t = s;
        nw->next = ptr->next;
        nw->prev = ptr;
        ptr->next->prev = nw;
        ptr->next = nw;
    }
    else {
      cout<<"$ "<<st<<" is not found in list"<<endl;
    }
}

void text :: emptyText(){
   word *ptr = head;
   while(ptr != head){
      word *temp = ptr;
      ptr = ptr->next;
      delete temp;
   }
   delete head; 
}

void text :: searchText(){
     if(head == nullptr){
        cout<<"$ list is empty can't search for your key "<<endl;
        return;
     }
     string key;
     cout<<"enter the text to search $ ";
     cin>>key;
     word *ptr = head;
     if((head == tail && head->t == key) || ptr->t == key){
        cout<<"$ "<<key<<" is searched."<<endl;
        return;
     }
     ptr = ptr->next;
     while(ptr){
        if(ptr->t == key){
           cout<<"$ "<<key<<" is searched."<<endl;
           return;
        }
        else {
          ptr = ptr->next;
        }
     }
     cout<<"$ "<<key<<" is not searched."<<endl;
     return;  
}

int main(){

   text l1;

   cout<<"Enter $ "<<endl;
   cout<<"1 for add text at beg"<<endl<<"2 for add text at end"<<endl<<"3 for insert text "<<endl<<"4 for insert text after"<<endl<<"5 for delete first text"<<endl<<"6 for delete last text"<<endl<<"7 for search text"<<endl<<"8 for delete the text"<<endl<<"9 for remove text"<<endl<<"10 for show all text"<<endl;

   while(true){
     cout<<endl<<"Enter Choice $ ";
     int choice;
     cin>>choice;
     switch(choice){
       case 1 :
        l1.prependText();
        break; 

       case 2 :
        l1.appendText();
        break;

       case 3 :
        l1.insertText();
        break;

       case 4 :
        l1.insertAfterText(); 
        break;

       case 5 :
        l1.popText();
        break;	

       case 6 :
        l1.popbackText();
        break;

       case 7 :
        l1.searchText(); 
        break;

       case 8 :
        l1.deleteText(); 
        break;

       case 9 :
        l1.removeText();
        break;

       case 10 :
        l1.showText();
        break;	

       default:
        cout<<endl<<"You Exit"<<endl<<endl;
        return 0; 
     }
   }                     
   return 0;
}