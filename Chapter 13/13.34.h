//Exercise 13.34: Write the Message class as described in this section.
//Exercise 13.36: Design and implement the corresponding Folder class.
//That class should hold a set that points to the Messages in that Folder.

#include <string>
#include <set>
class Message;

class Folder
{
public:
    Folder() = default;
    ~Folder();
    Folder &operator=(const Folder &);
    void AddMsg(Message*);
    void RemoveMsg(Message*);
private:
    std::set<Message*> msgs;

};
class Message
{
    friend class Folder;
    friend void swap(Message&,Message&);
public:
    explicit Message(const std::string str= ""):contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void AddFolder(Folder*);
    void RemoveFolder(Folder*);
private:
    std::string contents;
    std::set<Folder*> folders;

    void addToFolders(const Message&);
    void removeFromFolders();

};


