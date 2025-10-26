#include <iostream>
#include <string>
using namespace std;
class Song
{
public:
    string title;
    string artist;
    Song *next;

    Song()
    {
        title = "";
        artist = "";
        next = NULL;
    }

    Song(string t, string a)
    {
        title = t;
        artist = a;
        next = NULL;
    }
};

class Playlist
{
public:
    Song *head;

    Playlist()
    {
        head = NULL;
    }

    void addSongAtBeginning(string title, string artist)
    {
        Song *newSong = new Song(title, artist);

        if (head == NULL)
        {
            newSong->next = newSong; 
            head = newSong;
        }
        else
        {
            Song *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            newSong->next = head;
            head = newSong;
            last->next = head; 
        }

        cout << "Song added at the beginning\n";
    }

    void removeSongAtEnd()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty\n";
        }
        else
        {
            Song *last = head;
            Song *secondLast = NULL;

            while (last->next != head)
            {
                secondLast = last;
                last = last->next;
            }

            if (secondLast == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                
                secondLast->next = head;
                delete last;
            }

            cout << "Song removed from the end\n";
        }
    }

    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty\n";
        }
        else
        {
            Song *current = head;

            do
            {
                cout << "Title: " << current->title << ", Artist: " << current->artist << endl;
                current = current->next;
            } while (current != head);
        }
    }

    ~Playlist()
    {
        Song *current = head;
        Song *nextNode = NULL;

        if (head != NULL)
        {
            do
            {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }
};

int main()
{
    Playlist playlist;
    int choice;
    string title, artist;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Song at Beginning\n";
        cout << "2. Remove Song at End\n";
        cout << "3. Display Playlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSongAtBeginning(title, artist);
        }
        else if (choice == 2)
        {
            playlist.removeSongAtEnd();
        }
        else if (choice == 3)
        {
            playlist.displayPlaylist();
        }
        else if (choice == 4)
        {
            cout << "Exiting the program\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
