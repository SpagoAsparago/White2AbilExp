# White2AbilExp
This is a code injection repository that adds most gen 6 abilities to Pokemon White 2. Only works on the US version of the ROM.

## List of Abilities currently Implemented
Those are the abilities whose basic effect currently works at the moment, issues are listed alongside them.


## How to Install
If you haven't already, install [CTRMap-CE](https://github.com/kingdom-of-ds-hacking/CTRMap-CE) as well as [CTRMapV](https://github.com/kingdom-of-ds-hacking/CTRMapV), then create an extracted folder of the contents of your ROM. 

Next you need to download [PMC](https://github.com/kingdom-of-ds-hacking/PMC), go to the extras tab of CTRMap and click "Install/Update PMC".
Then click "Convert ELF to DLL" and select the esdb.yml obtained from this repository, and at the next prompt of the file selection screen, select abilexp.elf. Now you can save your project and export your ROM.
Now open the ROM with TinkeDSi, go to the file a/0/0/2, click unpack and replace entries 384 and 385 with the files from this repository that have the same name. Next click the "Pack" button on a/0/0/2  and save the ROM.

## Assigning the new abilities to the Pokémons
At the moment there is no tool that supports expanded abilities, so you have to hex edit the personal narc. First with Tinke extract the a/0/1/6 narc. Then open a fresh BW2 ROM in PRC_BW2 (doesn't need to be the same as the one you are using), scroll to the pokemon you want to edit and copy the bytes in the hexadecimal view. Next open the a/0/1/6 narc you extracted with a hex editor and search those bytes you copied. The ability slots start at the 25th byte, being in order respectively first ability, second ability and hidden ability.
Once you found it, replace the byte in that slot with the hexadecimal number of the ability found on [Bulbapedia's List of Abilities](https://bulbapedia.bulbagarden.net/wiki/Ability#List_of_Abilities) and save the file. Then you can reinsert it with Tinke and save the ROM.

## Compiling the code
If you want to change some numbers in the ability effects or just mess around with the code, you will need the [White 2 Development Headers](https://github.com/kingdom-of-ds-hacking/swan) the g++ compiler from the [GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain). Once you've made the changes to the code files, make sure they are all in the same folder along with the swan-master folder and the g++ executable, then you can run the abilexpcompile.bat file in order to compile your code. To install it again just follow the steps previously explained.
