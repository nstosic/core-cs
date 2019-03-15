void SwapInPlaceArithmetical(int &x, int &y) {
    // This algorithm is prone to fail when parameters have big absolute values because of overflow issues.
    x = x + y;
    y = x - y;
    x = x - y;
}

void SwapInPlaceXor(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}