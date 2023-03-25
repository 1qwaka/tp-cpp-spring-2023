#include <iostream>
#include <string>
#include <filesystem>


#include "PrincipalsParser.h"
#include "TitleBasicsParser.h"
#include "AkasParser.h"


bool need_help(int argc, char *argv[]);
void help();
bool files_exists(char *argv[]);
int do_logic(char *argv[]);

int main(int argc, char *argv[]) {
    if (need_help(argc, argv)) {
        help();
        return 0;
    }

    if (argc != 5) {
        std::cout << "usage error" << std::endl;
        return 1;
    }

    if (!files_exists(argv)) {
        std::cout << "required files doesn't exists" << std::endl;
        return 2;
    }

    return do_logic(argv);
}


int do_logic(char *argv[]) {
    PrincipalsParser principals(argv[1]);
    TitleBasicsParser title_basics(argv[2]);
    AkasParser akas(argv[3]);
    std::string name(argv[4]);

    std::vector<size_t> ids, filtered_ids;

#ifdef DEBUG
    std::cout << "start search titles with character names" << std::endl;
#endif

    principals.getTitleIdsByCharacterName(ids, name);

#ifdef DEBUG
    std::cout << "IDs found:" << std::endl;
    for (size_t id : ids) {
        std::cout << "tt" << id << " ";
    }
    std::cout << std::endl;
#endif

    title_basics.filterNonAdultIds(ids, filtered_ids);

#ifdef DEBUG
    std::cout << "filtered IDs:" << std::endl;
    for (size_t id : filtered_ids) {
        std::cout << "tt" << id << " ";
    }
    std::cout << std::endl;
    
    std::cout << "names found:" << std::endl;
#endif
    
    akas.printRuNames(filtered_ids);

    return 0;
}


bool need_help(int argc, char *argv[]) {
    return argc == 2 && 
            (std::string("-h") == argv[1] || std::string("--help") == argv[1]);
}

void help() {
    std::cout << "usage: ./main.exe PRINCIPALS TITLE_BASICS AKAS NAME" << std::endl;
    std::cout << "PRINCIPALS - path to title.principals.tsv" << std::endl;
    std::cout << "TITLE_BASICS - path to title.basics.tsv" << std::endl;
    std::cout << "AKAS - path to title.akas.tsv" << std::endl;
    std::cout << "NAME - character name" << std::endl;
}

bool files_exists(char *argv[]) {
    return std::filesystem::exists(argv[1]) && 
           std::filesystem::exists(argv[2]) && 
           std::filesystem::exists(argv[3]); 
}