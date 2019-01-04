#define PORTD _SFR_IO8(0x0B)
#define PIND _SFR_IO8(0x09)
struct _portd_out_bits
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} ;

struct _portd_in_bits
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} ;
#define PD_OUT0 ((struct _portd_out_bits *)(&PORTD))->ODR0
#define PD_IN0 ((struct _portd_in_bits *)(&PIND))->IDR0

