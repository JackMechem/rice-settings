# Rice Settings With GUI (Using WxWidgets)
> An application written in c++ made to put all configuration files, apps, and scripts in one place (like a web portal).
> Disclaimer: I started this project as a part of my c++ learning journey. Please bear with any poorly written code!

## Installation
> Not widely tested

Install required dependencies:

- [yaml-cpp](https://github.com/jbeder/yaml-cpp)
- [wxwidgets](https://www.wxwidgets.org/)
- [cmake](https://cmake.org/)

```bash
# arch linux
sudo pacman -S yaml-cpp wxwidgets-gtk3 wxwidgets-common cmake
```

Clone and cd into the repo:
```bash
git clone https://github.com/JackMechem/rice-settings.git

cd rice-settings
```

Build and install with cmake:
```bash
cd build/
cmake ..
cmake --build .
cmake --install .
```

## Usage

### Config file

Before rice-settings can be run, a config file will need to be created at `$HOME/.config/rice-settings/conf.yaml`.

#### Config File Format
rice-settings uses yaml for its config file. A good refrence for yaml syntax can be found [here](https://docs.ansible.com/ansible/latest/reference_appendices/YAMLSyntax.html)
All entries must be nested in a list called `entries`. Each list item is an object that contains the properties in the table below. 

| Property (note: * means required)   | Value Type  | Description |
|:-----------:|:------------|:-----------------------------|
| *entries | array of objects | Where all entries go. |
| *name       | string      | Name shown in application    |
| command     | string | Command that is executed if the entry is selected **(Note: Do not add a & at the end of the command).** *If this field is not defined, the entry will be displayed as a title* |
| close-application-after | boolean  | if set to true, the applicaiton will close when an entry is executed. defaults to false. |
| dialog-after-run | boolean | If set to true, a message dialog will show after an extry is executed. |
| dialog-confirm | boolean | If set to true, a confirm dialog will display before an application is executed. dialog-after-run must also be set to true. |


#### Example Config File
```yaml
close-application-after: true
dialog-after-run: true
dialog-confirm: true

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

**To run rice-settings with the default config location ($HOME/.config/rice-settings):**
```bash
rice-settings
```

## Credits
```
Written by Jack Mechem
```
