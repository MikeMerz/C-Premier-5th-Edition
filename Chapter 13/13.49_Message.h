//Exercise 13.49: Add a move constructor and move-assignment operator to
//your StrVec, String, and Message classes.

#include <string>
#include <set>
class Message;

class Folder
{
public:
    Folder() = default;
    Folder(const Folder&);
    Folder(Folder&& rhs) noexcept :msgs(std::move(rhs.msgs)){};
    ~Folder();
    Folder &operator=(const Folder &);
    Folder &operator=(Folder &&) noexcept;
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
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&) noexcept;
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
    void move_Folders(Message*);

};


