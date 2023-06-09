# White2 Abilities Expansion
This is a code injection repository that currently adds 20/27 Gen VI abilities to Pokemon White 2. Only works on the US version of the ROM.

## [List of Abilities currently Implemented](https://docs.google.com/spreadsheets/d/1Z9BVbam3jXbOelvhXHAxihjGmpQW1BUehAXLNb5rvwo/edit#gid=1287043581)
Those are the abilities whose basic effect currently works at the moment, known issues and missing features are listed alongside them. Extensive testing is still required, and anything related to AI behavior regarding new abilities needs to be tested as well.

## How to Install
If you haven't already, install [CTRMap-Community Edition](https://github.com/kingdom-of-ds-hacking/CTRMap-CE) as well as the [CTRMapV](https://github.com/kingdom-of-ds-hacking/CTRMapV) plugin, then create an extracted folder of the contents of your ROM, then create a new project and close CTRMap.


Go to the *vfs/data/a/0/0/2* in the folder of the project you created, and drop there files 374 and 375 from the text folder of this repo. You can open CTRMap again now.
Next you need to download [PMC](https://github.com/kingdom-of-ds-hacking/PMC), go to the extras tab of CTRMap and click *Install/Update PMC*. You only need to do this the first time you create a new project.
Then make sure there is a `patches` directory at *vfs/data/patches*, if there isn't create one and move there the latest [NitroKernel.dll file](https://github.com/HelloOO7/NitroKernel/releases).

Then all you have to do is move AbilExp.dll inside the patches folder, and export the ROM with CTRMap.

### Gen 6+ Weather Duration 
If you don't like pre gen-6 endless weather from abilities, you can install the `abilweather.dll` patch in the same way listed above to have weather abilities set the weather for 5 turns, or 8 when holding the correct rock item. 

## Assigning the new abilities to the Pokémons
At the moment there is no tool that supports expanded abilities, so you have to hex edit the personal narc. First with Tinke extract the a/0/1/6 narc. Then open a unedited BW2 ROM in PRC_BW2 (doesn't need to be the same as the one you are using), scroll to the pokemon you want to edit and copy the bytes listed in the hexadecimal view. Next open the a/0/1/6 narc you extracted with a hex editor and search those bytes you copied. The ability slots start at the 25th byte, being in order respectively first ability, second ability and hidden ability.
Once you found it, replace the byte in that slot with the hexadecimal number of the ability found on [Bulbapedia's List of Abilities](https://bulbapedia.bulbagarden.net/wiki/Ability#List_of_Abilities) and save the file. Then you can reinsert it with Tinke and save the ROM.

## Compiling the code
If you want to change some numbers in the ability effects or just mess around with the code, you will need to download the [White 2 Development Headers](https://github.com/kingdom-of-ds-hacking/swan). If you haven't already, you also need to install the [ARM GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads). Once you've made the changes to the code files, you can compile it with g++.
Move the .cpp and .h files to the same folder along the swan-master folder, then launch the cmd from that folder and run `arm-none-eabi-g++ -r -mthumb -march=armv5t -Os abilexp.cpp -Iswan-master -o abilexp.elf`.

Next open CTRMap and go to the Extras tab, click "Convert ELF to DLL" and select the `esdb.yml` obtained from this repository, and at the next prompt on file selection screen, select the `abilexp.elf` file you previously compiled and make sure the *install to /patches* checkbox is enabled. Now you can save your project and export your ROM.

## Fairy Type
Pixilate and Fairy Aura work as well if the fairy type is implemented, otherwise they will affect only Struggle. For the fairy type implementation check [this page](https://kingdom-of-ds-hacking.github.io/gen5/b2w2/guides/fairy/fairy.html).
If the fairy type isn't implemented, Protean will make your mon typeless when using struggle. If you don't like this, change `if ( (result) != 18 )` to `if ( (result) != 17 )` in the `HandlerProtean` function, then compile the code.

## Issues Reporting/Contribute
You can message me on this discord at SpagoAsparago#1084.
If you are having troubles compiling the code or running CTRMap, I recommend joining [this server](https://discord.gg/zAtqJDW2jC).

## Credits
* Hello007 - CTRMap and the Gen V code injection system
* PlatinumMaster - Gen V code injection system and aswering a lot of my questions
* totally_anonymous - Battle IDB documentation
* Sunkern Enjoyer - For the help in fixing my code and researching some functions
