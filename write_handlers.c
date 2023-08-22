#include &quot;main.h&quot;
/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer&#39;s right */
int i = 0;
char padd = &#39; &#39;;
UNUSED(precision);
UNUSED(size);
if (flags &amp; F_ZERO)
padd = &#39;0&#39;;
buffer[i++] = c;
buffer[i] = &#39;\0&#39;;
if (width &gt; 1)
{
buffer[BUFF_SIZE - 1] = &#39;\0&#39;;
for (i = 0; i &lt; width - 1; i++)
buffer[BUFF_SIZE - i - 2] = padd;
if (flags &amp; F_MINUS)
return (write(1, &amp;buffer[0], 1) +

write(1, &amp;buffer[BUFF_SIZE - i - 1], width - 1));

else
return (write(1, &amp;buffer[BUFF_SIZE - i - 1], width - 1) +

write(1, &amp;buffer[0], 1));

}
return (write(1, &amp;buffer[0], 1));
}
/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = &#39; &#39;, extra_ch = 0;
UNUSED(size);
if ((flags &amp; F_ZERO) &amp;&amp; !(flags &amp; F_MINUS))
padd = &#39;0&#39;;
if (is_negative)
extra_ch = &#39;-&#39;;
else if (flags &amp; F_PLUS)
extra_ch = &#39;+&#39;;
else if (flags &amp; F_SPACE)
extra_ch = &#39; &#39;;
return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));

}
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer

 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 &amp;&amp; ind == BUFF_SIZE - 2 &amp;&amp; buffer[ind] == &#39;0&#39; &amp;&amp; width == 0)
return (0); /* printf(&quot;.0d&quot;, 0)  no char is printed */
if (prec == 0 &amp;&amp; ind == BUFF_SIZE - 2 &amp;&amp; buffer[ind] == &#39;0&#39;)
buffer[ind] = padd = &#39; &#39;; /* width is displayed with padding &#39; &#39; */
if (prec &gt; 0 &amp;&amp; prec &lt; length)
padd = &#39; &#39;;
while (prec &gt; length)
buffer[--ind] = &#39;0&#39;, length++;
if (extra_c != 0)
length++;
if (width &gt; length)
{
for (i = 1; i &lt; width - length + 1; i++)
buffer[i] = padd;
buffer[i] = &#39;\0&#39;;
if (flags &amp; F_MINUS &amp;&amp; padd == &#39; &#39;)/* Asign extra char to left of buffer */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[ind], length) + write(1, &amp;buffer[1], i - 1));
}
else if (!(flags &amp; F_MINUS) &amp;&amp; padd == &#39; &#39;)/* extra char to left of buff */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[1], i - 1) + write(1, &amp;buffer[ind], length));
}
else if (!(flags &amp; F_MINUS) &amp;&amp; padd == &#39;0&#39;)/* extra char to left of padd */
{
if (extra_c)

buffer[--padd_start] = extra_c;
return (write(1, &amp;buffer[padd_start], i - padd_start) +
write(1, &amp;buffer[ind], length - (1 - padd_start)));

}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[ind], length));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)
{
/* The number is stored at the bufer&#39;s right and starts at position i */
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = &#39; &#39;;
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 &amp;&amp; ind == BUFF_SIZE - 2 &amp;&amp; buffer[ind] == &#39;0&#39;)
return (0); /* printf(&quot;.0d&quot;, 0)  no char is printed */
if (precision &gt; 0 &amp;&amp; precision &lt; length)
padd = &#39; &#39;;
while (precision &gt; length)
{
buffer[--ind] = &#39;0&#39;;
length++;
}
if ((flags &amp; F_ZERO) &amp;&amp; !(flags &amp; F_MINUS))

padd = &#39;0&#39;;
if (width &gt; length)
{
for (i = 0; i &lt; width - length; i++)
buffer[i] = padd;
buffer[i] = &#39;\0&#39;;
if (flags &amp; F_MINUS) /* Asign extra char to left of buffer [buffer&gt;padd]*/
{
return (write(1, &amp;buffer[ind], length) + write(1, &amp;buffer[0], i));
}
else /* Asign extra char to left of padding [padd&gt;buffer]*/
{
return (write(1, &amp;buffer[0], i) + write(1, &amp;buffer[ind], length));
}
}
return (write(1, &amp;buffer[ind], length));
}
/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width &gt; length)
{
for (i = 3; i &lt; width - length + 3; i++)
buffer[i] = padd;
buffer[i] = &#39;\0&#39;;
if (flags &amp; F_MINUS &amp;&amp; padd == &#39; &#39;)/* Asign extra char to left of buffer */

{
buffer[--ind] = &#39;x&#39;;
buffer[--ind] = &#39;0&#39;;
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[ind], length) + write(1, &amp;buffer[3], i - 3));
}
else if (!(flags &amp; F_MINUS) &amp;&amp; padd == &#39; &#39;)/* extra char to left of buffer */
{
buffer[--ind] = &#39;x&#39;;
buffer[--ind] = &#39;0&#39;;
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[3], i - 3) + write(1, &amp;buffer[ind], length));
}
else if (!(flags &amp; F_MINUS) &amp;&amp; padd == &#39;0&#39;)/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = &#39;0&#39;;
buffer[2] = &#39;x&#39;;
return (write(1, &amp;buffer[padd_start], i - padd_start) +
write(1, &amp;buffer[ind], length - (1 - padd_start) - 2));

}
}
buffer[--ind] = &#39;x&#39;;
buffer[--ind] = &#39;0&#39;;
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &amp;buffer[ind], BUFF_SIZE - ind - 1));
}
