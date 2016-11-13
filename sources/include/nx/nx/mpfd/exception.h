// This file is distributed under GPLv3 licence
// Author: Gorelov Grigory (gorelov@grigory.info)
//
// Contacts and other info are on the WEB page:  grigory.info/MPFDParser

#pragma once

#include <string>
#include <iostream>
#include <errno.h>

#include <nx/config.h>

namespace nx {
namespace MPFD {

    class NX_API Exception {
    public:
        Exception(std::string error);
        Exception(const Exception& orig);
        virtual ~Exception();
        
        std::string GetError();
     
    private:
        std::string Error;

    };
}
}   // namespace nx


