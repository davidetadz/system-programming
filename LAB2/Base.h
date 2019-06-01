// Classe astratta dalla quale derivano
// Directory e File non instanziabile

#ifndef BASE_H
#define BASE_H

#include <string>

class Base {
public:
    // Restituisce il nome dell'oggetto
    std::string getName() const;

    // Metodo virtuale puro di cui fare override nelle
    // classi derivate; restituisce il tipo dell’istanza
    // (Directory o File) codificato come intero
    virtual int mType() const = 0;

    // Metodo virtuale puro di cui fare override nelle
    // classi derivate
    virtual void ls(int indent = 0) const = 0;

protected:
    Base(std::string);

    std::string name;
};


#endif //BASE_H
