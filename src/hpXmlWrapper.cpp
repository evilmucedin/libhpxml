#include "hpXmlWrapper.h"

#include <stdexcept>

THPXml::THPXml()
{
    m_ctl = hpx_init(0, 100*1024*1024);
    if (!m_ctl)
    {
        throw std::runtime_error("hpx_init failed");
    }

    m_tag = hpx_tm_create(1 << 10);
    if (!m_tag)
    {
        hpx_free(m_ctl);
        m_ctl = nullptr;

        throw std::runtime_error("hpx_tm_create failed");
    }
}

THPXml::~THPXml()
{
    hpx_tm_free(m_tag);
    m_tag = nullptr;

    hpx_free(m_ctl);
    m_ctl = nullptr;
}

bool THPXml::Next()
{
    bool res = hpx_get_elem(m_ctl, &m_b, NULL, &m_lno) > 0;
    if (res)
    {
        if (hpx_process_elem(m_b, m_tag))
        {
           throw std::runtime_error("bad XML 1"); 
        }
    }
    else
    {
        if (!m_ctl->eof)
        {
            throw std::runtime_error("bad XML 2");
        }
    }
    return res;
}
