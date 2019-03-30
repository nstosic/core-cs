int hash(int value, int slots) {
    long output = value;
    output += output << 10;
    output ^= output >> 6;
    return value % slots;
}

int hash(const char* value, int slots) {
    long output = 0L;
    const char* ch = value;
    while(*ch != '\0') {
        output += *ch;
        output += output << 10;
        output ^= output >> 6;
        ch++;
    }
    output += output << 3;
    output ^= output >> 11;
    output += output << 15;
    return (int)(output % slots);
}