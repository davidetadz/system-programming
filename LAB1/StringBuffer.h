#ifndef LAB01_STRINGBUFFER_H
#define LAB01_STRINGBUFFER_H

#ifndef BUF_SIZE
#define BUF_SIZE 16
#endif

class StringBuffer {

private:
    char* s;
    size_t allocated_len;
    size_t used_len;

public:

    StringBuffer();
    StringBuffer(const char *str);
    StringBuffer(const StringBuffer& sb);

    size_t size();
    size_t capacity();

    void clear();

    void insert(const char* str, size_t pos);
    void insert(const StringBuffer& sb, size_t pos);

    void append(const char* str);
    void append(const StringBuffer& sb);

    const char* c_str();

    void set(const char* str);

};


#endif //LAB01_STRINGBUFFER_H
