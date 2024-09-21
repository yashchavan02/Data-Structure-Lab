#include<iostream>
using namespace std;

struct textNode {
  string t;
  textNode *next;
};

class circularList {
   textNode *head , *tail;
   public:

   circularList(){
      head = nullptr;
      tail = nullptr;
   }

   void prependText();
   void appendText();
   void insertText();
   void insertAfterText(); 
   void popText();
   void popbackText();
   void searchText(); 
   void deleteText(); 
   void removeText();
   void displayText();
   void emptyText();

   ~ circularList(){
      emptyText();
   }
};

void circularList :: prependText(){
     textNode *newText = new textNode ;
     string s;
     cout<<"enter the text to prepend $ ";
     cin>>s;
     if(!newText) return;
     newText->t = s;
     newText->next = nullptr;
     if(head == nullptr){
        head = newText;
        tail = newText;
        newText->next = head;
        return;
     }
     tail->next = nullptr;
     newText->next = head;
     head = newText;
     tail->next = head;
}

void circularList :: popText(){
     if(head == nullptr){
        cout<<"$ list is empty can't pop "<<endl;
        return;
     }
     if(head == tail){
        textNode *ptr = head;
        delete ptr;
        head = nullptr;
        tail = nullptr;
        return;
     }
     tail->next = nullptr;
     textNode *ptr = head;
     head = ptr->next;
     delete ptr;
     tail->next = head;
}

void circularList :: appendText(){
     textNode *newText = new textNode ;
     string s;
     cout<<"enter the text to append $ ";
     cin>>s;
     if(!newText) return;
     newText->t = s;
     newText->next = nullptr;
     if(!head){
        head = newText;
        tail = newText;
        newText->next = head;        
        return;
     }
     tail->next = newText;
     tail = newText;
     newText->next = head;
}

void circularList :: popbackText(){
     if(head == nullptr){
        cout<<"$ list is empty can't popback "<<endl;
        return;
     }
     if(head == tail){
        textNode *ptr = head;
        delete ptr;
        head = nullptr;
        tail = nullptr;
        return;
     }
     textNode *ptr = head;
     while(ptr->next != tail){
        ptr = ptr->next;
     }
     tail->next = nullptr;
     textNode *temp = ptr->next;
     delete temp;
     tail = ptr;
     tail->next = head;
}

void circularList :: searchText(){
     if(head == nullptr){
        cout<<"$ list is empty can't search for your key "<<endl;
        return;
     }
     string key;
     cout<<"enter the text to search $ ";
     cin>>key;
     textNode *ptr = head;
     if((head == tail && head->t == key) || ptr->t == key){
        cout<<"$ "<<key<<" is searched."<<endl;
        return;
     }
     ptr = ptr->next;
     while(ptr != head){
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

void circularList :: deleteText(){
  if(head == nullptr){
    cout<<"$ list is empty can't search for your key and delete"<<endl;
    return;
  }
  string key;
  cout<<"enter the text to delete $ ";
  cin>>key;
  if(head == tail && head->t == key){
        textNode *temp = head;
        delete temp;
        head = nullptr;
        tail = nullptr;
        return;  
  }
  textNode *ptr = head;
  if(ptr->t == key){
     tail->next = nullptr;
     textNode *temp = head;
     head = temp->next;
     delete temp;
     tail->next = head;
     return;
  }
  textNode *temp = ptr;
  ptr = ptr->next;
  while(ptr != head){
     if(ptr->t == key){
       temp->next = ptr->next;
       delete ptr;
       return;
     }
     else {
       ptr = ptr->next;
       temp = temp->next;
     }
  }
 cout<<"$ "<<key<<" is not found !"<<endl;  
}

void circularList :: displayText(){
  textNode *ptr = head;
  if(!head){
    cout<<"$ list is empty can't display"<<endl;
    return;
  }
  while(ptr->next != head){
     cout<<ptr->t<<" ";
     ptr = ptr->next;
  }
  cout<<ptr->t<<endl;
}  

void circularList :: insertText(){
   int pos;
   cout<<"enter position to insert $ ";
   cin>>pos;
   if(pos <= 0){
      cout<<"$ you enter invalid pos"<<endl;
      return;
   }
   if(pos == 1){
     prependText();
     return;
   }
   textNode *ptr = head;
   if(!ptr){ 
        prependText(); 
        return;
   }
   for(int i=1;i<pos-1;i++){
      ptr = ptr->next;
   }
   string s;
   cout<<"enter the text to insert $ ";
   cin>>s;
   textNode *newText = new textNode ;
   if(!newText) return;
   newText->t = s;
   newText->next = ptr->next;
   ptr->next = newText;
}

void circularList :: insertAfterText(){
    string st;
    cout<<"enter the text to insert after $ ";
    cin>>st;
    textNode *ptr = head;
    if(!ptr){ 
        prependText(); 
        return;
    }
    while(ptr->t != st){
         ptr = ptr->next;
         if(ptr == tail) break;
    }
    if(ptr->t == st ){
        string s;
        cout<<"enter the text to insert $ ";
        cin>>s;
        textNode *newText = new textNode ;
        if(!newText) return;
        newText->t = s;
        newText->next = ptr->next;
        ptr->next = newText;
    }
    else {
      cout<<"$ "<<st<<" is not found in list"<<endl;
    }
}

void circularList :: emptyText(){
   textNode *ptr = head;
   while(ptr != head){
      textNode *temp = ptr;
      ptr = ptr->next;
      delete temp;
   }
   delete head; 
}

void circularList :: removeText(){
   textNode *ptr = head;
   int pos;
   cout<<"enter position to remove $ ";
   cin>>pos;
   if(pos <= 0 ){
      cout<<"$ you enter invalid pos can't remove"<<endl;
   }
   if(pos == 1){
      popText();
      return;
   }
   for(int i=1;i<pos-1;i++){
      ptr = ptr->next;
   }
   textNode *temp = ptr->next;
   ptr->next = temp->next;
   delete temp;
}

int main(){

   circularList l1; 

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
        l1.displayText();
        break;	

       default:
        cout<<endl<<"You Exit"<<endl<<endl;
        return 0; 
     }
   }                     
   return 0;
} 