#include <iostream>
#include "13.49_Message.h"
void Folder::RemoveMsg(Message* msg)
{
    msgs.erase(msg);
}
void Folder::AddMsg(Message* msg)
{
    msgs.insert(msg);
}
Folder::Folder(const Folder& rhs)
{
    for(auto msg : rhs.msgs)
    {
        msg->AddFolder(this);
    }
}

Folder &Folder::operator=(const Folder &rhs)
{
    for(auto msg : msgs)
        msg->remove(*this);
    msgs = rhs.msgs;
    for(auto msg : rhs.msgs)
        msg->AddFolder(this);
    std::cout << "Folder copy const" << std::endl;
    return *this;
}

Folder &Folder::operator=(Folder &&rhs)
 noexcept {
    for(auto msg : msgs)
        msg->remove(*this);
    msgs = std::move(rhs.msgs);
    std::cout << "Folder move operator" << std::endl;
    return *this;
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
    std::cout << "Message copy const" << std::endl;
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

Message::Message(Message &&rhs):contents(std::move(rhs.contents)) {
    move_Folders(&rhs);
}

Message &Message::operator=(Message &&rhs) noexcept {
    removeFromFolders();
    contents = std::move(rhs.contents); // move assignment
    folders = std::move(rhs.folders);
    std::cout << "Message Was Moved" << std::endl;
    return *this;
}

void Message::move_Folders(Message *msg) {
    folders = std::move(msg->folders);
    for(auto f : folders)
    {
        f->RemoveMsg(msg);
        f->AddMsg(this);
    }
    msg->folders.clear();

}

