#ifndef STRING_H
#define STRING_H

class String {
private:
    char* buffer_;
    unsigned long count_;
public:
    String();
    ~String();
    unsigned long Length() const;
    void Print() const;
    const char* UnsafePointer() const;

    // Operator overloading
    void operator= (const char* data);
};

#endif