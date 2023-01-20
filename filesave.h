#ifndef FILESAVE_H
#define FILESAVE_H

#include "address.h"

#include <string>
#include <QWidget>
#include <vector>

class FileSave
{
public:
    FileSave();

public:
    void save_addresses_data_txt(std::vector<Address>& addresses);

private:
    static const std::string m_addresses_file_path;
    static const std::string m_addresses_data_txt_end_symbol;
};

#endif // FILESAVE_H
