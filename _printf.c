#include &quot;main.h&quot;

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format &amp;&amp; format[i] != &#39;\0&#39;; i++)
{
if (format[i] != &#39;%&#39;)
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &amp;buff_ind);
/* write(1, &amp;format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &amp;buff_ind);
flags = get_flags(format, &amp;i);
width = get_width(format, &amp;i, list);
precision = get_precision(format, &amp;i, list);
size = get_size(format, &amp;i);
++i;
printed = handle_print(format, &amp;i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &amp;buff_ind);

va_end(list);
return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind &gt; 0)
write(1, &amp;buffer[0], *buff_ind);
*buff_ind = 0;
}
