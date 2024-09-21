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
   void displayText();
   void popText();
   void popbackText();
   void deleteText(); 
   void insertText();
   void searchText();  
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

int main(){
    circularList l1; 

    l1.appendText(); 
    l1.appendText(); 
    l1.appendText(); 
    l1.popText();
    l1.popbackText();
    l1.deleteText();
    l1.insertText();
    l1.displayText();  
    l1.insertText(); 
    l1.displayText(); 
    l1.searchText(); 
                            
    return 0;
} 