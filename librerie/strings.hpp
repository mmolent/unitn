//declaration of functions to work with strings (char arrays)
/*
mstrlen(s): restituisce la lunghezza di s escluso ’\0’
mstrchr(s,c): restituisce un puntatore alla prima occorrenza di c in s, oppure NULL se c non si trova in s
mstrrchr(s,c): come sopra ma per l’ultima occorrenza di c in s
mstrstr(s,t): restituisce un puntatore alla prima occorrenza della sottostringa t in s, oppure NULL se t non si trova in s
mstrcpy(s,t): copia t in s e restituisce s
mstrncpy(s,t,n): copia n caratteri di t in s e restituisce s. Se non c’è lo ’\0’ negli n caratteri la stringa s non è ben formata!
mstrcat(s,t): concatena t al termine di s e restituisce s
mstrncat(s,t,n): concatena n caratteri di t al termine di s e restituisce s. La stringa di destinazione contiene sempre ’\0’, vengono copiati n caratteri e sempre aggiunto ’0’).
mstrcmp(s,t): restituisce un valore negativo, nullo o positivo se s è alfabeticamente minore, uguale o maggiore di t
*/
#ifndef STRINGS_HPP
#define STRINGS_HPP

int mstrlen(const char* s);
char* mstrchr(char* s, char c);
char* mstrrchr(char* s, char c);
char* mstrstr(char* s, const char* t);
char* mstrcpy(char* s, const char* t);
char* mstrncpy(char* s, const char* t, int n);
char* mstrcat(char* s, const char* t);
char* mstrncat(char* s, const char* t, int n);
int mstrcmp(const char* s, const char* t);
#endif