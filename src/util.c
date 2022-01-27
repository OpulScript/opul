int isAlpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isNumeric(char c){
    return c >= '0' && c <= '9';
}

int isAlphaNumeric(char c){
    return isAlpha(c) || isNumeric(c);
}
