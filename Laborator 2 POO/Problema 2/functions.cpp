#include "functions.h"
#include <cstring> 

int CompNume(const Student& s1, const Student& s2) {
    int rez = strcmp(s1.GetNume(), s2.GetNume());
    if (rez == 0) return 0;
    if (rez > 0) return 1;
    return -1;
}

int CompNotaMatematica(const Student& s1, const Student& s2) {
    if (s1.GetNotaMatematica() == s2.GetNotaMatematica()) return 0;
    if (s1.GetNotaMatematica() > s2.GetNotaMatematica()) return 1;
    return -1;
}

int CompNotaEngleza(const Student& s1, const Student& s2) {
    if (s1.GetNotaEngleza() == s2.GetNotaEngleza()) return 0;
    if (s1.GetNotaEngleza() > s2.GetNotaEngleza()) return 1;
    return -1;
}

int CompNotaIstorie(const Student& s1, const Student& s2) {
    if (s1.GetNotaIstorie() == s2.GetNotaIstorie()) return 0;
    if (s1.GetNotaIstorie() > s2.GetNotaIstorie()) return 1;
    return -1;
}

int CompMedia(const Student& s1, const Student& s2) {
    if (s1.GetMediaNote() == s2.GetMediaNote()) return 0;
    if (s1.GetMediaNote() > s2.GetMediaNote()) return 1;
    return -1;
}