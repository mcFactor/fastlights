const char* CANONICAL_NAMES[78] = {
    "OUTER_TOP_RIGHT_POSTERIOR",
    "OUTER_TOP_POSTERIOR_CENTER",
    "OUTER_TOP_LEFT_POSTERIOR",
    "OUTER_TOP_LEFT_CENTER",
    "OUTER_TOP_LEFT_FRONT",
    "OUTER_TOP_CENTER_FRONT",
    "OUTER_TOP_CENTER_CENTER",
    "OUTER_TOP_RIGHT_CENTER",
    "OUTER_TOP_RIGHT_FRONT",
    "OUTER_FRONT_RIGHT_TOP",
    "OUTER_FRONT_RIGHT_CENTER",
    "OUTER_FRONT_RIGHT_BOTTOM",
    "OUTER_FRONT_CENTER_BOTTOM",
    "OUTER_FRONT_LEFT_BOTTOM",
    "OUTER_FRONT_LEFT_CENTER",
    "OUTER_FRONT_CENTER_CENTER",
    "OUTER_FRONT_CENTER_TOP",
    "OUTER_FRONT_LEFT_TOP",
    "OUTER_LEFT_FRONT_TOP",
    "OUTER_LEFT_CENTER_TOP",
    "OUTER_LEFT_POSTERIOR_TOP",
    "OUTER_LEFT_POSTERIOR_CENTER",
    "OUTER_LEFT_POSTERIOR_BOTTOM",
    "OUTER_LEFT_CENTER_BOTTOM",
    "OUTER_LEFT_CENTER_CENTER",
    "OUTER_LEFT_CENTER_FRONT",
    "OUTER_LEFT_BOTTOM_FRONT",
    "OUTER_BOTTOM_LEFT_FRONT",
    "OUTER_BOTTOM_CENTER_FRONT",
    "OUTER_BOTTOM_RIGHT_FRONT",
    "OUTER_BOTTOM_RIGHT_CENTER",
    "OUTER_BOTTOM_RIGHT_POSTERIOR",
    "OUTER_BOTTOM_CENTER_POSTERIOR",
    "OUTER_BOTTOM_CENTER_CENTER",
    "OUTER_BOTTOM_LEFT_CENTER",
    "OUTER_BOTTOM_LEFT_POSTERIOR",
    "OUTER_POSTERIOR_LEFT_BOTTOM",
    "OUTER_POSTERIOR_LEFT_CENTER",
    "OUTER_POSTERIOR_LEFT_TOP",
    "OUTER_POSTERIOR_CENTER_TOP",
    "OUTER_POSTERIOR_RIGHT_TOP",
    "OUTER_POSTERIOR_RIGHT_CENTER",
    "OUTER_POSTERIOR_CENTER_CENTER",
    "OUTER_POSTERIOR_CENTER_BOTTOM",
    "OUTER_POSTERIOR_RIGHT_BOTTOM",
    "OUTER_RIGHT_POSTERIOR_BOTTOM",
    "OUTER_RIGHT_CENTER_BOTTOM",
    "OUTER_RIGHT_BOTTOM_FRONT",
    "OUTER_RIGHT_CENTER_FRONT",
    "OUTER_RIGHT_FRONT_TOP",
    "OUTER_RIGHT_CENTER_TOP",
    "OUTER_RIGHT_CENTER_CENTER",
    "OUTER_RIGHT_POSTERIOR_CENTER",
    "OUTER_RIGHT_POSTERIOR_TOP",
    "INNER_TOP_RIGHT_POSTERIOR",
    "INNER_TOP_LEFT_POSTERIOR",
    "INNER_TOP_LEFT_FRONT",
    "INNER_TOP_RIGHT_FRONT",
    "INNER_FRONT_RIGHT_TOP",
    "INNER_FRONT_RIGHT_BOTTOM",
    "INNER_FRONT_LEFT_BOTTOM",
    "INNER_FRONT_LEFT_TOP",
    "INNER_LEFT_FRONT_TOP",
    "INNER_LEFT_POSTERIOR_TOP",
    "INNER_LEFT_POSTERIOR_BOTTOM",
    "INNER_LEFT_BOTTOM_FRONT",
    "INNER_BOTTOM_LEFT_FRONT",
    "INNER_BOTTOM_RIGHT_FRONT",
    "INNER_BOTTOM_RIGHT_POSTERIOR",
    "INNER_BOTTOM_LEFT_POSTERIOR",
    "INNER_POSTERIOR_RIGHT_BOTTOM",
    "INNER_POSTERIOR_RIGHT_TOP",
    "INNER_POSTERIOR_LEFT_TOP",
    "INNER_POSTERIOR_LEFT_BOTTOM",
    "INNER_RIGHT_POSTERIOR_BOTTOM",
    "INNER_RIGHT_BOTTOM_FRONT",
    "INNER_RIGHT_FRONT_TOP",
    "INNER_RIGHT_POSTERIOR_TOP"
};

/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -L ANSI-C -Ncanonical_name_to_number -t lightnames.gperf  */
/* Computed positions: -k'1,7,13-14,21,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "lightnames.gperf"


#line 4 "lightnames.gperf"
struct canonical_numbers {
    char *name;
    int number;
};

#define TOTAL_KEYWORDS 150
#define MIN_WORD_LENGTH 20
#define MAX_WORD_LENGTH 29
#define MIN_HASH_VALUE 41
#define MAX_HASH_VALUE 644
/* maximum key range = 604, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
    static unsigned short asso_values[] = {
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645,  55, 205, 645, 115,
        0,  80,   0,   5, 645, 645, 205, 230,  25,   0,
        0, 645,  15,  80,  45, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645,  40, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645, 645, 645, 645, 645,
        645, 645, 645, 645, 645, 645
    };
    register int hval = (int)len;

    switch (hval) {
    default:
        hval += asso_values[(unsigned char)str[20]];
        /*FALLTHROUGH*/
    case 20:
    case 19:
    case 18:
    case 17:
    case 16:
    case 15:
    case 14:
        hval += asso_values[(unsigned char)str[13]];
        /*FALLTHROUGH*/
    case 13:
        hval += asso_values[(unsigned char)str[12]];
        /*FALLTHROUGH*/
    case 12:
    case 11:
    case 10:
    case 9:
    case 8:
    case 7:
        hval += asso_values[(unsigned char)str[6]];
        /*FALLTHROUGH*/
    case 6:
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
    return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct canonical_numbers *
canonical_name_to_number (register const char *str, register unsigned int len) {
    static struct canonical_numbers wordlist[] = {
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""},
#line 26 "lightnames.gperf"
        {"OUTER_FRONT_RIGHT_TOP", 9},
        {""}, {""}, {""}, {""},
#line 119 "lightnames.gperf"
        {"INNER_FRONT_RIGHT_TOP", 58},
        {""}, {""},
#line 90 "lightnames.gperf"
        {"OUTER_POSTERIOR_BOTTOM_CENTER", 43},
        {""},
#line 102 "lightnames.gperf"
        {"OUTER_RIGHT_FRONT_TOP", 49},
        {""}, {""}, {""},
#line 109 "lightnames.gperf"
        {"OUTER_RIGHT_POSTERIOR_TOP", 53},
#line 155 "lightnames.gperf"
        {"INNER_RIGHT_FRONT_TOP", 76},
        {""}, {""}, {""},
#line 157 "lightnames.gperf"
        {"INNER_RIGHT_POSTERIOR_TOP", 77},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 81 "lightnames.gperf"
        {"OUTER_POSTERIOR_LEFT_TOP", 38},
        {""}, {""}, {""},
#line 108 "lightnames.gperf"
        {"OUTER_RIGHT_POSTERIOR_CENTER", 52},
#line 147 "lightnames.gperf"
        {"INNER_POSTERIOR_LEFT_TOP", 72},
#line 85 "lightnames.gperf"
        {"OUTER_POSTERIOR_RIGHT_TOP", 40},
        {""},
#line 77 "lightnames.gperf"
        {"OUTER_POSTERIOR_BOTTOM_LEFT", 36},
#line 92 "lightnames.gperf"
        {"OUTER_POSTERIOR_BOTTOM_RIGHT", 44},
        {""},
#line 145 "lightnames.gperf"
        {"INNER_POSTERIOR_RIGHT_TOP", 71},
        {""},
#line 149 "lightnames.gperf"
        {"INNER_POSTERIOR_BOTTOM_LEFT", 73},
#line 143 "lightnames.gperf"
        {"INNER_POSTERIOR_BOTTOM_RIGHT", 70},
#line 29 "lightnames.gperf"
        {"OUTER_FRONT_RIGHT_CENTER", 10},
        {""}, {""},
#line 80 "lightnames.gperf"
        {"OUTER_POSTERIOR_LEFT_CENTER", 37},
        {""}, {""},
#line 86 "lightnames.gperf"
        {"OUTER_POSTERIOR_TOP_RIGHT", 40},
        {""}, {""},
#line 88 "lightnames.gperf"
        {"OUTER_POSTERIOR_RIGHT_CENTER", 41},
#line 101 "lightnames.gperf"
        {"OUTER_RIGHT_FRONT_CENTER", 48},
#line 146 "lightnames.gperf"
        {"INNER_POSTERIOR_TOP_RIGHT", 71},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""},
#line 42 "lightnames.gperf"
        {"OUTER_FRONT_TOP_LEFT", 17},
        {""}, {""},
#line 94 "lightnames.gperf"
        {"OUTER_RIGHT_BOTTOM_POSTERIOR", 45},
        {""},
#line 126 "lightnames.gperf"
        {"INNER_FRONT_TOP_LEFT", 61},
        {""}, {""},
#line 151 "lightnames.gperf"
        {"INNER_RIGHT_BOTTOM_POSTERIOR", 74},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""},
#line 30 "lightnames.gperf"
        {"OUTER_FRONT_BOTTOM_RIGHT", 11},
        {""}, {""}, {""}, {""},
#line 121 "lightnames.gperf"
        {"INNER_FRONT_BOTTOM_RIGHT", 59},
#line 17 "lightnames.gperf"
        {"OUTER_TOP_FRONT_LEFT", 4},
        {""}, {""}, {""},
#line 71 "lightnames.gperf"
        {"OUTER_BOTTOM_POSTERIOR_CENTER", 32},
#line 115 "lightnames.gperf"
        {"INNER_TOP_FRONT_LEFT", 56},
#line 16 "lightnames.gperf"
        {"OUTER_TOP_LEFT_CENTER", 3},
        {""}, {""},
#line 13 "lightnames.gperf"
        {"OUTER_TOP_LEFT_POSTERIOR", 2},
        {""},
#line 83 "lightnames.gperf"
        {"OUTER_POSTERIOR_CENTER_TOP", 39},
        {""}, {""},
#line 113 "lightnames.gperf"
        {"INNER_TOP_LEFT_POSTERIOR", 55},
        {""}, {""}, {""},
#line 69 "lightnames.gperf"
        {"OUTER_BOTTOM_RIGHT_POSTERIOR", 31},
#line 98 "lightnames.gperf"
        {"OUTER_RIGHT_BOTTOM_FRONT", 47},
#line 18 "lightnames.gperf"
        {"OUTER_TOP_LEFT_FRONT", 4},
#line 27 "lightnames.gperf"
        {"OUTER_FRONT_TOP_RIGHT", 9},
        {""},
#line 140 "lightnames.gperf"
        {"INNER_BOTTOM_RIGHT_POSTERIOR", 68},
#line 153 "lightnames.gperf"
        {"INNER_RIGHT_BOTTOM_FRONT", 75},
#line 116 "lightnames.gperf"
        {"INNER_TOP_LEFT_FRONT", 56},
#line 120 "lightnames.gperf"
        {"INNER_FRONT_TOP_RIGHT", 58},
        {""}, {""},
#line 89 "lightnames.gperf"
        {"OUTER_POSTERIOR_CENTER_CENTER", 42},
        {""}, {""},
#line 76 "lightnames.gperf"
        {"OUTER_BOTTOM_POSTERIOR_LEFT", 35},
#line 68 "lightnames.gperf"
        {"OUTER_BOTTOM_POSTERIOR_RIGHT", 31},
#line 64 "lightnames.gperf"
        {"OUTER_BOTTOM_FRONT_RIGHT", 29},
        {""},
#line 103 "lightnames.gperf"
        {"OUTER_RIGHT_TOP_FRONT", 49},
#line 141 "lightnames.gperf"
        {"INNER_BOTTOM_POSTERIOR_LEFT", 69},
#line 139 "lightnames.gperf"
        {"INNER_BOTTOM_POSTERIOR_RIGHT", 68},
#line 137 "lightnames.gperf"
        {"INNER_BOTTOM_FRONT_RIGHT", 67},
        {""},
#line 156 "lightnames.gperf"
        {"INNER_RIGHT_TOP_FRONT", 76},
        {""}, {""}, {""}, {""},
#line 24 "lightnames.gperf"
        {"OUTER_TOP_FRONT_RIGHT", 8},
#line 22 "lightnames.gperf"
        {"OUTER_TOP_CENTER_RIGHT", 7},
        {""}, {""}, {""},
#line 117 "lightnames.gperf"
        {"INNER_TOP_FRONT_RIGHT", 57},
        {""}, {""}, {""}, {""}, {""},
#line 79 "lightnames.gperf"
        {"OUTER_POSTERIOR_CENTER_LEFT", 37},
#line 87 "lightnames.gperf"
        {"OUTER_POSTERIOR_CENTER_RIGHT", 41},
#line 65 "lightnames.gperf"
        {"OUTER_BOTTOM_RIGHT_FRONT", 29},
        {""}, {""},
#line 40 "lightnames.gperf"
        {"OUTER_FRONT_TOP_CENTER", 16},
#line 21 "lightnames.gperf"
        {"OUTER_TOP_CENTER_CENTER", 6},
#line 138 "lightnames.gperf"
        {"INNER_BOTTOM_RIGHT_FRONT", 67},
        {""},
#line 11 "lightnames.gperf"
        {"OUTER_TOP_CENTER_POSTERIOR", 1},
        {""}, {""}, {""}, {""}, {""},
#line 19 "lightnames.gperf"
        {"OUTER_TOP_CENTER_FRONT", 5},
        {""}, {""},
#line 32 "lightnames.gperf"
        {"OUTER_FRONT_BOTTOM_CENTER", 12},
        {""},
#line 105 "lightnames.gperf"
        {"OUTER_RIGHT_TOP_CENTER", 50},
        {""}, {""},
#line 110 "lightnames.gperf"
        {"OUTER_RIGHT_TOP_POSTERIOR", 53},
        {""}, {""}, {""}, {""},
#line 158 "lightnames.gperf"
        {"INNER_RIGHT_TOP_POSTERIOR", 77},
        {""},
#line 20 "lightnames.gperf"
        {"OUTER_TOP_FRONT_CENTER", 5},
        {""}, {""},
#line 96 "lightnames.gperf"
        {"OUTER_RIGHT_BOTTOM_CENTER", 46},
#line 15 "lightnames.gperf"
        {"OUTER_TOP_CENTER_LEFT", 3},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 25 "lightnames.gperf"
        {"OUTER_TOP_RIGHT_FRONT", 8},
        {""},
#line 34 "lightnames.gperf"
        {"OUTER_FRONT_BOTTOM_LEFT", 13},
        {""},
#line 43 "lightnames.gperf"
        {"OUTER_LEFT_FRONT_TOP", 18},
#line 118 "lightnames.gperf"
        {"INNER_TOP_RIGHT_FRONT", 57},
        {""},
#line 123 "lightnames.gperf"
        {"INNER_FRONT_BOTTOM_LEFT", 60},
        {""},
#line 127 "lightnames.gperf"
        {"INNER_LEFT_FRONT_TOP", 62},
        {""}, {""}, {""}, {""},
#line 63 "lightnames.gperf"
        {"OUTER_BOTTOM_FRONT_CENTER", 28},
#line 84 "lightnames.gperf"
        {"OUTER_POSTERIOR_TOP_CENTER", 39},
        {""}, {""}, {""},
#line 9 "lightnames.gperf"
        {"OUTER_TOP_POSTERIOR_RIGHT", 0},
#line 46 "lightnames.gperf"
        {"OUTER_LEFT_TOP_CENTER", 19},
        {""}, {""},
#line 48 "lightnames.gperf"
        {"OUTER_LEFT_TOP_POSTERIOR", 20},
#line 111 "lightnames.gperf"
        {"INNER_TOP_POSTERIOR_RIGHT", 54},
        {""}, {""}, {""},
#line 130 "lightnames.gperf"
        {"INNER_LEFT_TOP_POSTERIOR", 63},
#line 67 "lightnames.gperf"
        {"OUTER_BOTTOM_RIGHT_CENTER", 30},
        {""}, {""}, {""}, {""},
#line 44 "lightnames.gperf"
        {"OUTER_LEFT_TOP_FRONT", 18},
        {""}, {""}, {""}, {""},
#line 128 "lightnames.gperf"
        {"INNER_LEFT_TOP_FRONT", 62},
        {""},
#line 23 "lightnames.gperf"
        {"OUTER_TOP_RIGHT_CENTER", 7},
#line 60 "lightnames.gperf"
        {"OUTER_BOTTOM_FRONT_LEFT", 27},
#line 82 "lightnames.gperf"
        {"OUTER_POSTERIOR_TOP_LEFT", 38},
#line 10 "lightnames.gperf"
        {"OUTER_TOP_RIGHT_POSTERIOR", 0},
        {""}, {""},
#line 135 "lightnames.gperf"
        {"INNER_BOTTOM_FRONT_LEFT", 66},
#line 148 "lightnames.gperf"
        {"INNER_POSTERIOR_TOP_LEFT", 72},
#line 112 "lightnames.gperf"
        {"INNER_TOP_RIGHT_POSTERIOR", 54},
        {""}, {""},
#line 95 "lightnames.gperf"
        {"OUTER_RIGHT_POSTERIOR_BOTTOM", 45},
        {""}, {""}, {""}, {""},
#line 152 "lightnames.gperf"
        {"INNER_RIGHT_POSTERIOR_BOTTOM", 74},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 78 "lightnames.gperf"
        {"OUTER_POSTERIOR_LEFT_BOTTOM", 36},
#line 57 "lightnames.gperf"
        {"OUTER_LEFT_FRONT_CENTER", 25},
        {""}, {""}, {""},
#line 150 "lightnames.gperf"
        {"INNER_POSTERIOR_LEFT_BOTTOM", 73},
#line 93 "lightnames.gperf"
        {"OUTER_POSTERIOR_RIGHT_BOTTOM", 44},
        {""}, {""}, {""}, {""},
#line 144 "lightnames.gperf"
        {"INNER_POSTERIOR_RIGHT_BOTTOM", 70},
#line 53 "lightnames.gperf"
        {"OUTER_LEFT_BOTTOM_CENTER", 23},
        {""}, {""}, {""},
#line 58 "lightnames.gperf"
        {"OUTER_LEFT_BOTTOM_FRONT", 26},
#line 31 "lightnames.gperf"
        {"OUTER_FRONT_RIGHT_BOTTOM", 11},
        {""}, {""}, {""},
#line 133 "lightnames.gperf"
        {"INNER_LEFT_BOTTOM_FRONT", 65},
#line 122 "lightnames.gperf"
        {"INNER_FRONT_RIGHT_BOTTOM", 59},
        {""}, {""}, {""}, {""},
#line 99 "lightnames.gperf"
        {"OUTER_RIGHT_FRONT_BOTTOM", 47},
        {""}, {""}, {""}, {""},
#line 154 "lightnames.gperf"
        {"INNER_RIGHT_FRONT_BOTTOM", 75},
        {""}, {""}, {""}, {""}, {""},
#line 41 "lightnames.gperf"
        {"OUTER_FRONT_LEFT_TOP", 17},
        {""},
#line 39 "lightnames.gperf"
        {"OUTER_FRONT_CENTER_TOP", 16},
        {""},
#line 70 "lightnames.gperf"
        {"OUTER_BOTTOM_CENTER_POSTERIOR", 32},
#line 125 "lightnames.gperf"
        {"INNER_FRONT_LEFT_TOP", 61},
        {""}, {""}, {""},
#line 47 "lightnames.gperf"
        {"OUTER_LEFT_POSTERIOR_TOP", 20},
        {""}, {""}, {""}, {""},
#line 129 "lightnames.gperf"
        {"INNER_LEFT_POSTERIOR_TOP", 63},
        {""}, {""},
#line 104 "lightnames.gperf"
        {"OUTER_RIGHT_CENTER_TOP", 50},
        {""}, {""}, {""}, {""}, {""}, {""},
#line 74 "lightnames.gperf"
        {"OUTER_BOTTOM_LEFT_CENTER", 34},
        {""},
#line 45 "lightnames.gperf"
        {"OUTER_LEFT_CENTER_TOP", 19},
#line 50 "lightnames.gperf"
        {"OUTER_LEFT_POSTERIOR_CENTER", 21},
#line 61 "lightnames.gperf"
        {"OUTER_BOTTOM_LEFT_FRONT", 27},
        {""},
#line 62 "lightnames.gperf"
        {"OUTER_BOTTOM_CENTER_FRONT", 28},
        {""},
#line 51 "lightnames.gperf"
        {"OUTER_LEFT_BOTTOM_POSTERIOR", 22},
#line 136 "lightnames.gperf"
        {"INNER_BOTTOM_LEFT_FRONT", 66},
        {""}, {""}, {""},
#line 131 "lightnames.gperf"
        {"INNER_LEFT_BOTTOM_POSTERIOR", 64},
#line 107 "lightnames.gperf"
        {"OUTER_RIGHT_CENTER_POSTERIOR", 52},
#line 91 "lightnames.gperf"
        {"OUTER_POSTERIOR_CENTER_BOTTOM", 43},
        {""}, {""}, {""}, {""}, {""},
#line 66 "lightnames.gperf"
        {"OUTER_BOTTOM_CENTER_RIGHT", 30},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 28 "lightnames.gperf"
        {"OUTER_FRONT_CENTER_RIGHT", 10},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 37 "lightnames.gperf"
        {"OUTER_FRONT_LEFT_CENTER", 14},
        {""}, {""}, {""}, {""}, {""},
#line 55 "lightnames.gperf"
        {"OUTER_LEFT_CENTER_CENTER", 24},
        {""}, {""}, {""},
#line 56 "lightnames.gperf"
        {"OUTER_LEFT_CENTER_FRONT", 25},
        {""}, {""},
#line 12 "lightnames.gperf"
        {"OUTER_TOP_POSTERIOR_CENTER", 1},
        {""}, {""},
#line 100 "lightnames.gperf"
        {"OUTER_RIGHT_CENTER_FRONT", 48},
        {""}, {""},
#line 75 "lightnames.gperf"
        {"OUTER_BOTTOM_LEFT_POSTERIOR", 35},
        {""}, {""}, {""}, {""},
#line 142 "lightnames.gperf"
        {"INNER_BOTTOM_LEFT_POSTERIOR", 69},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 14 "lightnames.gperf"
        {"OUTER_TOP_POSTERIOR_LEFT", 2},
        {""}, {""}, {""}, {""},
#line 114 "lightnames.gperf"
        {"INNER_TOP_POSTERIOR_LEFT", 55},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 49 "lightnames.gperf"
        {"OUTER_LEFT_CENTER_POSTERIOR", 21},
        {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 38 "lightnames.gperf"
        {"OUTER_FRONT_CENTER_CENTER", 15},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""},
#line 106 "lightnames.gperf"
        {"OUTER_RIGHT_CENTER_CENTER", 51},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""},
#line 36 "lightnames.gperf"
        {"OUTER_FRONT_CENTER_LEFT", 14},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""},
#line 59 "lightnames.gperf"
        {"OUTER_LEFT_FRONT_BOTTOM", 26},
        {""}, {""}, {""}, {""},
#line 134 "lightnames.gperf"
        {"INNER_LEFT_FRONT_BOTTOM", 65},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""},
#line 72 "lightnames.gperf"
        {"OUTER_BOTTOM_CENTER_CENTER", 33},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 73 "lightnames.gperf"
        {"OUTER_BOTTOM_CENTER_LEFT", 34},
#line 33 "lightnames.gperf"
        {"OUTER_FRONT_CENTER_BOTTOM", 12},
        {""}, {""}, {""}, {""}, {""}, {""},
#line 52 "lightnames.gperf"
        {"OUTER_LEFT_POSTERIOR_BOTTOM", 22},
        {""}, {""}, {""}, {""},
#line 132 "lightnames.gperf"
        {"INNER_LEFT_POSTERIOR_BOTTOM", 64},
        {""}, {""},
#line 97 "lightnames.gperf"
        {"OUTER_RIGHT_CENTER_BOTTOM", 46},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 35 "lightnames.gperf"
        {"OUTER_FRONT_LEFT_BOTTOM", 13},
        {""}, {""}, {""}, {""},
#line 124 "lightnames.gperf"
        {"INNER_FRONT_LEFT_BOTTOM", 60},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
        {""}, {""},
#line 54 "lightnames.gperf"
        {"OUTER_LEFT_CENTER_BOTTOM", 23}
    };

    if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH) {
        register int key = hash (str, len);

        if (key <= MAX_HASH_VALUE && key >= 0) {
            register const char *s = wordlist[key].name;

            if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[key];
        }
    }
    return 0;
}
