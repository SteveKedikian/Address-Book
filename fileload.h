#ifndef FILELOAD_H
#define FILELOAD_H

#include "address.h"

#include <vector>
#include <QWidget>
#include <string>

enum {
    NO_ADDRESSES = 0
};

class FileLoad
{
public:
    FileLoad();

public:
    std::vector<Address> load_addresses_data_txt(QWidget* parent);

private:
    void load_check_and_create_addresses_data_txt(QWidget* parent);

private:
    static const std::string m_addresses_file_path;
    static const std::string m_addresses_data_txt_end_symbol;
};

#endif // FILELOAD_H
