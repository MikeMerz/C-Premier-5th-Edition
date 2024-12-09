#include "13.34.h"

void Folder::RemoveMsg(Message* msg)
{
    msgs.erase(msg);
}
void Folder::AddMsg(Message* msg)
{
    msgs.insert(msg);
}
Folder &Folder::operator=(const Folder &rhs)
{
    for(auto msg : msgs)
        msg->remove(*this);
    msgs = rhs.msgs;
}
Folder::~Folder()
{
    for(auto msg : msgs)
        msg->remove(*this);
    msgs.clear();
}
void Message::save(Folder& f)
{
    folders.insert(&f);
    f.AddMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.RemoveMsg(this);
}

void Message::addToFolders(const Message &msg)
{
    for(auto f : msg.folders)
        f->AddMsg(this);
}

void Message::removeFromFolders()
{
    for(auto f : folders)
        f->RemoveMsg(this);
}

Message &Message::operator=(const Message & msg)
{
    removeFromFolders();
    contents = msg.contents;
    folders = msg.folders;
    addToFolders(msg);
    return *this;
}

Message::Message(const Message & msg):contents(msg.contents),folders(msg.folders)
{
    addToFolders(msg);
}

Message::~Message()
{
    removeFromFolders();
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for(auto f : lhs.folders)
        f->RemoveMsg(&lhs);
    for(auto f : rhs.folders)
        f->RemoveMsg(&rhs);
    std::swap(lhs.contents,rhs.contents);
    std::swap(lhs.folders,rhs.folders);
    for(auto f : lhs.folders)
        f->AddMsg(&lhs);
    for(auto f : rhs.folders)
        f->AddMsg(&rhs);
}

void Message::AddFolder(Folder* folder) {
    folders.insert(folder);
}

void Message::RemoveFolder(Folder* folder) {
    folders.erase(folder);
}


