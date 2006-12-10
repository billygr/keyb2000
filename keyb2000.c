/* Keyboard Matrix Decoder
   $Id$
*/

#define MICROCONTROLLER_8051
#include <mcs51reg.h>
const char *version = "Keyb2000 V1.2 2004 by billy";


char power(char ekthetis)
{
        char i,j;

        j=1;
        for (i=1;i<=ekthetis;i++) j=j*2;
        return j;
}

char keypress(void)
{
        char i,j,k,ret;

        ret=0;
        P1=0;
	for(i=4;i<=7;i++)
        {
                j=power(i);
		P1=j;
		k=P1;

		if (k != j) ret=1;
		
        }
        return ret;
}

char findcol(char pos)
{
        char i,j,a; 

        P1=255-power(pos);

        for(i=0;i<=3;i++)
        {
                j=255-power(i);          
			
                a=P1;

                a=(255-(a & j)/16)&0x0f;
        }
        return a;
}

char findrow()
{
        char i,j,row;

        for(i=0;i<=3;i++)
        {
                j=findcol(i);
			
                if (j!=0)
                {
                        row=i;
                        i=3;
                }
        }

        return row;
}

char scan(void)
{
        char a,b,c,scankey;

        a=keypress();

        scankey=-1;

        if (a)
        {
                b=findrow();
                c=findcol(b);

                switch (c)
                {
                        case 1: scankey=(b*4)+0;break;
                        case 2: scankey=(b*4)+1;break;
                        case 4: scankey=(b*4)+2;break;
                        case 8: scankey=(b*4)+3;break;
                        default : break;
                }
        }
        
return scankey;
}


void main(void)
{
        char a;

        P3_4=1;

        while(1)
        {
                a=scan();

                if (a)
                {
                        P3=a & 0x0F;
                        P3_4=0;
                        P3_4=0;
                        P3_4=0;
                        P3_4=0;

                        P3_4=0;
                        P3_4=0;
                        P3_4=0;
                        P3_4=0;

			P3_4=0;
			P3_4=0;
			P3_4=0;
			P3_4=0;

                        P3_4=1;

                        while(keypress()==1){ };
                }
        }
}
