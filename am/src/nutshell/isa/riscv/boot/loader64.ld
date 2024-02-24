pmem_base = 0x00000000;

MEMORY {
  ram (rwxa) : ORIGIN = 0x00000000, LENGTH = 128M
}

INCLUDE "section.ld"
