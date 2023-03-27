#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

#include "args.h"
#include "PrincipalsParser.h"
#include "TitleBasicsParser.h"
#include "AkasParser.h"


static constexpr int kNoErr = 0;
static constexpr int kUsageErr = 1;
static constexpr int kFilesNotExistsErr = 2;

static constexpr const char *kPrincipalsArg = "--principals";
static constexpr const char *kTitleBasicsArg = "--titlebasics";
static constexpr const char *kAkasArg = "--akas";
static constexpr const char *kNameArg = "--name";


bool need_help(int argc, char *argv[]);
void help();

bool file_exists(char *path);
bool files_exists(const std::vector<char*>& files);

int get_ru_title_names_by_character_name(int argc, char *argv[]);


int main(int argc, char *argv[]) {
    if (need_help(argc, argv)) {
        help();
        return kNoErr;
    }

    if (argc != 5) {
        std::cerr << "usage error" << std::endl;
        return kUsageErr;
    }

    std::vector<char*> files{args::get_argvalue_or_null(argc, argv, kPrincipalsArg),
                             args::get_argvalue_or_null(argc, argv, kTitleBasicsArg),
                             args::get_argvalue_or_null(argc, argv, kAkasArg)};
    if (!files_exists(files)) {
        std::cerr << "required files doesn't exists" << std::endl;
        return kFilesNotExistsErr;
    }

    return get_ru_title_names_by_character_name(argc, argv);
}


int get_ru_title_names_by_character_name(int argc, char *argv[]) {
    PrincipalsParser principals(args::get_argvalue_or_null(argc, argv, kPrincipalsArg));
    TitleBasicsParser title_basics(args::get_argvalue_or_null(argc, argv, kTitleBasicsArg));
    AkasParser akas(args::get_argvalue_or_null(argc, argv, kAkasArg));
    std::string name(args::get_argvalue_or_null(argc, argv, kNameArg));

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

    return kNoErr;
}


bool need_help(int argc, char *argv[]) {
    return args::get_arg_or_null(argc, argv, "-h") != nullptr || 
           args::get_arg_or_null(argc, argv, "--help") != nullptr;
}

void help() {
    std::cout << "usage: ./main.exe OPTIONS" << std::endl;
    std::cout << "OPTIONS: " << std::endl;
    std::cout << "--principals - path to title.principals.tsv" << std::endl;
    std::cout << "--titlebasics - path to title.basics.tsv" << std::endl;
    std::cout << "--akas - path to title.akas.tsv" << std::endl;
    std::cout << "--name - character name" << std::endl;
}

bool file_exists(char *path) {
    return path && std::filesystem::exists(path);
}

bool files_exists(const std::vector<char*>& files) {
    bool exists = true;
    for (char *f : files) {
        exists = exists && file_exists(f);
    }
    return exists;
}