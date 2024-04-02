/*
 *
 *  Written By Jack Mechem
 *
 *  I am very new to c++ so this project is most likely written horribly.
 *  If you see something you don't like, make a pull request. :)
 *
 */

#include "yaml-cpp/yaml.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <pwd.h>
#include <string>
#include <unistd.h>
#include <vector>

// GTK
using namespace std;

int main(int argc, char *argv[]) {

    string customConfigLocation;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            cout << "\nHelp Page\n"
                 << "---------\n\n"
                 << "-h | --help                                        -->  "
                    "Help\n\n"
                 << "-c [/path/to/config] | --config [/path/to/config]  -->  "
                    "Custom "
                    "Config Location (Default is "
                    ".config/rice-settings/conf.yaml)\n\n";
            return 0;
        }

        if (strcmp(argv[i], "--config") == 0 || strcmp(argv[i], "-c") == 0) {
            customConfigLocation = argv[i + 1];
        }
    }

    // Clean terminal
    system("clear");

    try {

        ifstream file;

        struct passwd *pw = getpwuid(getuid());

        const string homedir = pw->pw_dir;

        // Load the config file
        YAML::Node config;
        if (customConfigLocation.size() > 0) {
            file.open(customConfigLocation);
            if (file) {
                config = YAML::LoadFile(customConfigLocation);
            } else {
                cout << "Could not find config file at location: "
                     << customConfigLocation << endl;
            }

        } else {
            file.open(homedir + "/.config/rice-settings/conf.yaml");
            if (file) {
                config = YAML::LoadFile(homedir +
                                        "/.config/rice-settings/conf.yaml");
            } else {
                cout << "Could not find config file at location: "
                     << homedir + "/.config/rice-settings/conf.yaml\n";
            }
        }

        if (config["entries"]) {
            YAML::Node entries = config["entries"];

            struct entry {
                string name;
                string command;
            };

            vector<entry> entriesParsed;

            for (int i = 0; i < entries.size(); i++) {
                entry ent;
                ent.name = entries[i]["name"].as<string>();
                if (entries[i]["command"]) {
                    ent.command = entries[i]["command"].as<string>();
                    cout << "(" << i << ")" << " | " << ent.name << endl;
                    entriesParsed.push_back(ent);
                } else {
                    // runs if there is no command. At the moment this is
                    // assumed to be a title.
                    ent.command = "";
                    entriesParsed.push_back(ent);
                    cout << endl << ent.name << endl;
                    cout << std::string(ent.name.size(), '=') + "\n \n";
                }
            }

            cout << "\nInput The Number Of The Setting You Would Like To "
                    "Launch: ";
            int inputIndex;
            cin >> inputIndex;

            string command;
            if (entriesParsed[inputIndex].command.size() > 0) {
                command = entriesParsed[inputIndex].command + " &>/dev/null &";
            } else {
                cout << "Not a valid option\n";
                return 0;
            }

            // Clean terminal
            system("clear");

            // Run command given by config file
            system(command.c_str());

            // Clean terminal
            system("clear");
        }

    } catch (const YAML::ParserException &ex) {
        std::cout << "FILE ERROR" << std::endl;
    }

    return 0;
}
