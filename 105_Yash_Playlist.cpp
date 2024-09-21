#include<iostream>
#include<cmath>
using namespace std;

struct Song {
	int Id;
	string Title, Artist;
	float Duration;
	Song* next;
};

class playList {
private:
	Song * head;
public:
	playList() {
		head = nullptr;
	}

	void AddAtBeginSong(void);
	void AddAtLastSong(void);
	void AddAtGivenPos(int);
	void AddBeforeSong(string);
	void AddAfterSong(string);
	void AddAtSortPos(void);
	void DeleteFirstSong(void);
	void DeleteLastSong(void);
	void DeleteAtPosSong(int);
	void DeleteByTitleSong(void);
	void DeleteByArtistSong(void);
	void PlaySong(void);
	void DisplayAllSong(void);
	void SearchSong(void);
	void SortPlaylistById(void);

	Song* mergeSort(Song*);
	Song* getMiddle(Song*);
	Song* merge(Song*,Song*);

	~playList();
};

playList :: ~playList() {
	Song * current = head;
	Song * nextNode = nullptr;
	while (current != nullptr) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
}

void playList :: AddAtLastSong() {
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 10;
	newSong->next = nullptr;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	else {
		Song* ptr = head;
		while(ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = newSong;
	}
}

void playList :: AddAtBeginSong() {
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 1000;
	newSong->next = nullptr;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	else {
		newSong->next = head;
		head = newSong;
	}
}

void playList :: AddAtGivenPos(int pos) {
	if (pos == 1) {
		AddAtBeginSong();
		return;
	}
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 1000;
	newSong->next = nullptr;
	Song* ptr = head;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	for(int i=1; i<pos-1; i++) {
		if(ptr == nullptr) {
			cout<<"Position not exist."<<endl;
			return;
		}
		ptr = ptr->next;
	}
	newSong->next = ptr->next;
	ptr->next = newSong;
}

void playList :: AddAtSortPos() {
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 1000;
	newSong->next = nullptr;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	else {
		Song* ptr = head;
		if(ptr->Id > newSong->Id) {
			newSong->next = head;
			head  = newSong;
		}
		while(ptr->next && ptr->next->Id < newSong->Id) {
			ptr = ptr->next;
		}
		if(ptr->next == nullptr) {
			ptr->next = newSong;
		}
		else {
			newSong->next = ptr->next;
			ptr->next = newSong;
		}
	}
}

void playList :: AddAfterSong(string SongName) {
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 1000;
	newSong->next = nullptr;
	Song* ptr = head;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	while(ptr->Title != SongName) {
		if(ptr == nullptr) {
			cout<<"Song not exist."<<endl;
			return;
		}
		ptr = ptr->next;
	}
	newSong->next = ptr->next;
	ptr->next = newSong;
}

void playList :: AddBeforeSong(string SongName) {
	Song* ptr = head;
	if(ptr->Title == SongName) {
		AddAtBeginSong();
		return;
	}
	Song* newSong = new Song;
	cout<<"Enter /> Title | Artist | Duration : ";
	cin>>newSong->Title>>newSong->Artist>>newSong->Duration;
	newSong->Id = rand() % 1000;
	newSong->next = nullptr;
	if(head == nullptr) {
		head = newSong;
		return;
	}
	while(ptr->next->Title != SongName) {
		if(ptr == nullptr) {
			cout<<"Song not exist."<<endl;
			return;
		}
		ptr = ptr->next;
	}
	newSong->next = ptr->next;
	ptr->next = newSong;
}

void playList :: DeleteFirstSong() {
	Song* ptr = head;
	if(head == nullptr) {
		cout<<"Empty playlist! can't delete"<<endl;
		return;
	}
	else {
		head = ptr->next;
		delete ptr;
	}
}

void playList :: DeleteLastSong() {
	Song* ptr = head;
	if(head == nullptr) {
		cout<<"Empty playlist! can't delete"<<endl;
		return;
	}
	else {
		if(ptr->next == nullptr) head = nullptr;
		delete ptr;
		return;
		while(ptr->next->next != nullptr) {
			ptr = ptr->next;
		}
		Song* ptrNxt = ptr->next;
		ptr->next = nullptr;
		delete ptrNxt;
	}
}

void playList :: DeleteAtPosSong(int pos) {
	Song* ptr = head;
	if(head == nullptr) {
		cout<<"Empty playlist! can't delete"<<endl;
		return;
	}
	if(pos == 1) {
		DeleteFirstSong();
		return;
	}
	for(int i=1; i<pos-1; i++) {
		if(ptr == nullptr) {
			cout<<"Position not exist."<<endl;
			return;
		}
		ptr = ptr->next;
	}
	Song* ptrNxt = ptr->next;
	ptr->next = ptrNxt->next;
	delete ptrNxt;
}

void playList :: DeleteByTitleSong() {
	Song* ptr = head;
	string T;
	cout<<"Enter song name for delete : ";
	cin>>T;
	if(head == nullptr) {
		cout<<"Empty playlist! can't delete"<<endl;
		return;
	}
	if(head->Title == T) {
		head = head->next ;
		return;
	}
	while(ptr->next) {
		if(ptr->next->Title == T) {
			ptr->next = ptr->next->next;
			return;
		}
		else {
			ptr = ptr->next;
		}
	}
	cout<<endl<<T<<" is not found in the playlist!"<<endl;
}

void playList :: DeleteByArtistSong() {
	Song* ptr = head;
	string T;
	cout<<"Enter artist name for delete : ";
	cin>>T;
	if(head == nullptr) {
		cout<<"Empty playlist! can't delete"<<endl;
		return;
	}
	if(head->Artist == T) {
		head = head->next ;
		return;
	}
	while(ptr->next) {
		if(ptr->next->Artist == T) {
			ptr->next = ptr->next->next;
			return;
		}
		else {
			ptr = ptr->next;
		}
	}
	cout<<endl<<T<<" is not found in the playlist!"<<endl;
}

void playList :: PlaySong() {
	Song* ptr = head;
	string T;
	cout<<"Enter song name for play : ";
	cin>>T;
	if(ptr == nullptr) {
		cout<<"Your Playlist is Empty"<<endl;
		return;
	}
	while(ptr->Title != T) {
		if(ptr->next == nullptr) {
			cout<<"Song not found !"<<endl<<endl;
			return;
		}
		else {
			ptr = ptr->next;
		}
	}
	cout<<endl;
	cout<<"1. Song Id  : "<<ptr->Id<<endl;
	cout<<"2. Title    : "<<ptr->Title<<endl;
	cout<<"3. Artist   : "<<ptr->Artist<<endl;
	cout<<"4. Duration : "<<ptr->Duration<<endl;
	cout<<endl<<"is Playing..."<<endl<<endl;
}

void playList :: DisplayAllSong() {
	Song* ptr = head;
	if(ptr == nullptr) {
		cout<<"Your Playlist is Empty"<<endl;
		return;
	}
	while(ptr != nullptr) {
		cout<<endl;
		cout<<"1. Song Id  : "<<ptr->Id<<endl;
		cout<<"2. Title    : "<<ptr->Title<<endl;
		cout<<"3. Artist   : "<<ptr->Artist<<endl;
		cout<<"4. Duration : "<<ptr->Duration<<endl;
		ptr = ptr->next;
	}
}

void playList :: SearchSong(void) {
	Song* ptr = head;
	string T;
	cout<<endl<<"Enter song name for search /> ";
	cin>>T;
	while(ptr != nullptr) {
		if(ptr->Title == T) {
			cout<<endl;
			cout<<"1. Song Id  : "<<ptr->Id<<endl;
			cout<<"2. Title    : "<<ptr->Title<<endl;
			cout<<"3. Artist   : "<<ptr->Artist<<endl;
			cout<<"4. Duration : "<<ptr->Duration<<endl;
			return;
		}
		else {
			ptr = ptr->next;
		}
	}
	if(ptr->next == nullptr) cout<<endl<<T<<" is not found in playlist !"<<endl<<endl;
}

void playList::SortPlaylistById() {
	head = mergeSort(head);
	DisplayAllSong();
}

Song* playList :: mergeSort(Song* head) {
	if (!head || !head->next) return head;

	Song* middle = getMiddle(head);
	Song* nextToMiddle = middle->next;
	middle->next = nullptr;

	Song* left = mergeSort(head);
	Song* right = mergeSort(nextToMiddle);

	return merge(left, right);
}

Song* playList :: getMiddle(Song* head) {
	if (!head) return head;

	Song* slow = head;
	Song* fast = head;

	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Song* playList :: merge(Song* left, Song* right) {
	if (!left) return right;
	if (!right) return left;

	Song* result = nullptr;

	if (left->Id <= right->Id) {
		result = left;
		result->next = merge(left->next, right);
	} else {
		result = right;
		result->next = merge(left, right->next);
	}

	return result;
}


int main(){
   playList p;
   string S1,S2;
   cout<<endl;
   cout<<"Enter />"<<endl;
   cout<<"1 for add song at first"<<endl<<"2 for add song at last"<<endl<<"3 for add song at pos"<<endl<<"4 for add before song"<<endl<<"5 for add after song"<<endl<<"6 for add song at sorted position"<<endl<<"7 for delete first song"<<endl<<"8 for delete last song"<<endl<<"9 for delete at position"<<endl<<"10 for delete song by song name"<<endl<<"11 for delete song by song artist"<<endl<<"12 for play song"<<endl<<"13 for display playlist"<<endl<<"14 for search song"<<endl<<"15 for sort playlist"<<endl;
   while(true){
     cout<<endl<<"Enter Choice /> ";
     int choice;
     cin>>choice;
     switch(choice){
       case 1 :
        p.AddAtBeginSong();
        break; 

       case 2 :
        p.AddAtLastSong();
        break;

       case 3 :
	    int pos;
		cout<<"Enter Position /> ";
		cin>>pos;
        p.AddAtGivenPos(pos);
        break;

       case 4 :
		cout<<"Enter song /> ";
		cin>>S1;
        p.AddBeforeSong(S1);
        break;

       case 5 :
		cout<<"Enter song /> ";
		cin>>S2;
        p.AddAfterSong(S2);
        break;	

       case 6 :
        p.AddAtSortPos();
        break;

       case 7 :
        p.DeleteFirstSong();
        break;

       case 8 :
        p.DeleteLastSong();
        break;

       case 9 :
	    int pos2;
		cout<<"Enter Position /> ";
		cin>>pos2;	   
        p.DeleteAtPosSong(pos2);
        break;

       case 10 :
        p.DeleteByTitleSong();
        break;	

       case 11 :
        p.DeleteByArtistSong();
        break;

       case 12 :
        p.PlaySong();
        break;

       case 13 :
		p.DisplayAllSong();		
        break;

       case 14 :
		p.SearchSong();		
        break;

       case 15 :
        p.SortPlaylistById();
        break;	

       default:
        cout<<endl<<"You Exit"<<endl<<endl;
        return 0; 
     }
   }
   cout<<endl;
}
