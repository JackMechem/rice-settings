/*
 *
 *  Written By Jack Mechem
 *
 *  I am very new to c++ so this project is most likely written horribly.
 *  If you see something you don't like, make a pull request. :)
 *
 */

#include "yaml-cpp/yaml.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>

#include "configFile.h"

ConfigFile::ConfigFile() {}

bool ConfigFile::getCloseApplication() {
    bool closeApp = config["close-application-after"].as<bool>();
    return closeApp;
}

ConfigFile::dialog ConfigFile::getCommandDialog() {
    dialog dia;
    dia.commandDialog = config["dialog-after-run"].as<bool>();
    dia.dialogConfirm = config["dialog-confirm"].as<bool>();
    return dia;
}

std::vector<entry> ConfigFile::getParsedEntries() {
    try {

        ifstream file;

        struct passwd *pw = getpwuid(getuid());

        const string homedir = pw->pw_dir;

        // Load the config file
        file.open(homedir + "/.config/rice-settings/conf.yaml");
        if (file) {
            config =
                YAML::LoadFile(homedir + "/.config/rice-settings/conf.yaml");
        } else {
            cout << "Could not find config file at location: "
                 << homedir + "/.config/rice-settings/conf.yaml\n";
        }

        if (config["entries"]) {
            YAML::Node entries = config["entries"];

            for (int i = 0; i < entries.size(); i++) {
                entry ent;
                ent.name = entries[i]["name"].as<string>();
                if (entries[i]["command"]) {
                    ent.command = entries[i]["command"].as<string>();
                    entriesParsed.push_back(ent);
                } else {
                    // runs if there is no command. At the moment this is
                    // assumed to be a title.
                    ent.command = "";
                    entriesParsed.push_back(ent);
                }
            }
        }

    } catch (const YAML::ParserException &ex) {
        std::cout << "FILE ERROR" << std::endl;
    }

    return entriesParsed;
}

ConfigFile::~ConfigFile() {}
