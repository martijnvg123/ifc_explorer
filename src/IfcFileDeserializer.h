#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <vector>
#include <cstring>

#include "IfcConstants.h"

std::map<std::string, IfcEx::IfcSchema> IFC_SCHEMA_MAP{
    {"IFC4X3_RC2", IfcEx::IfcSchema::IFC4X3_RC2},
    {"IFC2x3", IfcEx::IfcSchema::IFC2x3}};

class IfcHeader
{
public:
    IfcHeader(IfcEx::IfcSchema schema)
    {
        Schema = schema;
    };

    IfcEx::IfcSchema Schema;
};

class IfcFile
{
public:
    // IfcFile() {};

    IfcHeader Header;
};


class IfcFileDeserializer
{
public:
    std::vector<std::string> ReadFileLines(std::filesystem::path path)
    {
        std::ifstream file(path);
        std::string line;
        std::vector<std::string> statements{};

        if (file.is_open())
        {
            std::string lineBuffer{};

            while (std::getline(file, line))
            {
                lineBuffer.append(line);
                if (line.contains(IfcEx::LEND))
                {
                    statements.push_back(std::move(lineBuffer));
                }
            }
        }

        return statements;
    }

    IfcFile Deserialize(std::filesystem::path path)
    {
        std::vector<std::string> statements = ReadFileLines(path);

        for(std::string& entry : statements)
        {
            int endlIndex = entry.length() - 1;
            std::string ch = &(entry[endlIndex]);
            // char* chPtr = &ch;
            bool isEndl = ch == IfcEx::LEND;
            if (!entry.empty() && isEndl)
            {
                entry.pop_back();
            }
        }

        return IfcFile{IfcHeader{IfcEx::IfcSchema::IFC4X3_RC2}};
    }
};