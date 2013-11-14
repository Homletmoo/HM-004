// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_6_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_6_usascii'.
//
/* // Example usage:

static stb_fontchar fontdata[STB_SOMEFONT_NUM_CHARS];

static void init(void)
{
    // optionally replace both STB_SOMEFONT_BITMAP_HEIGHT with STB_SOMEFONT_BITMAP_HEIGHT_POW2
    static unsigned char fontpixels[STB_SOMEFONT_BITMAP_HEIGHT][STB_SOMEFONT_BITMAP_WIDTH];
    STB_SOMEFONT_CREATE(fontdata, fontpixels, STB_SOMEFONT_BITMAP_HEIGHT);
    ... create texture ...
    // for best results rendering 1:1 pixels texels, use nearest-neighbor sampling
    // if allowed to scale up, use bilerp
}

// This function positions characters on integer coordinates, and assumes 1:1 texels to pixels
// Appropriate if nearest-neighbor sampling is used
static void draw_string_integer(int x, int y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0, cd->t0); glVertex2i(x + cd->x0, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t0); glVertex2i(x + cd->x1, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t1); glVertex2i(x + cd->x1, y + cd->y1);
        glTexCoord2f(cd->s0, cd->t1); glVertex2i(x + cd->x0, y + cd->y1);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance_int;
    }
    glEnd();
}

// This function positions characters on float coordinates, and doesn't require 1:1 texels to pixels
// Appropriate if bilinear filtering is used
static void draw_string_float(float x, float y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0f, cd->t0f); glVertex2f(x + cd->x0f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t0f); glVertex2f(x + cd->x1f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t1f); glVertex2f(x + cd->x1f, y + cd->y1f);
        glTexCoord2f(cd->s0f, cd->t1f); glVertex2f(x + cd->x0f, y + cd->y1f);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance;
    }
    glEnd();
}
*/

#ifndef STB_FONTCHAR__TYPEDEF
#define STB_FONTCHAR__TYPEDEF
typedef struct
{
    // coordinates if using integer positioning
    float s0,t0,s1,t1;
    signed short x0,y0,x1,y1;
    int   advance_int;
    // coordinates if using floating positioning
    float s0f,t0f,s1f,t1f;
    float x0f,y0f,x1f,y1f;
    float advance;
} stb_fontchar;
#endif

#define STB_FONT_consolas_6_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_6_usascii_BITMAP_HEIGHT         24
#define STB_FONT_consolas_6_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_consolas_6_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_6_usascii_NUM_CHARS             95

#define STB_FONT_consolas_6_usascii_LINE_SPACING           4

static unsigned int stb__consolas_6_usascii_pixels[]={
    0x08504426,0x02009804,0x08201040,0x83b98402,0x73801010,0x0b531408,
    0x5d2e6041,0xa847733b,0x4371c911,0x5064621b,0x45751d4c,0xa87771c9,
    0x27381c92,0x24433383,0x22875305,0xb85552da,0x39ce70e2,0x143148e7,
    0x2a996147,0x46eaa387,0xb992e0c9,0x2ee39cc0,0x2639c263,0x45470e4b,
    0x389106c3,0x23da8aee,0x2e9553bb,0x3108e73b,0x38333944,0x57288728,
    0x7712ee17,0x4e38a1dc,0x4e3ba8e3,0x225470a3,0xb95c3839,0x21ce1c49,
    0x883ba873,0x030e38e1,0x2ea350e5,0x3d996ee3,0x45141737,0xba8513ab,
    0xb3289750,0x9808e2a5,0x8702602d,0x40010873,0x371cb11a,0x191a88c4,
    0x3001351c,0x000c0000,0x00000030,0x30000000,0x22010208,0x00080260,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x57300000,0x21a995c4,0x8dc46e64,0x267712a8,0x2077103b,0xc984ca52,
    0x23952e62,0x44ea6132,0x2294132b,0x52964c53,0x31b98aea,0x1706ae55,
    0x0155298b,0x9c0ab86e,0x1a8eaa13,0xb9ce3887,0x88cc1c29,0x7571ce1c,
    0x21dc130e,0x9371c3a9,0x509a8e2e,0x2b21ce13,0x64911cc3,0x2245ce60,
    0x4ea69173,0x9ce20e29,0x38387953,0x547530ec,0x8265712b,0x2e38483b,
    0x55435749,0x224e1550,0x4caa63ba,0x9d54712a,0x263733b9,0x8d47754b,
    0x5d4712b9,0x5c38d393,0x0d89173b,0x45cb2600,0x9cb661c3,0x2a0a8e73,
    0x0007792b,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x2ba80000,0x71064555,0x245ca2e7,0x9039c773,
    0x32b995cc,0x1b992697,0x70aa1540,0x4c775081,0x7247771a,0x541dcc79,
    0x4e91ce39,0x8ae27374,0x2e7774a9,0x4e71ce4b,0x387381b8,0x70dc471c,
    0x932a3a88,0x2a751389,0x39cae608,0x2e155471,0x2a60d8a0,0x9371bb83,
    0x74ab92aa,0xba8aea95,0x8dc52ea3,0x20a92a24,0x33a98e0b,0x7724e45b,
    0x10508809,0xaa81ce11,0x26a0b2a2,0x2e1c06c3,0x2017173b,0x00054ed3,
    0xca8dcc02,0x203d98e3,0x3331c442,0x00000000,0x00000000,0x00000000,
    0x00000000,0x86661517,0x000dc408,0x00000000,0x00000000,0x00000000,
    0x43331e5c,0x000004ba,0x00000000,0x00000000,0x70000000,0x000000b5,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_6_usascii_x[95]={ 0,1,0,0,0,0,0,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__consolas_6_usascii_y[95]={ 4,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,3,2,
3,-1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,4,-1,1,-1,1,-1,1,-1,1,-1,-1,
-1,-1,-1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,-1,-1,-1,1, };
static unsigned short stb__consolas_6_usascii_w[95]={ 0,2,3,4,3,4,4,1,3,3,3,4,3,3,
2,3,4,3,3,3,4,3,3,3,3,3,2,3,3,3,3,3,4,4,3,3,4,3,3,3,3,3,3,4,
3,4,3,4,3,4,4,3,4,3,4,4,4,4,3,2,3,3,3,4,2,3,3,3,3,3,4,4,3,3,
3,4,3,4,3,4,3,3,4,3,3,3,4,4,4,4,3,3,1,3,4, };
static unsigned short stb__consolas_6_usascii_h[95]={ 0,6,3,4,6,6,6,3,7,7,4,4,3,1,
2,6,5,4,4,5,4,5,5,4,5,4,4,5,5,3,5,6,7,4,4,5,4,4,4,5,4,4,5,4,
4,4,4,5,4,6,4,5,4,5,4,4,4,4,4,7,6,7,3,2,3,4,6,4,6,4,5,5,5,5,
7,5,5,3,3,4,5,5,3,4,5,4,3,3,3,5,3,7,7,7,2, };
static unsigned short stb__consolas_6_usascii_s[95]={ 126,53,82,73,40,44,35,126,15,26,36,
63,99,93,125,60,1,55,47,6,68,10,22,51,34,43,40,14,38,91,46,
49,30,9,5,42,121,117,113,30,104,100,26,90,86,22,18,121,1,64,108,
18,59,50,73,54,68,95,64,23,73,1,78,83,112,14,56,82,69,78,104,
99,109,91,19,81,77,103,95,27,117,113,86,59,95,32,120,78,115,86,108,
11,9,5,88, };
static unsigned short stb__consolas_6_usascii_t[95]={ 5,1,15,15,1,1,1,1,1,1,15,
15,15,19,15,1,9,15,15,9,15,9,9,15,9,15,15,9,9,15,9,
1,1,15,15,9,9,9,9,9,9,9,9,9,9,15,15,1,15,1,9,
9,9,9,9,9,9,9,9,1,1,1,15,19,15,15,1,9,1,9,1,
1,1,1,1,1,1,15,15,15,1,1,15,15,1,15,15,19,15,1,15,
1,1,1,19, };
static unsigned short stb__consolas_6_usascii_a[95]={ 53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_6_usascii_BITMAP_HEIGHT or STB_FONT_consolas_6_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_6_usascii(stb_fontchar font[STB_FONT_consolas_6_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_6_usascii_BITMAP_HEIGHT][STB_FONT_consolas_6_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_6_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_6_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_6_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_6_usascii_BITMAP_WIDTH-1; ++i) {
                unsigned int value;
                if (numbits==0) bitpack = *bits++, numbits=32;
                value = bitpack & 1;
                bitpack >>= 1, --numbits;
                if (value) {
                    if (numbits < 3) bitpack = *bits++, numbits = 32;
                    data[j][i] = (bitpack & 7) * 0x20 + 0x1f;
                    bitpack >>= 3, numbits -= 3;
                } else {
                    data[j][i] = 0;
                }
            }
        }
    }

    // build font description
    if (font != 0) {
        float recip_width = 1.0f / STB_FONT_consolas_6_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_6_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_6_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_6_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_6_usascii_s[i] + stb__consolas_6_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_6_usascii_t[i] + stb__consolas_6_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_6_usascii_x[i];
            font[i].y0 = stb__consolas_6_usascii_y[i];
            font[i].x1 = stb__consolas_6_usascii_x[i] + stb__consolas_6_usascii_w[i];
            font[i].y1 = stb__consolas_6_usascii_y[i] + stb__consolas_6_usascii_h[i];
            font[i].advance_int = (stb__consolas_6_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_6_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_6_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_6_usascii_s[i] + stb__consolas_6_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_6_usascii_t[i] + stb__consolas_6_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_6_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_6_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_6_usascii_x[i] + stb__consolas_6_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_6_usascii_y[i] + stb__consolas_6_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_6_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_6_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_6_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_6_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_6_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_6_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_6_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_6_usascii_LINE_SPACING
#endif

