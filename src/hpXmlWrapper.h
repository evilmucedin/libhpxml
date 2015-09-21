#pragma once

#include "libhpxml.h"

class THPXml
{
private:
    hpx_ctrl_t* m_ctl;
    hpx_tag_t* m_tag;
    bstring_t m_b;
    long m_lno;

public:
    THPXml();
    ~THPXml();

    bool Next();

    const hpx_tag_t* GetTag() const 
    {
        return m_tag;
    }

    long GetLineNumber() const
    {
        return m_lno;
    }

    long GetTotal() const 
    {
        return m_ctl->total;
    }
};
