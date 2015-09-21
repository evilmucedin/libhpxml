#include <stdio.h>
#include <stdlib.h>

#include "hpXmlWrapper.h"

int main(int argc, char *argv[])
{
    const bool quite = argc > 1;

    THPXml xml;

    // loop as long as XML elements are available
    while (xml.Next())
    {
        if (!quite)
        {
            printf("[%ld] type=%d, name=%.*s, nattr=%d\n", xml.GetLineNumber(), xml.GetTag()->type, xml.GetTag()->tag.len, xml.GetTag()->tag.buf, xml.GetTag()->nattr);
        }
    }

    return 0;
}
