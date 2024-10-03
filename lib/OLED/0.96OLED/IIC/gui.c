#include "gui.h"
#include "oled.h"
#include "string.h"
#include "oledfont.h"

extern uint8_t F6x8[][8];
extern uint8_t F8X16[];

extern uint8_t Index16[];
extern typFNT_GB16 cfont16[];
extern uint8_t Index24[];
extern typFNT_GB24 cfont24[];
extern uint8_t Index32[];
extern typFNT_GB32 cfont32[];

void GUI_DrawPoint(uint8_t x, uint8_t y, uint8_t color)
{
    OLED_Set_Pixel(x, y, color);
}

void GUI_Fill(uint8_t sx, uint8_t sy, uint8_t ex, uint8_t ey, uint8_t color)
{
    uint8_t i, j;
    uint8_t width = ex - sx + 1;
    uint8_t height = ey - sy + 1;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            uint8_t pixel_x = sx + j;
            uint8_t pixel_y = sy + i;
            OLED_Set_Pixel(pixel_x, pixel_y, color);
        }
    }
}

void GUI_ReverseFill(uint8_t sx, uint8_t sy, uint8_t ex, uint8_t ey)
{
    uint8_t i, j;
    uint8_t width = ex - sx + 1;
    uint8_t height = ey - sy + 1;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            uint8_t pixel_x = sx + j;
            uint8_t pixel_y = sy + i;
            OLED_Reverse_Pixel(pixel_x, pixel_y);
        }
    }
}

void GUI_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
    uint16_t t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy, uRow, uCol;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    uRow = x1;
    uCol = y1;
    if (delta_x > 0)
        incx = 1;
    else if (delta_x == 0)
        incx = 0;
    else
    {
        incx = -1;
        delta_x = -delta_x;
    }
    if (delta_y > 0)
        incy = 1;
    else if (delta_y == 0)
        incy = 0;
    else
    {
        incy = -1;
        delta_y = -delta_y;
    }
    if (delta_x > delta_y)
        distance = delta_x;
    else
        distance = delta_y;
    for (t = 0; t <= distance + 1; t++)
    {
        OLED_Set_Pixel(uRow, uCol, color);
        xerr += delta_x;
        yerr += delta_y;
        if (xerr > distance)
        {
            xerr -= distance;
            uRow += incx;
        }
        if (yerr > distance)
        {
            yerr -= distance;
            uCol += incy;
        }
    }
}

void GUI_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
    GUI_DrawLine(x1, y1, x2, y1, color);
    GUI_DrawLine(x1, y1, x1, y2, color);
    GUI_DrawLine(x1, y2, x2, y2, color);
    GUI_DrawLine(x2, y1, x2, y2, color);
}

void GUI_ReverseRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    uint8_t i, j;
    uint8_t Width, Height;
    if (x1 > 127)
    {
        return;
    }
    if (y1 > 63)
    {
        return;
    }
    if (x2 > 127)
    {
        Width = 127 - x1;
    }
    if (y2 > 63)
    {
        Height = 63 - y1;
    }

    for (j = y1; j < y1 + Height; j++) // 遍历指定页
    {
        for (i = x1; i < x1 + Width; i++) // 遍历指定列
        {
            OLED_Reverse_Pixel(i, j);
        }
    }
}

void GUI_FillRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
    GUI_Fill(x1, y1, x2, y2, color);
}

void GUI_ReverseRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    GUI_ReverseFill(x1, y1, x2, y2);
}

static void _draw_circle_8(uint8_t xc, uint8_t yc, uint8_t x, uint8_t y, uint8_t color)
{
    OLED_Set_Pixel(xc + x, yc + y, color);
    OLED_Set_Pixel(xc - x, yc + y, color);
    OLED_Set_Pixel(xc + x, yc - y, color);
    OLED_Set_Pixel(xc - x, yc - y, color);
    OLED_Set_Pixel(xc + y, yc + x, color);
    OLED_Set_Pixel(xc - y, yc + x, color);
    OLED_Set_Pixel(xc + y, yc - x, color);
    OLED_Set_Pixel(xc - y, yc - x, color);
}

void GUI_DrawCircle(uint8_t xc, uint8_t yc, uint8_t color, uint8_t r)
{
    int x = 0, y = r, d;
    d = 3 - 2 * r;
    while (x <= y)
    {
        _draw_circle_8(xc, yc, x, y, color);
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void GUI_FillCircle(uint8_t xc, uint8_t yc, uint8_t color, uint8_t r)
{
    int x = 0, y = r, yi, d;
    d = 3 - 2 * r;
    while (x <= y)
    {
        for (yi = x; yi <= y; yi++)
        {
            _draw_circle_8(xc, yc, x, yi, color);
        }
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void GUI_DrawTriangel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
    GUI_DrawLine(x0, y0, x1, y1, color);
    GUI_DrawLine(x1, y1, x2, y2, color);
    GUI_DrawLine(x2, y2, x0, y0, color);
}

static void Myswap(uint8_t *a, uint8_t *b)
{
    uint16_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static void _draw_h_line(uint8_t x0, uint8_t x1, uint8_t y, uint8_t color)
{
    uint8_t i = 0;
    for (i = x0; i <= x1; i++)
    {
        OLED_Set_Pixel(i, y, color);
    }
}

void GUI_FillTriangel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color)
{
    uint8_t a, b, y, last;
	int dx01, dy01, dx02, dy02, dx12, dy12;
	long sa = 0;
	long sb = 0;
	if (y0 > y1)
	{
		_swap(&y0, &y1);
		_swap(&x0, &x1);
	}
	if (y1 > y2)
	{
		_swap(&y2, &y1);
		_swap(&x2, &x1);
	}
	if (y0 > y1)
	{
		_swap(&y0, &y1);
		_swap(&x0, &x1);
	}
	if (y0 == y2)
	{
		a = b = x0;
		if (x1 < a)
		{
			a = x1;
		}
		else if (x1 > b)
		{
			b = x1;
		}
		if (x2 < a)
		{
			a = x2;
		}
		else if (x2 > b)
		{
			b = x2;
		}
		_draw_h_line(a, b, y0, color);
		return;
	}
	dx01 = x1 - x0;
	dy01 = y1 - y0;
	dx02 = x2 - x0;
	dy02 = y2 - y0;
	dx12 = x2 - x1;
	dy12 = y2 - y1;

	if (y1 == y2)
	{
		last = y1;
	}
	else
	{
		last = y1 - 1;
	}
	for (y = y0; y <= last; y++)
	{
		a = x0 + sa / dy01;
		b = x0 + sb / dy02;
		sa += dx01;
		sb += dx02;
		if (a > b)
		{
			_swap(&a, &b);
		}
		_draw_h_line(a, b, y, color);
	}
	sa = dx12 * (y - y1);
	sb = dx02 * (y - y0);
	for (; y <= y2; y++)
	{
		a = x1 + sa / dy12;
		b = x0 + sb / dy02;
		sa += dx12;
		sb += dx02;
		if (a > b)
		{
			_swap(&a, &b);
		}
		_draw_h_line(a, b, y, color);
	}
}

void GUI_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size, uint8_t mode);
void GUI_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t Size, uint8_t mode);
void GUI_ShowString(uint8_t x, uint8_t y, uint8_t *chr, uint8_t Char_Size, uint8_t mode);
void GUI_ShowFont16(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowFont24(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowFont32(uint8_t x, uint8_t y, uint8_t *s, uint8_t mode);
void GUI_ShowCHinese(uint8_t x, uint8_t y, uint8_t hsize, uint8_t *str, uint8_t mode);
void GUI_DrawBMP(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t BMP[], uint8_t mode);
void GUI_ShowStringW(uint8_t x, uint8_t y, uint8_t *chr, uint8_t Char_Size, uint8_t mode);
