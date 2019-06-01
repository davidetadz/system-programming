#include <utility>

//
// Created by Davide on 15-Apr-19.
//

#include "Directory.h"

std::shared_ptr <Directory> Directory::root = nullptr;

Directory::Directory(std::string name) : Base(name) {
    this->children.clear();
}

Directory::Directory(std::string name, Directory) : Base(name) {
    this->children.clear();
}

std::shared_ptr <Directory> Directory::getRoot() {
    if (Directory::root == nullptr) {
        root = std::shared_ptr<Directory>(new Directory("/"));
        root->current = root;
    }
    return root;
}

std::shared_ptr<Directory> Directory::addDirectory(std::string name) {
    std::shared_ptr<Directory> d(new Directory(name));
    d->current = d;
    d->parent = this->current;

    this->children.push_front(d);

    return d;
}

std::shared_ptr<File> Directory::addFile(std::string name, uintmax_t size) {
    std::shared_ptr<File> f(new File(name, size));

    this->children.push_front(f);

    return f;
}

int Directory::mType() const {
    return 1;
}

void Directory::ls(int indent) const {

    for (int i = 0; i < indent; i++)
        printf("\t\t");
    printf("[+] %s\n", this->getName().c_str());

    auto it = this->children.cbegin();

    for (; it != this->children.cend(); it++) {
        (*it)->ls(indent + 1);
    }
}

std::shared_ptr<Base> Directory::get(std::string name) {

    if (name == ".")
        return this->current.lock();

    if (name == "..")
        return this->parent.lock();

    auto it = this->children.cbegin();

    for (; it != this->children.cend(); it++) {
        if ( (*it)->getName() == name )
            return *it;
    }

    return std::shared_ptr<Base>();
}

std::shared_ptr<Directory> Directory::getDir(std::string name) {
    return std::dynamic_pointer_cast<Directory>(this->get(name));
}

std::shared_ptr<File> Directory::getFile(std::string name) {
    return std::dynamic_pointer_cast<File>(this->get(name));
}

void Directory::remove(std::string name) {
    auto it = this->children.begin();

    for (; it != this->children.cend(); it++) {
        if ( (*it)->getName() == name ) {
            this->children.remove(*it);
            return;
        }
    }
}
