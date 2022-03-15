# CINO

`CINO` stands for `CINO Is Not OOP`

## NOTES

#define NEW(type) ( (type*) calloc(1, sizeof(type)) )

---

/* __FILE__, __LINE__ && assert */
#ifndef NDEBUG
#define assert(x) ((x)?(void)0:__assert(#x, __FILE__, __LINE__))
#else
#define assert(x)
#endif

---

