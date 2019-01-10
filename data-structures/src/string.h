#ifndef STRING_H
#define STRING_H

class String {
private:
    char* buffer;
    int count;
public:
    String();
    ~String();
    int length() const;
    void print() const;
};

#endif