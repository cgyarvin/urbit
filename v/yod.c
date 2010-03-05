/* yod.c: standalone id tester.
**
** This file is in the public domain.
*/
#include <stdint.h>
#include <stdio.h>
#include <uuid/uuid.h>

/* Decode the yod value of $phoneme and put it in *$pbyte.  Return 1
** iff decoding works correctly.
*/
uint8_t
yod_decode(char *phoneme, uint8_t *pbyte)
{
  uint8_t prefix, vowel, suffix;

  /* XXX: fixme */
  switch ( phoneme[0] ) {
    default: return 0;
    case 'b': prefix = 0; break;
    case 'd': prefix = 1; break;
    case 'h': prefix = 2; break;
    case 'l': prefix = 3; break;
    case 'n': prefix = 4; break;
    case 'v': prefix = 5; break;
    case 'w': prefix = 6; break;
    case 'y': prefix = 7; break;
  }
  switch ( phoneme[1] ) {
    default: return 0;
    case 'a': vowel = 0; break;
    case 'e': vowel = 1; break;
    case 'i': vowel = 2; break;
    case 'o': vowel = 3; break;
  }
  switch ( phoneme[2] ) {
    default: return 0;
    case 'c': suffix = 0; break;
    case 'f': suffix = 1; break;
    case 'g': suffix = 2; break;
    case 'm': suffix = 3; break;
    case 'p': suffix = 4; break;
    case 'r': suffix = 5; break;
    case 's': suffix = 6; break;
    case 't': suffix = 7; break;
  }
  return 1;
}

/* Write the yod value of $byte into $phoneme, and null-terminate it.
**
** If $flip is set, flip the terms.
*/
void
yod_encode(char *phoneme, uint8_t byte, uint8_t flip)
{
  uint8_t prefix = (byte & 7);
  uint8_t vowel = (byte >> 3) & 3;
  uint8_t suffix = (byte >> 5);
  static char *prefixes = "bcmrtvwz";
  static char *vowels = "aeio";
  static char *suffixes = "dfklgnps";

  phoneme[1] = vowels[vowel];
  if ( flip ) {
    phoneme[0] = prefixes[prefix];
    phoneme[2] = suffixes[suffix];
  } else {
    phoneme[0] = suffixes[prefix];
    phoneme[2] = prefixes[suffix];
  }
  phoneme[3] = 0;
}

/* Print $id as yod.
*/
void
yod_print_uuid(uuid_t uuid)
{
  char text[80];
  char *point = text;

  yod_encode(point, uuid[0], 0); point += 3;
  yod_encode(point, uuid[1], 1); point += 3;
  // printf("%d.%d", uuid[0], uuid[1]);
  *point = '-'; point++;

  yod_encode(point, uuid[2], 0); point += 3;
  yod_encode(point, uuid[3], 1); point += 3;
  // printf(".%d.%d\n", uuid[2], uuid[3]);
  *point = '-'; point++;

  yod_encode(point, uuid[4], 0); point += 3;
  yod_encode(point, uuid[5], 1); point += 3;
  *point = '-'; point++;

  yod_encode(point, uuid[6], 0); point += 3;
  yod_encode(point, uuid[7], 1); point += 3; 

  *point = '.'; point++;

  yod_encode(point, uuid[8], 0); point += 3;
  yod_encode(point, uuid[9], 1); point += 3;
  *point = '-'; point++;

  yod_encode(point, uuid[10], 0); point += 3;
  yod_encode(point, uuid[11], 1); point += 3;
  *point = '-'; point++;

  yod_encode(point, uuid[12], 0); point += 3;
  yod_encode(point, uuid[13], 1); point += 3;
  *point = '-'; point++;

  yod_encode(point, uuid[14], 0); point += 3;
  yod_encode(point, uuid[15], 1); point += 3; 

  printf("%s\n", text);
}

int main(int argc, char *argv[])
{
  uuid_t uuid;

  uuid_generate_random(uuid);
  yod_print_uuid(uuid);
  
  exit(0);
}
