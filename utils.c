#include &quot;main.h&quot;
/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
if (c &gt;= 32 &amp;&amp; c &lt; 127)
return (1);
return (0);
}
/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = &quot;0123456789ABCDEF&quot;;
/* The hexa format code is always 2 digits long */
if (ascii_code &lt; 0)
ascii_code *= -1;

buffer[i++] = &#39;\\&#39;;
buffer[i++] = &#39;x&#39;;
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}
/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
if (c &gt;= &#39;0&#39; &amp;&amp; c &lt;= &#39;9&#39;)
return (1);
return (0);
}
/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num

 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
