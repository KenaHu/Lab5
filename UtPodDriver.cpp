/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {
    UtPod t;
    UtPod under(256);
    UtPod over(1000);
    UtPod neg(-1);

    int memSize = t.getTotalMemory();
    cout << "Memory of t is " << memSize << "MB" << endl;
    memSize = under.getTotalMemory();
    cout << "Memory of under is " << memSize << "MB" << endl;
    memSize = over.getTotalMemory();
    cout << "Memory of over is " << memSize << "MB" << endl;
    memSize = neg.getTotalMemory();
    cout << "Memory of neg is " << memSize << "MB" << endl;

    Song s1("Beatles", "Hey Jude1", 4);
    Song s2("Beatles", "Hey Jude2", 5);
    Song s3("Beatles", "Hey Jude3", 6);
    Song s4("Beatles", "Hey Jude4", 7);
    Song s5("Beatles", "Hey Jude5", 241);
    int result = t.addSong(s1);
    result = t.addSong(s2);
    result = t.addSong(s3);
    result = t.addSong(s4);
    result = t.addSong(s5);
    cout << "Pod t" << endl;
    t.showSongList();

    result = under.addSong(s1);
    result = under.addSong(s2);
    result = under.addSong(s3);
    result = under.addSong(s4);
    cout << "Pod under" << endl;
    result = under.getRemainingMemory();
    cout << "Memory left " << result << "MB" << endl;
    result = under.addSong(s5);
    under.showSongList();
    under.clearMemory();
    result = under.addSong(s5);
    result = under.getRemainingMemory();
    cout << "Memory left " << result << "MB" << endl;
    under.showSongList();

    result = over.addSong(s1);
    result = over.addSong(s2);
    result = over.addSong(s3);
    result = over.addSong(s4);
    result = over.addSong(s5);
    cout << "Pod over" << endl;
    over.sortSongList();
    over.showSongList();

    result = neg.addSong(s1);
    result = neg.addSong(s2);
    result = neg.addSong(s3);
    result = neg.addSong(s4);
    result = neg.addSong(s5);
    cout << "Pod neg" << endl;
    neg.shuffle();
    neg.showSongList();
    cout << "Pod neg" << endl;
    neg.shuffle();
    neg.showSongList();
    cout << "Pod neg" << endl;
    neg.shuffle();
    neg.showSongList();

    result = neg.removeSong(s2);
    result = neg.removeSong(s3);
    cout << "After removing 2 songs from Pod neg you have " << neg.numSongs() << " remaining." << endl;
    neg.showSongList();
    result = neg.removeSong(s2);
    cout << "Removing a song that isn't on the device gives the error code " << result << endl;
}
