#include "Song.h"

using namespace std;
Song::Song(){
    title = "";
    artist = "";
    size = 0;
}
Song::Song(string _artist, string _title, int _size){
    title = _title;
    artist = _artist;
    size = _size;
}

string Song::getArtist() const{
    return artist;
}

 void Song::setArtist(string singer) {
    artist = singer;
}


int Song::getSize() const{
    return size;
}

 void Song::setSize(int size){
    this->size = size;
}

void Song::swap(Song &g2){
    Song temp = g2;
    g2 = *this;
    *this = temp;
}

bool Song::operator >(Song const &rhs){
    if(artist > rhs.artist) {
        return true;
    }
    else if (artist == rhs.artist) {
        if (title > rhs.title) {
            return true;
        }
        else if (title == rhs.title) {
            if (size > rhs.size) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator ==(Song const &rhs){
    return (artist == rhs.artist &&
            title == rhs.title &&
            size == rhs.size);
}
bool Song::operator !=(Song const &rhs){
    return (artist != rhs.artist ||
            title != rhs.title ||
            size != rhs.size);
}
bool Song::operator <(Song const &rhs){
    if(artist < rhs.artist) {
        return true;
    }
    else if (artist == rhs.artist) {
        if (title < rhs.title) {
            return true;
        }
        else if (title == rhs.title) {
            if (size < rhs.size) {
                return true;
            }
        }
    }
    return false;
}


Song::~Song() =default;



ostream& operator << (ostream& out, const Song &g){
    out << g.getTitle() << " (" << g.getArtist() << ") - " << g.getSize();
    return out;
}