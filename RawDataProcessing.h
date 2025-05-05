#ifndef RAW_DATA_PROCESSING_H
#define RAW_DATA_PROCESSING_H


#include <string>
#include <sstream>
#include "FileIO.h"
#include "Constants.h"
#include "DataSorting.h"
#include "TypeDefinitions.h"
#include "DataComparisonDefinitions.h"
#include "Classes/Date/Date.h"
#include "Classes/Time/Time.h"
#include "Classes/DateTime2DBst/DateTime2DBst.h"

#include <iostream>
using namespace std;

using std::string;
using std::stringstream;

bool StoreAllUnaggregatedRecordsInVector(
                UnaggregatedWeatherVector& unaggWeatherVec,
                string& errorMessage);

bool StoreFileNamesInVector(StringVector& fileNamesVec,
                            string& errorMessage);


bool StoreRawStringDataInVector(
                const StringVector& fileNamesVec,
                StringVector& rawStringDataVec,
                string& errorMessage);


bool StoreRawStringDataInVector(
                const StringVector& fileNamesVec,
                StringVector& rawStringDataVec,
                string& errorMessage);


bool ExtractAndStoreAllFileRecordsInVector(
                    const StringVector& fileNamesVec,
                    UnaggregatedWeatherVector& unaggWeatherVec,
                    string& errorMessage);


bool ExtractAndStoreCurrentFileRecordInVector (
                const string& fileDataString,
                DateTime2DBst& unaggWeatherQueryMap,
                UnaggregatedWeatherVector& unaggWeatherVec);


bool StoreSingleRecordInVector(
            const RawWeatherData& rawWeatherData,
            UnaggregatedWeatherVector& unaggWeatherVec,
            DateTime2DBst& unaggWeatherQueryTree);

#endif // RAW_DATA_PROCESSING_H
