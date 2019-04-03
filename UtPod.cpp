//DOCUMENT HERE
#include "Song.h"
#include "UtPod.h"

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod() {
    songs = NULL;
    podMemSize = MAX_MEMORY;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);  //seed the random number generator
}
//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    songs = NULL;
    if (size > 512 || size <= 0)
        podMemSize = MAX_MEMORY;
    else
        podMemSize = size;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);  //seed the random number generator
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &s){
    if((s.getTitle() == "") || (s.getArtist() == "") || (s.getSize() <= 0))
        return NO_MEMORY;
    int current = getRemainingMemory();
    if (current > s.getSize()) {
        SongNode* temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }
    else
        return NO_MEMORY;
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms -

   output parms -
*/

int UtPod::removeSong(Song const &s){
    if (songs == NULL)
        return -1;

    SongNode* p = songs;
    SongNode* prev = NULL;

    while((p->next != NULL) && (p->s != s)){
        prev = p;
        p = p->next;
    }
    if (prev == NULL){
        songs = p->next;
        delete p;
        return SUCCESS;
    }
    if (p->s == s){
        prev->next = p->next;
        delete p;
        return SUCCESS;
    }
    return -1;
}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::shuffle(){
    for (int i = 0; i < numSongs(); i++) {
        SongNode *p1 = songs;
        SongNode *p2 = songs;
        int mod = numSongs();
        int roll = (rand() % mod);
        while (roll > 0){
            p1=p1->next;
            roll-=1;
        }
        swap(p1->s, p2->s);
	}
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList(){
    for(SongNode *p=songs; p!=NULL; p=p->next)
        cout<< p->s << endl;
}

int UtPod::numSongs(){
    int temp = 0;
    for(SongNode *p=songs; p!=NULL; p=p->next)
        temp+=1;
    return temp;
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList(){
    for(SongNode *p = songs; p != NULL; p=p->next){
        for(SongNode *p2 = p->next; p2!=NULL; p2 = p2->next)
            if (p2->s < p->s)
                swap(p2->s, p->s);
    }
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    while (songs!=NULL)
        removeSong(songs->s);
}


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod

   input parms -

   output parms -
*/

int UtPod::getTotalMemory() {
    return podMemSize;
}



/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/

int UtPod::getRemainingMemory(){
    int memory=0;
    if (songs != NULL) {
        for (SongNode *p = songs; p != NULL; p = p->next)
            memory += p->s.getSize();
    }
    memory = getTotalMemory() - memory;
    return memory;
}


UtPod::~UtPod(){
    clearMemory();
}
