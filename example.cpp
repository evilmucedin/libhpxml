#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "hpXmlWrapper.h"

int main(int argc, char *argv[])
{
    const bool quite = argc > 1;

    THPXml xml;

    // loop as long as XML elements are available
    size_t count = 0;
    while (xml.Next())
    {
        ++count;
        if ( 0 == (count % 1000000) )
        {
            std::cout << count << "\t" << xml.GetTotal() << std::endl;
        }
        if (!quite)
        {
            printf("[%ld] type=%d, name=%.*s, nattr=%d\n", xml.GetLineNumber(), xml.GetTag()->type, xml.GetTag()->tag.len, xml.GetTag()->tag.buf, xml.GetTag()->nattr);
        }
    }

    return 0;
}
