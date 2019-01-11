#ifndef STRING_H
#define STRING_H

class String {
private:
    char* buffer;
    unsigned long count;
public:
    String();
    ~String();
    unsigned long length() const;
    void print() const;
    const char* unsafePointer() const;

    // Operator overloading
    void operator= (const char* data);
};

#endif