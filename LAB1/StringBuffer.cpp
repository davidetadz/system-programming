#include <string>
#include "StringBuffer.h"

/*
 * Classe StringBuffer
 */

/* COSTRUTTORI */

/*
 * Costruisce un oggetto con buffer di dimensione iniziale
 * ragionevole inizializzandolo con il terminatore di stringa
 *
*/
StringBuffer::StringBuffer() {
    int len = BUF_SIZE * sizeof(char);
    this->s = (char *)(malloc(len));
    if (this->s != nullptr) {
        this->allocated_len = len;
        this->s[0] = '\0';
        this->used_len = 0;
    }
}

/*
 * Costruisce un oggetto allocando un buffer di dimensione
 * sufficiente a contenere l’array di caratteri str (compreso il terminatore finale)
 * e segnando correttamente il numero di caratteri effettivamente utilizzati
 *
 */
StringBuffer::StringBuffer(const char *str) {
    /* strlen ritorna l'indice del terminatore */
    int len = strlen(str) + 1;
    this->s = (char *)(malloc(len));
    if (this->s != nullptr) {
        this->allocated_len = len;
        strcpy(this->s, str);
        this->used_len = len;
    }
}

/*
 * costruttore di copia
 * costruisce un oggetto con un buffer iniziale di dimensione adeguata
 * a contenere i caratteri contenuti nell’oggetto sb e inizializzato con
 * una copia di tali caratteri
 */

StringBuffer::StringBuffer(const StringBuffer &sb) {

}