/*

BSD 2-Clause License

Copyright (c) 2024, TcMcKrLiTb

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef __GUI_H__
#define __GUI_H__

/**
 * @file gui.h
 *
 * @brief Provide some function to use
 *
 * After every usage of functions, it will only affect buffer not the screen.
 * You need to use OLED_Display to refresh it.
 *
 */

#include <stdint.h>

void GUI_DrawPoint(uint8_t x, uint8_t y, uint8_t color);
void GUI_Fill(uint8_t sx, uint8_t sy, uint8_t ex, uint8_t ey, uint8_t color);
void GUI_ReverseFill(uint8_t sx, uint8_t sy, uint8_t ex, uint8_t ey);
void GUI_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void GUI_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void GUI_ReverseRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void GUI_FillRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void GUI_ReverseRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void GUI_DrawCircle(uint8_t xc, uint8_t yc, uint8_t color, uint8_t r);
void GUI_FillCircle(uint8_t xc, uint8_t yc, uint8_t color, uint8_t r);
void GUI_DrawTriangel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void GUI_FillTriangel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void GUI_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size, uint8_t mode);
void GUI_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t Size, uint8_t mode);
void GUI_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_t Char_Size, uint8_t mode);
void GUI_ShowFont16(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowFont24(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowFont32(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowCHinese(uint8_t x, uint8_t y, uint8_t hsize, uint8_t *str, uint8_t mode);
void GUI_DrawBMP(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t BMP[], uint8_t mode);
void GUI_ShowStringW(uint8_t x, uint8_t y, uint8_t *chr, uint8_t Char_Size, uint8_t mode);

#endif
