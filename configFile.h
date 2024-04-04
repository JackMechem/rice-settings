#include "yaml-cpp/yaml.h"
#include <fstream>
#include <iostream>
#include <vector>

using std::string, std::vector, std::ifstream, std::cout;

struct entry {
    string name;
    string command;
};

class ConfigFile {
  public:
    ConfigFile();

    std::vector<entry> getParsedEntries();

    struct dialog {
        bool commandDialog;
        bool dialogConfirm;
    };

    bool getCloseApplication();
    dialog getCommandDialog();

    ~ConfigFile();

  private:
    YAML::Node config;
    vector<entry> entriesParsed;

    // default values
    bool closeApplication = false;
    bool commandDialog = false;
    bool dialogConfirm = false;
};
