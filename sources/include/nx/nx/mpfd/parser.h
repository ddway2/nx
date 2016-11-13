// This file is distributed under GPLv3 licence
// Author: Gorelov Grigory (gorelov@grigory.info)
//
// Contacts and other info are on the WEB page:  grigory.info/MPFDParser
#pragma once

#include <nx/config.h>
#include <iostream>
#include <string>
#include <map>
#include <nx/mpfd/exception.h>
#include <nx/mpfd/field.h>
#include <string.h>
#include <stdlib.h>

namespace nx {
namespace MPFD {

    class NX_API parser {
    public:
        static const int StoreUploadedFilesInFilesystem = 1, StoreUploadedFilesInMemory = 2;


        parser();
        ~parser();

        void content_type(const std::string& type);

        void accept_data(const char *data, const long length);



        void SetMaxCollectedDataLength(long max);
        void SetTempDirForFileUpload(const std::string& dir);
        void SetUploadedFilesStorage(int where);

        std::map<std::string, field *> get_fields_map();
        field * get_field(const std::string& Name);

    private:
        int WhereToStoreUploadedFiles;

        std::map<std::string, field *> Fields;

        std::string TempDirForFileUpload;
        int CurrentStatus;

        // Work statuses
        static int const Status_LookingForStartingBoundary = 1;
        static int const Status_ProcessingHeaders = 2;
        static int const Status_ProcessingContentOfTheField = 3;

        std::string Boundary;
        std::string ProcessingFieldName;
        bool _HeadersOfTheFieldAreProcessed;
        long ContentLength;
        char *DataCollector;
        long DataCollectorLength, MaxDataCollectorLength;
        bool FindStartingBoundaryAndTruncData();
        void _ProcessData();
        void _ParseHeaders(std::string headers);
        bool WaitForHeadersEndAndParseThem();
        void TruncateDataCollectorFromTheBeginning(long n);
        long BoundaryPositionInDataCollector();
        bool ProcessContentOfTheField();
    };
}
}   // namespace nx


