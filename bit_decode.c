/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED ** TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY ** WITH RESPECT TO THIS ASSIGNMENT.
 *  * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned char create_key(void);
unsigned char rotate_right(unsigned char, int);
unsigned char rotate_left(unsigned char, int);
void decrypt(unsigned char);
#undef PROMPT

int main(void)
{
/*Brian Tan*/
/*user inputs a 4bit pin and an encrypted message, using the pin to create a 8bit key, the key and the encrypted message is put into an algorithm and the decoded message is outputed*/
    unsigned char key;
    /* create key*/
#ifdef PROMPT
    printf("enter 4 bit: ");
#endif
    key = create_key();
    /* use key to decrypt message*/
#ifdef PROMPT
    printf("enter encrypted message: ");
#endif
    decrypt(key);
/*output new line*/
putchar('\n');
    return 0;
}

/*decrypt and output message, using the key*/
void decrypt(unsigned char key)
{
    unsigned int i = 0, c, x = 0;
    /* while next char is not a new line, get input as hex*/
    while (    scanf("%2x", &c)>0)
    {
    /* use algorithm to decrypt hex*/
/*if statement to decide if rotate left or right*/
    if (i % 2 != 0)
        c = rotate_left(c, 1);
    else
        c = rotate_right(c, 1);
    /* xor against key*/
    c = c ^ key;
    putchar(c);        
        i++;
/*break out of loops if newline */
        if (getchar() == '\n')
break;
    }
}

/*create 8 bit key from 4 bit pin*/
unsigned char create_key(void)
{
    unsigned char c;
    unsigned char key;
    int i;
    unsigned char copy = 0;
    /* get 4 bit key*/
    for (i = 3; i >= 0; i--)
    {
        c = getchar();
        /* copy the key*/
        if (c == '1')
            copy = 1;
        else
            copy = 0;
        c = c << 4;
        c = (c | copy) << (i);
        key |= c;
    }
    return key;
}

/*rotate the encrytion right with carry*/
unsigned char rotate_right(unsigned char c, int y)
{
    /* if 1 is the right most character, move it over to the left.*/
    if ((c & 1) == 1)
        c = (c >> y) | 128;
    else
        c = c >> y;
    return c;
}


/*rotate the encrytion left  with carry*/
unsigned char rotate_left(unsigned char c, int y)
{
    /* if 1 is the left most character, move it over to the right.*/
    if ((c & 128) == 128)
        c = (c << y) | 1;
    else
        c = c << y;
    return c;
}

