#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

private:
    string artist;
    string title;
    int size;

public:
    Song();
    Song(string artist, string title, int size);

    string getTitle() const
    { return title; }

    void setTitle(string n)
    {
        title = n;
    };

    string getArtist() const;
    void setArtist(string singer);
    int getSize() const;
    void setSize(int h);

    void swap(Song &p);

    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator !=(Song const &rhs);
    bool operator <(Song const &rhs);

    ~Song();
};


ostream& operator << (ostream& out, const Song &g);


#endif