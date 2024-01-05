//implementation of function to work with strings (char arrays)

#include "strings.hpp"

#include <iostream>

int mstrlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char* mstrchr(char* s, char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) {
            return &s[i];
        }
        i++;
    }
    return nullptr;
}

char* mstrrchr(char* s, char c) {
    int i = mstrlen(s) - 1;
    while (i >= 0) {
        if (s[i] == c) {
            return &s[i];
        }
        i--;
    }
    return nullptr;
}

char* mstrstr(char* s, const char* t) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] == t[j]) {
            j++;
            if (t[j] == '\0') {
                return &s[i - j + 1];
            }
        } else {
            j = 0;
        }
        i++;
    }
    return nullptr;
}

char* mstrcpy(char* s, const char* t) {
    int i = 0;
    while (t[i] != '\0') {
        s[i] = t[i];
        i++;
    }
    s[i] = '\0';
    return s;
}

char* mstrncpy(char* s, const char* t, int n) {
    int i = 0;
    while (i < n && t[i] != '\0') {
        s[i] = t[i];
        i++;
    }
    while (i < n) {
        s[i] = '\0';
        i++;
    }
    return s;
}

char* mstrcat(char* s, const char* t) {
    int i = mstrlen(s);
    int j = 0;
    while (t[j] != '\0') {
        s[i] = t[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return s;
}

char* mstrncat(char* s, const char* t, int n) {
    int i = mstrlen(s);
    int j = 0;
    while (j < n && t[j] != '\0') {
        s[i] = t[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return s;
}

int mstrcmp(const char* s, const char* t) {
    int i = 0;
    while (s[i] != '\0' && t[i] != '\0') {
        if (s[i] < t[i]) {
            return -1;
        } else if (s[i] > t[i]) {
            return 1;
        }
        i++;
    }
    if (s[i] == '\0' && t[i] == '\0') {
        return 0;
    } else if (s[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}
