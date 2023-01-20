#include "filesave.h"

#include <fstream>

const std::string FileSave::m_addresses_file_path = "../AddressBook/addresses_data.txt";
const std::string FileSave::m_addresses_data_txt_end_symbol = "(*)";

FileSave::FileSave()
{}

void FileSave::save_addresses_data_txt(std::vector<Address>& addresses) {
    std::ofstream fout;

    if (addresses.empty()) {
        return;
    }

    fout.open(m_addresses_file_path);
    fout << addresses.size() << "\n";
    for (auto i : addresses) {
        fout << i.get_name() << " " << i.get_email() << " " << i.get_phone() << "\n";
    }
    fout << "(*)";
}
