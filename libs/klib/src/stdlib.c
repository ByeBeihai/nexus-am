#include "klib.h"
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}


int isspace(int x)
{
 if(x==' '||x=='\t'||x=='\n'||x=='\f'||x=='\b'||x=='\r')
  return 1;
 else  
  return 0;
}
int isdigit(int x)
{
 if(x<='9'&&x>='0')         
  return 1; 
 else 
  return 0;
 
}
int atoi(const char *nptr)
{
        int c;              /* current char */
        int total;         /* current total */
        int sign;           /* if '-', then negative, otherwise positive */
 
        /* skip whitespace */
        while ( isspace((int)(unsigned char)*nptr) )
            ++nptr;
 
        c = (int)(unsigned char)*nptr++;
        sign = c;           /* save sign indication */
        if (c == '-' || c == '+')
            c = (int)(unsigned char)*nptr++;    /* skip sign */
 
        total = 0;
 
        while (isdigit(c)) {
            total = 10 * total + (c - '0');     /* accumulate digit */
            c = (int)(unsigned char)*nptr++;    /* get next char */
        }
 
        if (sign == '-')
            return -total;
        else
            return total;   /* return result, negated if necessary */
}

static struct {
  void *ptr;
  uintptr_t size;
} last = { .ptr = NULL, .size = 0 };

void *malloc(size_t size) {
  if (last.ptr == NULL) {
    last.ptr = _heap.start;
    printf("heap start = %x\n", last.ptr);
  }

  // aligning
  size = ROUNDUP(size, sizeof(uintptr_t));

  // skip the region allocated by the last call
  last.ptr += last.size;
  if (last.ptr + size >= _heap.end) return NULL;
  void *ret = last.ptr;
  last.size = size;
  return ret;
}

void free(void *ptr) {
  if (ptr == last.ptr) last.size = 0;
}

#endif
