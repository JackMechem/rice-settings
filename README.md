# rice-settings (WIP)
> A configurable terminal settings application written in c++ made to make configuration files and apps more accessible.

## Installation
> May not work properly.

Install required dependencies:

- [yaml-cpp](https://github.com/jbeder/yaml-cpp)

```bash
# arch linux
sudo pacman -S yaml-cpp
```

Clone and cd into the repo:
```bash
git clone https://github.com/JackMechem/rice-settings.git

cd rice-settings
```

Run the installation script. (Builds the application (binary located in bin/) and copies to /usr/bin/):
```bash
make install
```

## Usage

### Config file
> SUBJECT TO CHANGE

Before rice-settings can be run, a config file will need to be created at `$HOME/.config/rice-settings/conf.yaml`.

#### Config File Format
rice-settings uses yaml for its config file. A good refrence for yaml syntax can be found [here](https://docs.ansible.com/ansible/latest/reference_appendices/YAMLSyntax.html)
All entries must be nested in a list called `entries`. Each list item is an object that contains the properties in the table below. 

| Property (note: * means required)   | Value Type  | Description |
|:-----------:|:------------|:-----------------------------|
| *name       | string      | Name shown in application    |
| command     | string | Command that is executed if the entry is selected **(Note: Do not add a & at the end of the command).** *If this field is not defined, the entry will be displayed as a title* |

#### Example Config File
```yaml
# Enteries show up in the same order as config file
entries: [ 
  {
    name: "Appearance" # If no command is given, it will be assumed to be a title.
  },
  { 
    name: Wallpaper,   # Name shown in terminal.
    command: waypaper  # Command that is run if selected. Do not add a & at the end (This will break things).
  }, 
  {
    name: GTK Settings,
    command: nwg-look
  }, 
  {
    name: Hyprland Config,
    command: kitty --hold sh -c "nvim /home/jack/.config/hypr/hyprland.conf"
  }, 
]
```

### Running The Program

**To show the help page:**
```bash
rice-settings -h 
# or
rice-settings --help
```

**To run rice-settings with the default config location ($HOME/.config/rice-settings):**
```bash
rice-settings
```

**To run rice-settings with a custon config location:**
```bash
rice-settings -c /path/to/config.yaml
# or
rice-settings --config /path/to/config.yaml
```

## Credits
```
Written by Jack Mechem
```
