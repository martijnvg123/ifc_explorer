#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <vector>

#include "IFC4X3_RC2.hxx"

const std::filesystem::path TEST_FILE{"./test_data/SpatialStructure_2.ifc"};

enum class IfcSchema
{
    IFC4X3_RC2,
    IFC2x3, //?
};

std::map<std::string, IfcSchema> IFC_SCHEMA_MAP{
    {"IFC4X3_RC2", IfcSchema::IFC4X3_RC2},
    {"IFC2x3", IfcSchema::IFC2x3}
};

class IfcHeader
{
    IfcHeader(IfcSchema schema)
    {
        Schema = schema;
    };

    IfcSchema Schema;

};

class IfcFile
{
    public:
    // IfcFile() {};

    IfcHeader Header;
};

const std::string_view LEND = ";";
int main() 
{
    std::ifstream file(TEST_FILE);

    std::string line;
    std::vector<std::string> statements{};

    if(file.is_open())
    {
        std::string lineBuffer{};

         while(std::getline(file, line))
        {
            lineBuffer.append(line);
            if(line.contains(LEND))
            {
                statements.push_back(std::move(lineBuffer));
                bool test = false;

            }


            // if(line == "HEADER")
            // {
            //     isHeader = true;
            //     continue;
            // }

            // if(isHeader && !headerRead)
            // {
            //     headerLines.emplace_back(line);
            // }

            // std::cout << line << std::endl;
        }
        
        // IfcHeader header{IfcSchema::IFC4X3_RC2};
        bool lel = true;
    }

    // std::byte s{"test"};
    std::cout << "Test" << std::endl;
    std::cout << "Test35" << std::endl;
    // std::cout << s << std::endl;
    return 0;
}