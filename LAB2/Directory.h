#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <cstdlib>
#include <vector>
#include <memory>
#include <forward_list>
#include "Base.h"
#include "File.h"

class Directory : public Base {
protected:
    Directory();

    Directory(std::string);

    Directory(std::string, Directory);

private:
    std::forward_list <std::shared_ptr<Base>> children;
    std::weak_ptr <Directory> parent;
    std::weak_ptr <Directory> current;

    static std::shared_ptr <Directory> root;

public:
    //crea, se ancora non esiste, l’oggetto di tipo
    //Directory e ne restituisce lo smart pointer
    static std::shared_ptr <Directory> getRoot();

    // crea un nuovo oggetto di tipo Directory,
    // il cui nome è desunto dal parametro, e
    // lo aggiunge alla cartella corrente.
    // Se risulta già presente, nella cartella corrente,
    // un oggetto con il nome indicato, solleva un’eccezione
    std::shared_ptr <Directory> addDirectory(std::string name);

    std::shared_ptr <File> addFile(std::string name, uintmax_t size);

    std::shared_ptr <Base> get(std::string name);

    std::shared_ptr <Directory> getDir(std::string name);

    std::shared_ptr <File> getFile(std::string name);

    void remove(std::string name);

    void ls(int indent = 0) const override;

    int mType() const;
};


#endif //DIRECTORY_H
