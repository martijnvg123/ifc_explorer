#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <vector>

#include "IFC4X3_RC2.hxx"
#include "IfcFileDeserializer.h"

int main()
{
    const std::filesystem::path TEST_FILE{"./test_data/SpatialStructure_2.ifc"};

    IfcFileDeserializer deserializer{};
    deserializer.Deserialize(TEST_FILE);
    
    return 0;
}