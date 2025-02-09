#ifndef FONT_H
#define FONT_H

// Largura e altura da fonte
#define FONT_WIDTH 8
#define FONT_HEIGHT 8

// Definição da fonte *dentro* do font.h
static uint8_t font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Nothing
    0x6A, 0x85, 0x85, 0xFA, 0x85, 0x85, 0x85, 0x00, // a
    0x7C, 0x44, 0x7C, 0x44, 0x7C, 0x00, 0x00, 0x00, // b
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00, // c
    0x7C, 0x42, 0x7C, 0x42, 0x7C, 0x00, 0x00, 0x00, // d
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00, // e
    0x7C, 0x04, 0x3C, 0x04, 0x04, 0x00, 0x00, 0x00, // f
    0x3E, 0x41, 0x41, 0x51, 0x3E, 0x00, 0x00, 0x00, // g
    0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00, 0x00, // h
    0x3C, 0x04, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, // i
    0x04, 0x02, 0x3C, 0x02, 0x04, 0x00, 0x00, 0x00, // j
    0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, // k
    0x40, 0x40, 0x40, 0x40, 0x7C, 0x00, 0x00, 0x00, // l
    0x78, 0x44, 0x28, 0x10, 0x78, 0x00, 0x00, 0x00, // m
    0x7C, 0x04, 0x04, 0x04, 0x7C, 0x00, 0x00, 0x00, // n
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00, // o
    0x7C, 0x44, 0x7C, 0x04, 0x04, 0x00, 0x00, 0x00, // p
    0x3E, 0x41, 0x41, 0x51, 0x7E, 0x00, 0x00, 0x00, // q
    0x7C, 0x44, 0x7C, 0x44, 0x04, 0x00, 0x00, 0x00, // r
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00, // s
    0x04, 0x04, 0x7C, 0x04, 0x04, 0x00, 0x00, 0x00, // t
    0x7C, 0x04, 0x04, 0x04, 0x7C, 0x00, 0x00, 0x00, // u
    0x30, 0x50, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, // v
    0x7C, 0x10, 0x28, 0x44, 0x7C, 0x00, 0x00, 0x00, // w
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, // x
    0x04, 0x02, 0x3C, 0x02, 0x04, 0x00, 0x00, 0x00, // y
    0x44, 0x62, 0x54, 0x4C, 0x44, 0x00, 0x00, 0x00, // z
    0x3e, 0x41, 0x41, 0x49, 0x41, 0x41, 0x3e, 0x00, //0
    0x00, 0x00, 0x42, 0x7f, 0x40, 0x00, 0x00, 0x00, //1
    0x30, 0x49, 0x49, 0x49, 0x49, 0x46, 0x00, 0x00, //2
    0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00, //3
    0x3f, 0x20, 0x20, 0x78, 0x20, 0x20, 0x00, 0x00, //4
    0x4f, 0x49, 0x49, 0x49, 0x49, 0x30, 0x00, 0x00, //5
    0x3f, 0x48, 0x48, 0x48, 0x48, 0x48, 0x30, 0x00, //6
    0x01, 0x01, 0x01, 0x61, 0x31, 0x0d, 0x03, 0x00, //7
    0x36, 0x49, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00, //8
    0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7f, 0x00, //9
};

#endif