# ColorWall-Hass
The Home Assistant integration for ColorWall

[![hacs_badge](https://img.shields.io/badge/HACS-Custom-orange.svg?style=for-the-badge)](https://github.com/custom-components/hacs)

# Integrates ColorWall with Home Assistant
A simple integration for controlling light panels that are 3D printable and open for modification. See the build guide here (TODO, add post link) for all the details on the hardware side.
By default, there are a few effects available but more can easily be added with a few firmware modifications. The controller will appear as its own entity allowing for control of on/off, master brightness, and effect selection.
Each panel will also show up as an entity, allowing for control of on/off, color, and brightness per panel.

# Installing
This integration can be installed simply by copying the files located in the "custom_components" folder to the custom_components folder in your instance. 
Alternatively, you can install it using a custom repository in HACS. To do so, visit the HACS menu in Home Assistant and click on the 3 dots in the top right corner.
Then click on "Custom repositories" and add the URL of this repository in the "Add custom reposity URL" field.
